#include <iostream> 
using namespace std;

int main() {
	// оголошення змінної, для зберігання літерної
	// оцінки 
	char cGrade;
	// прохання ввести літерну оцінку 
	cout << "Input your letter grade\n";
	cin >> cGrade;
	// аналіз введеного значення 
	switch (cGrade) {
	case 'A':
	case 'a':
		// оцінка A чи a рівноцінна 5 
		cout << "Your grade is 5\n";
		break;
	case 'B':
	case 'b':
		// оцінка B чи b рівноцінна 4
		// а також оцінка С або с рівноцінна 4- 
	case 'C':
	case 'c':
		cout << "Your rate is 4\n";
		break;
		// оцінка C чи c рівноцінна 3 
		cout << "Your grade is 3\n";
		break;
	case 'D':
	case 'd':
		// оцінка D чи d рівноцінна 2 
		cout << "Your grade is 2\n";
		break;
	case 'F':
	case 'f':
		// оцінка F чи f рівноцінна 1 
		cout << "Your grade is 1\n";
		break;
	default:
		// інші символи є некоректними 
		cout << "This grade is invalid\n";
	}
	return 0;
}
