#ifndef FILE_BUFFER_H
#define FILE_BUFFER_H

long getFileSize(const char *filename);

// Function to get the base name without extension
char* getBaseName(const char* filename);
    
#endif