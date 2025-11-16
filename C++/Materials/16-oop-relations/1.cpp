#include <iostream>
#include <windows.h>

class Heart {
public:
    Heart() {
        std::cout << "Я - серце. Я формуюся всередині людини." << std::endl;
    }

    void PrintInfo() const {
        std::cout << "Я - серце. Я pumping кров по всьому тілу." << std::endl;
    }
};

class Person {
private:
    Heart* heart_;

public:
    Person() {
        heart_ = new Heart();
    }

    ~Person() {
        delete heart_;
    }

    void PrintInfo() const {
        std::cout << "Я - людина. У мене є:" << std::endl;
        heart_->PrintInfo();
    }
};

int main() {
    SetConsoleOutputCP(1251);
    Person person;

    person.PrintInfo();

    return 0;
}