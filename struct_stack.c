#include "struct_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Узел стека
typedef struct elem {
    inf data;
    struct elem* next;
} elem;

// Структура для стека
typedef struct {
    elem* top;
} stack;

// Инициализация стека
void initStack(stack* stc) {
    stc->top = NULL;
}

// Проверка, пуст ли стек
bool isEmpty(stack* stc) {
    return stc->top == NULL;
}

// Добавление элемента в стек
bool push(stack* stc, inf value) {
    elem* new_elem = (elem*)malloc(sizeof(elem));
    if (!new_elem) {
        printf("Memory allocation failed!\n");
        return false;
    }
    new_elem->data = value;
    new_elem->next = stc->top;
    stc->top = new_elem;
    return true;
}

// Удаление элемента из стека
bool pop(stack* stc, inf* outValue) {
    if (isEmpty(stc)) {
        printf("Stack underflow!\n");
        return false;
    }
    elem* temp = stc->top;
    *outValue = temp->data;
    stc->top = stc->top->next;
    free(temp);
    return true;
}

// Чтение верхнего элемента стека без удаления
bool peek(stack* stc, inf* outValue) {
    if (isEmpty(stc)) {
        printf("Stack is empty!\n");
        return false;
    }
    *outValue = stc->top->data;
    return true;
}

// Освобождение памяти, занятой стеком
void freeStack(stack* stc) {
    inf tempValue;
    while (!isEmpty(stc)) {
        pop(stc, &tempValue);
    }
}