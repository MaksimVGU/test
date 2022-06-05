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
#include "list.h"
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
