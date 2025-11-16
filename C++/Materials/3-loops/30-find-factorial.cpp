#include <iostream>
using namespace std;

int main()
{
    int no, f = 1;
    cout << "Enter any number\n";
    cin >> no;
    for (int i = 1;i <= no;i++)
    {
        f = f * i;
    }
    cout << "Factorial=" << f;
}


/*
### Output ###
Enter any number
6
Factorial=720
*/