#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    int a;
    std::cout << "Enter a number: ";
    std::cin >> a;

    int b;
    std::cout << "Enter another number: ";
    std::cin >> b;

    int op;
    do
    {
        std::cout << "Enter an operation (0 = add, 1 = subtract, 2 = multiply): ";
        std::cin >> op;
    } while (op < 0 || op > 2);

    // Створюємо вказівник на функцію з іменем pFcn (погоджуюся, синтаксис жахливий)
    int (*pFcn)(int, int) = nullptr;

    // Вказуємо pFcn вказувати на функцію, яку вибере користувач
    switch (op)
    {
    case 0: pFcn = add; break;
    case 1: pFcn = subtract; break;
    case 2: pFcn = multiply; break;
    }

    // Викликаємо функцію, на яку вказує pFcn з параметрами a і b.
    // Використовується пізнє зв'язування
    std::cout << "The answer is: " << pFcn(a, b) << std::endl;

    return 0;
}