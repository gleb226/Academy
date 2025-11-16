#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

// Клас для роботи з діапазонами чисел
class RangeProcessor {
private:
    std::vector<int> range1;
    std::vector<int> range2;

public:
    RangeProcessor(std::vector<int> r1, std::vector<int> r2) : range1(r1), range2(r2) {}

    // Метод для перевірки, чи міститься один діапазон у іншому
    bool containsRange() {
        return std::ranges::includes(range1, range2);
    }
};

int main7() {
    std::vector<int> range1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> range2 = { 3, 5, 8 };

    // Створення об'єкту класу RangeProcessor з двома діапазонами
    RangeProcessor processor(range1, range2);

    // Перевірка, чи міститься range2 у range1
    if (processor.containsRange()) {
        std::cout << "range2 is contained in range1." << std::endl;
    }
    else {
        std::cout << "range2 is not contained in range1." << std::endl;
    }

    return 0;
}