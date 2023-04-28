#include "lib_list.h"
#include "lib_utils.h"

#define LINE_SIZE 1024

#define SPACE_CHAR -1
#define UNKNOWN_CHAR -2 

void encode_message(char *book, char *input, char *output, char *keyfile);

void decode_using_book(char *input, char *book, char *output);

void decode_using_keyfile(char *input, char *keyfile, char *output);
