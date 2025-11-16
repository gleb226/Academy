#include <iostream>

using namespace std;

int main()
{
    const int n = 20;
    char* userStr = new char[n];
    
    cout << "Input string: ";
    fgets(userStr, n, stdin);
    
    cout << "Number of symbol '*' = " << getNumberOfStars(userStr) << endl;
    
    delete[] userStr;

    return 0;
}