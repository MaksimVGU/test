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
typedef struct List_Vvod
{
    int type;
    char deistvie;
    double *peremenai_1;
    double *peremenai_2;
    char *prodolzit_li;
    struct list *next;
}Vvod;
typedef struct List_Vivod
{
    float rez;
    struct List_Vivod *next;
}Vivod;

#include <stdio.h>
#include <stdlib.h>
char end='y';
int main(int argc,char *argv[])
{
    while(end!='n')
    {
        char regul;
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
        FILE *input,*output;
        char filename1[259];
        char filename2[259];
        printf("Введите откуда читать\n");
        scanf("%s",filename1);
        printf("Введите куда записать\n");
        scanf("%s",filename2);
        input=fopen(filename1,"r");
        output=fopen(filename2,"w");
        do
        {
            int size;
            fscanf(input," %i", &size);
            if (size==1)
            {
                double a,b,i,d; // задаем переменные типа double
                char deistvie; // задаем переменную типа char
                fscanf(input," %c", &deistvie); //вводим с
                switch(deistvie) //блок функций
                {
                    case '+'://блок суммы
                        //fprintf(output,"введите первое число a=");
                        fscanf(input," %lg",&a);
                        //fprintf(output,"введите первое число b=");
                        fscanf (input," %lg",&b);
                        fprintf(output," %lg plus %lg = %lg\n", a,b, a+b);
                        break;
                    case '-'://блок разности
                        //fprintf(output,"введите первое число a=");
                        fscanf(input," %lg",&a);
                        //fprintf(output," введите первое число b=");
                        fscanf (input," %lg",&b);
                        fprintf (output," %lg minus %lg = %lg\n", a,b,a-b);
                        break;
                    case '*'://блок умножения
                        //fprintf(output," введите первое число a=");
                        fscanf(input," %lg",&a);
                        //fprintf(output," введите первое число b=");
                        fscanf (input," %lg",&b);
                        fprintf (output," %lg multiply by %lg = %lg\n", a,b, a*b);
                        break;
                    case '/'://блок деления
                        //fprintf(output," введите первое число a=");
                        fscanf(input," %lg",&a);
                        //fprintf(output," введите первое число b=");
                        fscanf (input," %lg",&b);
                        fprintf (output," %lg divide by %lg = %lg\n", a,b,a/b);
                        break;
                    case '^': //блок степени
                        //fprintf(output," введите первое число a=");
                        fscanf(input," %lg",&a);
                        //fprintf(output,"введите первое число b=");
                        fscanf (input," %lg",&b);
                        d=a;//приравниваем для того, чтобы посчитать степень
                        for (i=1;i<b;i++)
                            {
                                d=d*a;
                            }
                        fprintf(output,"%lg в степени %lg = %g\n",a,b,d);
                        break;
                    case '!'://блок факториала
                        d=1;//приравниваем для того, чтобы посчитать факториал
                        //fprintf(output," введите первое число a=");
                        fscanf(input," %lg",&a);
                        if (a>=0)//тк факториал 0=1 тогда сделаем такой цикл
                        {
                            for (i=0;i<a;i++)
                            {
                                d=d*(i+1);
                            }
                            fprintf(output,"факториал %lg = %lg\n",a,d);
                        }
                        else
                            fprintf(output," nop\n");
                        break;
                    default:
                        fprintf (output," nop\n");

                }
            }
            if(size>=2)//Блок векторов
            {
                int rez=0;
                int *t;
                int *a1;
                int *b1;
                char deistvie;
                double a,b;
                fscanf(input," %c",&deistvie);
                switch (deistvie)
                {
                    case '+': //блок сложения
                        t=malloc(size*sizeof(int));
                        a1=malloc(size*sizeof(int));
                        b1=malloc(size*sizeof(int));
                        for(int i=0;i<size;i++)
                        {
                            fscanf(input,"%lf",&a);
                            a1[i]=a;
                        }
                        for (int i = 0; i < size; i++)
                        {
                            fscanf(input,"%lf",&b);
                            b1[i]=b;
                        }
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
                        fprintf(output,")\n");
                    break;
                    case '-': //блок вычитания
                        t=malloc(size*sizeof(int));
                        a1=malloc(size*sizeof(int));
                        b1=malloc(size*sizeof(int));
                        for(int i=0;i<size;i++)
                        {
                            fscanf(input,"%lf",&a);
                            a1[i]=a;
                        }
                        for (int i = 0; i < size; i++)
                        {
                            fscanf(input,"%lf",&b);
                            b1[i]=b;
                        }
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
                        fprintf(output,")\n");

                    break;
                    case '*': //блок умножения скалярного
                        t=malloc(size*sizeof(int));
                        a1=malloc(size*sizeof(int));
                        b1=malloc(size*sizeof(int));
                        for(int i=0;i<size;i++)
                        {
                            fscanf(input,"%lf",&a);
                            a1[i]=a;
                        }
                        for (int i = 0; i < size; i++)
                        {
                            fscanf(input,"%lf",&b);
                            b1[i]=b;
                        }
                        for (int i = 0; i < size; i++)
                        {
                            rez+=a1[i]*b1[i];
                        }
                            fprintf(output,"%i \n", rez);
                    break;
                    default:
                    fprintf(output,"to be contine\n");
                    break;
                    free(a1);
                    free(b1);
                    free(t);
                }
            }
            //fprintf(output,"\n хотите продолжить (y/n) ?\n");
            fscanf (input," %c", &regul);
        }
        while((regul)=='y');
        if ((regul)=='n')
            {
                fprintf(output,"end\n");
            }
        else
            fprintf(output,"вы ввели неправильно, для завершения надо было n, программа завершена из-за вашей ошибки\n");
        fclose(input);
        fclose(output);
        printf("продолжить?\n");
        scanf(" %c", &end);
    }
    return 0;
}
