#include <iostream>
#include <string>
using namespace std;

class String {
private:
    string str;
    static int count;

public:
    String() : String(string(80, ' ')) { }

    String(int len) : str(len, ' ') {
        count++;
    }

    String(const string& s) : str(s) {
        count++;
    }

    ~String() {
        count--;
    }

    void input() {
        getline(cin, str);
    }

    void display() const {
        cout << str << endl;
    }

    static int getCount() {
        return count;
    }
};

int String::count = 0;

int main() {
    String s1;
    String s2(50);
    String s3("Hello!");

    s2.input();
    s1.display();
    s2.display();
    s3.display();

    cout << "Objects created: " << String::getCount() << endl;

    return 0;
}
