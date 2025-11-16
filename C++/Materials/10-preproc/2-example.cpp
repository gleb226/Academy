#include <iostream>

using namespace std;

#define ArrFlg 1
int main() {
#ifdef ArrFlg
	int arr[30] = { 1, 21 };
	cout << arr[0] << " " << arr[1];
#else
	cout << "Array is not defined!";
#endif
	return 0;
}