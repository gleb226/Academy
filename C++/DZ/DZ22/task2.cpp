#include <iostream>
#include <string>

using namespace std;

class Flat {
private:
    double area;
    double price;
    string address;

public:
    Flat() : area(0.0), price(0.0), address("") {}
    Flat(double a, double p, string addr) : area(a), price(p), address(addr) {}

    Flat& operator=(const Flat& other) {
        if (this != &other) {
            area = other.area;
            price = other.price;
            address = other.address;
        }
        return *this;
    }

    bool operator==(const Flat& other) const {
        return area == other.area;
    }

    bool operator>(const Flat& other) const {
        return price > other.price;
    }

    void display() const {
        cout << "Address: " << address << ", Area: " << area << ", Price: " << price << endl;
    }
};

int main() {
    Flat flat1(50.5, 120000, "Street A");
    Flat flat2(50.5, 150000, "Street B");
    Flat flat3(70.0, 200000, "Street C");

    flat1.display();
    flat2.display();
    flat3.display();

    if (flat1 == flat2) {
        cout << "flat1 and flat2 have the same area." << endl;
    }

    if (flat1 > flat2) {
        cout << "flat1 is more expensive than flat2." << endl;
    } else {
        cout << "flat1 is not more expensive than flat2." << endl;
    }

    flat3 = flat1;
    flat3.display();

    return 0;
}
