// C++ program to demonstrate working of accumulate()
#include <iostream>
#include <numeric>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

// User defined function
int myfun(int x, int y)
{
    // for this example we have taken product
    // of adjacent numbers
    return x * y;
}

int main2()
{
    // Initialize sum = 1
    int sum = 2;
    vector<int> numbers{ 5, 10, 15 };

    // Simple default accumulate function
    cout << "\nResult using accumulate: ";
    cout << accumulate(numbers.begin(), numbers.end(), sum);

    // Using accumulate function with
    // defined function
    cout << "\nResult using accumulate with"
        "user-defined function: ";
    cout << accumulate(numbers.begin(), numbers.end(), sum, myfun);
    cout << accumulate(numbers.begin(), numbers.end(), sum, [](auto a, auto b) { return a * b; });

    // Using accumulate function with
    // pre-defined function
    cout << "\nResult using accumulate with "
        "pre-defined function: ";
    cout << accumulate(numbers.begin(), numbers.end(), sum, std::minus<int>());

    return 0;
}