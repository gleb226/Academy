#include <iostream>
using namespace std;

template<typename T>
class MyUniquePtr {
    T *ptr;

public:
    explicit MyUniquePtr(T *p = nullptr) : ptr(p) {
    }

    ~MyUniquePtr() { delete ptr; }

    MyUniquePtr(const MyUniquePtr &) = delete;

    MyUniquePtr &operator=(const MyUniquePtr &) = delete;

    MyUniquePtr(MyUniquePtr &&other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    MyUniquePtr &operator=(MyUniquePtr &&other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T &operator*() const { return *ptr; }
    T *operator->() const { return ptr; }
    T *get() const { return ptr; }
};

template<typename T>
class MySharedPtr {
    T *ptr;
    int *count;

public:
    explicit MySharedPtr(T *p = nullptr) : ptr(p), count(new int(1)) {
    }

    ~MySharedPtr() { release(); }

    MySharedPtr(const MySharedPtr &other) {
        ptr = other.ptr;
        count = other.count;
        (*count)++;
    }

    MySharedPtr &operator=(const MySharedPtr &other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            count = other.count;
            (*count)++;
        }
        return *this;
    }

    void release() {
        if (--(*count) == 0) {
            delete ptr;
            delete count;
        }
    }

    T &operator*() const { return *ptr; }
    T *operator->() const { return ptr; }
    int use_count() const { return *count; }
};

int main() {
    cout << "=== MyUniquePtr test ===\n";
    MyUniquePtr<int> up1(new int(42));
    cout << *up1 << endl;
    MyUniquePtr<int> up2 = std::move(up1);
    if (!up1.get()) cout << "up1 now empty\n";
    cout << *up2 << endl;

    cout << "\n=== MySharedPtr test ===\n";
    MySharedPtr<int> sp1(new int(100));
    MySharedPtr<int> sp2 = sp1;
    cout << "sp1 count: " << sp1.use_count() << endl;
    cout << "sp2 count: " << sp2.use_count() << endl;
    cout << *sp1 << endl;
    return 0;
}
