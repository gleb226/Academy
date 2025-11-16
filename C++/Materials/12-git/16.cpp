#include <array>
#include <iostream>

int main()
{
    std::array array{ 1, 2, 3 };

    // Даний цикл працює аналогічно вищенаведеному циклу
    for (int i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}