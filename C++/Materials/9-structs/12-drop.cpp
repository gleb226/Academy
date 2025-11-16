#include <iostream>

struct Drob
{
    int chislitel;
    int znamenatel;
};

void multiply(Drob d1, Drob d2)
{
    using namespace std;

    // Не забуваємо про static_cast, інакше компілятор виконає цілочисельне ділення!
    cout << static_cast<float>(d1.chislitel * d2.chislitel) /
        (d1.znamenatel * d2.znamenatel);
}

int main()
{
    using namespace std;

    // Визначаємо першу дробову змінну
    Drob d1;
    cout << "Input the first chislitel: ";
    cin >> d1.chislitel;
    cout << "Input the first znamenatel: ";
    cin >> d1.znamenatel;

    // Визначаємо другу дробову змінну
    Drob d2;
    cout << "Input the second chislitel: ";
    cin >> d2.chislitel;
    cout << "Input the second znamenatel: ";
    cin >> d2.znamenatel;

    multiply(d1, d2);

    return 0;
}