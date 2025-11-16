#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    FILE* in = fopen("input.txt", "r");
    if (!in) return 1;
    map<string, int> freq;
    string word = "";
    char c;
    while ((c = fgetc(in)) != EOF) {
        if (c >= 'A' && c <= 'Z') c += 32;
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) word += c;
        else {
            if (!word.empty()) {
                freq[word]++;
                word = "";
            }
        }
    }
    if (!word.empty()) freq[word]++;
    fclose(in);
    if (freq.empty()) return 0;
    for (auto &p : freq) cout << p.first << " " << p.second << endl;
    string maxWord = "";
    int maxCount = 0;
    for (auto &p : freq) {
        if (p.second > maxCount) {
            maxCount = p.second;
            maxWord = p.first;
        }
    }
    cout << maxWord << " " << maxCount << endl;
    FILE* out = fopen("output.txt", "w");
    for (auto &p : freq) fprintf(out, "%s %d\n", p.first.c_str(), p.second);
    fprintf(out, "%s %d\n", maxWord.c_str(), maxCount);
    fclose(out);
}
