#include <iostream>
using namespace std;

int main() {
	// оголошуЇмо зм≥нну з задуманим числом
	int magicNum = 2;
	cout << "==================================\n\n";
	cout << " My magic number between 1 and 10\n";
	cout << "==================================\n\n";
	int user = 0;

	for (int n = 1; n <= 5; n++)
	{
		cout << "Your number is -> ";
		cin >> user;
		// перев≥р€Їмо, чи вгадав користувач наше
		// число; €кщо так, виводимо прив≥танн€
		// ≥ перериваЇмо цикл
		if (user == magicNum)
		{
			cout << "Congrats!!!\n";
			break;
		}
		else
		{
			// ≥накше, користувач ще не в≥дгадав 
			cout << "ThatТs not my number\n";
		}
		// €кщо л≥чильник дос€г 5, виводимо пов≥домленн€
		// спробувати з≥грати знову
		if (n == 5)
		{
			cout << "Try again later\n";
		}
	}

	return 0;
}