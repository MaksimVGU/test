#include "num.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

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

                break;
            case 'q':

                break;
            case 's':

            	break;






        }
        printf("продолжить программу? \n");
        scanf(" %c", &end_program);
    }
    return 0;
}
