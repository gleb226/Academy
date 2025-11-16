#pragma once

class Student
{
private:
    // ПІБ
    char name[21];
    // оцінки
    int marks[3];
public:
    // зчитування закритих членів класу
    const char* getName()
    {
        return name;
    }

    int getMark(int index)
    {
        return marks[index];
    }

    // запис закритих членів у
    void setName(const char* studentName);
    void setMark(int mark, int index);

    // обчислення среднього бала
    double getAver();
};


