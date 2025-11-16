// програма для з’ясування параметрів окружності
#include <iostream>
using namespace std;

int main()
{
	const float PI = 3.141592;// позначення константи — числа пі
	// оголошення змінних для зберігання параметрів
	float radius, circumference, area;
	
	// запрошення ввести радіус
	cout << "Welcome to the program for working with circles\n\n";
	cout << "Enter the radiuses of your circles\n\n";
	cin >> radius;
	cout << "\n\n";
	area = PI * radius * radius; // підрахунок площі кола
	circumference = PI * (radius * 2); // підрахунок довжини окружності

	// вивід результатів
	cout << "The area of the circle is " << area << "\n\n";
	cout << "The circumference is " << circumference << "\n\n";
	cout << "THANKS!!! BYE!!!\n\n";

	return 0;
}
