
#ifndef STRUCT_STACK_H
#define STRUCT_STACK_H

typedef struct elem{
    struct elem *previous;
    inf data;
    struct elem *next;
} elem; //Элемент двухсвязного списка
typedef struct {
    elem *head;
    elem *tail;
    long size;
} list; //Двухсвязный список
typedef struct {
    char name[128];
    char surname[128];
    char initials[2];
    char magazine_name[128];
    int year;
    int volume;
    int include_in_RINC;
    int number_of_pages;
    int citations;
} inf; //Структура для данных

#endif