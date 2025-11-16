#include<iostream>
// у цьому файлі містяться функції rand() і srand()
#include<stdlib.h>
// у цьому файлі міститься функція time() 
#include<time.h> 
using namespace std;

int main()
{
	int array[10];
	srand(time(NULL));
	for (int i = 0;i < 10;i++)
	{
		// генерація випадкового числа і запис його
		// в поточний елемент масиву
		array[i] = rand() % 100;
		// вивід значення елемента на //екран 
		cout << array[i] << "\n";
	}
	return 0;
}