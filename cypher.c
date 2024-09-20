#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "headers/cypher.h"

char* generateKey() {
    // Allocate memory for the key on the heap
    char* hexStr = (char*)malloc(KEY_SIZE + 1);
    if (hexStr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Sets the "seed" for the rand function
    srand((unsigned int) time(0));

    // Fills the string with random hex characters
    for(int i = 0; i < KEY_SIZE; i++){
        sprintf(hexStr + i, "%x", rand() % 16);
    }
    hexStr[KEY_SIZE] = '\0'; // Null-terminate the string

    return hexStr;
}

void xorCypher(const char *inputFile, const char *outputFile, const char *key) {
    FILE *inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        perror("Error opening output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    size_t keyLength = strlen(key);
    int ch;
    size_t keyIndex = 0;

    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key[keyIndex], outFile);
        keyIndex = (keyIndex + 1) % keyLength;
    }

    fclose(inFile);
    fclose(outFile);
}

