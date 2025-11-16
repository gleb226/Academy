// На початку файлі де оголошується макрос не забудьте додати
// інклуд: "#include <iostream>"

// Власне, сам макрос. Роздруковує в "std::cout" вираз
// у вигляді рядка (для спрощення читання вираз обрамляється
// фігурними дужками) і значення обчисленого виразу.
#define PrintExpression(Expression)\
     std::cout << "{" #Expression "}: " << (Expression) <<\
         std::endl;

// Приклади використання макроса:

// 1. Роздруківка змінної
int value = 1;
PrintExpression(value)
//Роздрукує наступне: {value}: 1

// 2. Роздрукування виразу
int arrayValue[]{ 1, 2, 3, 4 };
PrintExpression(arrayValue[1] + arrayValue[2])
// Роздрукує наступне: {arrayValue[1] + arrayValue[2]}: 5