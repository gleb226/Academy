#include <iostream>
using namespace std;
int main()
{
	struct DateTime {
		unsigned short DayNum : 5;
		unsigned short MonthNum : 4;
		unsigned short YearNum : 7;
		unsigned short HourNum : 5;
		unsigned short MinuteNum : 6;
		unsigned short SecondNum : 6;
	};
	DateTime d;
	int i

	cout << "Input the day number (from 1 to 31):" << '\t';
	cin >> i;
	d.DayNum = i;
	cout << "Input the month number (from 1 to 12):" << '\t';
	cin >> i;
	d.MonthNum = i;
	cout << "Input Year (from 00 to 99) :" << '\t';
	cin >> i;
	d.YearNum = i;
	cout << endl << "Input Hours (from 0 to 24):" << '\t';
	cin >> i;
	d.HourNum = i;
	cout << "Input Minutes (from 0 tp60):" << '\t';
	cin >> i;
	d.MinuteNum = i;
	cout << "Input Seconds (0-60):" << '\t';
	cin >> i;
	d.SecondNum = i;

	cout << endl << "Date is: " << d.DayNum << "." << d.MonthNum << ".20" << d.YearNum << " ";
	cout << d.HourNum << ":" << d.MinuteNum << ":" << d.SecondNum << endl;
	cout << sizeof(d) << endl;

	return 0;
}