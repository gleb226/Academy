#include <iostream>
using namespace std;

// Створення користувацького типу даних (структури) для зберігання дати. 
// Усі дані, що стосуються одного об'єкта, зібрані разом.
struct Date
{
	int day; // день 
	int month; //місяць 
	int year; //рік
	int weekday; // день тижня
	char monName[15];// назва місяця
};

int main() {
	// створення об'єкта з типом date та його ініціалізація при створенні
	Date myBirthday = { 
		20, 
		7, 
		1981, 
		1, 
		"July" 
	};
	// вивід вмісту об'єкта на екран звернення до окремого члена структури
	// здійснюється через оператор крапка (.)
	cout << "________MY BIRTHDAY __________\n\n";
	cout << "DAY " << myBirthday.day << "\n\n";
	cout << "MONTH " << myBirthday.month << "\n\n";
	cout << "YEAR " << myBirthday.year << "\n\n";
	cout << "WEEK DAY " << myBirthday.weekday << "\n\n";
	cout << "MONTH NAME ";
	cout << myBirthday.monName << "\n\n";
	// Створення порожнього об'єкта і заповнення його з клавіатури 
	Date yourBirthday;
	cout << "DAY ? ";
	cin >> yourBirthday.day;
	cout << "MONTH ?";
	cin >> yourBirthday.month;
	cout << "YEAR ?";
	cin >> yourBirthday.year;
	cout << "WEEK DAY ?";
	cin >> yourBirthday.weekday;
	cout << "MONTH NAME ?";
	cin >> yourBirthday.monName;
	cout << "______YOUR BIRTHDAY_____\n\n";
	cout << "DAY " << yourBirthday.day << "\n\n";
	cout << "MONTH " << yourBirthday.month << "\n\n";
	cout << "YEAR " << yourBirthday.year << "\n\n";
	cout << "WEEK DAY " << yourBirthday.weekday << "\n\n";
	cout << "MONTH NAME ";
	cout << yourBirthday.monName << "\n\n";

	return 0;
}