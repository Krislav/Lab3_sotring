#include <stdbool.h>
#ifndef STRUCT_INF_H
#define STRUCT_INF_H


typedef struct {
    char company_name[128];
    char surname[128];
    int type; // 1-панельный, 2-кирпичный, 3-монолитный
    int year;
    bool elevator;
    bool garbage_chute;
    int number_of_apartments;
    int number_of_levels;
    float average_area;
} inf; //Структура для данных
typedef int (*Comparator)(inf a, inf b, PriorityOrder* order);
typedef struct {
    int priority_field[9];
} PriorityOrder;  // Массив приоритетов полей (индексы 0-8 соответствуют полям структуры)
int compareElements(inf a, inf b, PriorityOrder* order); // Функция компоратор

#endif