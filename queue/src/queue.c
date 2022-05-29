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
////////////////////////////////////////////////СТРУКТУРА ДЛЯ ВВОДА ДАННЫХ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct QUEUE_IN
{
    int size;
    char deistvie;
    float *peremenai_1;
    float *peremenai_2;
    struct QUEUE_IN *next_in;
}QUEUE_IN;
QUEUE_IN *head_in=NULL;
QUEUE_IN *tail_in=NULL;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////СТРУКТУРА ДЛЯ ВЫВОДА ДАННЫХ///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct QUEUE_OUT
{
    float *rez;
    struct QUEUE_OUT *next_out;
}QUEUE_OUT;
QUEUE_OUT *head_out=NULL;
QUEUE_OUT *tail_out=NULL;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЕЙСТВИЯ С ЧИСЛАМИ//////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float *num(char deistvie,float *peremenai_1, float *peremenai_2)
{
    float *rez;
    float var1;
    rez=malloc(1*sizeof(float));
    switch (deistvie)
    {
        case '+'://блок суммы
            rez[0]=peremenai_1[0]+peremenai_2[0];
            return rez;
        case '-'://блок разности
            rez[0]=peremenai_1[0]-peremenai_2[0];
            return rez;
        case '*'://блок умножения
            rez[0]=peremenai_1[0]*peremenai_2[0];
            return rez;
        case '/'://блок деления
            rez[0]=peremenai_1[0]/peremenai_2[0];
            return rez;
        case '^': //блок степени
            rez[0]=peremenai_1[0];//приравниваем для того, чтобы посчитать степень
            if (peremenai_2[0]==0)
            {
                rez[0]=1;
            }
            else if (peremenai_2[0]==1)
            {
                rez[0]=peremenai_1[0];
            }
            else
            {
                for (float i=1;i<peremenai_2[0];i++)
                {
                    rez[0]*=peremenai_1[0];
                }
            }
            return rez;
        case '!'://блок факториала
            var1=1;
            int var2=peremenai_1[0];//приравниваем для того, чтобы посчитать факториал
            for (int i=1;i<=var2;i++)
            {
            	var1=var1*i;
            }
            rez[0]=var1;
            return rez;

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
float*vector(char deistvie,int size, float *peremenai_1,float *peremenai_2)
{
    float *rez;
    switch (deistvie)
    {
        case '+':
            rez=malloc(size*sizeof(float));
            for (int i=0;i<size;i++)
            {
                rez[i]=peremenai_1[i]+peremenai_2[i];
            }
            return rez;
        case '-':
            rez=malloc(size*sizeof(float));
            for (int i=0;i<size;i++)
            {
                rez[i]=peremenai_1[i]-peremenai_2[i];
            }
            return rez;
        case '*':
            rez=malloc(1*sizeof(float));
            for (int i = 0; i<size; i++)
            {
                rez[0]+=(peremenai_1[i]*peremenai_2[i]);
            }
            return rez;
    }
    return peremenai_1;
    return peremenai_2;
    free(peremenai_1);
    free(peremenai_2);
    free(rez);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЧИСЛА////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float *addperemenai(FILE *input, int size)
{
    float *peremenai;
    peremenai=malloc(size*sizeof(float));
    for(int i=0;i<size;i++)
    {
        fscanf(input,"%f",&peremenai[i]);
    }
    return peremenai;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВВОДА///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_el_in(FILE *input)
{
    QUEUE_IN *tmp=malloc(1*sizeof(QUEUE_IN));
    fscanf(input,"%i %c",&tmp->size,&tmp->deistvie);
    if (tmp->deistvie!='!')
    {
        tmp->peremenai_1=addperemenai(input,tmp->size);
        tmp->peremenai_2=addperemenai(input,tmp->size);
    }
    else
    {
        tmp->peremenai_1=addperemenai(input,tmp->size);
        tmp->peremenai_2=NULL;
    }
    tmp->next_in=NULL;
    if (tail_in != NULL)//Неизвестная ошибка начинается тут
    {
        tail_in->next_in=tmp;
        tail_in=tmp;
    }
    else
    {
        head_in=tmp;
        tail_in=tmp;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВЫВОДА//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_el_out(QUEUE_OUT *head_OUT, QUEUE_IN *head_in)
{
    QUEUE_OUT *tmp_res=malloc(1*sizeof(QUEUE_OUT));
    if (head_in->size!=1)
    {
        tmp_res->rez=vector(head_in->deistvie,head_in->size,head_in->peremenai_1,head_in->peremenai_2);
    }
    else
    {
        tmp_res->rez=num(head_in->deistvie,head_in->peremenai_1,head_in->peremenai_2);
    }
    tmp_res->next_out=NULL;
    if (tail_out != NULL)
    {
        tail_out->next_out=tmp_res;
        tail_out=tmp_res;
    }
    else
    {
        head_out=tmp_res;
        tail_out=tmp_res;
    }
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
    char File_IN[259];
    char File_OUT[259];
    while(end!='n')
    {
        printf("Введите откуда читать\n");
        scanf("%s",File_IN);
        printf("Введите куда записать\n");
        scanf("%s",File_OUT);
        int cont=0;
        input=fopen(File_IN,"r");
        if (!feof(input))
        {
            while(!feof(input))
            {
                add_el_in(input);
                cont++;
            }
            fclose(input);
            output=fopen(File_OUT,"w");
            while (cont!=0)
            {
                add_el_out(head_out,head_in);
                cont--;
            }
            printf("перед закрытием");
            fclose(output);
            printf("перед закрытием");
            while (head_in!=NULL)
            {
                if (head_in->size!=1)
                {
                    fprintf(output," ( ");
                    for (int i=0;i<head_in->size;i++)
                    {
                        fprintf(output,"%1.f", head_in->peremenai_1[i]);
                    }
                    fprintf(output," ) ");
                    fprintf(output,"%c",head_in->deistvie);
                    fprintf(output," ( ");
                    for (int i=0;i<head_in->size;i++)
                    {
                        fprintf(output," %1.f ", head_in->peremenai_2[i]);
                    }
                    fprintf(output," ) ");
                    fprintf(output," = ");
                    fprintf(output," ( ");
                    for (int i=0;i<head_in->size;i++)
                    {
                        fprintf(output," %1.f ", head_out->rez[i]);
                    }
                    fprintf(output," ) \n");
                }
                else
                {
                    if(head_in->deistvie!='!')
                    {
                        fprintf(output," %1.f %c %1.f = %1.f ",head_in->peremenai_1[0],head_in->deistvie,head_in->peremenai_2[0],head_out->rez[0]);
                    }
                    else
                    {
                        fprintf(output," %1.f %c = %1.f ",head_in->peremenai_1[0],head_in->deistvie,head_out->rez[0]);
                    }
                }
                QUEUE_IN *to_del_in=head_in;
                head_in=head_in->next_in;
                QUEUE_OUT *to_del_out=head_out;
                head_out=head_out->next_out;
                free(to_del_in);
                free(to_del_out);
            }
        }
        printf("продолжить? \n");
        scanf(" %c", &end);
    }
    return 0;
}
