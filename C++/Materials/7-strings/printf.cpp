#include <iostream>

using namespace std;

int main()
{
    char c = 'S';
    char str[] = "Hello";
    float x = 5.0, y = 12.45;
    double d = 66.123;
    int i = -100;
    unsignedint j = 10;

    printf("Single character: %c \n", c);
    printf("Character string: %s \n", str);
    printf("Float values: %f; %f \n", x, y);
    printf("Double value: %f \n", d);
    printf("Signed integer - decimal representation: %d \n", i);
    printf("Unsigned integer - decimal representation: %u \n", j);
    printf("The hex equivalent of %f is %a \n", x, x);

    return 0;
}