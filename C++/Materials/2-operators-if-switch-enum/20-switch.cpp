#include <iostream>
using namespace std;

int main() {
	// оголошення змінних і ввід значення
	// з клавіатури 
	float A, B, RES;
	cout << "Enter your first number:\n";
	cin >> A;
	cout << "Enter your second number:\n";
	cin >> B;
	// реалізація програмного меню 
	char key;
	cout << "\nSelect operator:\n";
	cout << "\n + — if you want to ADD.\n";
	cout << "\n — - if you want to DEDUCT.\n";
	cout << "\n * — if you want to MULTIPLY.\n";
	cout << "\n / — if you want to DIVIDE.\n";
	// очікування вибору користувача 
	cin >> key;

	// перевіряється значення змінної key 
	switch (key) {
	case '+': // якщо користувач вибрав додавання 
		RES = A + B;
		cout << "\nAnswer: " << RES << "\n";
		break; // зупинка switch
	case '-': // якщо користувач вибрав віднімання
		RES = A - B;
		cout << "\nAnswer: " << RES << "\n";
		break; // зупинка switch
	case '*': // якщо користувач вибрав множення 
		RES = A * B;
		cout << "\nAnswer: " << RES << "\n";
		break; // зупинка switch case '/':
		// якщо користувач вибрав ділення
	case '/': // якщо користувач вибрав ділення
		if (B) { // якщо дільник не дорівнює нулю
			RES = A / B;
			cout << "\nAnswer: " << RES << "\n";
		}
		else { // якщо дільник дорівнює нулю 
			cout << "\nError! You cannot divide by zero!\n";
		}
		break; // зупинка switch
	default: // якщо введений символ є некоректним
		cout << "\nError! Invalid "
			"value\n";
		break; // зупинка switch
	}
	return 0;
}