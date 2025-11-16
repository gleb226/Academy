#include <iostream>

class SomeString
{
private:
    char* m_data;
    int m_length;

public:
    SomeString(const char* data = "", int length = 0) :
        m_length(length)
    {
        if (!length)
            m_data = nullptr;
        else
            m_data = new char[length];

        for (int i = 0; i < length; ++i)
            m_data[i] = data[i];
    }


    SomeString& operator= (const SomeString& str);

    friend std::ostream& operator<<(std::ostream& out, const SomeString& s);
};

std::ostream& operator<<(std::ostream& out, const SomeString& s)
{
    out << s.m_data;
    return out;
}

// Перевантаження оператора присвоювання (поганий варіант перевантаження)
SomeString& SomeString::operator= (const SomeString& str)
{
    // Якщо m_data вже має значення, то видаляємо це значення
    if (m_data) delete[] m_data;

    m_length = str.m_length;

    // Копіюємо значення з str в m_data неявного об'єкта
    m_data = new char[str.m_length];
    for (int i = 0; i < str.m_length; ++i)
        m_data[i] = str.m_data[i];

    // Повертаємо поточний об'єкт
    return *this;
}

int main()
{
    SomeString anton("Anton", 7);
    SomeString employee;
    employee = anton;
    std::cout << employee;

    return 0;
}