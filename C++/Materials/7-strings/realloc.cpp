#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    float *symbols, *newSymbols;
    int n;

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

        newSymbols = (float*)realloc(symbols, 2 * n * sizeof(float));

        if (!newSymbols)
        {
            cout << "Memory re-allocation Failed";
        }
        else
        {
            cout << "Let's add new values to 2nd part!" << endl;
            for (int i = n; i < 2 * n; i++) {
                cout << "Input item #" << i + 1;
                cin >> newSymbols[i];
            }
            cout << "New memory content:" << endl;
            for (int i = 0; i < 2 * n; i++) {
                printf("Item #%d: %.2f\n", i + 1, newSymbols[i]);
            }
        }
    }
    return 0;
}