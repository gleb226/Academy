#include <iostream>
using namespace std;

int main()
{
    int no, b;
    cout << "Enter any number\n";
    cin >> no;
    cout << "Revere is given below\n";
    while (no != 0)
    {
        b = no % 10;
        cout << b;
        no = no / 10;
    }
}


/*
### Output ###
Enter any number
589
Revere is given below
985
*/