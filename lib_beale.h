#include "lib_list.h"
#include "lib_utils.h"

#define YES 1
#define NO 0

#define LINE_SIZE 1024
#define SPACE_CHARCODE -1
#define UNKNOWN_CHARCODE -2 

void encode_message(char *book, char *input, char *output, char *keyfile);

void decode_using_book(char *input, char *book, char *output);

void decode_using_keyfile(char *input, char *keyfile, char *output);
