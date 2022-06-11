#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

float*vector(char deistvie,int size, float *peremenai_1,float *peremenai_2) 	//ФУНКЦИЯ ДЕЙСТВИЯ С ВЕКТОРАМИ
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
