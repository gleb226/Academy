#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	FILE* out;
	// if (fopen_s(&out, "outfile.txt", "w") != 0)
	if ((out = fopen("outfile.txt", "w")) == NULL)
		cout << "The file could not be created!";
	else
		cout << "OK!";
	return 0;
}