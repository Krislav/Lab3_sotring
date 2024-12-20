
#ifndef STRUCT_STACK_H
#define STRUCT_STACK_H
#include <stdbool.h>
#include "struct_inf.h"

typedef struct elem{
    inf data;
    struct elem *next;
} elem; //Элемент стека
typedef struct {
    elem *top;
    long size;
} stack; //Стек
void initStack(stack* stc); // Инициализация стека
bool isEmpty(stack* stc); // Проверка, пуст ли стек
bool push(stack* stc, inf value); // Добавление элемента в стек
bool pop(stack* stc, inf* outValue); // Удаление элемента из стека
bool peek(stack* stc, inf* outValue); // Чтение верхнего элемента стека без удаления
void freeStack(stack* stc); // Освобождение памяти, занятой стеком
long getSize(stack* stc); // Возвращает размер стека
bool getElementAt(stack* stc, long index, inf* outValue); // Получает элемент по индеку
elem* getStart(stack* stc); // Получает указатель на начало
elem* getEnd(stack* stc); // Получает указатель на конец
elem* getNext(elem* node); // Получает следующий элемент
elem* getPrevious(stack* stc, elem* node); // Получает предидущий элемент
bool addAtBeginning(stack* stc, inf value); // Добовляет элемент в начало
bool addAtEnd(stack* stc, inf value); // Добовляет элемент в конец
bool addAt(stack* stc, inf value, long index); //  Добовляет элемент в произвольное место
bool removeAtBeginning(stack* stc, inf* outValue); // Удаляет элемент из начала
bool removeAtEnd(stack* stc, inf* outValue); //  Удаляет элемент из конца
bool removeAt(stack* stc, inf* outValue, long index); //  Удаляет элемент из произвольного места
bool swapElements(stack* stc, long index1, long index2); // Заменяет пару элементов
bool arrayToStack(stack* stc, inf* arr, long arrSize); // Из массива в стек
bool stackToArray(stack* stc, inf* arr, long arrSize); // Из стека в массив
#endif