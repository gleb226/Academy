#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Enter any number\n";
    cin >> number;
    for (int i = 1; i <= 10; i++)
    {
        cout << i * number << "";
    }
}


/*
### Output ###
Enter any number
5
5 10 15 20 25 30 35 40 45 50
*/