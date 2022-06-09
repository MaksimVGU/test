#include "list.h"
#include "queue.h"
#include "rez.h"

QUEUE_IN *head_in_queue=NULL;
QUEUE_IN *tail_in_queue=NULL;
QUEUE_OUT *head_out_queue=NULL;
QUEUE_OUT *tail_out_queue=NULL;

int main(int argc,char *argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    char end_program='y';
    while (end_program != 'n')
    {
        char rezim;
        char end='y';
        FILE *input,*output;
        char File_IN[259];
        char File_OUT[259];
        printf("Выберите режим: l,q или s \n");
        scanf(" %c",&rezim);
        switch (rezim)
        {
            case 'l':
                List_IN *head,*current;
                List_OUT *head_OUT,*current_OUT;
                while (end != 'n')
                {
                    printf("Введите откуда читать\n");
                    scanf("%s",File_IN);
                    printf("Введите куда записать\n");
                    scanf("%s",File_OUT);
                    input=fopen(File_IN,"r");
                    head=malloc(1*sizeof(List_IN));
                    fscanf(input, " %i %c",&head->size, &head->deistvie);
                    if (!feof(input))//добавляем головной элемент ввода
                    {
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
                    printf("Продолжить? \n");
                    scanf(" %c", &end);
                }
                break;
            case 'q':
                float *p_1,*p_2;
                char d;
                int s;
                while(end!='n')
                {
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
                            add_el_in_queue(p_1,d,p_2,s);
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
                                    fprintf(output," %0.1f %c %f = %0.1f \n",head_out_queue->peremenai_1[0],head_out_queue->deistvie,head_out_queue->peremenai_2[0],head_out_queue->rez[0]);
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
                        free(p_1);
                        free(p_2);
                    }
                    printf("продолжить? \n");
                    scanf(" %c", &end);
                }
                break;
        }
        printf("продолжить программу? \n");
        scanf(" %c", &end_program);
    }
    return 0;
}


