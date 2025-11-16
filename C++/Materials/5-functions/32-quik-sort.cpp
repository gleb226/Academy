#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
void quickSortR(T a[], long N) {
	// На вході — масив a[], 
	// a[N] — його останній елемент.
	// поставити покажчики на вихідні місця
	long i = 0, j = N;
	T temp, p;
	p = a[N / 2]; // центральний елемент

	// процедура поділу 
	do {
		while (a[i] < p) i++;
		while (a[j] > p) j--;
		if (i <= j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	/* рекурсивні виклики, якщо є що сортувати */
	if (j > 0) quickSortR(a, j);
	if (N > i) quickSortR(a + i, N - i);
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
	quickSortR(ar, SIZE - 1);

	// після сортування 
	for (int i = 0;i < SIZE;i++) {
		cout << ar[i] << "\t";
	}
	cout << "\n\n";

	return 0;
}