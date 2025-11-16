#include <iostream>
using namespace std;

long int factorial(long int N)
{
	// якщо проведена спроба обчислити факторіал нуля
	if (N < 1) return 0;
	/* якщо обчислюється факторіал одиниці,
	саме тут виконується вихід із рекурсії */
	else if (N == 1) return 1;
	// будь-яке інше число викликає функцію заново з формулою N-1
	else return N * factorial(N - 1);
}

int main()
{
	long number = 5;
	// перший виклик рекурсивної функції 
	long result = factorial(number);
	cout << "Result " << number << "! is — " << result << "\n";
	return 0;
}