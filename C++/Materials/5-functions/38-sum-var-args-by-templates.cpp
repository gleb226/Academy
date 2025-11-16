#include <iostream>

template<typename T>
T SUM(T v)
{
    return v;
}

template<typename T, typename T1, typename... Ts>
T SUM(T v, T1 v1, Ts... vs)
{
    return v + SUM(v1, vs...);
}

int main(int argc, char**)
{
    std::cout << SUM(2, 2) << std::endl;
    std::cout << SUM(argc, 1, 2, 3) << std::endl;
}