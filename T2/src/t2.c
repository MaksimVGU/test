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
        printf("������� ������ ������\n");
        scanf("%s",filename1);
        printf("������� ���� ��������\n");
        scanf("%s",filename2);
        input=fopen(filename1,"r");
        output=fopen(filename2,"w");
        do
        {
            int size;
            fscanf(input," %i", &size);
            if (size==1)
            {
                double a,b,i,d; // ������ ���������� ���� double
                char deistvie; // ������ ���������� ���� char
                fscanf(input," %c", &deistvie); //������ �
                switch(deistvie) //���� �������
                {
                    case '+'://���� �����
                        //fprintf(output,"������� ������ ����� a=");
                        fscanf(input," %lg",&a);
                        //fprintf(output,"������� ������ ����� b=");
                        fscanf (input," %lg",&b);
                        fprintf(output," %lg plus %lg = %lg\n", a,b, a+b);
                        break;
                    case '-'://���� ��������
                        //fprintf(output,"������� ������ ����� a=");
                        fscanf(input," %lg",&a);
                        //fprintf(output," ������� ������ ����� b=");
                        fscanf (input," %lg",&b);
                        fprintf (output," %lg minus %lg = %lg\n", a,b,a-b);
                        break;
                    case '*'://���� ���������
                        //fprintf(output," ������� ������ ����� a=");
                        fscanf(input," %lg",&a);
                        //fprintf(output," ������� ������ ����� b=");
                        fscanf (input," %lg",&b);
                        fprintf (output," %lg multiply by %lg = %lg\n", a,b, a*b);
                        break;
                    case '/'://���� �������
                        //fprintf(output," ������� ������ ����� a=");
                        fscanf(input," %lg",&a);
                        //fprintf(output," ������� ������ ����� b=");
                        fscanf (input," %lg",&b);
                        fprintf (output," %lg divide by %lg = %lg\n", a,b,a/b);
                        break;
                    case '^': //���� �������
                        //fprintf(output," ������� ������ ����� a=");
                        fscanf(input," %lg",&a);
                        //fprintf(output,"������� ������ ����� b=");
                        fscanf (input," %lg",&b);
                        d=a;//������������ ��� ����, ����� ��������� �������
                        for (i=1;i<b;i++)
                            {
                                d=d*a;
                            }
                        fprintf(output,"%lg � ������� %lg = %g\n",a,b,d);
                        break;
                    case '!'://���� ����������
                        d=1;//������������ ��� ����, ����� ��������� ���������
                        //fprintf(output," ������� ������ ����� a=");
                        fscanf(input," %lg",&a);
                        if (a>=0)//�� ��������� 0=1 ����� ������� ����� ����
                        {
                            for (i=0;i<a;i++)
                            {
                                d=d*(i+1);
                            }
                            fprintf(output,"��������� %lg = %lg\n",a,d);
                        }
                        else
                            fprintf(output," nop\n");
                        break;
                    default:
                        fprintf (output," nop\n");

                }
            }
            if(size>=2)//���� ��������
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
                    case '+': //���� ��������
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
                    case '-': //���� ���������
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
                    case '*': //���� ��������� ����������
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
            //fprintf(output,"\n ������ ���������� (y/n) ?\n");
            fscanf (input," %c", &regul);
        }
        while((regul)=='y');
        if ((regul)=='n')
            {
                fprintf(output,"end\n");
            }
        else
            fprintf(output,"�� ����� �����������, ��� ���������� ���� ���� n, ��������� ��������� ��-�� ����� ������\n");
        fclose(input);
        fclose(output);
        printf("����������?\n");
        scanf(" %c", &end);
    }
    return 0;
}
