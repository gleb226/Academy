#include <iostream>

int main()
{
    int array[4] = { 5, 8, 6, 4 };

    // Виводимо на екран значення масиву (змінну array)
    std::cout << "The array has address: " << array << '\n';

    // Виводимо на екран адресу елемента масиву
    std::cout << "Element 0 has address: " << &array[0] << '\n';

    return 0;
}