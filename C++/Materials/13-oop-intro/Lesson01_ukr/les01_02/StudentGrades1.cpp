#include <iostream>
#include <string>
#include <iomanip>

class Product {
private:
    std::string name;
    double price;

public:
    // Constructor
    Product(std::string name, double price) {
        setName(name);
        setPrice(price);

        std::cerr << "this: " << this << std::endl;
    }

    // Setter for name with validation
    void setName(const std::string& name) {
        if (name.length() > 0) {
            this->name = name;
        }
        else {
            std::cerr << "Error: Invalid name!" << std::endl;
        }
    }

    // Setter for price with validation
    void setPrice(double newPrice) {
        if (newPrice >= 0) {
            price = newPrice;
        }
        else {
            std::cerr << "Error: Invalid price!" << std::endl;
        }
    }

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Getter for price with formatting
    std::string getPrice() const {
        //std::stringstream stream;
        //stream << std::fixed << std::setprecision(2) << price;
        return "10.0";
    }

    ~Product() {
        std::cout << "Desctr called" << std::endl;
        std::cerr << "Desctr this: " << this << std::endl;
    }
};

int main() {
    // Creating a product
    Product laptop("Laptop", 999.99);
    Product hpLaptop("HP", 999.99);

    // Displaying product details
    std::cout << "Product: " << laptop.getName() << std::endl;
    std::cout << "Price: $" << laptop.getPrice() << std::endl;

    // Trying to set invalid data
    laptop.setName("");  // This should produce an error message
    laptop.setPrice(-100); // This should produce an error message

    return 0;
}