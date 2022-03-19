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
char regul;
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	do
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
