#include <iostream>
using namespace std;

const int SIZE = 4;

void initMatrix(int mat[SIZE][SIZE])
{
    int val = 1;
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            mat[i][j] = val++;
}

void initMatrix(double mat[SIZE][SIZE])
{
    double val = 1.1;
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            mat[i][j] = val++;
}

void initMatrix(char mat[SIZE][SIZE])
{
    char val = 'A';
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
        {
            mat[i][j] = val;
            val++;
            if (val > 'Z') val = 'A';
        }
}

void printMatrix(int mat[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

void printMatrix(double mat[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

void printMatrix(char mat[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

void minMaxDiag(int mat[SIZE][SIZE])
{
    int minVal = mat[0][0], maxVal = mat[0][0];
    for (int i = 1; i < SIZE; ++i)
    {
        if (mat[i][i] < minVal) minVal = mat[i][i];
        if (mat[i][i] > maxVal) maxVal = mat[i][i];
    }
    cout << "Min: " << minVal << ", Max: " << maxVal << "\n";
}

void minMaxDiag(double mat[SIZE][SIZE])
{
    double minVal = mat[0][0], maxVal = mat[0][0];
    for (int i = 1; i < SIZE; ++i)
    {
        if (mat[i][i] < minVal) minVal = mat[i][i];
        if (mat[i][i] > maxVal) maxVal = mat[i][i];
    }
    cout << "Min: " << minVal << ", Max: " << maxVal << "\n";
}

void minMaxDiag(char mat[SIZE][SIZE])
{
    char minVal = mat[0][0], maxVal = mat[0][0];
    for (int i = 1; i < SIZE; ++i)
    {
        if (mat[i][i] < minVal) minVal = mat[i][i];
        if (mat[i][i] > maxVal) maxVal = mat[i][i];
    }
    cout << "Min: " << minVal << ", Max: " << maxVal << "\n";
}

void sortRows(int mat[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE - 1; ++j)
            for (int k = j + 1; k < SIZE; ++k)
                if (mat[i][j] > mat[i][k])
                    swap(mat[i][j], mat[i][k]);
}

void sortRows(double mat[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE - 1; ++j)
            for (int k = j + 1; k < SIZE; ++k)
                if (mat[i][j] > mat[i][k])
                    swap(mat[i][j], mat[i][k]);
}

void sortRows(char mat[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE - 1; ++j)
            for (int k = j + 1; k < SIZE; ++k)
                if (mat[i][j] > mat[i][k])
                    swap(mat[i][j], mat[i][k]);
}

// int main()
// {
//     int intMatrix[SIZE][SIZE];
//     double doubleMatrix[SIZE][SIZE];
//     char charMatrix[SIZE][SIZE];
//
//     initMatrix(intMatrix);
//     printMatrix(intMatrix);
//     minMaxDiag(intMatrix);
//     sortRows(intMatrix);
//     printMatrix(intMatrix);
//
//     initMatrix(doubleMatrix);
//     printMatrix(doubleMatrix);
//     minMaxDiag(doubleMatrix);
//     sortRows(doubleMatrix);
//     printMatrix(doubleMatrix);
//
//     initMatrix(charMatrix);
//     printMatrix(charMatrix);
//     minMaxDiag(charMatrix);
//     sortRows(charMatrix);
//     printMatrix(charMatrix);
//
//     return 0;
// }
