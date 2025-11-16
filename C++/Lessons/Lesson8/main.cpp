#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int c = *a;
    *a=*b;
    *b=c;
}

int main()
{
    int av = 5, bv = 9;
    swap(&av, &bv);
    cout << av << " " << bv;

    return 0;
}
