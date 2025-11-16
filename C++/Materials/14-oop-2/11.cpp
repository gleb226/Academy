#include <iostream>

class Anything
{
private:
    static int s_idGenerator;
    int id;

public:
    Anything() { id = s_idGenerator++; } // збільшуємо значення ідентифікатора для наступного об'єкту

    int getID() const { return id; }
};

// Ми визначаємо і ініціалізуємо s_idGenerator незважаючи на те, що він оголошений як private.
// Це нормально, оскільки визначення не підпадає під дію специфікаторів доступу
int Anything::s_idGenerator = 1; // починаємо наш ID-генератор зі значення 1

int main()
{
    Anything first;
    Anything second;
    Anything third;

    std::cout << first.getID() << '\n';
    std::cout << second.getID() << '\n';
    std::cout << third.getID() << '\n';
    return 0;
}