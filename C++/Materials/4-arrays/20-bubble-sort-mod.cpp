#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
void shakerSort(T a[], long size) {
	long j, k = size - 1;
	long lb = 1, ub = size - 1; // межі частини масиву, 
	// що не є відсортованою
	T x;
	do {
		// прохід знизу вгору 
		for (j = ub;j > 0;j--) {
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
				k = j;
			}
		}
		lb = k + 1;
		// прохід зверху вниз 
		for (j = 1;j <= ub;j++) {
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
				k = j;
			}
		}
		ub = k - 1;
	} while (lb < ub);
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
	shakerSort(ar, SIZE);
	// після сортування 
	for (int i = 0;i < SIZE;i++) {
		cout << ar[i] << "\t";
	}
	cout << "\n\n";
	return 0;
}
