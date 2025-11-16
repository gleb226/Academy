#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    char buffer[50];
    char *login;
    cout << "Login: ";
    cin >> buffer;
    login = (char*)malloc(strlen(buffer) * sizeof(char) + 1);
    cout << strlen(buffer) << endl;
    if (login)
    {
        strcpy_s(login, strlen(buffer) * sizeof(char) + 1, buffer);
        printf("login: %s\n", login);
    }
    return 0;
}