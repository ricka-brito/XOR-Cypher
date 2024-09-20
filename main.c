#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "headers/fileBuffer.h"
#include "headers/cypher.h"
#include "headers/parser.h"

// TODO: COMMENT THE CODE
// TODO: APPEND THE EXTENSION OF THE FILE IN THE ENC FILE


int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    // Setting the locale. (e.g. format decimals to caret instead of dots)

    bool isEncrypt = getFlag(argc, argv, "-E");
    bool isDecrypt = getFlag(argc, argv, "-D");
    const char* filename = getFlagParam(argc, argv, "-f");
    if (filename == NULL) {
        printf("\n Please provide the filename");
        exit(EXIT_FAILURE);
    }
    const char* key;

    if (isEncrypt) {
        bool removeAfterEncrypt = getFlag(argc, argv, "-r");
        bool hasKey = getFlag(argc, argv, "-k");
        if (hasKey) {
            key = getFlagParam(argc, argv, "-k");
            if (key == NULL) exit(EXIT_FAILURE);
            printf("WARNING: You provided a key to encrypt. Ensure that the key is long enough to make it secure.\n");
        } else {
            key = generateKey();
        }

        // Encrypt the file
        char* outName = strcat(getBaseName(filename), ".enc");
        xorCypher(filename, outName, key);
        if (removeAfterEncrypt) remove(filename);
        printf("File encrypted successfully. \nYour key: '%s'\n", key);
    } else if (isDecrypt) {
        key = getFlagParam(argc, argv, "-k");
        if (key == NULL) {
            printf("Please provide a key to decrypt.\n");
            exit(EXIT_FAILURE);
        }

        // Decrypt the file
        char* cryptName = strcat(getBaseName(filename), ".enc");
        xorCypher(cryptName, filename, key);
        printf("File decrypted successfully.\n");
    } else {
        printf("Please specify whether to encrypt or decrypt the file using -E or -D.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
