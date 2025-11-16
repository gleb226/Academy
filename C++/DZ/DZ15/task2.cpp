#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'A' ||
           c == 'e' || c == 'E' ||
           c == 'i' || c == 'I' ||
           c == 'o' || c == 'O' ||
           c == 'u' || c == 'U';
}

bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isConsonant(char c) {
    return isLetter(c) && !isVowel(c);
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    ifstream input("input.txt");

    if (!input.is_open()) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    string line;
    while (getline(input, line)) {
        lineCount++;
        for (char c : line) {
            charCount++;
            if (isDigit(c)) digitCount++;
            else if (isVowel(c)) vowelCount++;
            else if (isConsonant(c)) consonantCount++;
        }
    }

    cout << "Characters: " << charCount << endl;
    cout << "Lines: " << lineCount << endl;
    cout << "Vowels: " << vowelCount << endl;
    cout << "Consonants: " << consonantCount << endl;
    cout << "Digits: " << digitCount << endl;

    input.close();

    return 0;
}
