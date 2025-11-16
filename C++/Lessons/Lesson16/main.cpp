#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    ofstream outf("/run/media/gleb/USB/Sync/Academy/C++/Lessons/Lesson16/SomeText.txt");
    if (!outf) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    outf << "Hello World!" << endl;
    outf << "This is a test" << endl;

    return 0;
}