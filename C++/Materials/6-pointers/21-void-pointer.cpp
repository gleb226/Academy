#include <iostream>

int main()
{
    int value = 7;
    void* voidPtr = &value;

    //std::cout << *voidPtr << std::endl; // заборонено: не можна розіменовувати вказівники типу void

    int* intPtr = static_cast<int*>(voidPtr); // проте, якщо ми конвертуємо наш вказівник типу void у вказівник типу int,
    std::cout << *intPtr << std::endl; // то ми можемо його розіменувати, наче це звичайний вказівник

    return 0;
}