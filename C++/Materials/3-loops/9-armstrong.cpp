#include <iostream>
using namespace std;

int main()
{
    int no, b, sum = 0, copy;
    cout << "Enter any number\n";
    cin >> no;
    copy = no;
    while (no != 0)
    {
        b = no % 10;
        sum = sum + (b * b * b);
        no = no / 10;
    }
    if (copy == sum)
        cout << "Number is Armstrong";
    else
        cout << "Number is not Armstrong";
}


/*
### Output ###
Enter any number
153
Number is Armstrong
*/