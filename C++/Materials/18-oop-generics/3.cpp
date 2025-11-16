#include <iostream>

template <class T, int size> // size є параметром non-type в шаблоні класу
class StaticArray
{
private:
    // Параметр non-type в шаблоні класу відповідає за розмір виділеного масиву
    T m_array[size];

public:
    T* getArray();

    T& operator[](int index)
    {
        return m_array[index];
    }
};

// Синтаксис визначення шаблону методу і самого методу поза тілом класу з параметром non-type
template <class T, int size>
T* StaticArray<T, size>::getArray()
{
    return m_array;
}

int main()
{
    // Оголошуємо цілочисельний масив з 10 елементів
    StaticArray<int, 10> intArray;

    // Заповнюємо масив значеннями
    for (int count = 0; count < 10; ++count)
        intArray[count] = count;

    // Виводимо елементи масиву у зворотному порядку
    for (int count = 9; count >= 0; --count)
        std::cout << intArray[count] << " ";
    std::cout << '\n';

    // Оголошуємо масив типу double з 5 елементів
    StaticArray<double, 5> doubleArray;

    // Заповнюємо масив значеннями
    for (int count = 0; count < 5; ++count)
        doubleArray[count] = 5.5 + 0.1 * count;

    // Виводимо елементи масиву
    for (int count = 0; count < 5; ++count)
        std::cout << doubleArray[count] << ' ';

    return 0;
}