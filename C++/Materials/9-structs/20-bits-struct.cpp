#include <iostream>
using namespace std;
int main()
{
	struct myInfo {
		unsigned char part1 : 2;
		unsigned char part2 : 3;
		unsigned char part3 : 1;
		unsigned char part4 : 1;
		unsigned char mySymbol;
	};
	myInfo user1;
	cout << "Size of my data is " << sizeof(user1);

	return 0;
}