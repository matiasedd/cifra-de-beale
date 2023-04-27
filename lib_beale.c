#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib_beale.h"

void encode_message(char *book, char *input, char *output, char *keyfile)
{
    FILE *book_stream, *input_stream, *keyfile_stream;

    if ((book_stream = fopen(book, "r")) == NULL)
        throw_error("Nao foi possivel abrir o livro cifra");

    if ((input_stream = fopen(input, "r")) == NULL)
        throw_error("Nao foi possivel abrir a mensagem original");

    // TODO: implementar a codificacao
    int counter = 0;
    char line[LINE_SIZE];

    struct char_node *char_node;
    struct char_list *char_list = create_char_list();

    if (char_list == NULL)
        throw_error("Nao foi possivel alocar memoria para a lista");

    while (fgets(line, LINE_SIZE, book_stream) != NULL)
    {
        char *token = strtok(line, " ");

        while (token != NULL)
        {
            char letter = token[0];

            if (is_alphanumeric(letter))
            {
                if (is_uppercase(letter))
                    letter = to_lowercase(letter);

                if ((char_node = find_char_node(char_list, letter)) == NULL)
                {
                    insert_char_node(char_list, letter);
                    continue;
                }

                insert_num_node(char_node->num_list, counter);
                counter++;
            }

            token = strtok(NULL, " ");
        }
    }

    keyfile_stream = fopen(keyfile, "w");

    if (keyfile_stream == NULL)
        throw_error("Nao foi possivel abrir o arquivo de chave");

    char_node = char_list->head;

    while (char_node != NULL)
    {
        fprintf(keyfile_stream, "%c:", char_node->data);
        struct num_node *num_node = char_node->num_list->head;

        while (num_node != NULL)
        {
            fprintf(keyfile_stream, " %d", num_node->data);
            num_node = num_node->next;
        }

        fprintf(keyfile_stream, "\n");
        char_node = char_node->next;
    }

    destroy_char_list(char_list);
    fclose(keyfile_stream);
    fclose(input_stream);
    fclose(book_stream);
}

void decode_using_book(char *input, char *book, char *output)
{
    FILE *book_stream, *input_stream;

    if ((book_stream = fopen(book, "r")) == NULL)
        throw_error("Nao foi possivel abrir o livro cifra");

    if ((input_stream = fopen(input, "r")) == NULL)
        throw_error("Nao foi possivel abrir a mensagem codificada");

    // TODO: implementar a decodificacao

    fclose(book_stream);
    fclose(input_stream);
}

void decode_using_keyfile(char *input, char *keyfile, char *output)
{
    FILE *keyfile_stream, *input_stream;

    if ((keyfile_stream = fopen(keyfile, "r")) == NULL)
        throw_error("Nao foi possivel abrir o arquivo de chaves");

    if ((input_stream = fopen(input, "r")) == NULL)
        throw_error("Nao foi possivel abrir a mensagem codificada");

    // TODO: implementar a decodificacao

    fclose(keyfile_stream);
    fclose(input_stream);
}