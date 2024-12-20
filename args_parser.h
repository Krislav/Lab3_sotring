#ifndef ARGS_PARSER_H
#define ARGS_PARSER_H
#include <stdbool.h>
#include "struct_inf.h"
#define MODE_GENERATE 1
#define MODE_SORT 2
#define MODE_PRINT 3

typedef struct {
    int mode;
    int count; // Количество данных для генерации
    const char* inputFile; // Имя входного файла
    const char* outputFile; // Имя выходного файла
    const char* sortType; // Тип сортировки: "asc" или "desc"
} ParsedArgs;
ParsedArgs parseArguments(int argc, char* argv[]);
void generateData(int count, const char* outputFile);
void sortData(const char* inputFile, const char* outputFile, const char* sortType);
void printData(const char* inputFile, const char* outputFile);

#endif