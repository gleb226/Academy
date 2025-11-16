#include <iostream>
using namespace std;

int main()
{
    int no, a, b = 1, c = 0;
    cout << "Enter any number upto you want to print fabonacci series\n";
    cin >> no;
    for (int i = 1;i <= no;i++)
    {
        cout << c << "";
        a = b;
        b = c;
        c = a + b;

    }
}


/*
### Output ###
Enter any number upto you want to print fabonacci series
8
0 1 1 2 3 5 8 13
*/