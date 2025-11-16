#include <iostream>
#include "Student.h"
using namespace std;

// реалізація методу обчислення среднього бала
double Student::getAver()
{
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += marks[i];
    }
    return sum / 3;
}

// доступ до поля name 
// без можливості його зміни
const char* Student::getName()
{
    return name;
}

void Student::setName(const char* studentName)
{
    // присвоювання з перевіркою довжини
    strcpy_s(name, 20, studentName);
}

// доступ до елементів масиву marks
int Student::getMark(int index)
{
    return marks[index];
}

void Student::setMark(int mark, int index)
{
    // присвоювання з перевіркою оцінки
    if (mark < 1 or mark > 12)
    {
        mark = 0;
    }
    marks[index] = mark;
}
