#include <iostream>
using namespace std;

int main()
{
    int no, sum = 0;
    cout << "Enter any number\n";
    cin >> no;
    cout << "Natural no. from 1 to " << no << " is given below\n";

    for (int i = 1;i <= no;i++)
    {
        cout << i << "";
        sum = sum + i;
    }

    cout << "\nTotal sum=" << sum;
}


/*
### Output ###
Enter any number
8
Natural no. from 1 to 8 is given below
1 2 3 4 5 6 7 8
Total sum=36
*/