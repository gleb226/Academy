#include<iostream>

using namespace std;

int main(intargc, char* argv[])
{
    const char plus[] = "+";
    const char mult[] = "*";
    int x, y;
    cout << "Your program name is " << argv[0] << endl;

    if (argc < 4)
    {
        cout << "Not enough arguments!" << endl;
    }
    else if(argc == 4)
    {
        x = atoi(argv[1]);
        y = atoi(argv[3]);

        cout << "x=" << x << endl;
        cout << "y=" << y << endl;

        if (strcmp(argv[2], plus) == 0)
        {
            cout << "Result: x+y=" << x + y << endl;
        }
        else if(strcmp(argv[2], mult) == 0)
        {
            cout << "Result: x*y=" << x * y << endl;
        }
        else
        {
            cout << "Unknown operator!" << endl;
        }
    }
    else
    {
        cout << "Too many arguments!" << endl;
    }
    return 0;
}