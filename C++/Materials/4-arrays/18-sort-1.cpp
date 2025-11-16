#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>

void selectSort(T a[], long size) {
	long i, j, k;
	T x;
	// i Ч номер поточного кроку
	for (i = 0; i < size; i++) {
		k = i;
		x = a[i];
		// цикл вибору найменшого елемента 
		for (j = i + 1; j < size; j++)
			if (a[j] < x) {
				k = j;
				x = a[j];
				// k Ч ≥ндекс найменшого елемента
			}
		if (k != i) {
			a[k] = a[i];
			a[i] = x;
			// м≥н€Їмо м≥сц€ми найменший з a[i]
		}
	}
}

int main() {
	srand(time(NULL));

	const long SIZE = 10;
	int ar[SIZE];

	// до сортуванн€ 
	for (int i = 0;i < SIZE;i++) {
		ar[i] = rand() % 100;
		cout << ar[i] << "\t";
	}
	cout << "\n\n";

	selectSort(ar, SIZE);
	// п≥сл€ сортуванн€ 
	for (int i = 0;i < SIZE;i++) {
		cout << ar[i] << "\t";
	}
	cout << "\n\n";

	return 0;
}