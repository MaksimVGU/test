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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЕЙСТВИЯ С ЧИСЛАМИ//////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double *num(char deistvie,double *peremenai_1, double *peremenai_2)
{
    double *rez;
    rez=malloc(1*sizeof(double));
    switch (deistvie)
    {
        case '+'://блок суммы
            rez[0]=peremenai_1[0]+peremenai_2[0];
            return rez;
            break;
        case '-'://блок разности
            rez[0]=peremenai_1[0]-peremenai_2[0];
            return rez;
            break;
        case '*'://блок умножения
            rez[0]=peremenai_1[0]*peremenai_2[0];
            return rez;
            break;
        case '/'://блок деления
            return rez;
            break;
        case '^': //блок степени
            rez[0]=peremenai_1[0];//приравниваем для того, чтобы посчитать степень
            if (peremenai_2[0]==0)
            {
                rez[0]=1;
                return rez;
            }
            else if (peremenai_2[0]==1)
            {
                rez[0]=peremenai_1[0];
                return rez;
            }
            else
            {
                for (int i=1;i<peremenai_2[0];i++)
                    {
                        rez[0]*=peremenai_1[0];
                    }
                //fprintf(output,"%lg в степени %lg = %g\n",a,b,d);
            }
            return rez;
            break;
        case '!'://блок факториала
            rez[0]=1;//приравниваем для того, чтобы посчитать факториал
            if (peremenai_1[0]>=0)//тк факториал 0=1 тогда сделаем такой цикл
            {
                for (int i=0;i<peremenai_1[0];i++)
                {
                    rez[0]=rez[0]*(i+1);
                }
                return rez;
            }
            else
            {
                return rez=0;
            }

            break;
    }
    return peremenai_1;
    return peremenai_2;
    free(peremenai_1);
    free(peremenai_2);
    free(rez);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЕЙСТВИЯ С ВЕКТОРАМИ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double*vector(int type, char deistvie,double *peremenai_1,double *peremenai_2)
{
    double *rez;
    rez=malloc(type*sizeof(double));
    peremenai_1=malloc(type*sizeof(double));
    peremenai_2=malloc(type*sizeof(double));
    switch (deistvie)
    {
    case '+':
        for (int i=0;i<type;i++)
        {
            rez[i]=peremenai_1[i]+peremenai_2[i];
        }
        return rez;
        break;
    case '-':
        for (int i=0;i<type;i++)
        {
            rez[i]=peremenai_1[i]-peremenai_2[i];
        }
        return rez;
        break;
    case '*':
        for (int i = 0; i < type; i++)
        {
            rez[i]+=peremenai_1[i]*peremenai_2[i];
        }
        return rez;
        break;
    default:
    return rez=0;
        break;
    }
    return peremenai_1;
    return peremenai_2;
    free(peremenai_1);
    free(peremenai_2);
    free(rez);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////СТРУКТУРА ДЛЯ ВВОДА ДАННЫХ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct List_IN
{
    int type;
    char deistvie;
    double *peremenai_1;
    double *peremenai_2;
    struct List_IN *next;
}List_IN;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////СТРУКТУРА ДЛЯ ВЫВОДА ДАННЫХ///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct List_OUT
{
    double *rez;
    struct List_OUT *next_out;
}List_OUT;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЧИСЛА////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double *addperemenai(FILE *input, int type)
{
    double *peremenai;
    peremenai=malloc(type*sizeof(double));
    for(int i=0;i<type;i++)
    {
        fscanf(input,"%lf",&peremenai[i]);
    }
    return peremenai;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВВОДА///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_el_in(List_IN *current, FILE *input)
{
    List_IN *tmp=malloc(1*sizeof(List_IN));
    fscanf(input,"%i %c",&tmp->type,&tmp->deistvie);
    if (tmp->deistvie!='!')
    {
        tmp->peremenai_1=addperemenai(input,tmp->type);
        tmp->peremenai_2=NULL;
    }
    else
    {
        tmp->peremenai_1=addperemenai(input,tmp->type);
        tmp->peremenai_2=addperemenai(input,tmp->type);
    }
    current->next=tmp;
    tmp->next=NULL;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВЫВОДА//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_el_out(List_OUT *current_OUT, List_IN *current)
{
    List_OUT *tmp=malloc(sizeof(List_OUT));
    if (current->type>1)
    {
        tmp->rez=vector(current->type,current->deistvie,current->peremenai_1,current->peremenai_2);
    }
    else
    {
        tmp->rez=num(current->deistvie,current->peremenai_1,current->peremenai_2);
    }
    tmp->next_out=NULL;
    current_OUT->next_out=tmp;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc,char *argv[])
{
	char end='y';
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    FILE *input,*output;
    List_IN *head,*current;
    List_OUT *head_OUT,*current_OUT;
    char File_IN[259];
    char File_OUT[259];
    while(end!='n')
    {

        printf("Введите откуда читать\n");
        scanf("%s",File_IN);
        printf("Введите куда записать\n");
        scanf("%s",File_OUT);
        input=fopen(File_IN,"r");
        if (!feof(input))
        {
            head=malloc(1*sizeof(List_IN));
            fscanf(input,"%i %c",&head->type, &head->deistvie);
            if (head->deistvie=='!')
            {
                head->peremenai_1=addperemenai(input,head->type);
                head->peremenai_2=NULL;
            }
            else if(head->deistvie!='!')
            {
                head->peremenai_1=addperemenai(input,head->type);
                head->peremenai_2=addperemenai(input,head->type);
            }
            current=head;
            while (feof(input))
            {
            	add_el_in(current,input);
                current=current->next;
            }
            current=head;
            fclose(input);
            head_OUT=malloc(1*sizeof(List_OUT));
            output=fopen(File_OUT,"w");
            if (current->type==1)
            {
                head_OUT->rez=num(current->deistvie,current->peremenai_1,current->peremenai_2);
            }
            else
            {
                head_OUT->rez=vector(current->type,current->deistvie,current->peremenai_1,current->peremenai_2);
            }
            current_OUT=head_OUT;
            current_OUT->next_out;
            while (current!=NULL)
            {
                add_el_out(current_OUT,current);//ТУТ ОШИБКА
                current=current->next;
                current_OUT=current_OUT->next_out;
            }
            current_OUT=head_OUT;
            while (current_OUT!=NULL)
            {
                if (current->type>1)
                {
                    fprintf(output,"(");
                    for (int i=0;i<current->type;i++)
                    {
                        fprintf(output,"%f",current->peremenai_1[i]);
                    }
                    fprintf(output,")");
                    fprintf(output," %c ",current->deistvie);
                    fprintf(output,"(");
                    for (int i=0;i<current->type;i++)
                    {
                        fprintf(output,"%f",current->peremenai_2[i]);
                    }
                    fprintf(output,")");
                    fprintf(output," = ");
                    fprintf(output,"(");
                    for (int i=0;i<current->type;i++)
                    {
                        fprintf(output,"%f",head_OUT->rez[i]);
                    }
                    fprintf(output,")");
                    fprintf(output,"\n");
                }
                else
                {
                    fprintf(output,"%f %c %f = %f",current->peremenai_1[0],current->deistvie,current->peremenai_2[0],current_OUT->rez[0]);
                    fprintf(output,"/n");
                }
                current=current->next;
                current_OUT=current_OUT->next_out;
            }

        }
        fclose(output);
        printf("продолжить?\n");
        scanf(" %c", &end);
    }
    return 0;
}
