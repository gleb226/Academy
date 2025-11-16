#include <iostream> 
#include "math.h" // для функції sqrt()

int main()
{
    std::cout << "Enter a number: ";
    double a;
    std::cin >> a;

    try // шукаємо винятки всередині цього блоку і відправляємо їх у відповідний обробник catch
    {
        // Якщо користувач ввів від'ємне число, то викидається виняток
        if (a < 0.0)
            throw "Can not take sqrt of negative number"; // викидається виняток типу const char*

        // Якщо користувач ввів додатне число, то виконується операція і виводиться результат
        std::cout << "The sqrt of " << a << " is " << sqrt(a) << '\n';
    }
    catch (const char* exception) // обробник винятків типу const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }
}