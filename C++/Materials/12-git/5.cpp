#include <vector>
#include <iostream>

int main()
{
    std::vector<int> array{ 0, 1, 2 };
    array.resize(7); // змінюємо довжину array на 7

    std::cout << "The length is: " << array.size() << '\n';

    for (auto const& element : array)
        std::cout << element << ' ';

    return 0;
}