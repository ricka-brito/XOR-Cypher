#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "headers/parser.h"

const char* getFlagParam(int argc, char *argv[], const char *flag) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], flag) == 0) {
            // Ensure there's another argument after the flag
            if (i + 1 < argc) {
                return argv[i + 1];
            } else {
                fprintf(stderr, "Error: '%s' flag requires a parameter.\n", flag);
                return NULL;
            }
        }
    }
    return NULL; // Flag not found
}

const bool getFlag(int argc, char *argv[], const char *flag) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], flag) == 0) {
            return true;
        }
    }
    return false;
}
