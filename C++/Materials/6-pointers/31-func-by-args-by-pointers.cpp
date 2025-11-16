#include <iostream> 
#include <algorithm> // для std::swap() (використовуйте <utility>, якщо підтримується C++11)

// Зверніть увагу, третім параметром є користувацький вибір виконання сортування
void selectionSort(int* array, int size, bool (*comparisonFcn)(int, int))
{
    // Перебираємо кожний елемент масиву
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        // bestIndex - це індекс найменшого/найбільшого елементу, який ми виявили до цього моменту
        int bestIndex = startIndex;

        // Шукаємо найменший/найбільший елемент серед решти елементів масиву (починаємо з startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // Якщо поточний елемент менше/більше нашого попереднього знайденого найменшого/найбільшого елементу,
            if (comparisonFcn(array[bestIndex], array[currentIndex])) // ПОРІВНЯННЯ ВИКОНУЄТЬСЯ ТУТ
                // то це наш новий найменший/найбільший елемент в цій ітерації
                bestIndex = currentIndex;
        }

        // Міняємо місцями наш стартовий елемент зі знайденим найменшим/найбільшим елементом
        std::swap(array[startIndex], array[bestIndex]);
    }
}

// Ось функція порівняння, яка виконує сортування в порядку зростання (зверніть увагу, це та ж функція ascending(), що у прикладі, наведеному вище)
bool ascending(int a, int b)
{
    return a > b; // міняємо місцями, якщо перший елемент більше другого
}

// Ось функція порівняння, яка виконує сортування в порядку спадання
bool descending(int a, int b)
{
    return a < b; // міняємо місцями, якщо другий елемент більше першого
}

// Ця функція виводить значення масиву
void printArray(int* array, int size)
{
    for (int index = 0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << '\n';
}

int main()
{
    int array[8] = { 4, 8, 5, 6, 2, 3, 1, 7 };

    // Сортуємо масив в порядку спадання, використовуючи функцію descending()
    selectionSort(array, 8, descending);
    printArray(array, 8);

    // Сортуємо масив в порядку зростання, використовуючи функцію ascending()
    selectionSort(array, 8, ascending);
    printArray(array, 8);

    return 0;
}