#include <iostream>

struct Triangle
{
    double length = 2.0;
    double width = 2.0;
};

int main()
{
    Triangle z; // довжина = 2.0, ширина = 2.0

    z.length = 3.0; // ви також можете присвоювати членам структури і інші значення

    return 0;
}