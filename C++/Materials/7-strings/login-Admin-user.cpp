#include <iostream>

using namespace std;

int checkUserLevel(char* userLog, const char* adminLog, const char* standardLog)
{
    cout << "User login: " << userLog << endl;
    cout << "Admin login: " << adminLog << endl;
    cout << "Standard login: " << standardLog << endl;
    char* userLogTemp = userLog;

    _strlwr_s(userLog, strlen(userLog) + 1);

    if (strcmp(userLogTemp, adminLog) == 0)
    {
        return 1;
    }
    else if ((strstr(userLog, standardLog)) && (strlen(userLog) <= 10))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void copyStrPart(char* dest, char* src, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        dest[i] = src[i];
    }
    dest[n - 1] = '\0';
}

int main()
{
    const int n = 50;
    const char* adminLog = "admin";
    const char* standardLog = "user";
    char* login = new char[n];

    cout << "Input login: ";
    fgets(login, n, stdin);

    int loginLen = strlen(login);
    char* tempLog = new char[loginLen];
    copyStrPart(tempLog, login, loginLen);

    if (checkUserLevel(tempLog, adminLog, standardLog) == 1)
    {
        cout << "Welcome, admin!" << endl;
    }
    else if (checkUserLevel(tempLog, adminLog, standardLog) == 0)
    {
        cout << "Welcome, user!" << endl;
    }
    else
    {
        cout << "Wrong login!" << endl;
    }
    delete[] login;
    return 0;
}