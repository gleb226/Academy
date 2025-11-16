#include<iostream>
#include<stdlib.h> // у цьому файлі міститься фунцкія rand

using namespace std;
int main()
{
	int a;
	// генерація випадкового числа і запис його в змінну a
	a = rand();
	cout << a << "\n";
	// Повторна генерація випадкового числа і запис його в змінну a
	a = rand();
	cout << a << "\n";

	return 0;
}