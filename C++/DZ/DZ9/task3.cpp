#include <iostream>
using namespace std;

void splitArray(const int* arr, size_t size,
                int*& positives, size_t& pos_size,
                int*& negatives, size_t& neg_size,
                int*& zeros, size_t& zero_size)
{
    pos_size = 0;
    neg_size = 0;
    zero_size = 0;

    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i] > 0) pos_size++;
        else if (arr[i] < 0) neg_size++;
        else zero_size++;
    }

    positives = new(nothrow) int[pos_size];
    negatives = new(nothrow) int[neg_size];
    zeros = new(nothrow) int[zero_size];

    size_t p = 0, n = 0, z = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i] > 0) positives[p++] = arr[i];
        else if (arr[i] < 0) negatives[n++] = arr[i];
        else zeros[z++] = arr[i];
    }
}

int main()
{
    int arr[] = {3, -1, 0, 7, -5, 0, 2};
    size_t size = 7;

    int* positives = nullptr;
    int* negatives = nullptr;
    int* zeros = nullptr;

    size_t pos_size = 0, neg_size = 0, zero_size = 0;

    splitArray(arr, size, positives, pos_size, negatives, neg_size, zeros, zero_size);

    cout << "Positives: ";
    for (size_t i = 0; i < pos_size; ++i) cout << positives[i] << ' ';
    cout << '\n';

    cout << "Negatives: ";
    for (size_t i = 0; i < neg_size; ++i) cout << negatives[i] << ' ';
    cout << '\n';

    cout << "Zeros: ";
    for (size_t i = 0; i < zero_size; ++i) cout << zeros[i] << ' ';
    cout << '\n';

    delete[] positives;
    delete[] negatives;
    delete[] zeros;

    return 0;
}
