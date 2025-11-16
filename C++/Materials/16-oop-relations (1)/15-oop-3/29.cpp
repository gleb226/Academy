#include <iostream>

class Accumulator
{
private:
    int m_counter = 0;

public:
    Accumulator()
    {
    }

    int operator() (int i) { return (m_counter += i); }
};

int main()
{
    Accumulator accum;
    std::cout << accum(30) << std::endl; // виведеться 30
    std::cout << accum(40) << std::endl; // виведеться 70

    return 0;
}