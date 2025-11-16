#include <iostream>
#include <string>

using namespace std;

class Fruit {
private:
    string name;
    string color;

public:
    Fruit(const string &name, const string &color) : name(name), color(color) {
    }

    const string &getName() const { return name; }
    const string &getColor() const { return color; }
};

class Apple : public Fruit {
private:
    double fiber;

public:
    Apple(const string &name, const string &color, double fiber)
        : Fruit(name, color), fiber(fiber) {
    }

    double getFiber() const { return fiber; }

    friend ostream &operator<<(ostream &os, const Apple &a) {
        os << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ")";
        return os;
    }
};

class Banana : public Fruit {
public:
    Banana(const string &name, const string &color) : Fruit(name, color) {
    }

    friend ostream &operator<<(ostream &os, const Banana &b) {
        os << "Banana(" << b.getName() << ", " << b.getColor() << ")";
        return os;
    }
};


int main() {
    const Apple a("Red delicious", "red", 7.3);
    cout << a << '\n';

    const Banana b("Cavendish", "yellow");
    cout << b << '\n';

    return 0;
}
