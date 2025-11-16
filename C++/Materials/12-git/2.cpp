#include <iostream>
#include <array>

void printLength(const std::array<double, 4> &myarray)
{
    std::cout << "length: " << myarray.size();
}

int main()
{
    std::array<double, 4> myarray{ 8.0, 6.4, 4.3, 1.9 };

    printLength(myarray);

    return 0;
}