#include<iostream>
/* у цьому файлі містяться rand і srand */
#include<stdlib.h>
// у цьому файлі міститься функція time
#include<time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int a;
	// генерація випадкового числа і запис його в змінну
	a = rand();
	cout << a << "\n";
	return 0;
}