
#include <iostream>
#include <cassert> // для assert()

class Matrix
{
private:
    double data[5][5];
public:
    Matrix()
    {
        // Присвоюємо всім елементам масиву значення 0.0
        for (int row = 0; row < 5; ++row)
            for (int col = 0; col < 5; ++col)
                data[row][col] = 0.0;
    }

    double& operator()(int row, int col);
    const double& operator()(int row, int col) const; // для константних об'єктів
};

double& Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 5);
    assert(row >= 0 && row < 5);

    return data[row][col];
}

const double& Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 5);
    assert(row >= 0 && row < 5);

    return data[row][col];
}

int main()
{
    Matrix matrix;
    matrix(2, 3) = 3.6;
    std::cout << matrix(2, 3);

    return 0;
}