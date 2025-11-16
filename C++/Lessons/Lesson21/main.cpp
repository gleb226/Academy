#include <iostream>
using namespace std;

class Ball {
private:
    string color = "Red";
    int radius = 20;
public:
    Ball(const string& color) {
        this->color = color;
    }

    Ball(int& radius) {
        this->radius = radius;
    }
    Ball(const string& color, const int& radius) {
        this->color = color;
        this->radius = radius;
    }
    Ball() {
        color = "Red";
        radius = 20;
    }

    void print() {
        cout << color << "Ball " << radius << " color " << color << "radius " << radius << endl;
    }
};
int main() {
    Ball ball("Black", 40);
    ball.print();
}