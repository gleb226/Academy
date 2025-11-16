#include <iostream>

using namespace std;

int* allocate(size_t capacity)
{
    return new(nothrow) int[capacity];
}

bool init(int*& arr, size_t& size, size_t& capacity, size_t initial_capacity)
{
    arr = allocate(initial_capacity);
    if (!arr) return false;
    size = 0;
    capacity = initial_capacity;
    return true;
}

void print(const int* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i) cout << arr[i] << ' ';
    cout << '\n';
}

void freeArray(int*& arr, size_t& size, size_t& capacity)
{
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
}

bool resize(int*& arr, size_t& capacity, size_t new_capacity, size_t size)
{
    int* new_arr = allocate(new_capacity);
    if (!new_arr) return false;
    for (size_t i = 0; i < size; ++i) new_arr[i] = arr[i];
    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;
    return true;
}

bool push_back(int*& arr, size_t& size, size_t& capacity, int value)
{
    if (size == capacity)
    {
        size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
        if (!resize(arr, capacity, new_capacity, size)) return false;
    }
    arr[size++] = value;
    return true;
}

bool insert(int*& arr, size_t& size, size_t& capacity, size_t index, int value)
{
    if (index > size) return false;
    if (size == capacity)
    {
        size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
        if (!resize(arr, capacity, new_capacity, size)) return false;
    }
    for (size_t i = size; i > index; --i) arr[i] = arr[i - 1];
    arr[index] = value;
    ++size;
    return true;
}

bool erase(int* arr, size_t& size, size_t index)
{
    if (index >= size) return false;
    for (size_t i = index; i + 1 < size; ++i) arr[i] = arr[i + 1];
    --size;
    return true;
}

// int main()
// {
//     int* arr = nullptr;
//     size_t size = 0;
//     size_t capacity = 0;
//
//     if (!init(arr, size, capacity, 2)) return 1;
//
//     push_back(arr, size, capacity, 5);
//     push_back(arr, size, capacity, 10);
//     push_back(arr, size, capacity, 15);
//     print(arr, size);
//
//     insert(arr, size, capacity, 1, 7);
//     print(arr, size);
//
//     erase(arr, size, 2);
//     print(arr, size);
//
//     freeArray(arr, size, capacity);
//     return 0;
// }
