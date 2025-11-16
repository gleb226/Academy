#include <iostream>

class Values
{
private:
	int min; // мінімальне значення, яке ми виявили до цього моменту
	int max; // максимальне значення, яке ми виявили до цього моменту

public:
	Values(int min, int max)
	{
		this->min = min;
		this->max = max;
	}

	int getMin() { return min; }
	int getMax() { return max; }

	friend Values operator+(const Values& v1, const Values& v2);
	friend Values operator+(const Values& v, int value);
	friend Values operator+(int value, const Values& v);
};

Values operator+(const Values& v1, const Values& v2)
{
	// Визначаємо мінімальне значення між v1 і v2
	int min = v1.min < v2.min ? v1.min : v2.min;

	// Визначаємо максимальне значення між v1 і v2
	int max = v1.max > v2.max ? v1.max : v2.max;

	return Values(min, max);
}

Values operator+(const Values& v, int value)
{
	// Визначаємо мінімальне значення між v і value
	int min = v.min < value ? v.min : value;

	// Визначаємо максимальне значення між v і value
	int max = v.max > value ? v.max : value;

	return Values(min, max);
}

Values operator+(int value, const Values& v)
{
	// Викликаємо operator+(Values, int)
	return v + value;
}

int main()
{
	Values v1(11, 14);
	Values v2(7, 10);
	Values v3(4, 13);

	Values vFinal = v1 + v2 + 6 + 9 + v3 + 17;

	std::cout << "Result: (" << vFinal.getMin() << ", " << vFinal.getMax() << ")\n";

	return 0;
}