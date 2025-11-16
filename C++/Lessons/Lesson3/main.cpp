#include <iostream>
using namespace std;

int main() {
    char repeat;

    do {
        int amount;

        cout << "Enter amount in UAH (1-1000): ";
        cin >> amount;

        if (amount < 1 || amount > 1000) {
            cout << "Invalid amount. Please enter a value between 1 and 1000." << endl;
            continue;
        }

        int coins[] = {10, 5, 2, 1};
        int counts[4] = {0};
        int remaining = amount;
        int totalCoins = 0;

        for (int i = 0; i < 4; i++) {
            counts[i] = remaining / coins[i];
            remaining %= coins[i];
            totalCoins += counts[i];
        }

        cout << "Sum: " << amount << " UAH ";
        for (int i = 0; i < 4; i++) {
            cout << coins[i] << " UAH: " << counts[i] << " ";
        }
        cout << endl;
        cout << "Total coins: " << totalCoins << endl;

        cout << "Do you want to try again? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
