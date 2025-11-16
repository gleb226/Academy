#include <iostream>

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year)
    {
        setDate(day, month, year);
    }

    // Метод setDate() не може бути const, так як змінює значення змінних-членів
    void setDate(int day, int month, int year)
    {
        day = day;
        month = month;
        year = year;
    }

    // Всі наступні геттери можуть бути const
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

// Примітка: Ми передаємо об'єкт date по константному посиланню, щоб уникнути створення копії об'єкта date
void printDate(const Date& date)
{
    std::cout << date.getDay() << "." << date.getMonth() << "." << date.getYear() << '\n';
}

int main()
{
    Date date(12, 11, 2018);
    printDate(date);

    return 0;
}