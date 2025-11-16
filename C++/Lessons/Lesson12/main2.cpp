#include <iostream>

struct Advertasing
{
    int numAdds;
    int percentClicks;
    int avarageClicks;
};

void print(Advertasing a)
{
    std::cout << a.numAdds << " " << a.percentClicks << " " << a.avarageClicks << std::endl;
}

void printSalary(Advertasing a)
{
    std::cout << "Salary: " << a.avarageClicks * a.numAdds * a.percentClicks << std::endl;
}


int main()
{
    Advertasing a {3, 50, 100};
    print(a);
    printSalary(a);
    return 0;
}
