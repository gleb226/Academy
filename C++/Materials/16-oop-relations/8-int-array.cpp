#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert> // для assert()

class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() :
        m_length(0), m_data(nullptr)
    {
    }

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        // Тут потрібно вказати m_data значення nullptr, щоб на виході не було висячого вказівника
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // Функція reallocate() змінює розмір масиву. Всі існуючі елементи всередині масиву будуть знищені. Процес швидкий
    void reallocate(int newLength)
    {
        // Видаляємо всі існуючі елементи всередині масиву
        erase();

        // Якщо наш масив повинен бути пустим, то виконуємо повернення тут
        if (newLength <= 0)
            return;

        // Потім виділяємо нові елементи
        m_data = new int[newLength];
        m_length = newLength;
    }

    // Функція resize() змінює розмір масиву. Всі існуючі елементи зберігаються. Процес повільний
    void resize(int newLength)
    {
        // Якщо масив потрібної довжини, то виконуємо return
        if (newLength == m_length)
            return;

        // Якщо потрібно зробити масив пустим, то робимо це і потім виконуємо return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Тепер припустимо, що newLength складається, принаймні, з одного елементу. Виконується наступний алгоритм дій:
        // 1. Виділяємо новий масив.
        // 2. Копіюємо елементи з існуючого масиву в наш щойно виділений масив.
        // 3. Знищуємо старий масив і даємо команду m_data вказувати на новий масив.

        // Виділяємо новий масив
        int* data = new int[newLength];

        // Потім нам потрібно розібратися з кількістю скопійованих елементів в новий масив.
        // Нам потрібно скопіювати стільки елементів, скільки їх є в меншому з масивів
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // Почергово копіюємо елементи
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        // Видаляємо старий масив, тому що він нам вже не потрібний
        delete[] m_data;

        // І використовуємо замість старого масиву новий! Зверніть увагу, m_data вказує на ту ж адресу, на яку вказує наш новий динамічно виділений масив.
        // Оскільки дані були динамічно виділені, то вони не будуть знищені, коли вийдуть з області видимості
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // Перевірка коректності переданого індексу
        assert(index >= 0 && index <= m_length);

        // Створюємо новий масив на один елемент більше старого масиву
        int* data = new int[m_length + 1];

        // Копіюємо всі елементи аж до index
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // Додаємо наш новий елемент в наш новий масив
        data[index] = value;

        // Копіюємо всі значення після доданого елементу
        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        // Видаляємо старий масив і використовуємо замість нього новий масив
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index)
    {
        // Перевірка на коректність переданого індексу
        assert(index >= 0 && index < m_length);

        // Якщо це останній елемент масиву, то робимо масив пустим і виконуємо return
        if (m_length == 1)
        {
            erase();
            return;
        }

        // Створюємо новий масив на один елемент менше нашого старого масиву
        int* data = new int[m_length - 1];

        // Копіюємо всі елементи аж до index
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // Копіюємо всі значення після видаленого елементу
        for (int after = index + 1; after < m_length; ++after)
            data[after - 1] = m_data[after];

        // Видаляємо старий масив і використовуємо замість нього новий масив
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    // Декілька додаткових функцій просто для зручності
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }

    int getLength() { return m_length; }
};

#endif