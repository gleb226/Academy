#include <iostream>
#include <string>
using namespace std;

class var {
    enum Type { INT, DOUBLE, STRING, NONE } type;

    int i;
    double d;
    string s;

public:
    var() { type = NONE; }

    var(int v) {
        i = v;
        type = INT;
    }

    var(double v) {
        d = v;
        type = DOUBLE;
    }

    var(const char *v) {
        s = v;
        type = STRING;
    }

    var(const string &v) {
        s = v;
        type = STRING;
    }

    var operator+(const var &v) {
        var res;
        if (type == STRING) res = var(s + v.toString());
        else if (type == INT) res = var(i + v.toInt());
        else if (type == DOUBLE) res = var(d + v.toDouble());
        return res;
    }

    var operator-(const var &v) {
        var res;
        if (type == STRING) res = var("");
        else if (type == INT) res = var(i - v.toInt());
        else if (type == DOUBLE) res = var(d - v.toDouble());
        return res;
    }

    var operator*(const var &v) {
        var res;
        if (type == STRING) {
            string r = "";
            string a = s;
            string b = v.toString();
            for (char c: a) if (b.find(c) != string::npos) r += c;
            res = var(r);
        } else if (type == INT) res = var(i * v.toInt());
        else if (type == DOUBLE) res = var(d * v.toDouble());
        return res;
    }

    var operator/(const var &v) {
        var res;
        if (type == STRING) {
            string r = "";
            string a = s;
            string b = v.toString();
            for (char c: a) if (b.find(c) == string::npos) r += c;
            res = var(r);
        } else if (type == INT) res = var(i / v.toInt());
        else if (type == DOUBLE) res = var(d / v.toDouble());
        return res;
    }

    var &operator+=(const var &v) {
        *this = *this + v;
        return *this;
    }

    var &operator-=(const var &v) {
        *this = *this - v;
        return *this;
    }

    var &operator*=(const var &v) {
        *this = *this * v;
        return *this;
    }

    var &operator/=(const var &v) {
        *this = *this / v;
        return *this;
    }

    bool operator==(const var &v) {
        if (type == STRING) return s == v.toString();
        if (type == INT) return i == v.toInt();
        if (type == DOUBLE) return d == v.toDouble();
        return false;
    }

    bool operator!=(const var &v) { return !(*this == v); }

    operator int() { return toInt(); }
    operator double() { return toDouble(); }
    operator string() { return toString(); }

    int toInt() const {
        if (type == INT) return i;
        if (type == DOUBLE) return (int) d;
        if (type == STRING) return stoi(s);
        return 0;
    }

    double toDouble() const {
        if (type == DOUBLE) return d;
        if (type == INT) return i;
        if (type == STRING) return stod(s);
        return 0.0;
    }

    string toString() const {
        if (type == STRING) return s;
        if (type == INT) return to_string(i);
        if (type == DOUBLE) return to_string(d);
        return "";
    }

    void Show() {
        if (type == STRING) cout << s << endl;
        else if (type == INT) cout << i << endl;
        else if (type == DOUBLE) cout << d << endl;
    }
};

int main() {
    var a = 10, b = "120", c;
    c = a + b;
    c.Show();
    c = b + a;
    c.Show();
    var x = "Microsoft", y = "Windows", z;
    z = x * y;
    z.Show();
    z = x / y;
    z.Show();
    return 0;
}
