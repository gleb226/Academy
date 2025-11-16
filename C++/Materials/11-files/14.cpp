#include <iostream>
#include <io.h>

using namespace std;

int main()
{
	struct _finddata_t fileinfo;
	char str[200] = "D:\\examples\\*.dat";
	long done = _findfirst(str, &fileinfo);
	while (done != -1) {
		cout << fileinfo.name << "\n";
		done = _findnext(done, &fileinfo);
	}

	return 0;
}