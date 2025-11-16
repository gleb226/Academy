[] {
	std::cout << "hello lambda" << std::endl;
	}
//Цю функцію можна викликати безпосередньо
[]{
		std::cout << "hello lambda" << std::endl;
} (); // виводить на екран "hello lambda" 
//чи передавати об'єктам 
auto l = [] {
	std::cout << "hello lambda" << std::endl;
};
//...
l(); // виводимо на екран "hello lambda"