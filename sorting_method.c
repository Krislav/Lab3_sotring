
#include <stdio.h>
#include "sorting_method.h"
#include <stdbool.h>

bool selection_sort(stack* stc, int (*compare)(inf a, inf b)){
    // Получить размер стека
    long size = getSize(stc);
    if (size <= 1) {
        return true; // Уже отсортировано
    }

    for (long i = 0; i < size - 1; ++i) {
        long minIndex = i;
        inf minValue;

        // Получить значение текущего минимального элемента
        if (!getElementAt(stc, minIndex, &minValue)) {
            return false; // Ошибка
        }

        // Найти минимальный элемент в оставшейся части стека
        for (long j = i + 1; j < size; ++j) {
            inf currentValue;
            if (!getElementAt(stc, j, &currentValue)) {
                return false; // Ошибка
            }

            // Сравнение через переданную функцию
            if (compare(currentValue, minValue) < 0) {
                minIndex = j;
                minValue = currentValue;
            }
        }

        // Поменять элементы, если найден минимальный элемент не совпадает с текущим
        if (minIndex != i) {
            if (!swapElements(stc, i, minIndex)) {
                return false; // Ошибка
            }
        }
    }

    return true; // Успешная сортировка
}