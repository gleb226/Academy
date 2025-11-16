// Обчислити середню оцінку студента
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

// максимальна довжина імені
const int maxNameLength = 20;

// кількість оцінок
const int markCount = 3;

// визначення структури даних 
// ------------------------------------
// Студент
struct Student
{
    // ПІБ 
    char name[maxNameLength];

    // оцінки 
    int marks[markCount];
};
// ------------------------------------
// кінець визначення структури даних

// функції опрацювання структури даних
// ------------------------------------
// заповнення даних про студента
void initStudent(Student& student, const char* name, const int marks[])
{
    strcpy_s(student.name, maxNameLength, name);
    for (int i = 0; i < markCount; i++)
    {
        student.marks[i] = marks[i];
    }
}

// обчислення середньої оцінки
double averMark(Student student)
{
    double sum = 0;
    for (int i = 0; i < markCount; i++)
    {
        sum += student.marks[i];
    }
    return sum / markCount;
}

// виведення даних про студента
void printStudent(Student student)
{
    cout << student.name << endl;
    cout << "Оцінки: ";
    for (int i = 0; i < markCount; i++)
    {
        cout << setw(4) << student.marks[i];
    }
    cout << endl;
}
// ------------------------------------
// кінець списку функцій опрацювання структури даних

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Успішність студента."
        << endl << endl;
    Student student;
    const char* studentName{ "Петренко А.О." };
    int studentMarks[]{ 4, 4, 3 };

    initStudent(student, studentName, studentMarks);
    printStudent(student);

    cout << "Середній бал: "
        << fixed << setprecision(2)
        << averMark(student) << endl;

    _getch();
    return 0;
}
