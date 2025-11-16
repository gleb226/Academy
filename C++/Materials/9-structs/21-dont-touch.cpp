#include <iostream>

int main()
{
	// ¬изначаЇмо наб≥р з ф≥зичних/емоц≥йний стан≥в
	const unsigned char isHungry = 0x01;   // ш≥стнадц€тковий л≥терал дл€ 0000 0001
	const unsigned char isSad = 0x02;      // ш≥стнадц€тковий л≥терал дл€ 0000 0010
	const unsigned char isMad = 0x04;      // ш≥стнадц€тковий л≥терал дл€ 0000 0100
	const unsigned char isHappy = 0x08;    // ш≥стнадц€тковий л≥терал дл€ 0000 1000
	const unsigned char isLaughing = 0x10; // ш≥стнадц€тковий л≥терал дл€ 0001 0000
	const unsigned char isAsleep = 0x20;   // ш≥стнадц€тковий л≥терал дл€ 0010 0000
	const unsigned char isDead = 0x40;     // ш≥стнадц€тковий л≥терал дл€ 0100 0000
	const unsigned char isCrying = 0x80;   // ш≥стнадц€тковий л≥терал дл€ 1000 0000

	unsigned char me = 0; // вс≥ флаги/параметри вимкнен≥ до старту
	me |= isHappy | isLaughing; // € isHappy ≥ isLaughing
	me &= ~isLaughing; // € вже не isLaughing

	// «апитуЇмо в≥дразу дек≥лька стан≥в (ми будемо використовувати static_cast<bool> дл€ конвертац≥њ результат≥в в значенн€ типу bool)
	std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
	std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';

	return 0;
}