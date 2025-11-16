#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    char *symbols;
    int n;
    cout << "How many symbols: ";
    cin >> n;

    symbols = (char*)calloc(n, sizeof(char));

    if (!symbols) {
        cout << "Memory Allocation Failed";
    }
    else
    {
        cout << "Memory content just after allocation:" << endl;
        for (int i = 0; i < n; i++) {
            printf("Symbol #%d: %d\n", i + 1, symbols[i]);
        }
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << "Input symbol #" << i + 1;
            cin >> symbols[i];
        }
        cout << "New content:" << endl;
        for (int i = 0; i < n; i++) {
            printf("Symbol #%d: %c\n", i + 1, symbols[i]);
        }
    }
    return 0;
}