#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct_stack.h"

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

long getSize(stack* stc) {
    return stc->size;
}

bool getElementAt(stack* stc, long index, inf* outValue) {
    if (index < 0 || index >= stc->size) {
        printf("Index out of bounds!\n");
        return false;
    }
    elem* current = stc->top;
    for (long i = 0; i < index; ++i) {
        current = current->next;
    }
    *outValue = current->data;
    return true;
}

elem* getStart(stack* stc) {
    return stc->top;
}

elem* getEnd(stack* stc) {
    elem* current = stc->top;
    if (!current) return NULL;
    while (current->next) {
        current = current->next;
    }
    return current;
}

elem* getNext(elem* node) {
    return node ? node->next : NULL;
}

elem* getPrevious(stack* stc, elem* node) {
    if (stc->top == node) return NULL;
    elem* current = stc->top;
    while (current && current->next != node) {
        current = current->next;
    }
    return current;
}

bool addAtBeginning(stack* stc, inf value) {
    return push(stc, value);
}

bool addAtEnd(stack* stc, inf value) {
    elem* new_elem = (elem*)malloc(sizeof(elem));
    if (!new_elem) {
        printf("Memory allocation failed!\n");
        return false;
    }
    new_elem->data = value;
    new_elem->next = NULL;

    if (isEmpty(stc)) {
        stc->top = new_elem;
    } else {
        elem* end = getEnd(stc);
        end->next = new_elem;
    }
    ++stc->size;
    return true;
}

bool addAt(stack* stc, inf value, long index) {
    if (index < 0 || index > stc->size) {
        printf("Index out of bounds!\n");
        return false;
    }
    if (index == 0) return addAtBeginning(stc, value);
    if (index == stc->size) return addAtEnd(stc, value);

    elem* new_elem = (elem*)malloc(sizeof(elem));
    if (!new_elem) {
        printf("Memory allocation failed!\n");
        return false;
    }
    new_elem->data = value;

    elem* current = stc->top;
    for (long i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    new_elem->next = current->next;
    current->next = new_elem;
    ++stc->size;
    return true;
}

bool removeAtBeginning(stack* stc, inf* outValue) {
    return pop(stc, outValue);
}

bool removeAtEnd(stack* stc, inf* outValue) {
    if (isEmpty(stc)) {
        printf("Stack underflow!\n");
        return false;
    }
    if (stc->size == 1) return pop(stc, outValue);

    elem* current = stc->top;
    while (current->next && current->next->next) {
        current = current->next;
    }
    *outValue = current->next->data;
    free(current->next);
    current->next = NULL;
    --stc->size;
    return true;
}


bool removeAt(stack* stc, inf* outValue, long index) {
    if (index < 0 || index >= stc->size) {
        printf("Index out of bounds!\n");
        return false;
    }
    if (index == 0) return removeAtBeginning(stc, outValue);
    if (index == stc->size - 1) return removeAtEnd(stc, outValue);

    elem* current = stc->top;
    for (long i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    elem* temp = current->next;
    *outValue = temp->data;
    current->next = temp->next;
    free(temp);
    --stc->size;
    return true;
}

bool swapElements(stack* stc, long index1, long index2) {
    if (index1 < 0 || index1 >= stc->size || index2 < 0 || index2 >= stc->size || index1 == index2) {
        printf("Invalid indices!\n");
        return false;
    }
    elem* elem1 = stc->top;
    elem* elem2 = stc->top;
    for (long i = 0; i < index1; ++i) elem1 = elem1->next;
    for (long i = 0; i < index2; ++i) elem2 = elem2->next;

    inf temp = elem1->data;
    elem1->data = elem2->data;
    elem2->data = temp;
    return true;
}

bool arrayToStack(stack* stc, inf* arr, long arrSize) {
    for (long i = arrSize - 1; i >= 0; --i) {
        if (!push(stc, arr[i])) {
            return false;
        }
    }
    return true;
}

bool stackToArray(stack* stc, inf* arr, long arrSize) {
    if (arrSize < stc->size) {
        printf("Array size is too small!\n");
        return false;
    }
    elem* current = stc->top;
    for (long i = 0; current; ++i) {
        arr[i] = current->data;
        current = current->next;
    }
    return true;
}