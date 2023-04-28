#include "lib_num_list.h"

struct char_node
{
    char data;
    struct char_node *next;
    struct num_list *num_list;
};

struct char_list
{
    struct char_node *head;
};

/*
 * Responsável por criar uma lista de caracteres.
 * Recebe um inteiro como parâmetro.
 * Retorna um ponteiro para uma lista de caracteres.
 */
struct char_list *create_char_list();

/*
 * Responsável por criar um nó de caractere.
 * Recebe um caractere como parâmetro.
 * Retorna um ponteiro para um nó de caractere.
 */
struct char_node *create_char_node(char data);

/*
 * Responsável por inserir um nó de caractere em uma lista de caracteres.
 * Recebe um ponteiro para uma lista de caracteres e um caractere como parâmetros.
 * Retorna um ponteiro para o nó de caractere inserido.
 */
struct char_node *insert_char_node(struct char_list *list, char data);

/*
 * Responsável por remover um nó de caractere de uma lista de caracteres.
 * Recebe um ponteiro para uma lista de caracteres e um caractere como parâmetros.
 * Retorna um ponteiro para o nó de caractere removido.
 */
struct char_node *find_char_node(struct char_list *list, char data);

/*
 * Responsável por remover um nó de número de uma lista de números.
 * Recebe um ponteiro para uma lista de números e um inteiro como parâmetros.
 * Retorna um ponteiro para o nó de número removido.
 */
struct char_node *find_char_node_by_num(struct char_list *list, int num);

/*
 * Responsável por remover um nó de caractere de uma lista de caracteres.
 * Recebe um ponteiro para uma lista de caracteres e um caractere como parâmetros.
 * Retorna um ponteiro para o nó de caractere removido.
 */
void print_char_list(struct char_list *list);

/*
 * Responsável por remover um nó de caractere de uma lista de caracteres.
 * Recebe um ponteiro para uma lista de caracteres e um caractere como parâmetros.
 * Retorna um ponteiro para o nó de caractere removido.
 */
void destroy_char_list(struct char_list *list);
