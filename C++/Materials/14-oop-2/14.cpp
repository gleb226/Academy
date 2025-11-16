#include <cassert>
#include <iostream>

class Drob
{
private:
    int numerator;
    int denominator;

public:
    // Конструктор за замовчуванням
    Drob(int numerator = 0, int denominator = 1) :
        numerator(numerator), denominator(denominator)
    {
        assert(denominator != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Drob& d1);
};

std::ostream& operator<<(std::ostream& out, const Drob& d1)
{
    out << d1.numerator << "/" << d1.denominator;
    return out;
}

// Ми можемо виконати пряму ініціалізацію:
int a(7); // пряма ініціалізація цілочисельної змінної
Drob sixSeven(6, 7); // пряма ініціалізація об'єкта класу Drob, викликається конструктор Drob(int, int)

// В C++11 ми можемо виконати uniform-ініціалізацію:
int a{ 7 }; // uniform-ініціалізація цілочисельної змінної
Drob sixSeven{ 6, 7 }; // uniform-ініціалізація об'єкта класу Drob, викликається конструктор Drob(int, int)

// І, нарешті, ми можемо виконати копіюючу ініціалізацію:
int a = 7; // копіююча ініціалізація цілочисельної змінної
Drob eight = Drob(8); // копіююча ініціалізація об'єкта класу Drob, викликається Drob(8, 1)
Drob nine = 9; // копіююча ініціалізація об'єкта класу Drob. Компілятор шукатиме спосіб конвертації 9 в об'єкт класу Drob, що призведе до виклику конструктора Drob(9, 1)