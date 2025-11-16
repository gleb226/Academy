#include <iostream>
#include <io.h>

using namespace std;

int main()
{
	struct _finddata_t myfileinfo;
	long done = _findfirst("*.cpp", &myfileinfo);
	cout << myfileinfo.name;
	return 0;
}