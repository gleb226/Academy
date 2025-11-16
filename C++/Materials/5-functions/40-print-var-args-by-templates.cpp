template <typename T>
void print(const T& arg)
{
	std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
	std::cout << firstArg << std::endl; // виводимо на екран перший аргумент 
	print(args...); // викликаємо print() для 
	// інших аргументів 
}