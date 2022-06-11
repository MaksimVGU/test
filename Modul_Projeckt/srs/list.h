#ifndef SRS_LIST_H_
#define SRS_LIST_H_
#include <stdlib.h>
#include <stdio.h>
typedef struct List_IN					//СТРУКТУРА ДЛЯ ВВОДА ДАННЫХ
{
    int size;
    char deistvie;
    float *peremenai_1;
    float *peremenai_2;
    struct List_IN *next;
}List_IN;

typedef struct List_OUT					//СТРУКТУРА ДЛЯ ВЫВОДА ДАННЫХ
{
    float *rez;
    struct List_OUT *next_out;
}List_OUT;
float *addperemenai(FILE *input, int size);//ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЧИСЛА
void add_el_in(List_IN *current, FILE *input);//ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВВОДА
void add_el_out(List_OUT *current_OUT, List_IN *current);//ФУНКЦИЯ ДЛЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА ВЫВОДА
List_IN *to_head_in(List_IN *current, List_IN *head);//ФУНКЦИЯ ПЕРЕХОДА В НАЧАЛО СПИСКА
List_OUT *to_head_out(List_OUT *current_out, List_OUT *head_out);//ФУНКЦИЯ ПЕРЕХОДА В НАЧАЛО СПИСКА(out)
List_IN *next_el_in(List_IN *current);//ФУНКЦИЯ ПЕРЕХОДА НА СЛЕД ЭЛЕМЕНТ
List_OUT *next_el_out(List_OUT *current);//ФУНКЦИЯ ПЕРЕХОДА НА СЛЕД ЭЛЕМЕНТ(OUT)
List_IN *del_in(List_IN *current);//ФУНКЦИЯ УДАЛЕНЯИ ЭЛЕМЕНТА
List_OUT *del_out(List_OUT *current);//ФУНКЦИЯ УДАЛЕНЯИ ЭЛЕМЕНТА(OUT)

#endif /* SRS_LIST_H_ */
