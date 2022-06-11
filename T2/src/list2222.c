// лицензия: GNU GPL
// калькулятор считает со знаками после запятой, способен на:
// сумма, знак +
// разность, знак -
// умножение, знак *
// деление, знак /
// степень, знак ^
// факториал, знак !
// чтобы вернуться в начало программы будем использловать do.. while. Пользователь должен будет ввести y если хочет продолжить работать в калькуляторе или n чтобы прекратить
//Для работы необходимо:В файл для ввода необходимо ввести попорядку
//числовой режим работы или векторный(1 или более соответственно). далее
//для векторного вводим координаты по-порядку. для числового нужно ввести
//число а и число b. Далее ввести название файла для ввода данных и для
//вывода.
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
//////////////////////////////////////////////ФУНКЦИЯ ПЕРЕХОДА В НАЧАЛО СПИСКА////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List_IN *to_head_in(List_IN *current, List_IN *head)
{
    current=head;
    return current;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ПЕРЕХОДА В НАЧАЛО СПИСКА(out)///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List_OUT *to_head_out(List_OUT *current_out, List_OUT *head_out)
{
    current_out=head_out;
    return current_out;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ПЕРЕХОДА НА СЛЕД ЭЛЕМЕНТ////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List_IN *next_el_in(List_IN *current)
{
    List_IN *next_el = current->next;
    return next_el;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ ПЕРЕХОДА НА СЛЕД ЭЛЕМЕНТ(OUT)///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List_OUT *next_el_out(List_OUT *current)
{
    List_OUT *next_el = current->next_out;
    return next_el;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ УДАЛЕНЯИ ЭЛЕМЕНТА///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List_IN *del_in(List_IN *current)
{
    List_IN *del=current;
    current=next_el_in(current);
    free(del);
    return current;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////ФУНКЦИЯ УДАЛЕНЯИ ЭЛЕМЕНТА(OUT)//////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List_OUT *del_out(List_OUT *current)
{
    List_OUT *del=current;
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
        if (!feof(input))//добавляем головной элемент ввода
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
            current=to_head_in(current,head);
            while (!feof(input))
            {
            	add_el_in(current,input);
                current=next_el_in(current);

            }

            head_OUT=malloc(sizeof(List_OUT));
            current=to_head_in(current,head);
            if (current->size==1)
            {
                head_OUT->rez=num(current->deistvie,current->peremenai_1,current->peremenai_2);

            }
            else
            {
                head_OUT->rez=vector(current->deistvie,current->size,current->peremenai_1,current->peremenai_2);

            }
            head_OUT->next_out=NULL;
            current=next_el_in(current);
            current_OUT=to_head_out(current_OUT,head_OUT);
            while (current!=NULL)
            {
                add_el_out(current_OUT,current);
                current=next_el_in(current);
                current_OUT=next_el_out(current_OUT);
            }
            current=to_head_in(current,head);
            current_OUT=to_head_out(current_OUT,head_OUT);
            fclose(input);
            output=fopen(File_OUT,"w");
            while (current_OUT!=NULL)
            {
                if (current->size>1)
                {
                    fprintf(output,"( ");
                    for (int i=0;i<current->size;i++)
                    {
                        fprintf(output," %0.01f ",current->peremenai_1[i]);
                    }
                    fprintf(output," ) %c ( ",current->deistvie);
                    for (int i=0;i<current->size;i++)
                    {
                        fprintf(output," %0.01f ",current->peremenai_2[i]);
                    }
                    fprintf(output," ) = ");
                    if (current->deistvie!='*')
                    {
                        fprintf(output," ( ");
                        for(int i=0;i<current->size;i++)
                        {
                            fprintf(output," %0.01f ",current_OUT->rez[i]);
                        }
                        fprintf(output,")\n");
                    }
                    else
                    {
                        fprintf(output," %0.01f\n",current_OUT->rez[0]);
                    }

                }
                else if (current->size==1)
                {
                    if (current->deistvie!='!')
                	{
                    	fprintf(output," %0.01f %c %0.01f = %0.01f ",current->peremenai_1[0],current->deistvie,current->peremenai_2[0],current_OUT->rez[0]);
                    	fprintf(output,"\n");
                	}
                    else
                    {
                    	fprintf(output," %0.01f %c = %0.01f ",current->peremenai_1[0],current->deistvie,current_OUT->rez[0]);
                    	fprintf(output,"\n");
                    }
                }
                current=del_in(current);
                current_OUT=del_out(current_OUT);
            }
            fclose(output);
        }
        printf("продолжить? \n");
        scanf(" %c", &end);
    }
    return 0;
}
