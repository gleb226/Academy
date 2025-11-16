#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char strDest[50] = "Destination";
    char strSrc[50] = "Source";

    cout << "Destination str: " << strDest << endl;
    cout << "Source str: " << strSrc << endl;

    strcpy_s(strDest, strSrc);
    cout << "String strDest is now:" << strDest << endl;
    return 0;
}