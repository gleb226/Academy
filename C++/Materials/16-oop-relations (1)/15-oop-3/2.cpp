#include <iostream>

class Dollars
{
private:
    int dollars;

public:
    Dollars(int dollars) { this->dollars = dollars; }

    int getDollars() const { return dollars; }
};

Dollars add(const Dollars& d1, const Dollars& d2)
{
    return Dollars(d1.getDollars() + d2.getDollars()); // повертаємо анонімний об'єкт класу Dollars
}

int main()
{
    //Dollars dollars1(7);
    //Dollars dollars2(9);
    //std::cout << "I have " << add(dollars1, dollars2).getDollars() << " dollars." << std::endl; // виводимо анонімний об'єкт класу Dollars
    std::cout << "I have " << add(Dollars(7), Dollars(9)).getDollars() << " dollars." << std::endl; // виводимо анонімний об'єкт класу Dollars

    return 0;
}