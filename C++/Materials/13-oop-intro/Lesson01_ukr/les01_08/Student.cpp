#include "Student.h"
using namespace std;

// реализація методу обчислення среднього бала
double Student::getAver()
{
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += marks[i];
    }
    return sum / 3;
}


