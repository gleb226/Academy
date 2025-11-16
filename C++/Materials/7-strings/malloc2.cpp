#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    char buffer[50];
    char* login;
    int n;

    cout << "How many logs: ";
    cin >> n;

    char** logins = new char *[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Login #" << i + 1 << ": ";
        cin >> buffer;

        login = (char*)malloc(strlen(buffer) * sizeof(char) + 1);

        if (login)
        {
            logins[i] = login;
            strcpy_s(logins[i], strlen(buffer) * sizeof(char) + 1, buffer);
        }
        else
        {
            logins[i] = nullptr;
        }
    }

    cout << "Login's list:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (logins[i])
        {
            cout << "Login #" << i + 1 << ": " << logins[i] << endl;
        }
        else
        {
            cout << "Login #" << i + 1 << " is missing!" << endl;
        }
    }

    return 0;
}