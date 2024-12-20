#include <stdio.h>
#include "struct_inf.h"
#include <string.h>

int compareElements(inf a, inf b, PriorityOrder* order) {
    // Если порядок не задан, использовать базовый порядок
    int defaultOrder[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int* priorities = (order && order->priority_field[0] != -1) ? order->priority_field : defaultOrder;

    for (int i = 0; i < 9; ++i) {
        switch (priorities[i]) {
            case 0: {
                int cmp = strcmp(a.company_name, b.company_name);
                if (cmp != 0) return cmp;
                break;
            }
            case 1: {
                int cmp = strcmp(a.surname, b.surname);
                if (cmp != 0) return cmp;
                break;
            }
            case 2: {
                if (a.type != b.type) return (a.type < b.type) ? -1 : 1;
                break;
            }
            case 3: {
                if (a.year != b.year) return (a.year < b.year) ? -1 : 1;
                break;
            }
            case 4: {
                if (a.elevator != b.elevator) return (a.elevator < b.elevator) ? -1 : 1;
                break;
            }
            case 5: {
                if (a.garbage_chute != b.garbage_chute) return (a.garbage_chute < b.garbage_chute) ? -1 : 1;
                break;
            }
            case 6: {
                if (a.number_of_apartments != b.number_of_apartments) return (a.number_of_apartments < b.number_of_apartments) ? -1 : 1;
                break;
            }
            case 7: {
                if (a.number_of_levels != b.number_of_levels) return (a.number_of_levels < b.number_of_levels) ? -1 : 1;
                break;
            }
            case 8: {
                if (a.average_area != b.average_area) return (a.average_area < b.average_area) ? -1 : 1;
                break;
            }
        }
    }
    return 0; // Все поля равны
}