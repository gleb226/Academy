#include <iostream>
#include <string>
using namespace std;

class Pet {
protected:
    string name;
    string type;

public:
    Pet(string n, string t) {
        name = n;
        type = t;
    }

    void Show() { cout << type << ": " << name << endl; }
};

class Dog : public Pet {
    string breed;

public:
    Dog(string n, string b) : Pet(n, "Dog") { breed = b; }
    void Show() { cout << type << ": " << name << " (" << breed << ")" << endl; }
};

class Cat : public Pet {
    string color;

public:
    Cat(string n, string c) : Pet(n, "Cat") { color = c; }
    void Show() { cout << type << ": " << name << " (" << color << ")" << endl; }
};

class Parrot : public Pet {
    string origin;

public:
    Parrot(string n, string o) : Pet(n, "Parrot") { origin = o; }
    void Show() { cout << type << ": " << name << " (" << origin << ")" << endl; }
};

int main() {
    Dog d("Rex", "Shepherd");
    Cat c("Mia", "White");
    Parrot p("Koko", "Africa");
    d.Show();
    c.Show();
    p.Show();
    return 0;
}
