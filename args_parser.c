#include "struct_inf.h"
#include "struct_stack.h"
#include "sorting_method.h"
#include "args_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ParsedArgs parseArguments(int argc, char* argv[]) {
    ParsedArgs args = {0};
    args.mode = 0;
    args.count = 0;
    args.inputFile = NULL;
    args.outputFile = NULL;
    args.sortType = "asc"; // По умолчанию сортировка по возрастанию

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--generate") == 0 || strcmp(argv[i], "-g") == 0) {
            args.mode = MODE_GENERATE;
            if (i + 1 < argc) {
                args.count = atoi(argv[++i]);
            } else {
                fprintf(stderr, "Error: Missing number of entries to generate.\n");
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(argv[i], "--sort") == 0 || strcmp(argv[i], "-s") == 0) {
            args.mode = MODE_SORT;
        } else if (strcmp(argv[i], "--print") == 0 || strcmp(argv[i], "-P") == 0) {
            args.mode = MODE_PRINT;
        } else if (strncmp(argv[i], "--in=", 5) == 0 || strncmp(argv[i], "-i", 2) == 0) {
            args.inputFile = strchr(argv[i], '=') ? strchr(argv[i], '=') + 1 : argv[++i];
        } else if (strncmp(argv[i], "--out=", 6) == 0 || strncmp(argv[i], "-o", 2) == 0) {
            args.outputFile = strchr(argv[i], '=') ? strchr(argv[i], '=') + 1 : argv[++i];
        } else if (strncmp(argv[i], "--type=", 7) == 0 || strncmp(argv[i], "-t", 2) == 0) {
            args.sortType = strchr(argv[i], '=') ? strchr(argv[i], '=') + 1 : argv[++i];
        } else {
            fprintf(stderr, "Error: Unknown argument %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }

    if (args.mode == 0) {
        fprintf(stderr, "Error: No valid mode specified.\n");
        exit(EXIT_FAILURE);
    }

    return args;
}

void generateData(int count, const char* outputFile) {
    FILE* out = outputFile ? fopen(outputFile, "w") : stdout;
    if (!out) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; ++i) {
        fprintf(out, "Company%d,Micro%d,%d,%d,%s,%s,%d,%d,%.2f\n",
                rand() % (count*2), rand() % (count*2), rand() % 3 + 1, 1980 + rand() % 41,
                rand() % 2 ? "true" : "false", rand() % 2 ? "true" : "false",
                rand() % 100 + 1, rand() % 20 + 1, (rand() % 1000) / 10.0);
    }

    if (out != stdout) {
        fclose(out);
    }
}


void sortData(const char* inputFile, const char* outputFile, const char* sortType) {
    FILE* in = inputFile ? fopen(inputFile, "r") : stdin;
    FILE* out = outputFile ? fopen(outputFile, "w") : stdout;

    if (!in) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    if (!out) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    stack stc;
    initStack(&stc);

    char line[256];
    while (fgets(line, sizeof(line), in)) {
        inf data;
        char temp_elevator[6], temp_garbage_chute[6];
        sscanf(line, "%127[^,],%127[^,],%d,%d,%5[^,],%5[^,],%d,%d,%f",
               data.company_name, data.surname, &data.type, &data.year,
               temp_elevator, temp_garbage_chute, &data.number_of_apartments,
               &data.number_of_levels, &data.average_area);

        data.elevator = (strcmp(temp_elevator, "true") == 0);
        data.garbage_chute = (strcmp(temp_garbage_chute, "true") == 0);

        push(&stc, data);
    }

    PriorityOrder order = { {0, 1, 2, 3, 4, 5, 6, 7, 8} }; // Базовый порядок сортировки

    if (strcmp(sortType, "desc") == 0) {
        for (int i = 0; i < 9; ++i) {
            order.priority_field[i] = 8 - i;
        }
    }

    if (!selectionSortStack(&stc, compareElements, &order)) {
        fprintf(stderr, "Error: Sorting failed.\n");
        exit(EXIT_FAILURE);
    }

    while (!isEmpty(&stc)) {
        inf data;
        pop(&stc, &data);
        fprintf(out, "%s,%s,%d,%d,%s,%s,%d,%d,%.2f\n",
                data.company_name, data.surname, data.type, data.year,
                data.elevator ? "true" : "false", data.garbage_chute ? "true" : "false",
                data.number_of_apartments, data.number_of_levels, data.average_area);
    }

    if (in != stdin) fclose(in);
    if (out != stdout) fclose(out);
}


void printData(const char* inputFile, const char* outputFile) {
    FILE* in = inputFile ? fopen(inputFile, "r") : stdin;
    FILE* out = outputFile ? fopen(outputFile, "w") : stdout;

    if (!in) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    if (!out) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    fprintf(out, "%-15s %-15s %-10s %-5s %-8s %-12s %-10s %-8s %-10s\n",
        "Company Name", "Microdistrict", "Type", "Year", "Elevator",
        "Garbage Chute", "Apartments", "Levels", "Avg Area");

    while (fgets(line, sizeof(line), in)) {
        char company_name[128], surname[128], elevator[6], garbage_chute[6];
        int type, year, number_of_apartments, number_of_levels;
        float average_area;

        if (sscanf(line, "%127[^,],%127[^,],%d,%d,%5[^,],%5[^,],%d,%d,%f",
                   company_name, surname, &type, &year, elevator, garbage_chute,
                   &number_of_apartments, &number_of_levels, &average_area) == 9) {
            fprintf(out, "%-15s %-15s %-10d %-5d %-8s %-12s %-10d %-8d %-10.2f\n",
                    company_name, surname, type, year, elevator, garbage_chute,
                    number_of_apartments, number_of_levels, average_area);
        }
    }


    if (in != stdin) fclose(in);
    if (out != stdout) fclose(out);
}
