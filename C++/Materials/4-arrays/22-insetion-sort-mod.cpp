#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class T>
void setMin(T a[], long size) {
	T min = a[0];
	for (int i = 1;i < size;i++)
		if (a[i] < min)
			min = a[i];
	a[0] = min;
}

template <class T>
void insertSortGuarded(T a[], long size) {
	T x;
	long i, j;
	// зберегти старий перший елемент
	T backup = a[0];
	// замінити на мінімальний 
	setMin(a, size);
	// вісортувати масив 
	for (i = 1;i < size;i++) {
		х = a[i];
		for (j = i - 1;a[j] > x;j--)
			a[j + 1] = a[j];
		a[j + 1] = x;
	}
	// вставити backup на правильне місце
	for (j = 1;j < size && a[j] < backup;j++)
		a[j - 1] = a[j];
	// вставка елемента
	a[j - 1] = backup;
}

int main() {
	srand(time(NULL));
	const long SIZE = 10;
	int ar[SIZE];

	// до сортування 
	for (int i = 0;i < SIZE;i++) {
		ar[i] = rand() % 100;
		cout << ar[i] << "\t";
	}
	cout << "\n\n";

	insertSortGuarded(ar, SIZE);
	// після сортування 
	for (int i = 0;i < SIZE;i++) {
		cout << ar[i] << "\t";
	}
	cout << "\n\n";

	return 0;
}
