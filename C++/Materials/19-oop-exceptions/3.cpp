#include <cmath> // для sqrt()
#include <iostream>

// Окрема функція обчислення квадратного кореня
double mySqrt(double a)
{
    // Якщо користувач ввів від'ємне число, то генеруємо виняток
    if (a < 0.0)
        throw "Can not take sqrt of negative number"; // генерується виняток типу const char*

    return sqrt(a);
}

int main()
{
    std::cout << "Enter a number: ";
    double a;
    std::cin >> a;

    try // шукаємо винятки, які генеруються в блоці try, і відправляємо їх для обробки в блок(и) catch
    {
        double d = mySqrt(a);
        std::cout << "The sqrt of " << a << " is " << d << '\n';
    }
    catch (const char* exception) // обробка винятків типу const char*
    {
        std::cerr << "Error: " << exception << std::endl;
    }

    return 0;
}