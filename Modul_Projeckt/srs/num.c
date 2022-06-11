#include "num.h"
#include <stdio.h>
#include <stdlib.h>

float *num(char deistvie,float *peremenai_1, float *peremenai_2)	//ФУНКЦИЯ ДЕЙСТВИЯ С ЧИСЛАМИ
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
