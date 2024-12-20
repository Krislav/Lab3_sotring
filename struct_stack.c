#include "struct_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initStack(stack* stc) {
    stc->top = NULL;
    stc->size = 0;
}

bool isEmpty(stack* stc) {
    return stc->top == NULL;
}

bool push(stack* stc, inf value) {
    elem* new_elem = (elem*)malloc(sizeof(elem));
    if (!new_elem) {
        printf("Memory allocation failed!\n");
        return false;
    }
    new_elem->data = value;
    new_elem->next = stc->top;
    stc->top = new_elem;
    ++stc->size;
    return true;
}

bool pop(stack* stc, inf* outValue) {
    if (isEmpty(stc)) {
        printf("Stack underflow!\n");
        return false;
    }
    elem* temp = stc->top;
    *outValue = temp->data;
    stc->top = stc->top->next;
    --stc->size;
    free(temp);
    return true;
}

bool peek(stack* stc, inf* outValue) {
    if (isEmpty(stc)) {
        printf("Stack is empty!\n");
        return false;
    }
    *outValue = stc->top->data;
    return true;
}

void freeStack(stack* stc) {
    inf tempValue;
    while (!isEmpty(stc)) {
        pop(stc, &tempValue);
    }
}