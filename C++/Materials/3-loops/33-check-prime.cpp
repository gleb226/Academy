#include <iostream>
using namespace std;

int main()
{
    int no, m = 0;
    cout << "Enter any number\n";
    cin >> no;
    for (int i = 2;i <= no - 1;i++)
    {
        if (no % i == 0)
        {
            cout << "Number is not prime";
            m = i;
            break;
        }
    }
    if (m == 0)
        cout << "Number is prime";
}


/*
### Output ###
Enter any number
43
Number is prime
*/