// автор: Жилкин Максим
// лицензия: GNU GPL
// калькулятор считает со знаками после запятой, способен на:
// сумма, знак +
// разность, знак -
// умножение, знак *
// деление, знак /
// степень, знак ^
// факториал, знак !
// чтобы вернуться в начало программы будем использловать do.. while. Пользователь должен будет ввести y если хочет продолжить работать в калькуляторе или n чтобы прекратить
#include <stdio.h>
#include <stdlib.h>
char type;
char regul;
double coordinate;
int main(void)
{
	do
    {
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
        printf("вектор(V)/Калькулятор(K)\n");
        scanf(" %c", &type);
        if (type=='k')
        {
            // пишем сначала все функции и их обозначения
            printf(" сумма, знак +\n");
            printf(" разность, знак -\n");
            printf(" умножение, знак *\n");
            printf(" деление, знак /\n");
            printf(" степень, знак ^\n");
            printf(" факториал, знак !\n\n");
            double a,b,i,d; // задаем переменные типа double
            char c; // задаем переменную типа char
            printf(" введите операцию "); // выводим надпись с подсказкой
            scanf(" %c", &c); //вводим с
            switch(c) //блок функций
            {
                case '+'://блок суммы
                    printf("введите первое число a=");
                    scanf(" %lg",&a);
                    printf("введите первое число b=");
                    scanf (" %lg",&b);
                    printf(" %lg plus %lg = %lg", a,b, a+b);
                    break;
                case '-'://блок разности
                    printf( "введите первое число a=");
                    scanf(" %lg",&a);
                    printf(" введите первое число b=");
                    scanf (" %lg",&b);
                    printf ( " %lg minus %lg = %lg", a,b,a-b);
                    break;
                case '*'://блок умножения
                    printf(" введите первое число a=");
                    scanf(" %lg",&a);
                    printf(" введите первое число b=");
                    scanf (" %lg",&b);
                    printf ( " %lg multiply by %lg = %lg", a,b, a*b);
                    break;
                case '/'://блок деления
                    printf(" введите первое число a=");
                    scanf(" %lg",&a);
                    printf(" введите первое число b=");
                    scanf (" %lg",&b);
                    printf ( " %lg divide by %lg = %lg", a,b,a/b);
                    break;
                case '^': //блок степени
                    printf(" введите первое число a=");
                    scanf(" %lg",&a);
                    printf("введите первое число b=");
                    scanf (" %lg",&b);
                    d=a;//приравниваем для того, чтобы посчитать степень
                    for (i=1;i<b;i++)
                        {
                            d=d*a;
                        }
                    printf("%lg в степени %lg = %g",a,b,d);
                    break;
                case '!'://блок факториала
                    d=1;//приравниваем для того, чтобы посчитать факториал
                    printf(" введите первое число a=");
                    scanf(" %lg",&a);
                    if (a>=0)//тк факториал 0=1 тогда сделаем такой цикл
                    {
                        for (i=0;i<a;i++)
                        {
                            d=d*(i+1);
                        }
                        printf("факториал %lg = %lg",a,d);
                    }
                    else
                        printf(" nop");
                    break;
                default:
                    printf (" nop");

            }
        }
        if(type=='v')
        {
        	int rez=0;
            int *t;
            int *a1;
            int *b1;
            char deistvie;
            double a,b;
            int size;
            printf("введите размер вектора");
            scanf("%i",&size);
            t=malloc(size*sizeof(int));
            a1=malloc(size*sizeof(int));
            b1=malloc(size*sizeof(int));
            for(int i=0;i<size;i++)
            {
                printf("введите координтаты вектора a ");
                scanf("%lf",&a);
                a1[i]=a;
            }
            for (int i = 0; i < size; i++)
            {
                printf("введите координтаты вектора b ");
                scanf("%lf",&b);
                b1[i]=b;
            }
            printf("введите действие\n");
            printf("Сложение вектора a и b --- '+'\n");
            printf("вычитание из вектора a вектор b --- '-'\n");
            printf("Скалярно умножить вектор a на b --- '*'\n");
            scanf(" %c",&deistvie);
            switch (deistvie)
            {
                case '+': //блок сложения
                    for (int i = 0; i < size; i++)
                    {
                        t[i]=a1[i]+b1[i];
                    }
                    for (int i = 0; i < size; i++)
                    {
                        printf("%i ", t[i]);
                    }
                break;
                case '-': //блок вычитания
                    for (int i = 0; i < size; i++)
                    {
                        t[i]=a1[i]-b1[i];
                    }
                    for (int i = 0; i < size; i++)
                    {
                        printf("%i ", t[i]);
                    }

                break;
                case '*': //блок умножения скалярного
                    for (int i = 0; i < size; i++)
                    {
                        t[i]=a1[i]*b1[i];
                    }
                    for (int i=0;i<size;i++)
                    {
                    	rez+=t[i];
                    }
                        printf("%i ", rez);
                break;
                default:
                printf("to be contine");
                break;
            }
        }
        printf("\n хотите продолжить (y/n) ?\n");
        scanf (" %c", &regul);
    }
    while((regul)=='y');
    if ((regul)=='n')
        {
            printf("end");
        }
    else
        printf("вы ввели неправильно, для завершения надо было n, программа завершена из-за вашей ошибки");

    return 0;
}
