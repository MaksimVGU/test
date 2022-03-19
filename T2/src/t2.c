#include <stdio.h>
int main ()
{
    /* Программа для проверки синтаксиса */
    char c1;
    float c2;
    printf("Введите целое число ");
    scanf("%c",&c1);
    printf("Введите вещественное число ");
    scanf("%f",&c2);
    printf("%c\n",c1+c2);
    return 0;
}
