#include <iostream>
using namespace std;

int main()
{
    float sellingPrice; 
    float costPrice; 
    float profit;
    float loss;

    cout << "Enter cost price\n";
    cin >> costPrice;
    cout << "Enter selling price\n";
    cin >> sellingPrice;

    if (sellingPrice > costPrice)
    {
        profit = sellingPrice - costPrice;
        cout << "Profit of " << profit << " $";
    }
    else
    {
        loss = costPrice - sellingPrice;
        cout << "Loss of " << loss << " $";
    }
}