#include <iostream> 
using namespace std;

int main() {
	// оголошення змінних і ввід значення з клавіатури 
	float A, B, RES;
	cout << "Enter your first number:\n";
	cin >> A;
	cout << "Enter your second number:\n";
	cin >> B;

	// реалізація програмного меню 
	char key;
	cout << "\nChoose the operator:\n";
	cout << "\n + — if you want to ADD.\n";
	cout << "\n — - if you want to DEDUCT.\n";
	cout << "\n * — if you want to MULTIPLY.\n0";
	cout << "\n / — if you want to DIVIDE.\n";

	// очікування вибору користувача 
	cin >> key;
	if (key == '+') { // якщо користувач вибрав додавання
		RES = A + B;
		cout << "\nAnswer: " << RES << "\n";
	}
	else if (key == '-') { // якщо користувач вибрав
		// віднімання
		RES = A - B;
		cout << "\nAnswer: " << RES << "\n";
	}
	else if (key == '*') { // якщо користувач вибрав
		// множення
		RES = A * B;
		cout << "\nAnswer: " << RES << "\n";
	}
	else if (key == '/') { // якщо користувач
		// вибрав ділення 
		if (B) { // якщо дільник не дорівнює нулю
			RES = A / B;
			cout << "\nAnswer: " << RES << "\n";
		}
		else { // якщо дільник дорівнює нулю 
			cout << "\nError! You cannot divide by zero!\n";
		}
	}
	else { // якщо введений символ є некоректним
		cout << "\nError! Invalid value \n";
	}

	return 0;
}
