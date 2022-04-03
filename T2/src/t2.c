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
#include <stdio.h>
#include <stdlib.h>
char type;
char regul;
double coordinate;
int main(void)
{
	do
    {
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
        printf("������(V)/�����������(K)\n");
        scanf(" %c", &type);
        if (type=='k')
        {
            // ����� ������� ��� ������� � �� �����������
            printf(" �����, ���� +\n");
            printf(" ��������, ���� -\n");
            printf(" ���������, ���� *\n");
            printf(" �������, ���� /\n");
            printf(" �������, ���� ^\n");
            printf(" ���������, ���� !\n\n");
            double a,b,i,d; // ������ ���������� ���� double
            char c; // ������ ���������� ���� char
            printf(" ������� �������� "); // ������� ������� � ����������
            scanf(" %c", &c); //������ �
            switch(c) //���� �������
            {
                case '+'://���� �����
                    printf("������� ������ ����� a=");
                    scanf(" %lg",&a);
                    printf("������� ������ ����� b=");
                    scanf (" %lg",&b);
                    printf(" %lg plus %lg = %lg", a,b, a+b);
                    break;
                case '-'://���� ��������
                    printf( "������� ������ ����� a=");
                    scanf(" %lg",&a);
                    printf(" ������� ������ ����� b=");
                    scanf (" %lg",&b);
                    printf ( " %lg minus %lg = %lg", a,b,a-b);
                    break;
                case '*'://���� ���������
                    printf(" ������� ������ ����� a=");
                    scanf(" %lg",&a);
                    printf(" ������� ������ ����� b=");
                    scanf (" %lg",&b);
                    printf ( " %lg multiply by %lg = %lg", a,b, a*b);
                    break;
                case '/'://���� �������
                    printf(" ������� ������ ����� a=");
                    scanf(" %lg",&a);
                    printf(" ������� ������ ����� b=");
                    scanf (" %lg",&b);
                    printf ( " %lg divide by %lg = %lg", a,b,a/b);
                    break;
                case '^': //���� �������
                    printf(" ������� ������ ����� a=");
                    scanf(" %lg",&a);
                    printf("������� ������ ����� b=");
                    scanf (" %lg",&b);
                    d=a;//������������ ��� ����, ����� ��������� �������
                    for (i=1;i<b;i++)
                        {
                            d=d*a;
                        }
                    printf("%lg � ������� %lg = %g",a,b,d);
                    break;
                case '!'://���� ����������
                    d=1;//������������ ��� ����, ����� ��������� ���������
                    printf(" ������� ������ ����� a=");
                    scanf(" %lg",&a);
                    if (a>=0)//�� ��������� 0=1 ����� ������� ����� ����
                    {
                        for (i=0;i<a;i++)
                        {
                            d=d*(i+1);
                        }
                        printf("��������� %lg = %lg",a,d);
                    }
                    else
                        printf(" nop");
                    break;
                default:
                    printf (" nop");

            }
        }
        if(type=='v')
        {
        	int rez=0;
            int *t;
            int *a1;
            int *b1;
            char deistvie;
            double a,b;
            int size;
            printf("������� ������ �������");
            scanf("%i",&size);
            t=malloc(size*sizeof(int));
            a1=malloc(size*sizeof(int));
            b1=malloc(size*sizeof(int));
            for(int i=0;i<size;i++)
            {
                printf("������� ����������� ������� a ");
                scanf("%lf",&a);
                a1[i]=a;
            }
            for (int i = 0; i < size; i++)
            {
                printf("������� ����������� ������� b ");
                scanf("%lf",&b);
                b1[i]=b;
            }
            printf("������� ��������\n");
            printf("�������� ������� a � b --- '+'\n");
            printf("��������� �� ������� a ������ b --- '-'\n");
            printf("�������� �������� ������ a �� b --- '*'\n");
            scanf(" %c",&deistvie);
            switch (deistvie)
            {
                case '+': //���� ��������
                    for (int i = 0; i < size; i++)
                    {
                        t[i]=a1[i]+b1[i];
                    }
                    for (int i = 0; i < size; i++)
                    {
                        printf("%i ", t[i]);
                    }
                break;
                case '-': //���� ���������
                    for (int i = 0; i < size; i++)
                    {
                        t[i]=a1[i]-b1[i];
                    }
                    for (int i = 0; i < size; i++)
                    {
                        printf("%i ", t[i]);
                    }

                break;
                case '*': //���� ��������� ����������
                    for (int i = 0; i < size; i++)
                    {
                        t[i]=a1[i]*b1[i];
                    }
                    for (int i=0;i<size;i++)
                    {
                    	rez+=t[i];
                    }
                        printf("%i ", rez);
                break;
                default:
                printf("to be contine");
                break;
            }
        }
        printf("\n ������ ���������� (y/n) ?\n");
        scanf (" %c", &regul);
    }
    while((regul)=='y');
    if ((regul)=='n')
        {
            printf("end");
        }
    else
        printf("�� ����� �����������, ��� ���������� ���� ���� n, ��������� ��������� ��-�� ����� ������");

    return 0;
}
