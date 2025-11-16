#include <iostream>
using namespace std;

int main() {
    int choice;

    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Factorial" << endl;
        cout << "2. Multiplication table" << endl;
        cout << "3. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int num;
                cout << "Enter a number: ";
                cin >> num;

                if(num < 0) {
                    cout << "Please enter a positive number!" << endl;
                }
                else {
                    int factorial = 1;
                    for(int i = 1; i <= num; i++) {
                        factorial *= i;
                    }
                    cout << "Factorial of " << num << " = " << factorial << endl;
                }
                break;
            }
            case 2: {
                int num;
                cout << "Enter a number: ";
                cin >> num;

                if(num < 0) {
                    cout << "Please enter a positive number!" << endl;
                }
                else {
                    for(int i = 1; i <= 10; i++) {
                        cout << num << " x " << i << " = " << (num * i) << endl;
                    }
                }
                break;
            }
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << endl;
    } while(choice != 3);

    return 0;
}
