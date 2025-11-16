#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");
    if (!input) return 1;

    string line;
    size_t maxLength = 0;

    while (getline(input, line)) {
        if (line.length() > maxLength) {
            maxLength = line.length();
        }
    }

    cout << "Max line length: " << maxLength << endl;

    input.close();
    return 0;
}
