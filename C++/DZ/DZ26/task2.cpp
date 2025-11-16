#include <iostream>
#include <string>
using namespace std;

class String {
protected:
    string s;
public:
    String() { s = ""; }
    String(const char* str) { s = str; }
    String(const String& other) { s = other.s; }
    String& operator=(const String& other) { s = other.s; return *this; }
    int length() { return s.length(); }
    void clear() { s = ""; }
    String operator+(const String& other) { return String((s + other.s).c_str()); }
    String& operator+=(const String& other) { s += other.s; return *this; }
    bool operator==(const String& other) { return s == other.s; }
    bool operator!=(const String& other) { return s != other.s; }
    ~String() {}
    void Show() { cout << s << endl; }
};

class BitString : public String {
public:
    BitString() : String() {}
    BitString(const char* str) {
        bool ok = true;
        for (int i = 0; str[i]; i++)
            if (str[i] != '0' && str[i] != '1') ok = false;
        s = ok ? str : "";
    }
    BitString(const BitString& other) : String(other) {}
    BitString& operator=(const BitString& other) { s = other.s; return *this; }
    ~BitString() {}

    void invert() {
        for (int i = 0; i < s.size(); i++)
            s[i] = (s[i] == '0' ? '1' : '0');
        int carry = 1;
        for (int i = s.size() - 1; i >= 0 && carry; i--) {
            if (s[i] == '1') { s[i] = '0'; carry = 1; }
            else { s[i] = '1'; carry = 0; }
        }
    }

    BitString operator+(const BitString& other) {
        string a = s, b = other.s, r = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            r = char(sum % 2 + '0') + r;
            carry = sum / 2;
        }
        return BitString(r.c_str());
    }

    BitString& operator+=(const BitString& other) { *this = *this + other; return *this; }
    bool operator==(const BitString& other) { return s == other.s; }
    bool operator!=(const BitString& other) { return s != other.s; }
};

int main() {
    String a("Hello"), b("World");
    String c = a + b;
    c.Show();

    BitString x("1011"), y("0110"), z;
    z = x + y;
    z.Show();

    x.invert();
    x.Show();
    return 0;
}
