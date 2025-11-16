#include <iostream>
using namespace std;

int main()
{
    cout << "Even number b/w 1 and 20 is given below\n";
    for (int i = 1; i <= 20; i = i + 1)
    {
        if (i % 2 == 0)
            cout << i << "";
    }
}


/*
### Output ###
Even number b/w 1 and 20 is given below
2 4 6 8 10 12 14 16 18 20
*/