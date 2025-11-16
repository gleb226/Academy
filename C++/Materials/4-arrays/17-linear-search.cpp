#include <iostream>
using namespace std;

int LinearSearch(int array[], int size, int key) {
	for (int i = 0;i < size;i++)
		if (array[i] == key)
			return i;
	return -1;
}

int main()
{
	const int arraySize = 100;
	int a[arraySize], searchKey, element;

	for (int x = 0;x < arraySize;x++) {
		a[x] = 2 * x;
	}
	// Наступний рядок виводить на екран повідомлення
	// Введіть ключ пошуку:
	cout << "Please, enter the key:";
	cin >> searchKey;
	element = LinearSearch(a, arraySize, searchKey);
	if (element != -1) {
		// Наступний рядок виводить на екран повідомлення
		// Знайдено значення в елементі
		cout << "\nThe key was found in element" <<
			element << '\n';
	}
	else {
		/*
		Наступний рядок виводить на екран повідомлення
		Значення не знайдено
		*/
		cout << "\nValue not found ";
	}
	return 0;
}