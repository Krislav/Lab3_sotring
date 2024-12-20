
#ifndef STRUCT_STACK_H
#define STRUCT_STACK_H
#include <stdbool.h>

typedef struct elem{
    inf data;
    struct elem *next;
} elem; //Элемент стека
typedef struct {
    elem *top;
    long size;
} stack; //Стек
typedef struct {
    char company_name[128];
    char surname[128];
    int type; // 1-панельный, 2-кирпичный, 3-монолитный
    int year;
    int elevator;
    int garbage_chute;
    int number_of_apartments;
    int number_of_levels;
    float average_area;
} inf; //Структура для данных
void initStack(stack* stc); // Инициализация стека
bool isEmpty(stack* stc); // Проверка, пуст ли стек
bool push(stack* stc, inf value); // Добавление элемента в стек
bool pop(stack* stc, inf* outValue); // Удаление элемента из стека
bool peek(stack* stc, inf* outValue); // Чтение верхнего элемента стека без удаления
void freeStack(stack* stc); // Освобождение памяти, занятой стеком
#endif