#include <iostream>
using namespace std;

void table(int no)
{
    if (no != 11)
    {
        cout << no << "\n";
        no++;
        table(no);
    }
}

int main()
{
    table(1);
}


/*
### Output ###
1
2
3
4
5
6
7
8
9
10
*/
