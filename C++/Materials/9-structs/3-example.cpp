#include <iostream>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
	char monName[12];
};

int main() {
	// створюємо об'єкт та ініціалізуємо поля
	Date a = { 14, 7, 1954, "July" };
	// створили об'єкт без ініціалізації
	Date b;
	// вивід вмісту об'єкта a 
	cout << a.day << " ";
	cout << a.month << " ";
	cout << a.monName << " ";
	cout << a.year << "\n\n";
	/*
	Ініціалізація об'єкта b об'єктом a
	Усі значення полів з a копіюються в b
	*/
	b = a;
	// вивід вмісту об'єкта b 
	cout << b.day << " ";
	cout << b.month << " ";
	cout << b.monName << " ";
	cout << b.year << "\n\n";

	return 0;
}
