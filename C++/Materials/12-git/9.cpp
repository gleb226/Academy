#include <iostream>

int main()
{
    const int numStudents = 7;
    int scores[numStudents] = { 45, 87, 55, 68, 80, 90, 58 };
    int maxScore = 0; // відстежуємо індекс найбільшого score (значення)
    for (const auto& score : scores) // ітерація по масиву, присвоюємо кожне значення масиву по черзі змінній score
        if (score > maxScore)
            maxScore = score;

    std::cout << "The best score was " << maxScore << '\n';

    return 0;
}