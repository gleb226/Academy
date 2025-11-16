// Обчислити середню оцінку студентів
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
    cout << "Успішність студентів."
        << endl << endl;

    // размір масиву об’єктів
    const int size = 2;

    // створення й ініціалізація 
    // динамічного масиву об’єктів
    Student* students = new Student[size]
    {
        {"Студент 1", 3, new int[3]{ 10, 10, 9 }},
        {"Студент 2", 3, new int[3]{ 8, 10, 8 }}
    };

    // робота з масивом об’єктів
    double sum = 0;
    for (Student* stud = students;
        stud < students + size; stud++)
    {
        double aver = stud->getAver();
        cout << "Середній бал " << stud->getName()
            << " : " << fixed << setprecision(2)
            << aver << endl;
        sum += aver;
    }

    cout << endl;
    cout << "Середній бал в групі: "
        << " : " << fixed << setprecision(2)
        << sum / size << endl;

    delete[] students;
    _getch();
    return 0;
}
