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

    // створення об’єкта із заданими значеннями
    Student student("Петренко А.О.", 3,
        new int[3]{ 10, 10, 9 });

    // виконання методу об’єкта
    cout << "Середній бал " << student.getName()
        << " : " << fixed << setprecision(2)
        << student.getAver() << endl;

    _getch();
    return 0;
}
