#include <iostream>
using namespace std;

int main()
{
    int no, b, rev = 0, cpy;
    cout << "Enter any number\n";
    cin >> no;
    cpy = no;
    while (no != 0)
    {
        b = no % 10;
        rev = rev * 10 + b;
        no = no / 10;
    }
    if (rev == cpy)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}


/*
### Output ###
Enter any number
5885
Palindrome
*/