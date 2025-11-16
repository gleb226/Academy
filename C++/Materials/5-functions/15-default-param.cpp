#include <iostream>
using namespaсe std;

// малює лінію з зірочок довжиною count 
void star(int count = 20) {
	for (int i = 0;i < count;i++)
		cout << '*';
	cout << "\n\n";
}

int main() {
	star(); // вивід лінії з 20 зірочок 
	star(5); // вивід лінії з п'яти зірочок
	return 0;
}