#include <iostream>
using namespace std;

int main()
{
    int no;
    cout << "Enter any number\n";
    cin >> no;
    cout << "Natural no. from " << no << " to 1 is given below\n";
    for (int i = 1;i >= no;i--)
    {
        cout << i << "";
    }
}


/*
### Output ###
Enter any number
8
Natural no. from 1 to 8 is given below
8 7 6 5 4 3 2 1
*/