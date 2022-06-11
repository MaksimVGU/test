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

QUEUE_IN *add_el_in_queue(float *p_1, char d, float *p_2, int s);
QUEUE_OUT *add_el_out_queue(QUEUE_IN *head_in_queue);
QUEUE_IN *next_el_in_queue(QUEUE_IN *current);
QUEUE_OUT *next_el_out_queue(QUEUE_OUT *current);
QUEUE_IN *del_in_queue(QUEUE_IN *current);
QUEUE_OUT *del_out_queue(QUEUE_OUT *current);

#endif /* QUEUE_H_ */
