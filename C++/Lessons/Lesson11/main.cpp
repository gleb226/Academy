#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "There are " << argc << endl;

    for (int count = 0; count < argc; ++count)
        cout << count << "" << endl;

    return 0;
}
