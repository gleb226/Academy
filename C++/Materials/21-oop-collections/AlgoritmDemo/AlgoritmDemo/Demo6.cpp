#include <iostream>
#include <ranges>
#include <vector>
#include <random>

using namespace std;

// Глобальна генерація випадкових чисел
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(1, 100);

int main6() {
    // Приклад з ranges::fill
    vector<int> numbers(10);
    ranges::fill(numbers, 5); // Заповнюємо вектор десяткою значень 5

    cout << "After ranges::fill (all 5):" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Приклад з ranges::generate
    vector<int> randomNumbers(10);
    ranges::generate(randomNumbers, []() {
        return dist(gen);
        }); // Заповнюємо випадковими числами

    cout << "\nAfter ranges::generate (random numbers):" << endl;
    for (int num : randomNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
