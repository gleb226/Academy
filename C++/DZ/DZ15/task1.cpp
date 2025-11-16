#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");

    if (!file1.is_open() || !file2.is_open()) {
        cout << "Failed to open one of the files." << endl;
        return 1;
    }

    string line1, line2;
    int lineNumber = 1;
    bool filesAreEqual = true;

    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            cout << "Line " << lineNumber << " does not match:" << endl;
            cout << "File 1: " << line1 << endl;
            cout << "File 2: " << line2 << endl;
            filesAreEqual = false;
            break;
        }
        lineNumber++;
    }

    if (filesAreEqual) {
        if (getline(file1, line1)) {
            cout << "File 1 has an extra line " << lineNumber << ": " << line1 << endl;
            filesAreEqual = false;
        } else if (getline(file2, line2)) {
            cout << "File 2 has an extra line " << lineNumber << ": " << line2 << endl;
            filesAreEqual = false;
        }
    }

    if (filesAreEqual) {
        cout << "All lines match." << endl;
    }

    file1.close();
    file2.close();

    return 0;
}
