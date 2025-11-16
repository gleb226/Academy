#include<iostream>
#include<time.h>

using namespace std;

int main() {
	srand(time(NULL));
	int size;
	int* dar;

	// запит розміру масиву з клавіатури 
	cout << "Enter size:\n";
	cin >> size;

	/* виділення пам'яті під масив з кількістю
	елементів size */
	dar = new int[size];
	// заповнення масиву та вивід на екран 
	for (int i = 0; i < size; i++) {
		dar[i] = rand() % 100;
		cout << dar[i] << "\t";
	}
	cout << "\n\n";

	return 0;
}