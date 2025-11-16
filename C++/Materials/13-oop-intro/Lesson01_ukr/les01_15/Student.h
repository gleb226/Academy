#pragma once

class Student
{
private:
    // ПІБ
    char* name;
    // кількість оцінок
    int markCount;
    // оцінки
    int* marks;

    // службові функції
    void createName(const char* studentName);

public:
    // конструктори
    Student();

    Student(const char* studentName,
        const int studentMarkCount);

    Student(const char* studentName,
        const int studentMarkCount,
        const int* studentMarks);

    // зчитування закритих членів класу
    const char* getName()
    {
        return name;
    }

    int getMark(int index)
    {
        return marks[index];
    }

    // запис закритих членів класу
    void setName(const char* studentName);
    void setMark(int mark, int index);

    // обчислення среднього бала
    double getAver();

    // деструктор
    ~Student();
};


