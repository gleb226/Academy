#include <iostream>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
	char mon_name[12];
};

/*
 Об'єкт структури передається у функцію за значенням
 Можлива також передача за посиланням і за покажчиком
*/
void show(Date a) {
	// вивід вмісту об'єкта a 
	cout << a.day << " ";
	cout << a.year << " ";
	cout << a.month << " ";
	cout << a.mon_name << "\n\n";
}

Date put() {
	// формування об'єкта 
	Date temp;
	cout << "DAY ? ";
	cin >> temp.day;
	cout << "MONTH ? ";
	cin >> temp.month;
	cout << "YEAR ? ";
	cin >> temp.year;
	cout << "MONTH NAME ? ";
	cin >> temp.mon_name;
	return temp;
}

int main() {
	Date a = { 14, 7, 1954, "July" };
	Date b;
	// передача об'єкта у функцію
	show(a);
	// отримання об'єкта як значення,
	// що повертається
	b = put();
	// вивід вмісту об'єкта b 
	show(b);

	return 0;
}