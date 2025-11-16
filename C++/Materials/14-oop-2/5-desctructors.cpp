#include <iostream>

class Another
{
private:
    int m_nID;

public:
    Another(int nID)
    {
        std::cout << "Constructing Another " << nID << '\n';
        m_nID = nID;
    }

    ~Another()
    {
        std::cout << "Destructing Another " << m_nID << '\n';
    }

    int getID() { return m_nID; }
};

int main()
{
    // Виділяємо об'єкт класу Another зі стеку
    Another object(1);
    std::cout << object.getID() << '\n';

    // Виділяємо об'єкт класу Another динамічно з купи
    Another* pObject = new Another(2);
    std::cout << pObject->getID() << '\n';
    delete pObject;

    return 0;
} // об'єкт object виходить з області видимості тут