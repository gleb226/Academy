#include <iostream>

int main()
{
    enum class Colors
    {
        PINK,
        GRAY
    };

    Colors color = Colors::GRAY;

    std::cout << color; // не працюватиме, оскільки немає неявної конвертації в тип int
    std::cout << static_cast<int>(color); // результатом буде 1

    return 0;
}