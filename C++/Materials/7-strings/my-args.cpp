// Програма MyArguments
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "There are " << argc << " arguments:\n";

    // Перебираємо кожний аргумент і виводимо його порядковий номер і значення
    for (int count = 0; count < argc; ++count)
        std::cout << count << " " << argv[count] << '\n';

    return 0;
}