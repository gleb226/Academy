#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input || !output) return 1;

    vector<string> lines;
    string line;
    while (getline(input, line)) {
        lines.push_back(line);
    }

    for (size_t i = 0; i + 1 < lines.size(); ++i) {
        output << lines[i] << endl;
    }

    input.close();
    output.close();
    return 0;
}
