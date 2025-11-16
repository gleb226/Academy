#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class T>
void bubbleSort(T a[], long size) {
	long i, j;
	T x;
	for (i = 0;i < size;i++) { // i Ч номер проходу
		for (j = size - 1;j > i;j--) { // внутр≥шн≥й цикл
			// проходу
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
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

	bubbleSort(ar, SIZE);
	// п≥сл€ сортуванн€ 
	for (int i = 0;i < SIZE;i++) {
		cout << ar[i] << "\t";
	}
	cout << "\n\n";

	return 0;
}