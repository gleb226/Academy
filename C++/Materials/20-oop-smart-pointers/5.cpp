#include <iostream>

void fun(const int& lref) // перевантаження функції для роботи з аргументами l-values
{
    std::cout << "l-value reference to const\n";
}

void fun(int&& rref) // перевантаження функції для роботи з аргументами r-values
{
    std::cout << "r-value reference\n";
}

int main()
{
    int x = 7;
    fun(x); // аргумент l-value викликає функцію з посиланням l-value
    fun(7); // аргумент r-value викликає функцію з посиланням r-value

    return 0;
}