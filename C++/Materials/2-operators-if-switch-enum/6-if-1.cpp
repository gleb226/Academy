#include <iostream> 
using namespace std;

int main() {
	int A, B; // оголосимо дві змінні просимо користувача ввести в них дані 
	
	cout << "Enter your first number:\n";
	cin >> A;
	cout << "Enter your second number:\n";
	cin >> B;
	
	if (B == 0) { // якщо B містить нуль, повідомляємо про помилку
		cout << "You can’t divide by zero!!!";
	}
	else { // в іншому випадку
		cout << "Result A/B=" << A << "/" << B << "=" << A / B; // видаємо результат ділення А на B
	}
	cout << "\n The end. \n"; // кінець

	return 0;
}