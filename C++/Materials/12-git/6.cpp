#include <vector>
#include <iostream>

int main()
{
    std::vector<int> array{ 0, 1, 4, 7, 9, 11 };
    array.resize(4); // змінюємо довжину array на 4

    std::cout << "The length is: " << array.size() << '\n';

    for (auto const& element : array)
        std::cout << element << ' ';

    return 0;
}