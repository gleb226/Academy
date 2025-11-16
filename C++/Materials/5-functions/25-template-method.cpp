// Нижче описується шаблон функції max, що має один шаблонний аргумент
// з іменем "Type". Ім'я може бути будь-яким іншим, правила формування ті самі що
// для іменування змінних і типів.
// Замість ключового слова "typename" для позначення шаблонного аргументу-типу
// може використовуватися ключове слово "class". Крім деяких нюансів
// (що виходять за рамки цієї статті) ці ключові слова абсолютно синонімічні.
template<typename Type>
Type max(Type a, Type b)
{
	return (a >= b ? a : b);
}

int main()
{
	// Використання шаблону "max<Type>(Type, Type)" з підстановкою "int"
	const int a = 3, b = 2, c = 1;
	const int abMax = max<int>(a, b);
	const int max = max<int>(abMax, c);

	// Використання того ж шаблону max<Type>(Type, Type) з підстановкою "char"  
	const char aChar = 3, bChar = 2, cChar = 1;
	const char abMaxChar = max<char>(aChar, bChar);
	const char maxChar = max<char>(abMaxChar, cChar);

	return 0;
}