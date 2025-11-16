
template<typename ...Ts> //C++17
//Універсальні посилання на кожен з параметрів
auto SUM(Ts&& ... param) {
	return (std::forward<Ts>(param) + ... + 0); //Приймає вигляд (param1 + (param2 + (...(0)))
	//Зверніть увагу: 0 виступає в ролі нейтрального значення
}

//Розглянемо можливий виклик функції :

int main(int argc, char* argv[])
{
	constexpr int a = 100;
	std::cout << SUM(10, 20, a); //Результат: 130
}