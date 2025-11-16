// Обчислення середньої оцінки студента

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;

// визначення класу Студент
class Student
{
public:
    // ПІБ
    char name[21];
    // оцінки
    int marks[3];
    // обчислення середнього бала
    double getAver();
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
    strcpy_s(student.name, 20, "Петренко А.О.");
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

// реалізація методу обчислення середнього бала
double Student::getAver()
{
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += marks[i];
    }
    return sum / 3;
}
