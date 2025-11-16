#pragma once

class Student
{
private:
    // ПІБ
    char name[21];
    // оцінки
    int marks[3];
public:
    // конструктор
    Student()
    {
        std::cout << "Конструктор Student"
            << std::endl;
    }

    // читання закритих членнів класу
    const char* getName()
    {
        return name;
    }

    int getMark(int index)
    {
        return marks[index];
    }

    // запис закритих членнів класу
    void setName(const char* studentName);
    void setMark(int mark, int index);

    // обчислення среднього бала
    double getAver();
};


