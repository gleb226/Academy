#include <iostream>
#include <string>

class Car
{
private:
    std::string company;
    std::string model;

public:
    Car(std::string company, std::string model): company(company), model(model)
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.company == c2.company && c1.model == c2.model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return !(c1 == c2);
}

int main()
{
    Car mustang("Ford", "Mustang");
    Car logan("Renault", "Logan");

    if (mustang == logan)
        std::cout << "Mustang and Logan are the same.\n";

    if (mustang != logan)
        std::cout << "Mustang and Logan are not the same.\n";

    return 0;
}