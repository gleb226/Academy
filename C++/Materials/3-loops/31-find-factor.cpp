#include <iostream>
using namespace std;

int main()
{
    int no;
    cout << "Enter any number\n";
    cin >> no;
    cout << "Factor is given below\n";
    for (int i = 1;i <= no;i++)
    {
        if (no % i == 0)
            cout << i << "";
    }
}


/*
### Output ###
Enter any number
8
Factor is given below
1 2 4 8
*/