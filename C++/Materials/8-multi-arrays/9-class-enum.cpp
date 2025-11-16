#include <iostream>

int main()
{
    enum class Colors
    {
        PINK,
        GRAY
    };

    Colors color = Colors::PINK;

    if (color == Colors::PINK) // це нормально
        std::cout << "The color is pink!\n";
    else if (color == Colors::GRAY)
        std::cout << "The color is gray!\n";

    return 0;
}