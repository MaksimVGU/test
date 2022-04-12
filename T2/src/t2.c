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
// Для работы через файл, надо выбрать режим работы: вектор v калькулятор s
// далее, для векторонго ввести через пробел размер_вектора координааты_первого_вектора координаты_второго_вектора действие
// для калькулятора: выбираем_действие вводим_первое_число вводим_второе_число(если не факториал)
// выбираем, продолжить ли работу
#include <stdio.h>
#include <stdlib.h>
char type;
char regul;
double coordinate;
int main(int argc,char *argv[])
{
	FILE *input,*output;
	input =fopen("input.txt","r");
	output=fopen("output.txt","w");
	do
    {

        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
        fprintf(output,"вектор(v)/Калькулятор(s)\n");
        fscanf(input," %c", &type);
        if (type=='s')
        {
            // пишем сначала все функции и их обозначения
            fprintf(output," сумма, знак +\n");
            fprintf(output," разность, знак -\n");
            fprintf(output," умножение, знак *\n");
            fprintf(output," деление, знак /\n");
            fprintf(output," степень, знак ^\n");
            fprintf(output," факториал, знак !\n\n");
            double a,b,i,d; // задаем переменные типа double
            char c; // задаем переменную типа char
            fprintf(output," введите операцию "); // выводим надпись с подсказкой
            fscanf(input," %c", &c); //вводим с
            switch(c) //блок функций
            {
                case '+'://блок суммы
                    fprintf(output,"введите первое число a=");
                    fscanf(input," %lg",&a);
                    fprintf(output,"введите первое число b=");
                    fscanf (input," %lg",&b);
                    fprintf(output," %lg plus %lg = %lg", a,b, a+b);
                    break;
                case '-'://блок разности
                    fprintf(output,"введите первое число a=");
                    fscanf(input," %lg",&a);
                    fprintf(output," введите первое число b=");
                    fscanf (input," %lg",&b);
                    fprintf (output," %lg minus %lg = %lg", a,b,a-b);
                    break;
                case '*'://блок умножения
                    fprintf(output," введите первое число a=");
                    fscanf(input," %lg",&a);
                    fprintf(output," введите первое число b=");
                    fscanf (input," %lg",&b);
                    fprintf (output," %lg multiply by %lg = %lg", a,b, a*b);
                    break;
                case '/'://блок деления
                    fprintf(output," введите первое число a=");
                    fscanf(input," %lg",&a);
                    fprintf(output," введите первое число b=");
                    fscanf (input," %lg",&b);
                    fprintf (output," %lg divide by %lg = %lg", a,b,a/b);
                    break;
                case '^': //блок степени
                    fprintf(output," введите первое число a=");
                    fscanf(input," %lg",&a);
                    fprintf(output,"введите первое число b=");
                    fscanf (input," %lg",&b);
                    d=a;//приравниваем для того, чтобы посчитать степень
                    for (i=1;i<b;i++)
                        {
                            d=d*a;
                        }
                    fprintf(output,"%lg в степени %lg = %g",a,b,d);
                    break;
                case '!'://блок факториала
                    d=1;//приравниваем для того, чтобы посчитать факториал
                    fprintf(output," введите первое число a=");
                    fscanf(input," %lg",&a);
                    if (a>=0)//тк факториал 0=1 тогда сделаем такой цикл
                    {
                        for (i=0;i<a;i++)
                        {
                            d=d*(i+1);
                        }
                        fprintf(output,"факториал %lg = %lg",a,d);
                    }
                    else
                        fprintf(output," nop");
                    break;
                default:
                    fprintf (output," nop");

            }
        }
        if(type=='v')//Блок векторов
        {
        	int rez=0;
            int *t;
            int *a1;
            int *b1;
            char deistvie;
            double a,b;
            int size;
            fprintf(output,"введите размер вектора ");
            fscanf(input,"%i",&size);
            t=malloc(size*sizeof(int));
            a1=malloc(size*sizeof(int));
            b1=malloc(size*sizeof(int));
            for(int i=0;i<size;i++)
            {
                fprintf(output,"введите координтаты вектора a ");
                fscanf(input,"%lf",&a);
                a1[i]=a;
            }
            for (int i = 0; i < size; i++)
            {
                fprintf(output,"введите координтаты вектора b ");
                fscanf(input,"%lf",&b);
                b1[i]=b;
            }
            fprintf(output,"введите действие\n");
            fprintf(output,"Сложение вектора a и b --- '+'\n");
            fprintf(output,"вычитание из вектора a вектор b --- '-'\n");
            fprintf(output,"Скалярно умножить вектор a на b --- '*'\n");
            fscanf(input," %c",&deistvie);
            switch (deistvie)
            {
                case '+': //блок сложения
                    for (int i = 0; i < size; i++)
                    {
                        t[i]=a1[i]+b1[i];
                    }
                    fprintf(output,"(");
                    for (int i=0;i<size;i++)
                    {
                    	fprintf(output," %i ", a1[i]);
                    }
                    fprintf(output,")");
                    fprintf(output," + ");
                    fprintf(output,"(");
                    for (int i=0;i<size;i++)
                    {
                    	fprintf(output," %i ", b1[i]);
                    }
                    fprintf(output,")");
                    fprintf(output," = ");
                    fprintf(output,"(");
                    for (int i = 0; i < size; i++)
                    {
                        fprintf(output," %i ", t[i]);
                    }
                    fprintf(output,")");
                break;
                case '-': //блок вычитания
                    for (int i = 0; i < size; i++)
                    {
                        t[i]=a1[i]-b1[i];
                    }
                    fprintf(output,"(");
                    for (int i=0;i<size;i++)
                    {
                    	fprintf(output," %i ", a1[i]);
                    }
                    fprintf(output,")");
                    fprintf(output," - ");
                    fprintf(output,"(");
                    for (int i=0;i<size;i++)
                    {
                    	fprintf(output," %i ", b1[i]);
                    }
                    fprintf(output,")");
                    fprintf(output," = ");
                    fprintf(output,"(");
                    for (int i = 0; i < size; i++)
                    {
                        fprintf(output," %i ", t[i]);
                    }
                    fprintf(output,")");

                break;
                case '*': //блок умножения скалярного
                    for (int i = 0; i < size; i++)
                    {
                        t[i]=a1[i]*b1[i];
                    }
                    fprintf(output,"(");
                    for (int i=0;i<size;i++)
                    {
                    	fprintf(output," %i ", a1[i]);
                    }
                    fprintf(output,")");
                    fprintf(output," * ");
                    fprintf(output,"(");
                    for (int i=0;i<size;i++)
                    {
                    	fprintf(output," %i ", b1[i]);
                    }
                    fprintf(output,")");
                    fprintf(output," = ");
                    for (int i=0;i<size;i++)
                    {
                    	rez+=t[i];
                    }
                        fprintf(output,"%i ", rez);
                break;
                default:
                fprintf(output,"to be contine");
                break;
                free(a1);
                free(b1);
                free(t);
            }
        }
        fprintf(output,"\n хотите продолжить (y/n) ?\n");
        fscanf (input," %c", &regul);
    }
    while((regul)=='y');
    if ((regul)=='n')
        {
            fprintf(output,"end");
        }
    else
        fprintf(output,"вы ввели неправильно, для завершения надо было n, программа завершена из-за вашей ошибки");
    fclose(input);
    fclose(output);
    return 0;
}
