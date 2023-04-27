#include <stdio.h>
#include <stdlib.h>

#include "lib_utils.h"

int is_uppercase(char c)
{
    return c >= 'A' && c <= 'Z';
}

int is_lowercase(char c)
{
    return c >= 'a' && c <= 'z';
}

int is_numeric(char c)
{
    return c >= '0' && c <= '9';
}

int is_alphanumeric(char c)
{
    return is_uppercase(c) || is_lowercase(c) || is_numeric(c);
}

char to_lowercase(char c)
{
    return c + 32;
}

void throw_error(char *message)
{
    fprintf(stderr, "ERRO: %s!\n", message);
    exit(EXIT_FAILURE);
}
