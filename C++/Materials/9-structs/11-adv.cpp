#include <iostream>

// Спочатку оголошуємо структуру Advertising 
struct Advertising
{
    int adsShown;
    double clickThroughRatePercentage;
    double averageEarningsPerClick;
};

void printAdvertising(Advertising ad)
{
    using namespace std;
    cout << "Number of ads shown: " << ad.adsShown << endl;
    cout << "Click through rate: " << ad.clickThroughRatePercentage << endl;
    cout << "Average earnings per click: $" << ad.averageEarningsPerClick << endl;

    // Ми ділимо ad.clickThroughRatePercentage на 100, тому що користувач вказує відсотки, а не готове число
    cout << "Total Earnings: $" << (ad.adsShown * ad.clickThroughRatePercentage / 100 * ad.averageEarningsPerClick) << endl;
}

int main()
{
    using namespace std;

    // Оголошуємо змінну структури Advertising 
    Advertising ad;

    cout << "How many ads were shown today? ";
    cin >> ad.adsShown;
    cout << "What percentage of users clicked on the ads? ";
    cin >> ad.clickThroughRatePercentage;
    cout << "What was the average earnings per click? ";
    cin >> ad.averageEarningsPerClick;

    printAdvertising(ad);

    return 0;
}