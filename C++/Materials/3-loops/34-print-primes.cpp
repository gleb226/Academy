#include <stdio.h>

int main()
{
    int n, m, num:
    printf("Enter any number you want to print prime number upto\n");
    scanf("%d", &num) :
        printf("Prime number between 1 and %d is given below\n", num);
    for (int i = 1;i <= num;i++)
    {
        n = 1, m = 0;
        for (int j = 2; <= n - 1;j++)
        {
            if (n % j == 0)
            {
                m = 1;
                break;
            }
        }
        if (m == 0)
            printf("%d", n);

    }

}


/*
### Output ###
Enter any number you want to print prime number upto
20
Prime number between 1 and 20 is given below
1 2 3 5 7 11 17 19
*/