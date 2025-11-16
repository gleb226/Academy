#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class T>
void bubbleSort(T a[], long size) {
	long i, j;
	T x;
	for (i = 0; i < size; i++) { // i Ч номер проходу 
		for (j = size Ч 1; j > i; j--) {
			// внутр≥шн≥й цикл проходу
			if (a[j Ч 1] > a[j]) {
				x = a[j Ч 1];
				a[j Ч 1] = a[j];
				a[j] = x;
			}
		}
	}
}

int BinarySearch(int A[], int Lb, int Ub, int Key) {
	int M;
	while (1) {
		M = (Lb + Ub) / 2;
		if (Key < A[M])
			Ub = M Ч 1;
		else if (Key > A[M])
			Lb = M + 1;
		else
			return M;
		if (Lb > Ub)
			return -1;
	}
}

int main() {
	srand(time(NULL));
	const long SIZE = 10;
	int ar[SIZE];
	int key, ind;
	// до сортуванн€ 
	for (int i = 0;i < SIZE;i++) {
		ar[i] = rand() % 100;
		cout << ar[i] << "\t";
	}
	cout << "\n\n";
	/*
	¬икличемо алгоритм бульбашкового сортуванн€,
	написаний нами ран≥ше.
	ѕеред дв≥йковим пошуком дан≥ потр≥бно в≥дсортувати.
	*/
	bubbleSort(ar, 10);

	// п≥сл€ сортуванн€ 
	for (int i = 0;i < SIZE;i++) {
		cout << ar[i] << "\t";
	}

	cout << "\n\n";
	cout << "Enter any digit:";
	cin >> key;

	ind = BinarySearch(ar, 0, SIZE, key);
	cout << "Index Ч " << ind << "\t"; cout << "\n\n";

	return 0;
}