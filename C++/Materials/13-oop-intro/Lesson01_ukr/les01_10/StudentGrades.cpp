// Обчислити середню оцінку студента

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
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
    student.setName("Петренко А.О.");
    student.setMark(10, 0);
    student.setMark(10, 1);
    student.setMark(9, 2);

    // виконання методу об’єкта
    cout << "Середній бал " << student.getName()
        << " : " << fixed << setprecision(2)
        << student.getAver() << endl;

    _getch();
    return 0;
}
