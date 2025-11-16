// les01_05.cpp
// Обчислити середній бал студента

#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

// визначення класу Студент
class Student
{
public:
    // ПІБ
    char name[21];
    // оцінки
    int marks[3];
};

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

    // отримання значень об’єкта
    cout << student.name << " : "
        << student.marks[0] << endl;

    _getch();
    return 0;
}


