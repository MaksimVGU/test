#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct QUEUE_IN				//СТРУКТУРА ДЛЯ ВВОДА ДАННЫХ
{
    int size;
    char deistvie;
    float *peremenai_1;
    float *peremenai_2;
    struct QUEUE_IN *next_in;
}QUEUE_IN;

typedef struct QUEUE_OUT			//СТРУКТУРА ДЛЯ ВЫВОДА ДАННЫХ
{
    int size;
    char deistvie;
    float *peremenai_1;
    float *peremenai_2;
    float *rez;
    struct QUEUE_OUT *next_out;
}QUEUE_OUT;



#endif /* QUEUE_H_ */
