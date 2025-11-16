#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_PRODUCTS = 10;
    string names[MAX_PRODUCTS];
    double prices[MAX_PRODUCTS];
    int counts[MAX_PRODUCTS];
    int productCount = 0;
    int choice = 0;

    cout << "===== STORE MENU =====" << endl;
    cout << "1 - Add product" << endl;
    cout << "2 - Show product list" << endl;
    cout << "3 - Convert price to another currency" << endl;
    cout << "4 - Check if product is on sale" << endl;
    cout << "5 - Create order" << endl;
    cout << "6 - Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        if (productCount < MAX_PRODUCTS) {
            cout << "Enter product name: ";
            cin >> names[productCount];

            cout << "Enter product price: ";
            cin >> prices[productCount];

            cout << "Enter product quantity: ";
            cin >> counts[productCount];

            productCount = productCount + 1;
            cout << "Product added!" << endl;
        } else {
            cout << "Product list is full!" << endl;
        }
    }
    else if (choice == 2) {
        if (productCount == 0) {
            cout << "No products in the list!" << endl;
        } else {
            cout << "Product list:" << endl;
            for (int i = 0; i < productCount; i = i + 1) {
                cout << i + 1 << ". " << names[i] << " - ";
                cout << prices[i] << " UAH - ";
                cout << counts[i] << " pcs" << endl;
            }
        }
    }
    else if (choice == 3) {
        if (productCount == 0) {
            cout << "No products in the list!" << endl;
        } else {
            int productIndex;
            cout << "Select product number: ";
            cin >> productIndex;

            if (productIndex <= 0 || productIndex > productCount) {
                cout << "Invalid product number!" << endl;
            } else {
                int currencyChoice;
                cout << "Select currency:" << endl;
                cout << "1 - Dollars" << endl;
                cout << "2 - Euro" << endl;
                cout << "Your choice: ";
                cin >> currencyChoice;

                if (currencyChoice == 1) {
                    double priceInDollars = prices[productIndex - 1] / 40;
                    cout << "Price in dollars: " << priceInDollars << "$" << endl;
                } else if (currencyChoice == 2) {
                    double priceInEuros = prices[productIndex - 1] / 42;
                    cout << "Price in euros: " << priceInEuros << "€" << endl;
                } else {
                    cout << "Invalid currency choice!" << endl;
                }
            }
        }
    }
    else if (choice == 4) {
        if (productCount == 0) {
            cout << "No products in the list!" << endl;
        } else {
            int productIndex;
            cout << "Select product number: ";
            cin >> productIndex;

            if (productIndex <= 0 || productIndex > productCount) {
                cout << "Invalid product number!" << endl;
            } else {
                if (prices[productIndex - 1] < 50) {
                    cout << "This product is on sale!" << endl;
                } else {
                    cout << "This product is not on sale." << endl;
                }
            }
        }
    }
    else if (choice == 5) {
        if (productCount == 0) {
            cout << "No products in the list!" << endl;
        } else {
            double totalCost = 0;
            int orderQuantity;

            for (int i = 0; i < productCount; i = i + 1) {
                cout << "Enter quantity for " << names[i] << " (0 to skip): ";
                cin >> orderQuantity;

                if (orderQuantity > counts[i]) {
                    cout << "Not enough items in stock! Setting to maximum available: " << counts[i] << endl;
                    orderQuantity = counts[i];
                }

                totalCost = totalCost + (prices[i] * orderQuantity);
            }

            cout << "Total cost: " << totalCost << " UAH" << endl;

            if (totalCost > 1000) {
                double discount = totalCost * 0.1;
                double discountedTotal = totalCost - discount;
                cout << "You get a 10% discount!" << endl;
                cout << "Discount amount: " << discount << " UAH" << endl;
                cout << "Final cost: " << discountedTotal << " UAH" << endl;
            }

            cout << "Thank you for your order!" << endl;
        }
    }
    else if (choice == 6) {
        cout << "Goodbye!" << endl;
    }
    else {
        cout << "Invalid choice! Please try again." << endl;
    }

    return 0;
}
