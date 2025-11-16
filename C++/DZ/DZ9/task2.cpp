#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int* removePrimes(const int* arr, size_t size, size_t& new_size)
{
    new_size = 0;
    for (size_t i = 0; i < size; ++i)
        if (!isPrime(arr[i])) ++new_size;

    int* new_arr = new(nothrow) int[new_size];
    if (!new_arr)
    {
        new_size = 0;
        return nullptr;
    }

    size_t idx = 0;
    for (size_t i = 0; i < size; ++i)
        if (!isPrime(arr[i]))
            new_arr[idx++] = arr[i];

    return new_arr;
}

// int main()
// {
//     int arr[] = {2, 4, 5, 6, 7, 8, 9, 10};
//     size_t size = 8;
//     size_t new_size = 0;
//
//     int* filtered = removePrimes(arr, size, new_size);
//
//     for (size_t i = 0; i < new_size; ++i)
//         cout << filtered[i] << ' ';
//     cout << '\n';
//
//     delete[] filtered;
//     return 0;
// }
