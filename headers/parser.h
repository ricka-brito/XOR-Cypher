#ifndef ARG_PARSER_H
#define ARG_PARSER_H
#include <stdbool.h>


// Function to get the parameter for a given flag
const char* getFlagParam(int argc, char *argv[], const char *flag);

// Function to verify if it has a param
const bool getFlag(int argc, char *argv[], const char *flag);

#endif // ARG_PARSER_H
