#include <iostream>

using namespace std;

union Employee {
	int id;
	double salary;
};

int main()
{

	Employee myEmployee;

	myEmployee.id = 15;
	cout << "The first value (id) at ";
	cout << "the allocated memory: ";
	cout << myEmployee.id << "\n";
	myEmployee.salary = 100.35;
	cout << "The next value (salary) stored ";
	cout << "after removing the previous value: ";
	cout << myEmployee.salary << "\n";
	return 0;

}

struct statusField
{
	unsigned int JS;
	unsigned int PHP;
	unsigned int Python;
} state;