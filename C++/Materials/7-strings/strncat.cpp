#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str1[20] = "Hello";
    const char* str2 = "World";
    strcat_s(str1, str2);
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "Result string str1 after concatenation with str2:" << str1 << endl;

    const char* str3 = "!!!";
    strncat_s(str1, str3, 1);
    cout << "str3: " << str3 << endl;
    cout << "Result string str1 after concatenation with str3 by using strncat:" << str1 << endl;

    return 0;
}