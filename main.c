#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "struct_inf.h"
#include "args_parser.h"

int main(int argc, char* argv[]) {
    ParsedArgs args = parseArguments(argc, argv);

    if (args.mode == MODE_GENERATE) {
        generateData(args.count, args.outputFile);
    } else if (args.mode == MODE_SORT) {
        sortData(args.inputFile, args.outputFile, args.sortType);
    } else if (args.mode == MODE_PRINT) {
        printData(args.inputFile, args.outputFile);
    } else {
        fprintf(stderr, "Error: Invalid mode.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}