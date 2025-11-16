#include <iostream>

using namespace std;

int main()
{
	char myStr[] = "Hello!";
	cout << "My string: " << myStr << endl;

	for (char* strPtr = myStr; *strPtr; strPtr++)
	{
		if ((*strPtr == 'o') || (*strPtr == 'e'))
		{
			cout << *strPtr << endl;
		}
	}

	return 0;
}