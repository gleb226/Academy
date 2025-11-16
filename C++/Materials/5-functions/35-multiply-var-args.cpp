/********************************************************************/

/* Функція для обчислення добутку довільної кількості дійсних чисел */

/********************************************************************/

#include <iostream>
#include <conio.h>
#include <stdarg.h>

double multiply(char*, ...); // прототип функції зі змінним чисом параметрів

using namespace std;

int main(int argc, char* argv[])
{
	multiply("4.0*6.0*2.0 = ", 4.0, 6.0, 2.0, -1.0);
	multiply("2.0*3.0*5.0*0.5 = ", 2.0, 3.0, 5.0, 0.5, -1.0);
	multiply("This product is ", -1.0);
	_getch();

	return 0;
}

double multiply(char* str, ...)

{
	double product = 1, term;

	va_list arg_list; // оголошуємо вказівник типу va_list
	va_start(arg_list, str); // встановлюємо вказівник на початок змінної

	// частини списку параметрів
	int k = 0;
	while ((term = va_arg(arg_list, double)) > 0)
	{
		product *= term;
		k = 1;
	}

	if (!k) product = 0;

	cout << str << product << endl;

	va_end(arg_list); // завершуємо оборобку списку параметрів

	return product;
}