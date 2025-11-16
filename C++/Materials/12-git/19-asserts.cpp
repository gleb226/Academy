#include <cassert> // для assert()

int getArrayValue(const std::array<int, 10>& array, int index)
{
    // Припускається, що значення index знаходиться між 0 і 8
    assert(index >= 0 && index <= 8); // це рядок 6 в Program.cpp

    return array[index];
}