#include <iostream>
#include <functional>

using namespace std;

// Функція пошуку з можливістю передачі лямбда-виразу
void linearSearch(int arr[], int size, int target, function<void(int)> displayResult) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            displayResult(arr[i]);
            return;
        }
    }
}

int main() {
    setlocale(LC_ALL, "uk_UA");

    int numbers[] = { 1, 2, 3, 4, 5 };
    int target = 3;
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Приклад використання з простим виведенням на консоль
    linearSearch(numbers, size, target, [](int result) {
        cout << "Значення знайдено: " << result << "\n";
        });

    // Приклад використання з виведенням червоним кольором
    linearSearch(numbers, size, 5, [](int result) {
        cout << "\033[1;32mЗначення знайдено: " << result << "\033[0m\n"; // Вивід зеленим кольором
        });

    return 0;
}
