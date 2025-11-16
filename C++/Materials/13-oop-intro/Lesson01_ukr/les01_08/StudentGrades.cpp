// Обчислити середню оцінку студента

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Student.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Успішність студента."
        << endl << endl;

    // визначення об’єкта
    Student student;

    // присвоєння значень об’єкту
    strcpy_s(student.name, 20, "Петренко А.О");
    student.marks[0] = 10;
    student.marks[1] = 10;
    student.marks[2] = 9;

    // виконання методу об’єкта
    double aver = student.getAver();

    cout << "Середній бал " << student.name
        << " : " << fixed << setprecision(2)
        << aver << endl;

    _getch();
    return 0;
}
