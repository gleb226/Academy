#include <iostream>
#include <string>
using namespace std;

class Array {
    int *data;
    int size;

public:
    Array(int s) {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = 0;
    }

    ~Array() {
        delete[] data;
    }

    int &operator[](int i) {
        return data[i];
    }

    void operator()(int n) {
        for (int i = 0; i < size; i++) data[i] += n;
    }

    operator int() {
        int sum = 0;
        for (int i = 0; i < size; i++) sum += data[i];
        return sum;
    }

    operator string() {
        string s = "";
        for (int i = 0; i < size; i++) s += to_string(data[i]) + " ";
        return s;
    }
};

int main() {
    Array a(5);
    for (int i = 0; i < 5; i++) a[i] = i + 1;
    a(2);
    cout << "Sum: " << (int) a << endl;
    cout << "As string: " << (string) a << endl;
    return 0;
}
