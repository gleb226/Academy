#include <iostream>

class IntArray
{
private:
    int m_array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // вказуємо початкові значення

public:
    int& operator[] (const int index);
    const int& operator[] (const int index) const;
};

int& IntArray::operator[] (const int index) // для неконстантних об'єктів: може використовуватися як для присвоювання значень елементам, так і для їх перегляду
{
    return m_array[index];
}

const int& IntArray::operator[] (const int index) const // для константних об'єктів: використовується тільки для перегляду (виводу) елементів масиву
{
    return m_array[index];
}

int main()
{
    IntArray array;
    array[4] = 5; // добре: викликається неконстантна версія operator[]()
    std::cout << array[4];

    const IntArray carray;
    carray[4] = 5; // помилка компіляції: викликається константна версія operator[](), яка повертає константне посилання. Виконувати операцію присвоювання заборонено
    std::cout << carray[4];

    return 0;
}