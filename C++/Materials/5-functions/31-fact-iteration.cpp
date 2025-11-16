#include <iostream>
using namespace std;

long int factorial(long int N)
{
	long int F = 1;
	// цикл обчислюЇ фактор≥ал
	for (int i = 2; i <= N; i++)
		F *= i;
	return F;
}

int main()
{
	long number = 5;
	long result = factorial(number);
	cout << "Result " << number << "! is Ч " << result << "\n";
	return 0;
}