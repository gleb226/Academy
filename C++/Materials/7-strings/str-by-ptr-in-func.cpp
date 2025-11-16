#include <iostream>
#include <windows.h>

using namespace std;

void changeSymbol(char* str)
{
    char* strPtr;
    for (strPtr = str; *strPtr; strPtr++)
    {
        if ((*strPtr == 'o')  (*strPtr == 'e'))
        {
            *strPtr = '*';
        }
    }
}

int main()
{
    char myStr[] = "Hello!";
    cout << "My original string: " << myStr << endl;
    changeSymbol(myStr);
    cout << "My transformed string: " << myStr << endl;
    return 0;
}