#include <iostream>
using namespace std;

int& rf(int index); // Прототип функції.
int a[10][2];

int main()
{
	int b;
	cout << "Fill array.\n";
	for (int i = 0;i < 10;i++)
	{
		cout << i + 1 << " element:";
		cin >> b;
		a[i][0] = b;
		rf(i) = b;
	}
	cout << "Show array.\n";
	cout << "1-st column 2-nd column" << "\n";
	for (int i = 0;i < 10;i++)
		cout << a[i][0] << "\t\t" << rf(i) << "\n";
	return 0;
}

int& rf(int index)
{
	return a[index][1]; // Повернення посилання на 
	// елемент масиву.
}