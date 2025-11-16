#include <iostream>
using namespace std;

int main() {
	int digit;
	cout << "Enter digit:";
	cin >> digit;

	// цикл перебирає числа від 2 до введеного числа
	for (int i = 2; i < digit; i++) {
		// якщо число не ділиться на поточне значення i без залишку, зупинити цей крок і перейти до наступного
		if (digit % i != 0)continue;
		// показати i на екрані 
		cout << i << " ";
	}

	cout << endl << endl;
	return 0;
}