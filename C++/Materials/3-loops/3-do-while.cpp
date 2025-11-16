#include <iostream> 
using namespace std;

int main()
{
	int answer, A, B, RES;
	do { // вхід у цикл
		// запит на вибір операції 
		cout << "\nSelect operation:\n";
		cout << "\n Press 1 if you want to ADD.\n";
		cout << "\n Press 2 if you want to DEDUCT.\n";
		cout << "\n Press 3 if you want to exit.\n";
		cin >> answer;
		// аналіз дії 
		switch (answer) {
		case 1: // якщо користувач вибрав складання 
			cout << "Enter your first number:\n";
			cin >> A;
			cout << "Enter your second number:\n";
			cin >> B;
			RES = A + B;
			cout << "\nAnswer: " << RES << "\n";
			break; // зупинка switch
		case 2: // якщо користувач вибрав віднімання 
			cout << "Enter your first number:\n";
			cin >> A;
			cout << "Enter your second number:\n";
			cin >> B;
			RES = A - B;
			cout << "\nAnswer: " << RES << "\n";
			break; // зупинка switch
		case 3: // якщо користувач вибрав вихід 
			cout << "\nEXIT!!!\n";
			break;
		default: // якщо вибрана дія
			// є некоректною 
			cout << "\nError! Invalid operation\n";
		}
	} while (answer != 3);

	cout << "\nBye. \n";
	return 0;
}