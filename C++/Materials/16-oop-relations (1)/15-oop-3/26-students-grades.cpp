#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
	std::string name;
	char grade;
};

class GradeMap
{
private:
	std::vector<StudentGrade> m_map;

public:
	GradeMap()
	{
	}

	char& operator[](const std::string& name);
};

char& GradeMap::operator[](const std::string& name)
{
	// Дивимося, чи знайдемо ім'я учня в векторі
	for (auto& ref : m_map)
	{
		// Якщо знайшли, то повертаємо посилання на його оцінку
		if (ref.name == name)
			return ref.grade;
	}

	// В протилежному випадку, створюємо новий StudentGrade для нового учня
	StudentGrade temp{ name, ' ' };

	// Поміщаємо його в кінець вектору
	m_map.push_back(temp);

	// І повертаємо посилання на його оцінку
	return m_map.back().grade;
}

int main()
{
	GradeMap grades;
	grades["John"] = 'A';
	grades["Martin"] = 'B';
	std::cout << "John has a grade of " << grades["John"] << '\n';
	std::cout << "Martin has a grade of " << grades["Martin"] << '\n';

	return 0;
}