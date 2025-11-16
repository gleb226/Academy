#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");
    if (!input) return 1;

    string word, line;
    cout << "Enter word to count: ";
    cin >> word;

    int count = 0;
    while (input >> line) {
        if (line == word) count++;
    }

    cout << "Occurrences: " << count << endl;

    input.close();
    return 0;
}
