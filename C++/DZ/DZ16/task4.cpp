#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    if (!input || !output) return 1;

    string findWord, replaceWord;
    cout << "Find: ";
    cin >> findWord;
    cout << "Replace with: ";
    cin >> replaceWord;

    string line;
    while (getline(input, line)) {
        size_t pos = 0;
        while ((pos = line.find(findWord, pos)) != string::npos) {
            line.replace(pos, findWord.length(), replaceWord);
            pos += replaceWord.length();
        }
        output << line << endl;
    }

    input.close();
    output.close();
    return 0;
}
