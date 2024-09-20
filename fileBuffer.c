#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/fileBuffer.h"

long getFileSize(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) exit(EXIT_FAILURE); // Error opening file

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);

    return size;
}

// Function to get the base name without extension
char* getBaseName(const char* filename) {
    static char baseName[256];
    strcpy(baseName, filename);
    
    // Find the last occurrence of the dot (.)
    char* dot = strrchr(baseName, '.');
    
    if (dot) {
        // Null-terminate the string at the dot position
        *dot = '\0';
    }
    
    return baseName;
}
