#include <iostream>
using namespace std;

int main() {
	int a, b; // оголошуЇмо дв≥ зм≥нн≥
	// просимо користувача ввести в них дан≥ 
	cout << "Enter your first number:\n";
	cin >> a;
	cout << "Enter your second number:\n";
	cin >> b;

	/* якщо(b > a), то на м≥сце оператора ? : п≥дставитьс€ b,
		в ≥ншому випадку, на м≥сце оператора п≥дставитьс€ a,
		так, б≥льше число запишетьс€ в зм≥нну max.
	*/
	int max = (b > a) ? b : a;

	/* якщо (b<a), то на м≥сце оператора ?: п≥дставитьс€ b,
	 в ≥ншому випадку, на м≥сце оператора п≥дставитьс€ a,
	 так, б≥льше число запишетьс€ в зм≥нну min.
	 */
	int min = (b < a) ? b : a;

	// ¬ив≥д результату на екран. 
	cout << "\n Maximum is \n" << max;
	cout << "\n Minimum is \n" << min << "\n";
	return 0;
}