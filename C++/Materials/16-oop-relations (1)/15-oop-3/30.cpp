#include <iostream>
#include <string>

class Mystring
{
private:
    std::string m_string;

public:
    Mystring(const std::string string = "")
        :m_string(string)
    {
    }

    std::string operator()(int index1, int length)
    {
        std::string ret;
        for (int count = 0; count < length; ++count)
            ret += m_string[index1 + count];
        return ret;
    }
};

int main()
{
    Mystring string("Hello, world!");
    std::cout << string(7, 6); // починаємо з 7-го символу (індексу) і повертаємо наступні 6 символів

    return 0;
}