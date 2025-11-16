#include <iostream>
#include <io.h>

using namespace std;

int main()
{
	struct _finddata_t fileinfo;
	char str[200] = "D:\\examples\\*.dat";
	long done = _findfirst(str, &fileinfo);
	if (done == 1)
	{
		cout << "The search result is unsuccessful";
	}
	else
	{
		cout << fileinfo.name;
	}
	return 0;
}