#ifndef SRS_STACK_H_
#define SRS_STACK_H_

typedef struct STACK_IN 		//СТРУКТУРА ДЛЯ ВВОДА ДАННЫХ
{
    float *peremenai_1;
    float *peremenai_2;
    char deistvie;
    struct STACK_IN *next_in;
}STACK_IN;
typedef struct STACK_OUT		//СТРУКТУРА ДЛЯ ВЫВОДА ДАННЫХ
{
    float *peremenai_1;
    char deistvie;
    float *peremenai_2;
    float *rez;
    struct STACK_OUT *next_out;
}STACK_OUT;

STACK_IN *next_el_in_stack(STACK_IN *current);
STACK_OUT *next_el_out_stack(STACK_OUT *current);
STACK_IN *del_in_stack(STACK_IN *current);
STACK_OUT *del_out_stack(STACK_OUT *current);
STACK_IN *add_el_in_stack(float *p_1, float *p_2, char d);
STACK_OUT *add_el_out_stack(STACK_IN *head_in_stack,float *rez);

#endif /* SRS_STACK_H_ */
