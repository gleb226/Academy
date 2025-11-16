#include <iostream>
using namespace std;

int main()
{
	const int size = 5;
	int arr[size] = { 33, 44, 7, 8, 9 };

	int* ptr = arr;
	/* відображаємо весь масив через покажчик
	на екрані 33 44 7 8 9 */
	for (int i = 0; i < size; i++) {
		cout << ptr[i] << " ";
	}
	// змінюємо значення першого елемента
	ptr[1] = 55;
	// змінюємо значення другого елемента
	ptr[2] = 12;
	cout << endl << endl;

	/* відображаємо весь масив через покажчик
	на екрані 33 55 12 8 9 */
	for (int i = 0; i < size; i++) {
		cout << ptr[i] << " ";
	}
	return 0;
}