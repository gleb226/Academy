#include <iostream>
using namespace std;

// Опис структури з ім'ям date. 
struct Date
{
	int day;
	int month;
	int year;
	char monName[12];
};

int main()
{
	/* Створення та ініціалізація об'єкта структури.
		d — змінна типу date.
		2 потрапить у day
		5 потрапить у month
		1976 у year
		July у mon_name
	*/
	Date d = { 2, 5, 1976, "July" };
	// Покажчик p вказує на структуру типу date
	Date *p = nullptr;
	// Вивід вмісту структури на екран (звернення через об'єкт)
	cout << d.day << " ";
	cout << d.month << " ";
	cout << d.year << " ";
	cout << d.monName << "\n\n";

	// запис адреси об'єкта структури в покажчик 
	p = &d;
	// Вивід вмісту структури на екран
	// (звернення через покажчик)
	// -> складається з мінуса — і знака більше ніж >
	cout << p->day << " ";
	cout << p->month << " ";
	cout << p->year << " ";
	cout << p->monName << "\n\n";

	return 0;
}