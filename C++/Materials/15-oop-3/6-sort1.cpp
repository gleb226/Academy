#include <iostream>
#include <array>
#include <chrono> // для функцій з std::chrono

const int g_arrayElements = 100000; // загальна кількість всіх елементів масиву

class Timer
{
private:
	// Псевдоніми типів використовуються для зручного доступу до вкладених типів
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> begin;

public:
	Timer()
	{
		this->begin = clock_t::now();
	}

	void reset()
	{
		begin = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - begin).count();
	}
};

void sortArray(std::array<int, g_arrayElements>& numbers)
{
	// Перебираємо кожний елемент масиву (крім останнього, він вже буде впорядкований, коли ми до нього дійдемо)
	for (int startIndex = 0; startIndex < g_arrayElements - 1; ++startIndex)
	{
		// У змінній smallestIndex зберігається індекс найменшого значення, яке ми знайшли в цій ітерації.
		// Почнемо з того, що найменший елемент в цій ітерації - це перший елемент (індекс 0)
		int smallestIndex = startIndex;

		// Потім шукаємо елемент менше нашого smallestIndex в решті масиву
		for (int currentIndex = startIndex + 1; currentIndex < g_arrayElements; ++currentIndex)
		{
			// Якщо знайшли елемент менше нашого найменшого елементу,
			if (numbers[currentIndex] < numbers[smallestIndex])
				// то записуємо/запам'ятовуємо його
				smallestIndex = currentIndex;
		}

		// smallestIndex тепер найменший елемент в решті масиву.
		// Міняємо місцями наше стартове найменше значення з тим, яке ми виявили
		std::swap(numbers[startIndex], numbers[smallestIndex]);
	}
}

int main()
{
	std::array<int, g_arrayElements> numbers;
	for (int i = 0; i < g_arrayElements; ++i)
		numbers[i] = g_arrayElements - i;

	Timer t;

	sortArray(numbers);

	std::cout << "Time taken: " << t.elapsed() << '\n';

	return 0;
}