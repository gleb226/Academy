class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year);

    void SetDate(int day, int month, int year);

    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
};

// Конструктор класу Date 
Date::Date(int day, int month, int year)
{
    SetDate(day, month, year);
}

// Метод класу Date 
void Date::SetDate(int day, int month, int year)
{
    day = day;
    month = month;
    year = year;
}