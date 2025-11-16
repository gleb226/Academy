#include <iostream>

using namespace std;

int main()
{
    char str1[] = "Hello";
    char ch = '*';

    _strnset_s(str1, ch, 3);
    cout << "Output string after replacing first 3 symbols to '*':" << str1 << endl;

    return 0;
}