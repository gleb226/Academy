#include <iostream>
using namespace std;

// малює лінію з зірочок довжиною count 
void Star(int count) {
	for (int i = 0;i < count;i++)
		cout << '*';
	cout << "\n\n";
}

int main() {
	Star(3); // вивід лінії з трьох зірочок 
	Star(5); // вивід лінії з п'яти зірочок
	return 0;
}