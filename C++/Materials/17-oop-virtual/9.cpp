#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner : virtual public PoweredDevice // примітка: PoweredDevice тепер віртуальний базовий клас
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power) // цей рядок необхідний для створення об'єктів класу Scanner, але в цій програмі він ігнорується
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : virtual public PoweredDevice // примітка: PoweredDevice тепер віртуальний базовий клас
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power) // цей рядок необхідний для створення об'єктів класу Printer, але в цій програмі він ігнорується
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power),
        PoweredDevice(power) // побудова PoweredDevice виконується тут
    {
    }
};

int main()
{
    Copier copier(1, 2, 3);
}