#include <iostream>
using namespace std;

void showArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " ";
	}
}

// обчислення суми елементів масиву
int getAmount(int* ptr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(ptr + i);
	}
	return sum;
}

int main()
{
	const int size = 5;
	int arr[size] = { 33, 44, 7, 8, 9 };

	// відображаємо весь масив на екрані 33 44 7 8 9
	showArray(arr, size);
	cout << endl << endl;

	// показуємо суму елементів масиву
	// 101
	cout << "Amount of array elements: " << getAmount(arr, size) << endl << endl;

	/* відображаємо весь масив на екрані
	33 44 7 8 9
	*/
	showArray(&arr[0], size);
	return 0;
}
