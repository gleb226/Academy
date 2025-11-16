#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str1[10] = "Hello";
    char str2[10] = { 'H','e','l','l','o' };
    const char* str3 = "Welcome!";

    cout << "Length of string str1 = " << strlen(str1) << endl;
    cout << "Length of string str2 = " << strlen(str2) << endl;
    cout << "Length of string str3 = " << strlen(str3) << endl;

    return 0;
}