class Mathem
{
private:
    int m_value = 0;

public:
    Mathem(int value = 0);

    Mathem& add(int value);
    Mathem& sub(int value);
    Mathem& divide(int value);

    int getValue() { return m_value; }
};

Mathem::Mathem(int value) : m_value(value)
{
}

Mathem& Mathem::add(int value)
{
    m_value += value;
    return *this;
}

Mathem& Mathem::sub(int value)
{
    m_value -= value;
    return *this;
}

Mathem& Mathem::divide(int value)
{
    m_value /= value;
    return *this;
}