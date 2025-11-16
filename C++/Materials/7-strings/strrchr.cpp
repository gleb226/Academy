#include <iostream>

using namespace std;

int main()
{
    char* strrchr(char* str, char ch);
    char str[] = "Welcome!";
    char ch = 'e';
    char* result;

    result = strchr(str, ch);
    cout << "String '" << str << "' after first '" << ch << "' is : " << result << endl;
    result = strrchr(str, ch);
    cout << "String '" << str << "' after last '" << ch << "' is : " << result << endl;

    return 0;
}