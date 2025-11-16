#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    float *symbols, *newSymbols;
    int n, m;

    cout << "How many items: ";
    cin >> n;

    symbols = (float*)malloc(n * sizeof(float));

    if (!symbols) {
        cout << "Memory Allocation Failed";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            symbols[i] = i * 2.5;
        }
        cout << "Memory content:" << endl;
        for (int i = 0; i < n; i++) {
            printf("Item #%d: %.2f\n", i + 1, symbols[i]);
        }
    }
    free(symbols);
    symbols = nullptr;
    return 0;
}