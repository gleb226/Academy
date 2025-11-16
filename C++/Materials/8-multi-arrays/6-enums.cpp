#include <iostream>

// Визначаємо новий перелічуваний тип Animals
enum Animals
{
	ANIMAL_PIG = -4,
	ANIMAL_LION, // присвоюється -3
	ANIMAL_CAT, // присвоюється -2
	ANIMAL_HORSE = 6,
	ANIMAL_ZEBRA = 6, // має те ж значення, що і ANIMAL_HORSE
	ANIMAL_COW // присвоюється 7
};

int main()
{
	int mypet = ANIMAL_PIG;
	std::cout << ANIMAL_HORSE; // конвертується в int, а потім виводиться на екран

	return 0;
}