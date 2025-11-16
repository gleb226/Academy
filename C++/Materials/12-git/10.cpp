#include <vector>
#include <iostream>

int main()
{
    std::vector<int> math = { 0, 1, 4, 5, 7, 8, 10, 12, 15, 17, 30, 41 }; // зверніть увагу на використання std::vector замість фіксованого масиву
    for (const auto& number : math)
        std::cout << number << ' ';

    return 0;
}