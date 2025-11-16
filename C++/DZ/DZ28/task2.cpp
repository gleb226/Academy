#include <iostream>
#include <fstream>
using namespace std;

class Shape {
public:
    virtual void Show() = 0;

    virtual void Save(ofstream &f) = 0;

    virtual void Load(ifstream &f) = 0;

    virtual ~Shape() {
    }
};

class Square : public Shape {
    int x, y, side;

public:
    Square() : x(0), y(0), side(0) {
    }

    Square(int _x, int _y, int _s) : x(_x), y(_y), side(_s) {
    }

    void Show() override { cout << "Square at (" << x << "," << y << ") side=" << side << endl; }
    void Save(ofstream &f) override { f << "S " << x << " " << y << " " << side << endl; }
    void Load(ifstream &f) override { f >> x >> y >> side; }
};

class Rectangle : public Shape {
    int x, y, w, h;

public:
    Rectangle() : x(0), y(0), w(0), h(0) {
    }

    Rectangle(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {
    }

    void Show() override { cout << "Rectangle at (" << x << "," << y << ") w=" << w << " h=" << h << endl; }
    void Save(ofstream &f) override { f << "R " << x << " " << y << " " << w << " " << h << endl; }
    void Load(ifstream &f) override { f >> x >> y >> w >> h; }
};

class Circle : public Shape {
    int cx, cy, r;

public:
    Circle() : cx(0), cy(0), r(0) {
    }

    Circle(int _cx, int _cy, int _r) : cx(_cx), cy(_cy), r(_r) {
    }

    void Show() override { cout << "Circle at (" << cx << "," << cy << ") r=" << r << endl; }
    void Save(ofstream &f) override { f << "C " << cx << " " << cy << " " << r << endl; }
    void Load(ifstream &f) override { f >> cx >> cy >> r; }
};

class Ellipse : public Shape {
    int x, y, w, h;

public:
    Ellipse() : x(0), y(0), w(0), h(0) {
    }

    Ellipse(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {
    }

    void Show() override { cout << "Ellipse at (" << x << "," << y << ") w=" << w << " h=" << h << endl; }
    void Save(ofstream &f) override { f << "E " << x << " " << y << " " << w << " " << h << endl; }
    void Load(ifstream &f) override { f >> x >> y >> w >> h; }
};

int main() {
    Shape *shapes[4];
    shapes[0] = new Square(0, 0, 5);
    shapes[1] = new Rectangle(1, 1, 4, 6);
    shapes[2] = new Circle(2, 2, 3);
    shapes[3] = new Ellipse(3, 3, 6, 4);

    ofstream fout("shapes.txt");
    for (int i = 0; i < 4; i++) shapes[i]->Save(fout);
    fout.close();

    Shape *loaded[4];
    ifstream fin("shapes.txt");
    for (int i = 0; i < 4; i++) {
        char type;
        fin >> type;
        if (type == 'S') loaded[i] = new Square();
        else if (type == 'R') loaded[i] = new Rectangle();
        else if (type == 'C') loaded[i] = new Circle();
        else if (type == 'E') loaded[i] = new Ellipse();
        loaded[i]->Load(fin);
    }
    fin.close();

    for (int i = 0; i < 4; i++) loaded[i]->Show();

    for (int i = 0; i < 4; i++) delete shapes[i];
    for (int i = 0; i < 4; i++) delete loaded[i];

    return 0;
}
