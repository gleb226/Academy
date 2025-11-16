#include <iostream>

// Параметр ptr містить копію адреси масиву
void changeArray(int* ptr)
{
    *ptr = 5; // тому зміна елемента масиву призведе до зміни фактичного масиву
}

int main()
{
    int array[] = { 1, 2, 3, 4, 4, 9, 15, 25 };
    std::cout << "Element 0 has value: " << array[0] << '\n';

    changeArray(array);

    std::cout << "Element 0 has value: " << array[0] << '\n';

    return 0;
}