#include <iostream>

class Point
{
private:
    double m_x, m_y, m_z;

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z)
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point);
    friend std::istream& operator>> (std::istream& in, Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Оскільки operator<< є другом класу Point, то ми маємо прямий доступ до членів Point
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";

    return out;
}

std::istream& operator>> (std::istream& in, Point& point)
{
    // Оскільки operator>> є другом класу Point, то ми маємо прямий доступ до членів Point.
    // Зверніть увагу, параметр point (об'єкт класу Point) повинен бути неконстантним, щоб ми мали можливість змінити члени класу
    in >> point.m_x;
    in >> point.m_y;
    in >> point.m_z;

    return in;
}