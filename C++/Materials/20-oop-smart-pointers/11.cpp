#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main()
{
	std::vector<std::string> v;
	std::string str = "Bye";

	std::cout << "Copying str\n";
	v.push_back(str); // викликає версію l-value методу push_back(), яка копіює str в елемент масиву

	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << '\n';

	std::cout << "\nMoving str\n";

	v.push_back(std::move(str)); // викликає версію r-value методу push_back(), яка переміщує str в елемент масиву

	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << ' ' << v[1] << '\n';

	return 0;
}