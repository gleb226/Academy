#include <iostream>
using namespace std;

int main()
{
    int no, b, m = 1;
    cout << "Enter any number\n";
    cin >> no;
    while (no != 0)
    {
        b = no % 10;
        m = m * b;
        no = no / 10;
    }
    cout << "Total multiply of digits=" << m;
}

/*
### Output ###
Enter any number
325
Total multiply of digits=30
*/