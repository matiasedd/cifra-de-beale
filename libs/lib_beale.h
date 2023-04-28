#include "lib_utils.h"
#include "lib_num_list.h"
#include "lib_char_list.h"

#define NO 0
#define YES 1

#define LINE_SIZE 1024

#define SPACE_CHARCODE -1
#define UNKNOWN_CHARCODE -2 

/*
 * Responsável por codificar uma mensagem.
 * Recebe como parâmetros o nome do arquivo que contém o livro, o nome do arquivo que contém a mensagem a ser codificada, o nome do arquivo de saída e o nome do arquivo de chaves.
 * Não possui retorno.
 */
void encode_message(char *book, char *input, char *output, char *keyfile);

/*
 * Responsável por decodificar uma mensagem usando um livro cifra.
 * Recebe como parâmetros o nome do arquivo que contém o livro, o nome do arquivo que contém a mensagem a ser decodificada e o nome do arquivo de saída.
 * Não possui retorno.
 */
void decode_using_book(char *input, char *book, char *output);

/*
 * Responsável por decodificar uma mensagem usando um arquivo de chave.
 * Recebe como parâmetros o nome do arquivo que contém a mensagem a ser decodificada, o nome do arquivo que contém a chave e o nome do arquivo de saída.
 * Não possui retorno.
 */
void decode_using_keyfile(char *input, char *keyfile, char *output);
