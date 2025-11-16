#include <iostream>
using namespace std;

// обчислює степінь (Pow) числа (Digit) 
int myPow(int digit, int pow) {
	int key = 1;
	for (int i = 0;i < pow;i++)
		key *= digit;
	return key;
}

int main() {
	// запис результату, що повертається, у змінну
	res int res = myPow(5, 3);
	cout << "Res = " << res << "\n\n";
	return 0;
}