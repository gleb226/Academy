#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

int main() {
    map<string, string> dict;
    int c;
    string a, b;
    while (cin >> c) {
        if (c == 1) { cin >> a >> b; dict[a] = b; }
        if (c == 2) { cin >> a; cout << dict[a] << endl; }
        if (c == 3) { cin >> a; dict.erase(a); }
        if (c == 4) {
            ofstream f("dict.txt");
            for (auto &p : dict) f << p.first << " " << p.second << endl;
        }
        if (c == 5) {
            ifstream f("dict.txt");
            while (f >> a >> b) dict[a] = b;
        }
        if (c == 0) break;
    }
}
