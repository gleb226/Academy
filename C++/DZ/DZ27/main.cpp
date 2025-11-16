#include <iostream>
#include <fstream>
using namespace std;

class FileReader {
public:
    virtual void Display(const char* path) {
        ifstream f(path);
        if (!f) { cout << "Cannot open file\n"; return; }
        char ch;
        while (f.get(ch)) cout << ch;
        cout << endl;
    }
    virtual ~FileReader() {}
};

class ASCIIFileReader : public FileReader {
public:
    void Display(const char* path) override {
        ifstream f(path);
        if (!f) { cout << "Cannot open file\n"; return; }
        char ch;
        while (f.get(ch)) cout << int(ch) << ' ';
        cout << endl;
    }
};

class BinaryFileReader : public FileReader {
public:
    void Display(const char* path) override {
        ifstream f(path, ios::binary);
        if (!f) { cout << "Cannot open file\n"; return; }
        char ch;
        while (f.get(ch)) {
            for (int i = 7; i >= 0; i--)
                cout << ((ch >> i) & 1);
            cout << ' ';
        }
        cout << endl;
    }
};

int main() {
    FileReader* fr = new FileReader();
    fr->Display("test.txt");

    FileReader* ar = new ASCIIFileReader();
    ar->Display("test.txt");

    FileReader* br = new BinaryFileReader();
    br->Display("test.txt");

    delete fr;
    delete ar;
    delete br;
    return 0;
}
