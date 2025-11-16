int main()
{
    const int constVariable = 4;
    const int factorial1 = getFactorial<constVariable>();
    //
    // Код вище скомпілюється успішно. Тип змінної constVariable позначено
    // як const і не залежить від змінних часу виконання - тому його
    // можна передати як значення шаблонного аргументу-константи

    int mutableVariable = 4;
    //const int factorial2 = getFactorial<mutableVariable>();
    //
    // Код вище не скомпілюється з помилкою: "значення 'mutableVariable'
    // is not usable in a constant expression". Передавати змінні в
    // getFactorial<>() не можна, оскільки mutableVariable не позначена як const і
    // є для компілятора значенням часу виконання.

    int a = 1;
    int b = 3;
    const int constVariableFromMutableVariables = a + b;
    //const int factorial3 = getFactorial<constVariableFromMutableVariables>();
    //
    // Код вище не скомпілюється з тією ж помилкою. Незважаючи на те, що
    // "constVariableFromMutableVariables" позначена як "const", її значення
    // залежить від змінних "a" і "b", які можуть змінюватися під час
    // виконання програми. Це перетворює її з константи часу компіляції на
    // змінну часу виконання. Так, вона позначена як незмінна. Але в
    // даному випадку, для компілятора це лише "обіцянка", що змінна не
    // буде змінюватися після ініціалізації значенням "a+b" і компілятор може
    // спробувати виконати якісь оптимізації спираючись на цю інформацію.

    const int constA = 1;
    const int constB = 3;
    const int constVariableFromConstVariables = constA + constB;
    const int factorial4 = getFactorial<constVariableFromConstVariables>();
    //
    // А ось цей код скомпілюється успішно. constVariableFromConstVariables
    // залежить тільки від константних значень часу компіляції.   

    return 0;
}