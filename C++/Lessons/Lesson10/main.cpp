#include <iostream>
using namespace std;

bool even(int a) {return a % 2 == 0;}

bool odd(int a) {return a % 2 != 0;}

void func(int* array, int size, bool (*func)(int))
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (func(array[i]))
        {
            cout << array[i] << endl;
        }
    }
}

int main()
{
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Even numbers:";
    func(array, size, even);

    cout << endl << "Odd numbers:";
    func(array, size, odd);

    return 0;
}
