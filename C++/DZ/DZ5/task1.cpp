#include <iostream>

using namespace std;

void sortMobile(long long mobile[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (mobile[j] > mobile[j + 1]) {
                long long temp = mobile[j];
                mobile[j] = mobile[j + 1];
                mobile[j + 1] = temp;
            }
        }
    }
}

void sortHome(long long home[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (home[j] > home[j + 1]) {
                long long temp = home[j];
                home[j] = home[j + 1];
                home[j + 1] = temp;
            }
        }
    }
}

void printList(long long mobile[], long long home[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Mobile: " << mobile[i] << ", Home: " << home[i] << endl;
    }
}

int main() {
    int size;
    cout << "Enter the number of users: ";
    cin >> size;

    long long mobile[size];
    long long home[size];

    for (int i = 0; i < size; ++i) {
        cout << "Enter mobile number for user " << i + 1 << ": ";
        cin >> mobile[i];
        cout << "Enter home number for user " << i + 1 << ": ";
        cin >> home[i];
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Sort by mobile numbers\n";
        cout << "2. Sort by home numbers\n";
        cout << "3. Print the list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sortMobile(mobile, size);
                cout << "Sorted by mobile numbers.\n";
                break;
            case 2:
                sortHome(home, size);
                cout << "Sorted by home numbers.\n";
                break;
            case 3:
                printList(mobile, home, size);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
