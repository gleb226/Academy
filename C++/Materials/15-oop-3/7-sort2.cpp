#include <iostream>
#include <array>
#include <chrono> // для функцій з std::chrono
#include <algorithm> // для std::sort()

const int g_arrayElements = 10000; // загальна кількість всіх елементів масиву

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
		begin = clock_t::now();
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

int main()
{
	std::array<int, g_arrayElements> array;
	for (int i = 0; i < g_arrayElements; ++i)
		array[i] = g_arrayElements - i;

	Timer t;

	std::sort(array.begin(), array.end());

	std::cout << "Time taken: " << t.elapsed() << '\n';

	return 0;
}