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
QUEUE_IN *head_in_queue=NULL;
QUEUE_IN *tail_in_queue=NULL;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////СТРУКТУРА ДЛЯ ВЫВОДА ДАННЫХ///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct QUEUE_OUT
{
    int size;
    char deistvie;
    float *peremenai_1;
    float *peremenai_2;
    float *rez;
    struct QUEUE_OUT *next_out;
}QUEUE_OUT;
QUEUE_OUT *head_out_queue=NULL;
QUEUE_OUT *tail_out_queue=NULL;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ПЕРЕХОДА НА СЛЕД ЭЛЕМЕНТ////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QUEUE_IN *next_el_in_queue(QUEUE_IN *current)
{
    QUEUE_IN *next_el = current->next_in;
    return next_el;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ПЕРЕХОДА НА СЛЕД ЭЛЕМЕНТ(OUT)///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QUEUE_OUT *next_el_out_queue(QUEUE_OUT *current)
{
    QUEUE_OUT *next_el = current->next_out;
    return next_el;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ УДАЛЕНЯИ ЭЛЕМЕНТА///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QUEUE_IN *del_in_queue(QUEUE_IN *current)
{
    QUEUE_IN *del=current;
    current=next_el_in_queue(current);
    free(del);
    return current;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ УДАЛЕНЯИ ЭЛЕМЕНТА(OUT)//////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QUEUE_OUT *del_out_queue(QUEUE_OUT *current)
{
    QUEUE_OUT *del=current;
    current=next_el_out_queue(current);
    free(del);
    return current;
}
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
            break;
        case '-'://блок разности
            rez[0]=peremenai_1[0]-peremenai_2[0];
            break;
        case '*'://блок умножения
            rez[0]=peremenai_1[0]*peremenai_2[0];
            break;
        case '/'://блок деления
            rez[0]=peremenai_1[0]/peremenai_2[0];
            break;
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
            break;
        case '!'://блок факториала
            var1=1;
            int var2=peremenai_1[0];//приравниваем для того, чтобы посчитать факториал
            for (int i=1;i<=var2;i++)
            {
            	var1=var1*i;
            }
            rez[0]=var1;
            break;

    }
    return rez;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЕЙСТВИЯ С ВЕКТОРАМИ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float*vector(char deistvie,int size, float *peremenai_1,float *peremenai_2)
{
    float *rez;
    switch (deistvie)
    {
        case '+'://блок суммы
            rez=malloc(size*sizeof(float));
            for (int i=0;i<size;i++)
            {
                rez[i]=peremenai_1[i]+peremenai_2[i];
            }
            break;
        case '-'://блок разности
            rez=malloc(size*sizeof(float));
            for (int i=0;i<size;i++)
            {
                rez[i]=peremenai_1[i]-peremenai_2[i];
            }
            break;
        case '*'://блок умножние
            rez=malloc(1);
            for (int i = 0; i<size; i++)
            {
                rez[0]+=(peremenai_1[i]*peremenai_2[i]);
            }
            break;
    }
    return rez;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВВОДА///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_el_in_queue(float *p_1, char d, float *p_2, int s)
{
		QUEUE_IN *tmp=malloc(1*sizeof(QUEUE_IN));
		tmp->deistvie=d;
		tmp->size=s;
		if (d !='!')
		{
			tmp->peremenai_1=p_1;
			tmp->peremenai_2=p_2;
		}
		else
		{
			tmp->peremenai_1=p_1;
			tmp->peremenai_2=NULL;
		}
		tmp->next_in=NULL;
		if (tail_in_queue != NULL)
		{
			tail_in_queue->next_in=tmp;
			tail_in_queue=tmp;
		}
		else
		{
			head_in_queue=tmp;
			tail_in_queue=tmp;
		}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВЫВОДА//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_el_out_queue(QUEUE_OUT *head_OUT, QUEUE_IN *head_in)
{
    QUEUE_OUT *tmp_res=malloc(1*sizeof(QUEUE_OUT));
    if (head_in->size>1)
    {
        tmp_res->size=head_in->size;
        tmp_res->peremenai_1=head_in->peremenai_1;
        tmp_res->deistvie=head_in->deistvie;
        tmp_res->peremenai_2=head_in->peremenai_2;
        tmp_res->rez=vector(head_in->deistvie,head_in->size,head_in->peremenai_1,head_in->peremenai_2);

    }
    else if (head_in->size==1)
    {
        tmp_res->size=head_in->size;
        tmp_res->peremenai_1=head_in->peremenai_1;
        tmp_res->deistvie=head_in->deistvie;
        tmp_res->peremenai_2=head_in->peremenai_2;
        tmp_res->rez=num(head_in->deistvie,head_in->peremenai_1,head_in->peremenai_2);
    }
    tmp_res->next_out=NULL;
    if (tail_out_queue != NULL)
    {
        tail_out_queue->next_out=tmp_res;
        tail_out_queue=tmp_res;
    }
    else
    {
        head_out_queue=tmp_res;
        tail_out_queue=tmp_res;
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
    	float *p_1,*p_2;
    	char d;
    	int s;
        printf("Введите откуда читать\n");
        scanf("%s",File_IN);
        printf("Введите куда записать\n");
        scanf("%s",File_OUT);
        input=fopen(File_IN,"r");
        if (!feof(input))
        {
            while(!feof(input))
            {
            	fscanf(input," %i",&s);
            	fscanf(input," %c",&d);
            	p_1=malloc(s*sizeof(float));
            	p_2=malloc(s*sizeof(float));
            	if(d != '!')
            	{
            		for(int i=0;i<s;i++)
            		{
            			fscanf(input," %f",&p_1[i]);
            		}
            		for(int i=0;i<s;i++)
            		{
            			fscanf(input," %f",&p_2[i]);
            		}
            	}
            	else
            	{
            		for(int i=0;i<s;i++)
            		{
            			fscanf(input," %f",&p_1[i]);
            		}
            	}
                add_el_in_queue(p_1, d , p_2 , s);
            }
            fclose(input);
            output=fopen(File_OUT,"w");
            while (head_in_queue != NULL)
            {
            	add_el_out_queue(head_out_queue,head_in_queue);
                head_in_queue=del_in_queue(head_in_queue);
            }
            while (head_out_queue!=NULL)
            {
                if (head_out_queue->size>1)
                {
                    fprintf(output," ( ");
                    for (int i=0;i<head_out_queue->size;i++)
                    {
                        fprintf(output," %1.f ", head_out_queue->peremenai_1[i]);
                    }
                    fprintf(output," ) ");
                    fprintf(output,"%c",head_out_queue->deistvie);
                    fprintf(output," ( ");
                    for (int i=0;i<head_out_queue->size;i++)
                    {
                        fprintf(output," %1.f ", head_out_queue->peremenai_2[i]);
                    }
                    fprintf(output," ) ");
                    fprintf(output," = ");
                    fprintf(output," ( ");
                    if(head_out_queue->deistvie != '*')
                    {
                    	for (int i=0;i<head_out_queue->size;i++)
                    	{
                    		fprintf(output," %0.1f ", head_out_queue->rez[i]);
                    	}
                    }
                    else
                    {
                    	fprintf(output," %0.1f ", head_out_queue->rez[0]);
                    }

                    fprintf(output," )\n");
                }
                else if (head_out_queue->size==1)
                {
                    if(head_out_queue->deistvie != '!')
                    {
                        fprintf(output," %0.1f %c %0.1f = %0.1f \n",head_out_queue->peremenai_1[0],head_out_queue->deistvie,head_out_queue->peremenai_2[0],head_out_queue->rez[0]);
                    }
                    else
                    {
                        fprintf(output," %0.1f %c = %0.1f \n",head_out_queue->peremenai_1[0],head_out_queue->deistvie,head_out_queue->rez[0]);
                    }
                }
                head_out_queue=del_out_queue(head_out_queue);
            }
            fclose(output);
            tail_in_queue=NULL;
            tail_out_queue=NULL;
            head_in_queue=NULL;
            head_out_queue=NULL;
            free(p_1);
            free(p_2);
        }
        printf("продолжить? \n");
        scanf(" %c", &end);
    }
    return 0;
}
