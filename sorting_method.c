
#include <stdio.h>
#include <stdbool.h>
#include "sorting_method.h"

bool selectionSortStack(stack* stc, Comparator compare, PriorityOrder* order) {
    long size = getSize(stc);
    if (size <= 1) {
        return true;
    }

    for (long i = 0; i < size - 1; ++i) {
        long minIndex = i;
        inf minValue;

        if (!getElementAt(stc, minIndex, &minValue)) {
            return false;
        }

        for (long j = i + 1; j < size; ++j) {
            inf currentValue;
            if (!getElementAt(stc, j, &currentValue)) {
                return false;
            }

            if (compare(currentValue, minValue, order) < 0) {
                minIndex = j;
                minValue = currentValue;
            }
        }

        if (minIndex != i) {
            if (!swapElements(stc, i, minIndex)) {
                return false;
            }
        }
    }

    return true;
}