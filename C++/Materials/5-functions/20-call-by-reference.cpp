#include <iostream>
using namespace std;

void add(int* y, int* z)
{
    int x;
    x = *y + *z;
    cout << "Add=" << x;
}

int main()
{
    int a = 20, b = 50;
    add(&a, &b);
}


/*
### Output ###
Add=70
*/