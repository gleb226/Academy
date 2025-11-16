#include<iostream>
using namespace std;

void add() 	// function definition
{
    int x, y = 20, z = 30;
    x = y + z;
    cout << "Add=" << x;
}
int main()
{
    add(); 	// function calling
}


/*
### Output ###
Add=50
*/