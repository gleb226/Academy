#ifndef ARRAY_H
#define ARRAY_H

#include <assert.h> // для assert()

template <class T> // це шаблон класу з T замість фактичного (переданого) типу даних
class Array
{
private:
    int m_length;
    T* m_data;

public:
    Array()
    {
        m_length = 0;
        m_data = nullptr;
    }

    Array(int length)
    {
        m_data = new T[length];
        m_length = length;
    }

    ~Array()
    {
        delete[] m_data;
    }

    void Erase()
    {
        delete[] m_data;
        // Присвоюємо значення nullptr для m_data, щоб на виході не отримати висячий вказівник!
        m_data = nullptr;
        m_length = 0;
    }


    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // Довжина масиву завжди є цілочисельним значенням, вона не залежить від типу елементів масиву
    int getLength(); // визначаємо метод і шаблон методу getLength() нижче
};

template <typename T> // метод, визначений поза тілом класу, потребує власного визначення шаблону методу
int Array<T>::getLength() { return m_length; } // зверніть увагу, ім'я класу - Array<T>, а не просто Array

#endif