#include <iostream>

class Dollars
{
private:
    int dollars;

public:
    Dollars(int dollars) { this->dollars = dollars; }

    int getDollars() const { return dollars; }
};

void print(const Dollars& dollars)
{
    std::cout << dollars.getDollars() << " dollars.";
}

int main()
{
    //Dollars dollars(7);
    //print(dollars);
    print(Dollars(7)); // тут ми передаємо анонімний об'єкт класу Dollars

    return 0;
}