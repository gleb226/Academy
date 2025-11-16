#include <iostream>
using namespace std;
// Функція визначає посилання на елемент
// масиву з максимальним значенням.

int& rmax(int n, int d[])
{
	int im = 0;
	for (int i = 1; i < n; i++)
		im = d[im] > d[i] ? im : i;
	return d[im];
}

int main()
{
	int x[] = { 10, 20, 30, 14 };
	int n = 4;
	cout << "\nrmax(n,x) = " << rmax(n, x) cout << "\n";
	// замінюємо максимум на нуль
	rmax(n, x) = 0;

	for (int i = 0;i < n;i++)
		cout << "x[" << i << "]=" << x[i] << " ";
	cout << "\n";

	return 0;
}