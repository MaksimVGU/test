// ��������: GNU GPL
// ����������� ������� �� ������� ����� �������, �������� ��:
// �����, ���� +
// ��������, ���� -
// ���������, ���� *
// �������, ���� /
// �������, ���� ^
// ���������, ���� !
// ����� ��������� � ������ ��������� ����� ������������� do.. while. ������������ ������ ����� ������ y ���� ����� ���������� �������� � ������������ ��� n ����� ����������
// ��� ������ ����� ����, ���� ������� ����� ������: ������ v ����������� s
// �����, ��� ���������� ������ ����� ������ ������_������� �����������_�������_������� ����������_�������_������� ��������
// ��� ������������: ��������_�������� ������_������_����� ������_������_�����(���� �� ���������)
// ��������, ���������� �� ������
#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////������� �������� � �������//////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double *num(char deistvie,double *peremenai_1, double *peremenai_2)
{
    double *rez;
    rez=malloc(1*sizeof(double));
    switch (deistvie)
    {
        case '+'://���� �����
            rez[0]=peremenai_1[0]+peremenai_2[0];
            return rez;
            break;
        case '-'://���� ��������
            rez[0]=peremenai_1[0]-peremenai_2[0];
            return rez;
            break;
        case '*'://���� ���������
            rez[0]=peremenai_1[0]*peremenai_2[0];
            return rez;
            break;
        case '/'://���� �������
            return rez;
            break;
        case '^': //���� �������
            rez[0]=peremenai_1[0];//������������ ��� ����, ����� ��������� �������
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
                //fprintf(output,"%lg � ������� %lg = %g\n",a,b,d);
            }
            return rez;
            break;
        case '!'://���� ����������
            rez[0]=1;//������������ ��� ����, ����� ��������� ���������
            if (peremenai_1[0]>=0)//�� ��������� 0=1 ����� ������� ����� ����
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
//////////////////////////////////////////////������� �������� � ���������////////////////////////////////////////////////
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
////////////////////////////////////////////////��������� ��� ����� ������////////////////////////////////////////////////
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
////////////////////////////////////////////////��������� ��� ������ ������///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct List_OUT
{
    double *rez;
    struct List_OUT *next_out;
}List_OUT;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////������� ��� ���������� �����////////////////////////////////////////////////
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

        printf("������� ������ ������\n");
        scanf("%s",File_IN);
        printf("������� ���� ��������\n");
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
            current=current->next;
        }
        fclose(input);
        current=head;
        output=fopen(File_OUT,"w");
        while (current!=NULL)
        {
            if (current->type==1)
            {
                head_OUT->rez=num(current->deistvie,current->peremenai_1,current->peremenai_2);
                fprintf(output,"%f %c %f = %f",current->peremenai_1,current->deistvie,current->peremenai_2,head_OUT->rez);
            }
            else
            {
                head_OUT->rez=vector(current->type,current->deistvie,current->peremenai_1,current->peremenai_2);
                fprintf(output,"(%f) %c (%f) = (%f)",current->peremenai_1,current->deistvie,current->peremenai_2,head_OUT->rez);
            }
            current=current->next;
            current_OUT=current_OUT->next_out;
        }
        fclose(output);
        printf("����������?\n");
        scanf(" %c", &end);
    }
    return 0;
}
