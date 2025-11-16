#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int stricmp(const char* str1, const char* str2);

    const char* str1 = "admin";
    const char* str2 = "Admin";

    if (strcmp(str1, str2) == 0)
    {
        cout << "str1: " << str1 << " = " << "str2: " << str2 << endl;
    }
    else if (_stricmp(str1, str2) == 0)
    {
        cout << "without Case Sensitivity! str1: " << str1 << " = " << "str2: " << str2 << endl;
    }

    return 0;
}