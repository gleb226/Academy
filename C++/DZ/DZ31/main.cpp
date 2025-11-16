#include <iostream>
using namespace std;

template <typename T>
class SmartUnique {
    T* ptr;
public:
    SmartUnique(T* p = nullptr) : ptr(p) {}
    ~SmartUnique() { delete ptr; }
    SmartUnique(const SmartUnique&) = delete;
    SmartUnique& operator=(const SmartUnique&) = delete;
    SmartUnique(SmartUnique&& other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    SmartUnique& operator=(SmartUnique&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    T* get() { return ptr; }
};

template <typename T>
class SmartShared {
    T* ptr;
    int* count;
public:
    SmartShared(T* p = nullptr) : ptr(p), count(new int(1)) {}
    SmartShared(const SmartShared& other) {
        ptr = other.ptr;
        count = other.count;
        ++(*count);
    }
    SmartShared& operator=(const SmartShared& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            count = other.count;
            ++(*count);
        }
        return *this;
    }
    ~SmartShared() { release(); }
    void release() {
        if (--(*count) == 0) {
            delete ptr;
            delete count;
        }
    }
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    int use_count() const { return *count; }
};

int main() {
    cout << "=== SmartUnique ===\n";
    SmartUnique<int> u1(new int(42));
    cout << *u1 << endl;
    SmartUnique<int> u2 = move(u1);
    if (!u1.get()) cout << "u1 is empty after move\n";
    cout << *u2 << endl;

    cout << "\n=== SmartShared ===\n";
    SmartShared<int> s1(new int(100));
    SmartShared<int> s2 = s1;
    SmartShared<int> s3 = s2;
    cout << "Value: " << *s1 << endl;
    cout << "Use count: " << s1.use_count() << endl;
    return 0;
}
