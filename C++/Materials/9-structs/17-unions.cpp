#include <iostream>

using namespace std;

int main()
{
	union
	{
		short int component1;
		int component2;
		long int component3;
	} myUnion; // об’єкт об’єднання

	myUnion.component1 = 22;
	cout << myUnion.component1 << endl;
	myUnion.Component3 = 222222222;
	cout << myUnion.Component3 << endl;
	cout << myUnion.component1 << endl; // знову 
	// звертаємося до component1

	return 0;
}