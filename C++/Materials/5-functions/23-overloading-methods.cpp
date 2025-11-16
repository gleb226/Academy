#include <iostream>
using namespace std;

long maxElement(int n, int array[])

// Функція для масивів з елементами типу int.
{
	int value = array[0];
	for (int i = 1; i < n; i++)
		value = value > array[i] ? value : array[i];
	cout << "\nFor (int) : "; return long(value);
}

long maxElement(int n, long array[])
// Функція для масивів з елементами типу long.
{
	long value = array[0];
	for (int i = 1; i < n; i++)
		value = value > array[i] ? value : array[i];
	cout << "\nFor (long) :";
	return value;
}

double maxElement(int n, float array[])
// Функція для масивів з елементами типу float.
{
	float value = array[0];
	for (int i = 1; i < n; i++)
		value = value > array[i] ? value : array[i];
	cout << "\nFor (float) : ";
	return double(value);
}

double maxElement(int n, double array[])
// Функція для масивів з елементами типу double.
{
	double value = array[0];
	for (int i = 1; i < n; i++)
		value = value > array[i] ? value : array[i];
	cout << "\nFor (double) : ";
	return value;
}

int main()
{
	int x[] = { 10, 20, 30, 40, 50, 60 };
	long f[] = { 12L, 44L, 5L, 22L, 37L, 30L };
	float y[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6 };
	double z[] = { 0.01, 0.02, 0.03, 0.04, 0.05, 0.06 };
	cout << "max_elem(6,x) = " << maxElement(6, x);
	cout << "max_elem(6,f) = " << maxElement(6, f);
	cout << "max_elem(6,y) = " << maxElement(6, y);
	cout << "max elem(6,z) = " << maxElement(6, z);
	return 0;
}