#include <iostream>

using namespace std;

int main()
{
	const char* path = "D:\\examples\\text.txt";
	int c;
	int len = 0, cnt = 0;
	FILE* in;
	if (fopen_s(&in, path, "r") != NULL)
		cout << "The file cannot be opened";
	else
	{
		while (!feof(in)) {
			c = fgetc(in);
			if (c == '\n') {
				cout << "\n";
			}
			else
			{
				cout << (char)c;
			}
		}
	}
	return 0;
}