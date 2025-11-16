#include <iostream>
using namespace std;

struct Test
{
	char c;
	int i;
};

int main()
{
	Test d = { '#',78 };
	cout << sizeof(Test) << " " << sizeof(d) << "\n\n";
	return 0;
}