#include <iostream>
using namespace std;

int main()
{
	int ivar = 1234; // Змінній присвоєно значення.
	int* iptr = &ivar; // Покажчику присвоєно адресу ivar.
	int& iref = ivar; // Посилання асоційована з ivar.
	int* p = &iref; // Покажчику присвоєно адресу iref.
	cout << "ivar = " << ivar << "\n";
	cout << "*iptr = " << *iptr << "\n";
	cout << "iref = " << iref << "\n";
	cout << "*p = " << *p << "\n";
	return 0;
}