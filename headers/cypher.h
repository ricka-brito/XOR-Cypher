#ifndef CYPHER_H
#define CYPHER_H

#define KEY_SIZE (256/4) // {bits you want}/4

char* generateKey();
void xorCypher(const char *inputFile, const char *outputFile, const char *key); 

#endif


