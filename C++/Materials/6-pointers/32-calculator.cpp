#include <iostream>

int getInteger()
{
    std::cout << "Enter an integer: ";
    int a;
    std::cin >> a;
    return a;
}

char getOperation()
{
    char op;

    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

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

int divide(int a, int b)
{
    return a / b;
}

typedef int (*arithmeticFcn)(int, int);

arithmeticFcn getArithmeticFcn(char op)
{
    switch (op)
    {
    default: // функцією за замовчуванням буде add()
    case '+': return add;
    case '-': return subtract;
    case '*': return multiply;
    case '/': return divide;
    }
}

int main()
{
    int a = getInteger();
    char op = getOperation();
    int b = getInteger();

    arithmeticFcn fcn = getArithmeticFcn(op);
    std::cout << a << ' ' << op << ' ' << b << " = " << fcn(a, b) << '\n';

    return 0;
}