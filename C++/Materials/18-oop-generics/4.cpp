template <>
class Repository8<bool> // спеціалізуємо шаблон класу Repository8 для роботи з типом bool
{
    // Реалізація класу
private:
    unsigned char m_data;

public:
    Repository8() : m_data(0)
    {
    }

    void set(int index, bool value)
    {
        // Вибираємо оперований біт
        unsigned char mask = 1 << index;

        if (value) // якщо на вході у нас true, то біт потрібно "увімкнути"
            m_data |= mask; // використовуємо побітове АБО, щоб "увімкнути" біт
        else // якщо на вході у нас false, то біт потрібно "вимкнути" 
            m_data &= ~mask; // використовуємо побітове І, щоб "вимкнути" біт
    }

    bool get(int index)
    {
        // Вибираємо біт
        unsigned char mask = 1 << index;

        // Використовуємо побітове І для отримання значення біта, а потім виконується його неявна конвертація в тип bool
        return (m_data & mask) != 0;
    }
};