#include<iostream> 
using namespace std;

int main() {
	// оголошується змінна для зберігання первісної суми 
	int sum;
	// запит на ввід суми з клавіатури 
	cout << "Enter the total amount:\n";
	cin >> sum;

	if (sum > 1000) { // якщо сума більша за 1000 грн.,
		// знижка 25% 
		cout << "You have a 25% discount!!!\n";
		cout << "You have to pay " <<
			sum - sum / 100 * 25 << "\n";
	}
	else { // якщо сума не більша за 100 грн.,
		// продовжуємо аналіз
		if (sum > 500) { // якщо сума не більша за 500 грн.,
			// знижка 10%
			cout << "You have a 10% discount!!!\n";
			cout << "You have to pay " <<
				sum - sum / 100 * 10 << "\n";
		}
		else { // якщо сума не більша за 500 грн.,
			// продовжуємо аналіз
			if (sum > 100) { // якщо сума більша за 100 грн.,
				// знижка 5% 
				cout << "You have a 5% discount!!!\n";
				cout << "You have to pay " <<
					sum - sum / 100 * 5 << "\n";
			}
			else { // якщо сума не більша за 100 грн.,
				// знижки немає 
				cout << "You have not discount!!!\n";
				cout << "You must pay — " << sum << "\n";
			}
		}
	}
	return 0;
}