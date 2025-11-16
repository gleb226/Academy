class Anything
{
public:
    int value;

    Anything() { value = 0; }

    void resetValue() { value = 0; }
    void setValue(int value) { value = value; }

    int getValue() const { return value; } // ключове слово const знаходиться після списку параметрів, але перед тілом функції
};