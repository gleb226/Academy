#include <iostream>

class Values; // попереднє оголошення класу Values

class Display
{
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void displayItem(Values& value); // вищенаведене попереднє оголошення необхідне для цього рядка
};

class Values // повне визначення класу Values
{
private:
    int m_intValue;
    double m_dValue;
public:
    Values(int intValue, double dValue)
    {
        m_intValue = intValue;
        m_dValue = dValue;
    }

    // Робимо метод Display::displayItem() другом класу Values
    friend void Display::displayItem(Values& value);
};

// Тепер ми можемо визначити метод Display::displayItem(), якому потрібно побачити повне визначення класу Values
void Display::displayItem(Values& value)
{
    if (m_displayIntFirst)
        std::cout << value.m_intValue << " " << value.m_dValue << '\n';
    else // або виводимо спочатку double
        std::cout << value.m_dValue << " " << value.m_intValue << '\n';
}

int main()
{
    Values value(7, 8.4);
    Display display(false);

    display.displayItem(value);

    return 0;
}