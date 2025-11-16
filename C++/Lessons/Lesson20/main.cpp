#include <iostream>
using namespace std;

class Numbers {
public:

    int a, b;

    void set(int n1, int n2) {
        a = n1;
        b = n2;
    }

    void print() {
        cout << a << " " << b << endl;
    }
};

int main() {
    Numbers n1;
    n1.set(3, 3);

    Numbers n2(4, 4);

    n1.print();
    n2.print();

    return 0;
}
