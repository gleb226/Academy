#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeap(int y) const {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    int daysInMonth(int m, int y) const {
        switch (m) {
            case 2: return isLeap(y) ? 29 : 28;
            case 4:
            case 6:
            case 9:
            case 11: return 30;
            default: return 31;
        }
    }

    void normalize() {
        while (day > daysInMonth(month, year)) {
            day -= daysInMonth(month, year);
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        while (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day += daysInMonth(month, year);
        }
    }

public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {
        normalize();
    }

    void addDay() {
        day++;
        normalize();
    }

    Date &operator++() {
        addDay();
        return *this;
    }

    Date operator++(int) {
        Date temp = *this;
        addDay();
        return temp;
    }

    Date &operator--() {
        day--;
        normalize();
        return *this;
    }

    Date operator--(int) {
        Date temp = *this;
        day--;
        normalize();
        return temp;
    }

    bool operator==(const Date &other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator!=(const Date &other) const {
        return !(*this == other);
    }

    bool operator<(const Date &other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator>(const Date &other) const {
        return other < *this;
    }

    Date &operator=(const Date &other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    Date &operator+=(int d) {
        day += d;
        normalize();
        return *this;
    }

    Date &operator-=(int d) {
        day -= d;
        normalize();
        return *this;
    }

    void operator()() const {
        cout << "Date: " << day << "." << month << "." << year << endl;
    }

    friend ostream &operator<<(ostream &os, const Date &date);

    friend istream &operator>>(istream &is, Date &date);
};

ostream &operator<<(ostream &os, const Date &date) {
    os << (date.day < 10 ? "0" : "") << date.day << "."
            << (date.month < 10 ? "0" : "") << date.month << "."
            << date.year;
    return os;
}

istream &operator>>(istream &is, Date &date) {
    is >> date.day >> date.month >> date.year;
    date.normalize();
    return is;
}

int main() {
    Date d1(28, 2, 2024);
    cout << d1 << endl;
    ++d1;
    cout << d1 << endl;
    d1 += 5;
    cout << d1 << endl;
    d1();
    Date d2;
    cin >> d2;
    cout << d2 << endl;
    return 0;
}
