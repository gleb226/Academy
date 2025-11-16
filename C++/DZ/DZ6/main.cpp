#include <iostream>
using namespace std;

const int MAX_TOYS = 100;

char names[MAX_TOYS][31];
float prices[MAX_TOYS];
int stock[MAX_TOYS];
int sold[MAX_TOYS];
int toyCount = 0;

void showTable() {
    cout << "Index Name                 Price   Stock   Sold   Profit\n";
    cout << "-------------------------------------------------------\n";
    for (int i = 0; i < toyCount; i++) {
        float profit = prices[i] * sold[i];
        cout.width(5);
        cout << (i + 1);
        cout.width(20);
        cout << names[i];
        cout.width(8);
        cout << prices[i];
        cout.width(8);
        cout << stock[i];
        cout.width(7);
        cout << sold[i];
        cout.width(9);
        cout << profit << "\n";
    }
}

void enterToys() {
    int n;
    cout << "How many toys to add (max " << (MAX_TOYS - toyCount) << "): ";
    cin >> n;
    if (n > (MAX_TOYS - toyCount)) n = MAX_TOYS - toyCount;
    for (int i = toyCount; i < toyCount + n; i++) {
        cout << "Toy name #" << (i + 1) << ": ";
        cin >> names[i];
        cout << "Price: ";
        cin >> prices[i];
        cout << "Stock quantity: ";
        cin >> stock[i];
        cout << "Sold quantity: ";
        cin >> sold[i];
    }
    toyCount += n;
    showTable();
}

void totalProfit() {
    float total = 0;
    float maxProfit = -1;
    int maxIndex = -1;
    for (int i = 0; i < toyCount; i++) {
        float profit = prices[i] * sold[i];
        total += profit;
        if (profit > maxProfit) {
            maxProfit = profit;
            maxIndex = i;
        }
    }
    cout << "Total profit: " << total << "\n";
    if (maxIndex != -1)
        cout << "Top profit toy: " << names[maxIndex] << " with " << maxProfit << "\n";
}

void stockAnalysis() {
    cout << "Toys with less than 5 in stock:\n";
    int notSold = 0;
    for (int i = 0; i < toyCount; i++) {
        if (stock[i] < 5)
            cout << (i + 1) << ". " << names[i] << "\n";
        if (sold[i] == 0)
            notSold++;
    }
    cout << "Toys not sold at all: " << notSold << "\n";
}

void restockNeeded() {
    cout << "Toys that need urgent restock:\n";
    for (int i = 0; i < toyCount; i++) {
        if (stock[i] - sold[i] <= 0)
            cout << names[i] << "\n";
    }
}

void sortByProfit() {
    for (int i = 0; i < toyCount - 1; i++) {
        for (int j = i + 1; j < toyCount; j++) {
            float profitI = prices[i] * sold[i];
            float profitJ = prices[j] * sold[j];
            if (profitI < profitJ) {
                for (int k = 0; k < 31; k++) {
                    char tmp = names[i][k];
                    names[i][k] = names[j][k];
                    names[j][k] = tmp;
                }
                float tmpPrice = prices[i];
                prices[i] = prices[j];
                prices[j] = tmpPrice;
                int tmpStock = stock[i];
                stock[i] = stock[j];
                stock[j] = tmpStock;
                int tmpSold = sold[i];
                sold[i] = sold[j];
                sold[j] = tmpSold;
            }
        }
    }
    showTable();
}

void searchByIndex() {
    int idx;
    cout << "Enter toy index (1 to " << toyCount << "): ";
    cin >> idx;
    if (idx < 1 || idx > toyCount) {
        cout << "Invalid index\n";
        return;
    }
    idx--;
    cout << "Name: " << names[idx] << "\n";
    cout << "Price: " << prices[idx] << "\n";
    cout << "Stock: " << stock[idx] << "\n";
    cout << "Sold: " << sold[idx] << "\n";
    cout << "Profit: " << prices[idx] * sold[idx] << "\n";
}

void suggestDiscount() {
    cout << "Suggested discounts for expensive toys with low sales:\n";
    for (int i = 0; i < toyCount; i++) {
        if (prices[i] > 500 && sold[i] < 3) {
            cout << names[i] << "\n";
        }
    }
}

void editToy() {
    int idx;
    cout << "Enter toy index to edit (1 to " << toyCount << "): ";
    cin >> idx;
    if (idx < 1 || idx > toyCount) {
        cout << "Invalid index\n";
        return;
    }
    idx--;
    cout << "Enter new name: ";
    cin >> names[idx];
    cout << "Enter new price: ";
    cin >> prices[idx];
    cout << "Enter new stock quantity: ";
    cin >> stock[idx];
    cout << "Enter new sold quantity: ";
    cin >> sold[idx];
}

void deleteToy() {
    int idx;
    cout << "Enter toy index to delete (1 to " << toyCount << "): ";
    cin >> idx;
    if (idx < 1 || idx > toyCount) {
        cout << "Invalid index\n";
        return;
    }
    idx--;
    for (int i = idx; i < toyCount - 1; i++) {
        for (int k = 0; k < 31; k++) {
            names[i][k] = names[i + 1][k];
        }
        prices[i] = prices[i + 1];
        stock[i] = stock[i + 1];
        sold[i] = sold[i + 1];
    }
    toyCount--;
    cout << "Toy deleted.\n";
}

int main() {
    enterToys();

    while (true) {
        cout << "\n1. Enter toys\n";
        cout << "2. Show table\n";
        cout << "3. Total profit\n";
        cout << "4. Stock analysis\n";
        cout << "5. Restock needed\n";
        cout << "6. Sort by profit\n";
        cout << "7. Search by index\n";
        cout << "8. Suggest discount\n";
        cout << "9. Edit toy\n";
        cout << "10. Delete toy\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        int choice;
        cin >> choice;
        if (choice == 0) break;
        switch(choice) {
            case 1: enterToys(); break;
            case 2: showTable(); break;
            case 3: totalProfit(); break;
            case 4: stockAnalysis(); break;
            case 5: restockNeeded(); break;
            case 6: sortByProfit(); break;
            case 7: searchByIndex(); break;
            case 8: suggestDiscount(); break;
            case 9: editToy(); break;
            case 10: deleteToy(); break;
            default: cout << "Invalid option\n";
        }
    }
    return 0;
}
