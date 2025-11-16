
#include <iostream>

using namespace std;

int main()
{
    char name[10];
    int age;
    const char templateStr[] = "Name: %s, age: %d";

    printf("Input user name:\n");
    scanf("%s", name);

    printf("Input user age:\n");
    scanf("%d", &age);

    printf(templateStr, name, age);

    return 0;
}