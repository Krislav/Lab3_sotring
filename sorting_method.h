
#ifndef SORTING_METHOD_H
#define SORTING_METHOD_H
#include <stdbool.h>
#include "struct_stack.h"
#include "struct_inf.h"

bool selectionSortStack(stack* stc, Comparator compare, PriorityOrder* order); //Выполняет сортировку выбором.

#endif