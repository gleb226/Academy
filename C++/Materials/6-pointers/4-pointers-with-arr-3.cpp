#include <iostream>
using namespace std;

int main()
{
	const int size = 5;
	int arr[size] = { 33, 44, 7, 8, 9 };

	// відображаємо весь масив на екрані 33 44 7 8 9
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " ";
	}

	// змінюємо значення першого елемента
	*(arr + 1) = 55;
	// змінюємо значення другого елемента
	*(arr + 2) = 12;
	cout << endl << endl;

	// відображаємо весь масив на екрані 33 55 12 8 9
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " ";
	}
	return 0;
}