#include <iostream>
#include <string>
using namespace std;

class Overcoat {
private:
    string type;
    double price;

public:
    Overcoat() : type(""), price(0.0) {}
    Overcoat(std::string t, double p) : type(t), price(p) {}

    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            this->type = other.type;
            this->price = other.price;
        }
        return *this;
    }

    bool operator==(const Overcoat& other) const {
        return this->type == other.type;
    }

    bool operator>(const Overcoat& other) const {
        if (*this == other) {
            return this->price > other.price;
        } else {
            cout << "Cannot compare different types of overcoats.\n";
            return false;
        }
    }

    void display() const {
        cout << "Type: " << type << ", Price: " << price << std::endl;
    }
};

int main() {
    Overcoat coat1("coat", 1200);
    Overcoat coat2("jumper", 1500);
    Overcoat coat3("jacket", 1000);

    coat1.display();
    coat2.display();
    coat3.display();

    if (coat1 == coat2) {
        cout << "coat1 and coat2 have the same type.\n";
    }

    if (coat1 == coat3) {
        cout << "coat1 and coat3 have the same type.\n";
    } else {
        cout << "coat1 and coat3 have different types.\n";
    }

    if (coat2 > coat1) {
        cout << "coat2 is more expensive than coat1.\n";
    }

    if (coat3 > coat1) {
        cout << "coat3 is more expensive than coat1.\n";
    }

    coat3 = coat1;
    coat3.display();

    return 0;
}
