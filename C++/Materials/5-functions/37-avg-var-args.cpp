/********************************************************************************/
/*Функція обчислення середнього арифметичного довільної кількості дійсних чисел */
/* Варіант 2 */
/********************************************************************************/

#include <iostream>
#include <conio.h>
#include <stdarg.h>

double f(int, ...);

using namespace std;

int main()
{
	cout << f(3, 2.0, 4.0, 3.0) << endl;
	cout << f(4, 2.0, 14.0, 8.0, 16.0) << endl;
	cout << f(10, 1.5, 1.5, 2.8, 3.4, 2.0, 14.0, 8.0, 16.0, 4.5, 2.3) << endl;

	_getch();

	return 0;
}

double f(int n, ...)
{
	double sum = 0, term;
	int count = 0;

	va_list p;
	va_start(p, n);

	for (int i = 0;i < n;i++)
	{
		term = va_arg(p, double);
		cout << "term #" << (i + 1) << " = " << term << "\t";
		sum += term;
		count++;
	}

	va_end(p);

	cout << endl << "Average = ";

	return ((sum) ? sum / count : 0);
}