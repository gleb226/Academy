#pragma once

class Student
{
private:
    // ПІБ
    char name[21];
    // оцінки
    int marks[3];
public:
    // обчислення середнього бала
    double getAver();

    // доступ до поля name
    const char* getName();
    void setName(const char* studentName);
    // доступ до елементів масиву marks
    int getMark(int index);
    void setMark(int mark, int index);
};


