#include<iostream>
using namespace std;

void add(int y, int z) 	// function definition
{
    int x;
    x = y + z;
    cout << "Add=" << x;
}

int main()
{
    add(10, 20); 	// function calling
}


/*
### Output ###
Add=30
*/