// лицензи€: GNU GPL
// калькул€тор считает со знаками после зап€той, способен на:
// сумма, знак +
// разность, знак -
// умножение, знак *
// деление, знак /
// степень, знак ^
// факториал, знак !
// чтобы вернутьс€ в начало программы будем использловать do.. while. ѕользователь должен будет ввести y если хочет продолжить работать в калькул€торе или n чтобы прекратить
// ƒл€ работы через файл, надо выбрать режим работы: вектор v калькул€тор s
// далее, дл€ векторонго ввести через пробел размер_вектора координааты_первого_вектора координаты_второго_вектора действие
// дл€ калькул€тора: выбираем_действие вводим_первое_число вводим_второе_число(если не факториал)
// выбираем, продолжить ли работу
#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////‘”Ќ ÷»я ƒ≈…—“¬»я — „»—Ћјћ»//////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double *num(char deistvie,double *peremenai_1, double *peremenai_2)
{
    double *rez;
    rez=malloc(1*sizeof(double));
    char sign;
    switch (sign)
    {
        case '+'://блок суммы
            //fprintf(output,"введите первое число a=");
            //fscanf(input," %lg",&a);
            //fprintf(output,"введите первое число b=");
            //fscanf (input," %lg",&b);
            //fprintf(output," %lg plus %lg = %lg\n", a,b, a+b);
            rez[0]=peremenai_1[0]+peremenai_2[0];
            return rez;
            break;
        case '-'://блок разности
            //fprintf(output,"введите первое число a=");
            //fscanf(input," %lg",&a);
            //fprintf(output," введите первое число b=");
            //fscanf (input," %lg",&b);
            //fprintf (output," %lg minus %lg = %lg\n", a,b,a-b);
            rez[0]=peremenai_1[0]-peremenai_2[0];
            return rez;
            break;
        case '*'://блок умножени€
            //fprintf(output," введите первое число a=");
            //fscanf(input," %lg",&a);
            //fprintf(output," введите первое число b=");
            //fscanf (input," %lg",&b);
            //fprintf (output," %lg multiply by %lg = %lg\n", a,b, a*b);
            rez[0]=peremenai_1[0]*peremenai_2[0];
            return rez;
            break;
        case '/'://блок делени€
            //fprintf(output," введите первое число a=");
            //fscanf(input," %lg",&a);
            //fprintf(output," введите первое число b=");
            //fscanf (input," %lg",&b);
            //fprintf (output," %lg divide by %lg = %lg\n", a,b,a/b);
            return rez;
            break;
        case '^': //блок степени
            //fprintf(output," введите первое число a=");
            //fscanf(input," %lg",&a);
            //fprintf(output,"введите первое число b=");
            //fscanf (input," %lg",&b);
            rez[0]=peremenai_1[0];//приравниваем дл€ того, чтобы посчитать степень
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
                for (int i=1;i<peremenai_2;i++)
                    {
                        rez[0]*=peremenai_1[0];
                    }
                //fprintf(output,"%lg в степени %lg = %g\n",a,b,d);
            }
            return rez;
            break;
        case '!'://блок факториала
            rez[0]=1;//приравниваем дл€ того, чтобы посчитать факториал
            //fprintf(output," введите первое число a=");
            //fscanf(input," %lg",&a);
            if (peremenai_1[0]>=0)//тк факториал 0=1 тогда сделаем такой цикл
            {
                for (int i=0;i<peremenai_1;i++)
                {
                    rez[0]=rez[0]*(i+1);
                }
                //fprintf(output,"факториал %lg = %lg\n",a,d);
            }
            else
            {
                //fprintf(output," nop\n");
            }
            return rez;
            break;
    }
    return peremenai_1;
    return peremenai_2;
    free(peremenai_1);
    free(peremenai_2);
    free(rez);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////‘”Ќ ÷»я ƒ≈…—“¬»я — ¬≈ “ќ–јћ»////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double *vector(int type, char deistvie,double *peremenai_1,double *peremenai_2)
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
    return 'nop';
        break;
    }
    return peremenai_1;
    return peremenai_2;
    free(peremenai_1);
    free(peremenai_2);
    free(rez);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////—“–” “”–ј ƒЋя ¬¬ќƒј ƒјЌЌџ’////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct List_IN
{
    int type;
    char deistvie;
    double *peremenai_1;
    double *peremenai_2;
    struct List_IN *next
}List_IN;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////—“–” “”–ј ƒЋя ¬џ¬ќƒј ƒјЌЌџ’///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct List_OUT
{
    float *rez;
    struct List_OUT *next_out
}List_OUT;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////‘”Ќ ÷»я ƒЋя ƒќЅј¬Ћ≈Ќ»я „»—Ћј////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////‘”Ќ ÷»я ƒЋя ƒќЅј¬Ћ≈Ќ»я ЁЋ≈ћ≈Ќ“ј/////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double *addelement(List_IN *current, FILE *input)
{
    List_IN *tmp_in=malloc(1*sizeof(List_IN));
    fscanf(input,"%i %c", &tmp_in->type,&tmp_in->deistvie);
    if (tmp_in->deistvie='!')
    {
        tmp_in->peremenai_1=addperemenai(input,tmp_in->type);
        tmp_in->peremenai_2=NULL;
    }
    else if(tmp_in->deistvie!='!')
    {
        tmp_in->peremenai_1=addperemenai(input,tmp_in->type);
        tmp_in->peremenai_2=addperemenai(input,tmp_in->type);
    }
    tmp_in->next=NULL;
    current->next=tmp_in;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////‘”Ќ ÷»я ƒЋя ƒќЅј¬Ћ≈Ќ»я ЁЋ≈ћ≈Ќ“ј –≈«”Ћ№“ј“ј//////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void addelement_out(List_OUT *current_res, List_IN *current)
{
    List_OUT *tmp_out=malloc(1*sizeof(List_OUT));
    if(current->type==1)
    {
        tmp_out->rez=num(current->deistvie,current->peremenai_1,current->peremenai_2);
    }
    else
    {
        tmp_out->rez=vector(current->type,current->deistvie,current->peremenai_1,current->peremenai_2);
    }
    tmp_out->next_out=NULL;
    current_res->next_out=tmp_out;
}
int main(int argc,char *argv[])
{   char end='y';
    char regul;
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    FILE *input,*output;
    List_IN *head,*current;
    List_OUT *head_OUT,*current_OUT;
    char File_IN[259];
    char File_OUT[259];
    while(end!='n')
    {

        printf("¬ведите откуда читать\n");
        scanf("%s",File_IN);
        printf("¬ведите куда записать\n");
        scanf("%s",File_OUT);
        input=fopen(File_IN,"r");
        if (!feof(input))
        {
            head=malloc(1*sizeof(List_IN));
            fscanf(input,"%i %c",&head->type, &head->deistvie);
            if (head->deistvie='!')
            {
                head->peremenai_1=addperemenai(input,head->type);
                head->peremenai_2=NULL;
            }
            else if(head->deistvie!='!')
            {
                head->peremenai_1=addperemenai(input,head->type);
                head->peremenai_2=addperemenai(input,head->type);
            }
            current=head;
            addelement(current,input);
            current=current->next;
        }
        current=head;
        fclose(input);
        output=fopen(File_OUT,"w");
        while (current!=NULL)
        {
            if (current->type==1)
            {
                head_OUT->rez=num(current->deistvie,current->peremenai_1,current->peremenai_2);
            }
            else
            {
                head_OUT->rez=vector(current->type,current->deistvie,current->peremenai_1,current->peremenai_2);
            }
            if (current->type==1)
            {
                fprintf(output,"%f %c %f = %f",current->peremenai_1,current->deistvie,current->peremenai_2,head_OUT->rez);
            }
            else
            {
                fprintf(output,"(%f) %c (%f) = %f",current->peremenai_1,current->deistvie,current->peremenai_2,head_OUT->rez);
            }
            current=current->next;
        }
        fclose(output);
        printf("продолжить?\n");
        scanf(" %c", &end);
    }
    return 0;
}

