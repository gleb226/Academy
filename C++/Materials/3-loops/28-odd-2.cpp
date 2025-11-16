#include <iostream>
using namespace std;

int main()
{
    cout << "Odd number b/w 1 and 20 is given below\n";
    for (int i = 1;i <= 20;i = i + 1)
    {
        if (i % 2 != 0)
            cout << i << "";
    }
}


/*
### Output ###
Odd number b/w 1 and 20 is given below
1 3 5 7 9 11 13 15 17 19
*/