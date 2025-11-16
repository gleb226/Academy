#include <iostream>
using namespace std;

template<typename T>
class Matrix {
    int rows, cols;
    T **data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T *[rows];
        for (int i = 0; i < rows; i++) data[i] = new T[cols]();
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
    }

    void Input() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
    }

    void Print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) cout << data[i][j] << " ";
            cout << endl;
        }
    }

    Matrix<T> operator+(Matrix<T> &m) {
        Matrix<T> res(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                res.data[i][j] = data[i][j] + m.data[i][j];
        return res;
    }

    Matrix<T> operator-(Matrix<T> &m) {
        Matrix<T> res(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                res.data[i][j] = data[i][j] - m.data[i][j];
        return res;
    }

    Matrix<T> operator*(Matrix<T> &m) {
        Matrix<T> res(rows, m.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < m.cols; j++) {
                res.data[i][j] = 0;
                for (int k = 0; k < cols; k++) res.data[i][j] += data[i][k] * m.data[k][j];
            }
        return res;
    }

    Matrix<T> operator/(T val) {
        Matrix<T> res(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                res.data[i][j] = data[i][j] / val;
        return res;
    }

    T Max() {
        T mx = data[0][0];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (data[i][j] > mx) mx = data[i][j];
        return mx;
    }

    T Min() {
        T mn = data[0][0];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (data[i][j] < mn) mn = data[i][j];
        return mn;
    }
};

int main() {
    Matrix<int> m1(2, 2), m2(2, 2);
    cout << "Enter elements for matrix 1:\n";
    m1.Input();
    cout << "Enter elements for matrix 2:\n";
    m2.Input();

    cout << "Matrix 1:\n";
    m1.Print();
    cout << "Matrix 2:\n";
    m2.Print();

    Matrix<int> sum = m1 + m2;
    cout << "Sum:\n";
    sum.Print();

    Matrix<int> prod = m1 * m2;
    cout << "Product:\n";
    prod.Print();

    cout << "Max of m1: " << m1.Max() << endl;
    cout << "Min of m1: " << m1.Min() << endl;

    return 0;
}
