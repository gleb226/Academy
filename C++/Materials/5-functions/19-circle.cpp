#include <iostream>
using namespace std;

void area(float radius)
{
    float ar = 3.14 * radius * radius;
    cout << "Area of circle=" << ar;
}

int main()
{
    float r;
    cout << "Enter radius of circle\n";
    cin >> r;
    area(r);
}


/*
### Output ###
Enter radius of circle=2.2
Area of circle=15.197
*/
