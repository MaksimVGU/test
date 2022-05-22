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
typedef struct List_IN
{
    int size;
    char deistvie;
    float *peremenai_1;
    float *peremenai_2;
    struct List_IN *next;
}List_IN;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////СТРУКТУРА ДЛЯ ВЫВОДА ДАННЫХ///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct List_OUT
{
    float *rez;
    struct List_OUT *next_out;
}List_OUT;
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
            rez=malloc(1);
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
void add_el_in(List_IN *current, FILE *input)
{
    List_IN *tmp=malloc(1*sizeof(List_IN));
    fscanf(input,"%i %c",&tmp->size,&tmp->deistvie);
    if (tmp->deistvie!='!')
    {
        tmp->peremenai_1=addperemenai(input,tmp->size);
        tmp->peremenai_2=addperemenai(input,tmp->size);
    }
    else if(tmp->deistvie=='!')
    {
        tmp->peremenai_1=addperemenai(input,tmp->size);
        tmp->peremenai_2=NULL;
    }
    tmp->next=NULL;
    current->next=tmp;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВЫВОДА//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_el_out(List_OUT *current_OUT, List_IN *current)
{
    List_OUT *tmp_res=malloc(1*sizeof(List_OUT));
    if (current->size!=1)
    {
        tmp_res->rez=vector(current->deistvie,current->size,current->peremenai_1,current->peremenai_2);
    }
    else
    {
        tmp_res->rez=num(current->deistvie,current->peremenai_1,current->peremenai_2);
    }
    tmp_res->next_out=NULL;
    current_OUT->next_out=tmp_res;
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
            fscanf(input, " %i %c",&head->size, &head->deistvie);
            if (head->deistvie != '!')
            {
                head->peremenai_1=addperemenai(input,head->size);
                head->peremenai_2=addperemenai(input,head->size);
            }
            else
            {
                head->peremenai_1=addperemenai(input,head->size);
                head->peremenai_2=NULL;
            }
            current=head;

            while (!feof(input))
            {
            	add_el_in(current,input);
                current=current->next;

            }

            head_OUT=malloc(sizeof(List_OUT));
            current=head;
            if (current->size==1)
            {
                head_OUT->rez=num(current->deistvie,current->peremenai_1,current->peremenai_2);

            }
            else
            {
                head_OUT->rez=vector(current->deistvie,current->size,current->peremenai_1,current->peremenai_2);

            }
            head_OUT->next_out=NULL;
            current=current->next;
            current_OUT=head_OUT;
            while (current!=NULL)
            {
                add_el_out(current_OUT,current);
                current=current->next;
                current_OUT=current_OUT->next_out;
            }
            current=head;
            current_OUT=head_OUT;
            fclose(input);
            output=fopen(File_OUT,"w");
            while (current_OUT!=NULL)
            {
                if (current->size>1)
                {
                    fprintf(output,"( ");
                    for (int i=0;i<current->size;i++)
                    {
                        fprintf(output," %1.f ",current->peremenai_1[i]);
                    }
                    fprintf(output," ) %c ( ",current->deistvie);
                    for (int i=0;i<current->size;i++)
                    {
                        fprintf(output," %1.f ",current->peremenai_2[i]);
                    }
                    fprintf(output," ) = ");
                    if (current->deistvie!='*')
                    {
                        fprintf(output," ( ");
                        for(int i=0;i<current->size;i++)
                        {
                            fprintf(output," %1.f ",current_OUT->rez[i]);
                        }
                        fprintf(output,")\n");
                    }
                    else
                    {
                        fprintf(output," %1.f\n",current_OUT->rez[0]);
                    }

                }
                else if (current->size==1)
                {
                    if (current->deistvie!='!')
                	{
                    	fprintf(output," %1.f %c %1.f = %1.f ",current->peremenai_1[0],current->deistvie,current->peremenai_2[0],current_OUT->rez[0]);
                    	fprintf(output,"\n");
                	}
                    else
                    {
                    	fprintf(output," %1.f %c = %1.f ",current->peremenai_1[0],current->deistvie,current_OUT->rez[0]);
                    	fprintf(output,"\n");
                    }
                }
                current=current->next;
                current_OUT=current_OUT->next_out;
            }
            fclose(output);
        }
        printf("продолжить? \n");
        scanf(" %c", &end);
    }
    return 0;
}
