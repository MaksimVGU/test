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
char regul;
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	do
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
