#include <iostream>
#include "Student.h"
using namespace std;

// конструктор
Student::Student()
{
    // присвоєння імені
    name = nullptr;

    // присвоєння списку оцінок
    marks = nullptr;
    markCount = 0;
}

// конструктор
Student::Student(const char* studentName,
    const int studentMarkCount)
{
    // присвоєння імені
    createName(studentName);

    // присвоєння списку оцінок
    marks = new int[studentMarkCount];
    for (int i = 0; i < studentMarkCount; i++)
    {
        marks[i] = 0;
    }
    markCount = studentMarkCount;
}

// конструктор
Student::Student(const char* studentName,
    const int studentMarkCount,
    const int* studentMarks)
{
    // присвоєння імені
    createName(studentName);

    // присвоєння списку оцінок
    marks = new int[studentMarkCount];
    for (int i = 0; i < studentMarkCount; i++)
    {
        marks[i] = studentMarks[i];
    }
    markCount = studentMarkCount;
}

// присвоєння імені
void Student::createName(const char* studentName)
{
    int nameLength = strlen(studentName);
    name = new char[nameLength + 1];
    for (int i = 0; i <= nameLength; i++)
    {
        name[i] = studentName[i];
    }
}

// запис імені
void Student::setName(const char* studentName)
{
    delete[] name;
    createName(studentName);
}

// запис елементів масиву marks
void Student::setMark(int mark, int index)
{
    // перевірка індексу
    if (index < 0 or index >= markCount)
    {
        return;
    }

    // присвоєння з перевіркою оцінки
    if (mark < 1 or mark > 12)
    {
        mark = 0;
    }
    marks[index] = mark;
}

// реалізація методу обчислення середнього бала
double Student::getAver()
{
    double sum = 0;
    for (int i = 0; i < markCount; i++)
    {
        sum += marks[i];
    }
    return sum / markCount;
}
