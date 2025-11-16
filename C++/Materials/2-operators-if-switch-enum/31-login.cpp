#include <iostream>
using namespace std;

int main()
{
    char username[200] = "example@itstep.org";
    char password[200] = "itstep1";

    char inputUsername[200]; 
    char inputPassword[200];

    cout << "Enter username\n";
    cin >> inputUsername;
    cout << "Enter password\n";
    cin >> inputPassword;

    if (strcmp(username, inputUsername) == 0 && strcmp(password, inputPassword) == 0)
    {
        cout << "Login Successful";
    }
    else
    {
        cout << "Wrong username or password";
    }
}