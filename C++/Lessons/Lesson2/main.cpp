#include <iostream>
using namespace std;

int main()
{
    double amountUAH;
    int currencyChoice;

    const float USD_RATE = 40.0;
    const float EUR_RATE = 42.0;

    cout << "Enter sum in UAN: ";
    cin >> amountUAH;

    cout << "Choise wallet" << endl;
    cout << "1 - Dollars" << endl;
    cout << "2 - Euro" << endl;
    cout << "Your choise: ";
    cin >> currencyChoice;

    if (currencyChoice == 1)
    {
        double amountUSD = amountUAH / USD_RATE;
        cout << "Sum in USD: " << amountUSD << endl;

        if (amountUSD >= 10000)
        {
            cout << "Congratulations, you're a real dollar millionaire!!!" << endl;
        }
    }
    else if (currencyChoice == 2)
    {
        double amountEUR = amountUAH / EUR_RATE;
        cout << "Sum in euro: " << amountEUR << endl;

        if (amountEUR >= 10000)
        {
            cout << "Congratulations, you're a real euro millionaire!!!" << endl;
        }
    }
    else
    {
        cout << "Incorrect choise" << endl;
    }

    return 0;
}
