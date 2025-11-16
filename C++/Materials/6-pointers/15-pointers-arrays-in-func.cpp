#include <iostream>

void printSize(int* array)
{
    // Тут масив розглядається як вказівник
    std::cout << sizeof(array) << '\n'; // виведеться розмір вказівника, а не довжина масиву!
}

int main()
{
    int array[] = { 1, 2, 3, 4, 4, 9, 15, 25 };
    std::cout << sizeof(array) << '\n'; // виведеться sizeof(int) * довжина масиву

    printSize(array); // тут аргумент array розпадається у вказівник

    return 0;
}