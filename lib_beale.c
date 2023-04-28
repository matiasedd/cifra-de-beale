#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib_beale.h"

void create_keyfile(char *keyfile, struct char_list *char_list)
{
    FILE *stream = fopen(keyfile, "w");

    if (stream == NULL)
        throw_error("Nao foi possivel abrir o arquivo de chave");

    struct char_node *node = char_list->head;

    while (node != NULL)
    {
        fprintf(stream, "%c:", node->data);
        struct num_node *num_node = node->num_list->head;

        while (num_node != NULL)
        {
            fprintf(stream, " %d", num_node->data);
            num_node = num_node->next;
        }

        fprintf(stream, "\n");
        node = node->next;
    }

    fclose(stream);
}

struct char_list *create_list_from_book(FILE *book_stream)
{
    int counter = 0;
    struct char_node *char_node;
    char letter, line[LINE_SIZE];

    struct char_list *char_list = create_char_list();

    if (char_list == NULL)
        throw_error("Nao foi possivel alocar memoria para a lista");

    while (fgets(line, LINE_SIZE, book_stream) != NULL)
    {
        char *token = strtok(line, " ");

        while (token != NULL)
        {
            letter = token[0];

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

    return char_list;
}

void encode_message(char *book, char *input, char *output, char *keyfile)
{
    FILE *book_stream, *input_stream, *output_stream;

    if ((book_stream = fopen(book, "r")) == NULL)
        throw_error("Nao foi possivel abrir o livro cifra");

    if ((input_stream = fopen(input, "r")) == NULL)
        throw_error("Nao foi possivel abrir a mensagem original");

    char letter;
    struct char_node *char_node;
    struct char_list *char_list = create_list_from_book(book_stream);

    if ((output_stream = fopen(output, "w")) == NULL)
        throw_error("Nao foi possivel abrir o arquivo de saida");

    while ((letter = fgetc(input_stream)) != EOF)
    {
        if (is_alphanumeric(letter))
        {
            if (is_uppercase(letter))
                letter = to_lowercase(letter);

            char_node = find_char_node(char_list, letter);
            int random = get_random_num_node(char_node->num_list)->data;
            
            fprintf(output_stream, "%d ", random);
        }
        else if (letter == ' ')
            fprintf(output_stream, "%d ", SPACE_CHAR);
        else
            fprintf(output_stream, "%d ", UNKNOWN_CHAR);
    }

    if (keyfile != NULL)
        create_keyfile(keyfile, char_list);

    destroy_char_list(char_list);
    fclose(input_stream);
    fclose(book_stream);
}

void decode_using_book(char *input, char *book, char *output)
{
    FILE *book_stream, *input_stream, *output_stream;

    if ((book_stream = fopen(book, "r")) == NULL)
        throw_error("Nao foi possivel abrir o livro cifra");

    if ((input_stream = fopen(input, "r")) == NULL)
        throw_error("Nao foi possivel abrir a mensagem codificada");

    if ((output_stream = fopen(output, "w")) == NULL)
        throw_error("Nao foi possivel abrir o arquivo de saida");

    char line[LINE_SIZE];
    struct char_list *char_list = create_list_from_book(book_stream);

    while (fgets(line, LINE_SIZE, input_stream) != NULL)
    {
        char *token = strtok(line, " ");

        while (token != NULL)
        {
            int number = atoi(token);

            if (number == SPACE_CHAR)
                fprintf(output_stream, " ");
            else if (number == UNKNOWN_CHAR)
                fprintf(output_stream, "?");
            else
            {
                struct char_node *char_node = find_char_node_by_num(char_list, number);
                fprintf(output_stream, "%c", char_node->data);
            }

            token = strtok(NULL, " ");
        }
    }    

    destroy_char_list(char_list);
    fclose(output_stream);
    fclose(input_stream);
    fclose(book_stream);
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
