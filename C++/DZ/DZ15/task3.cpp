#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char shiftChar(char c, int key) {
    if (c >= 'A' && c <= 'Z')
        return 'A' + (c - 'A' + key) % 26;
    if (c >= 'a' && c <= 'z')
        return 'a' + (c - 'a' + key) % 26;
    if (c >= 'А' && c <= 'Я')
        return 'А' + (c - 'А' + key) % 32;
    if (c >= 'а' && c <= 'я')
        return 'а' + (c - 'а' + key) % 32;
    return c;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        cout << "Failed to open files." << endl;
        return 1;
    }

    int key = 3;
    string line;

    while (getline(input, line)) {
        for (char& c : line)
            c = shiftChar(c, key);
        output << line << endl;
    }

    input.close();
    output.close();

    cout << "Encryption completed using Caesar cipher (key = " << key << ")." << endl;

    return 0;
}
