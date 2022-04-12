// �����: ������ ������
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
char type;
char regul;
double coordinate;
int main(int argc,char *argv[])
{
	FILE *input,*output;
	input =fopen("input.txt","r");
	output=fopen("output.txt","w");
	do
    {

        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
        fprintf(output,"������(v)/�����������(s)\n");
        fscanf(input," %c", &type);
        if (type=='s')
        {
            // ����� ������� ��� ������� � �� �����������
            fprintf(output," �����, ���� +\n");
            fprintf(output," ��������, ���� -\n");
            fprintf(output," ���������, ���� *\n");
            fprintf(output," �������, ���� /\n");
            fprintf(output," �������, ���� ^\n");
            fprintf(output," ���������, ���� !\n\n");
            double a,b,i,d; // ������ ���������� ���� double
            char c; // ������ ���������� ���� char
            fprintf(output," ������� �������� "); // ������� ������� � ����������
            fscanf(input," %c", &c); //������ �
            switch(c) //���� �������
            {
                case '+'://���� �����
                    fprintf(output,"������� ������ ����� a=");
                    fscanf(input," %lg",&a);
                    fprintf(output,"������� ������ ����� b=");
                    fscanf (input," %lg",&b);
                    fprintf(output," %lg plus %lg = %lg", a,b, a+b);
                    break;
                case '-'://���� ��������
                    fprintf(output,"������� ������ ����� a=");
                    fscanf(input," %lg",&a);
                    fprintf(output," ������� ������ ����� b=");
                    fscanf (input," %lg",&b);
                    fprintf (output," %lg minus %lg = %lg", a,b,a-b);
                    break;
                case '*'://���� ���������
                    fprintf(output," ������� ������ ����� a=");
                    fscanf(input," %lg",&a);
                    fprintf(output," ������� ������ ����� b=");
                    fscanf (input," %lg",&b);
                    fprintf (output," %lg multiply by %lg = %lg", a,b, a*b);
                    break;
                case '/'://���� �������
                    fprintf(output," ������� ������ ����� a=");
                    fscanf(input," %lg",&a);
                    fprintf(output," ������� ������ ����� b=");
                    fscanf (input," %lg",&b);
                    fprintf (output," %lg divide by %lg = %lg", a,b,a/b);
                    break;
                case '^': //���� �������
                    fprintf(output," ������� ������ ����� a=");
                    fscanf(input," %lg",&a);
                    fprintf(output,"������� ������ ����� b=");
                    fscanf (input," %lg",&b);
                    d=a;//������������ ��� ����, ����� ��������� �������
                    for (i=1;i<b;i++)
                        {
                            d=d*a;
                        }
                    fprintf(output,"%lg � ������� %lg = %g",a,b,d);
                    break;
                case '!'://���� ����������
                    d=1;//������������ ��� ����, ����� ��������� ���������
                    fprintf(output," ������� ������ ����� a=");
                    fscanf(input," %lg",&a);
                    if (a>=0)//�� ��������� 0=1 ����� ������� ����� ����
                    {
                        for (i=0;i<a;i++)
                        {
                            d=d*(i+1);
                        }
                        fprintf(output,"��������� %lg = %lg",a,d);
                    }
                    else
                        fprintf(output," nop");
                    break;
                default:
                    fprintf (output," nop");

            }
        }
        if(type=='v')//���� ��������
        {
        	int rez=0;
            int *t;
            int *a1;
            int *b1;
            char deistvie;
            double a,b;
            int size;
            fprintf(output,"������� ������ ������� ");
            fscanf(input,"%i",&size);
            t=malloc(size*sizeof(int));
            a1=malloc(size*sizeof(int));
            b1=malloc(size*sizeof(int));
            for(int i=0;i<size;i++)
            {
                fprintf(output,"������� ����������� ������� a ");
                fscanf(input,"%lf",&a);
                a1[i]=a;
            }
            for (int i = 0; i < size; i++)
            {
                fprintf(output,"������� ����������� ������� b ");
                fscanf(input,"%lf",&b);
                b1[i]=b;
            }
            fprintf(output,"������� ��������\n");
            fprintf(output,"�������� ������� a � b --- '+'\n");
            fprintf(output,"��������� �� ������� a ������ b --- '-'\n");
            fprintf(output,"�������� �������� ������ a �� b --- '*'\n");
            fscanf(input," %c",&deistvie);
            switch (deistvie)
            {
                case '+': //���� ��������
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
                    fprintf(output,")");
                break;
                case '-': //���� ���������
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
                    fprintf(output,")");

                break;
                case '*': //���� ��������� ����������
                    for (int i = 0; i < size; i++)
                    {
                        t[i]=a1[i]*b1[i];
                    }
                    fprintf(output,"(");
                    for (int i=0;i<size;i++)
                    {
                    	fprintf(output," %i ", a1[i]);
                    }
                    fprintf(output,")");
                    fprintf(output," * ");
                    fprintf(output,"(");
                    for (int i=0;i<size;i++)
                    {
                    	fprintf(output," %i ", b1[i]);
                    }
                    fprintf(output,")");
                    fprintf(output," = ");
                    for (int i=0;i<size;i++)
                    {
                    	rez+=t[i];
                    }
                        fprintf(output,"%i ", rez);
                break;
                default:
                fprintf(output,"to be contine");
                break;
                free(a1);
                free(b1);
                free(t);
            }
        }
        fprintf(output,"\n ������ ���������� (y/n) ?\n");
        fscanf (input," %c", &regul);
    }
    while((regul)=='y');
    if ((regul)=='n')
        {
            fprintf(output,"end");
        }
    else
        fprintf(output,"�� ����� �����������, ��� ���������� ���� ���� n, ��������� ��������� ��-�� ����� ������");
    fclose(input);
    fclose(output);
    return 0;
}
