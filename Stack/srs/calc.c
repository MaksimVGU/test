// лицензия: GNU GPL
// калькулятор считает со знаками после запятой, способен на:
// сумма, знак +
// разность, знак -
// умножение, знак *
// деление, знак /
// степень, знак ^
// факториал, знак !
// чтобы вернуться в начало программы будем использловать do.. while. Пользователь должен будет ввести y если хочет продолжить работать в калькуляторе или n чтобы прекратить
// Для работы через файл, надо ввести сначала два числа(для факториала, пишем на месте второго числа 0), после пишем в файле факториал
#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////СТРУКТУРА ДЛЯ ВВОДА ДАННЫХ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct STACK_IN
{
    float *peremenai_1;
    float *peremenai_2;
    char deistvie;
    struct STACK_IN *next_in;
}STACK_IN;
STACK_IN *head_in_stack=NULL;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////СТРУКТУРА ДЛЯ ВЫВОДА ДАННЫХ///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct STACK_OUT
{
    float *peremenai_1;
    char deistvie;
    float *peremenai_2;
    float *rez;
    struct STACK_OUT *next_out;
}STACK_OUT;
STACK_OUT *head_out_stack=NULL;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ПЕРЕХОДА НА СЛЕД ЭЛЕМЕНТ////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
STACK_IN *next_el_in_stack(STACK_IN *current)
{
    STACK_IN *next_el = current->next_in;
    return next_el;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ПЕРЕХОДА НА СЛЕД ЭЛЕМЕНТ(OUT)///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
STACK_OUT *next_el_out_stack(STACK_OUT *current)
{
    STACK_OUT *next_el = current->next_out;
    return next_el;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ УДАЛЕНЯИ ЭЛЕМЕНТА///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
STACK_IN *del_in_stack(STACK_IN *current)
{
    STACK_IN *del=current;
    current=next_el_in_stack(current);
    free(del);
    return current;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ УДАЛЕНЯИ ЭЛЕМЕНТА(OUT)//////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
STACK_OUT *del_out_stack(STACK_OUT *current)
{
    STACK_OUT *del=current;
    current=current->next_out;
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
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВВОДА///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_el_in_stack(float *p_1, float *p_2, char d)
{
    STACK_IN *tmp=malloc(1*sizeof(STACK_IN));
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
    tmp->deistvie=d;
    if (head_in_stack != NULL)
	{
		tmp->next_in=head_in_stack;
        head_in_stack=tmp;
	}
	else
	{
        tmp->next_in=NULL;
        head_in_stack=tmp;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВЫВОДА//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_el_out_stack(STACK_IN *head_in_stack,float *rez)
{
    STACK_OUT *tmp=malloc(1*sizeof(STACK_OUT));
	if (head_in_stack->deistvie !='!')
	{
		tmp->peremenai_1=head_in_stack->peremenai_1;
		tmp->peremenai_2=head_in_stack->peremenai_2;
	}
	else
	{
    	tmp->peremenai_1=head_in_stack->peremenai_1;
		tmp->peremenai_2=NULL;
	}
    tmp->deistvie=head_in_stack->deistvie;
    tmp->rez=rez;
    if (head_out_stack != NULL)
	{
		tmp->next_out=head_out_stack;
        head_out_stack=tmp;
	}
	else
	{
		tmp->next_out=NULL;
		head_out_stack=tmp;
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
    	float *p1,*p2;
    	float *rez;
    	char d;
    	int chet_2=0;
        printf("Введите откуда читать\n");
        scanf("%s",File_IN);
        printf("Введите куда записать\n");
        scanf("%s",File_OUT);
        input=fopen(File_IN,"r");
        if (!feof(input))
        {

            while(!feof(input))
            {
            	p1=malloc(1*sizeof(float));
            	p2=malloc(1*sizeof(float));
            	fscanf(input," %f",&p1[0]);
            	fscanf(input," %f",&p2[0]);
                fscanf(input," %c",&d);
                add_el_in_stack(p1, p2, d);
                chet_2++;
            }
            fclose(input);
            output=fopen(File_OUT,"w");
            while (head_in_stack != NULL)
            {
                rez=num(head_in_stack->deistvie,head_in_stack->peremenai_1,head_in_stack->peremenai_2);
            	add_el_out_stack(head_in_stack,rez);
            	head_in_stack=del_in_stack(head_in_stack);
            }
            while (chet_2 != 1)
            {
                if(head_out_stack->deistvie != '!')
                {
                    fprintf(output," %0.1f %c %0.1f = %0.1f \n",head_out_stack->peremenai_1[0],head_out_stack->deistvie,head_out_stack->peremenai_2[0],head_out_stack->rez[0]);
                }
                else
                {
                    fprintf(output," %0.1f %c = %0.1f \n",head_out_stack->peremenai_1[0],head_out_stack->deistvie,head_out_stack->rez[0]);
                }
                head_out_stack=del_out_stack(head_out_stack);
                chet_2--;
            }
            head_out_stack=del_out_stack(head_out_stack);
            fclose(output);
            free(rez);
            free(p1);
            free(p2);
        }
        printf("продолжить? \n");
        scanf(" %c", &end);
    }
    return 0;
}
