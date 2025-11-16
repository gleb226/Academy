#include<iostream>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
	char mon_name[12];
};

// перевірка на високосний рік
bool isLeapYear(int checkYear) {
	// рік не є високосним, якщо умова істинна
	if (checkYear % 4 != 0 
		|| 
		((checkYear % 100 == 0) && (checkYear % 400 != 0))) {
		return false;
	}
	// якщо умова є брехнею, рік високосний
	return true;
}

int main() {
	int tempYear = 2020;

	Date curDate = { 12, 5, tempYear, "May" };

	if (true == isLeapYear(curDate.year)) {
		cout << tempYear << " is leap year\n";
	}
	else {
		cout << tempYear << " is NOT leap year\n";
	}

	return 0;
}

struct
{
	int x;
	int *y;
} *p; // p — покажчик на структуру.