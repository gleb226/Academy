#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// відображення масиву
void showArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

/* ініціалізуємо масив усередині функції випадковими
 числами на відміну від звичайних змінних, зміни
 елементів масиву, що відбуваються всередині функції,
 при виході з функції зберігаються
*/
void initArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}
	cout << endl;
}
int main()
{
	srand(time(NULL));

	const int aSize = 10;
	int iArr[aSize];

	initArray(iArr, aSize);
	showArray(iArr, aSize);

	return 0;
}
