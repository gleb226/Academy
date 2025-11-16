#include <iostream>

template<class T>
class Auto_ptr1
{
    T* m_ptr;
public:
    // Отримуємо вказівник для "володіння" через конструктор
    Auto_ptr1(T* ptr = nullptr)
        :m_ptr(ptr)
    {
    }

    // Деструктор подбає про видалення вказівника
    ~Auto_ptr1()
    {
        delete m_ptr;
    }

    // Виконуємо перевантаження оператора розіменування і оператора ->, щоб мати можливість використовувати Auto_ptr1 як m_ptr
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};

// Клас для перевірки працездатності вищенаведеного коду
class Item
{
public:
    Item() { std::cout << "Item acquired\n"; }
    ~Item() { std::cout << "Item destroyed\n"; }
};

int main()
{
    Auto_ptr1<Item> item(new Item); // динамічне виділення пам'яті

    // ... але ніякого явного delete тут не потрібно

// Також зверніть увагу на те, що Item-у в кутових дужках не потрібен символ *, оскільки це надається шаблоном класу

    return 0;
} // item виходить з області видимості тут і знищує виділений Item замість нас
