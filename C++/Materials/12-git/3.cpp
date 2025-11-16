#include <iostream>
#include <array>
#include <algorithm> // для std::sort

int main()
{
    std::array<int, 5> myarray{ 8, 4, 2, 7, 1 };
    std::sort(myarray.begin(), myarray.end()); // сортування масиву по зростанню
    //    std::sort(myarray.rbegin(), myarray.rend()); // сортування масиву по спаданню

    for (const auto& element : myarray)
        std::cout << element << ' ';

    return 0;
}