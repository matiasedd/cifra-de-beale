struct num_node
{
    int data;
    struct num_node *next;
};

struct num_list
{
    int size;
    struct num_node *head;
};

/*
 * Responsável por criar uma lista de números.
 * Não recebe parâmetros.
 * Retorna um ponteiro para uma lista de números.
 */
struct num_list *create_num_list();

/*
 * Responsável por criar um nó de número.
 * Recebe um inteiro como parâmetro.
 * Retorna um ponteiro para um nó de número.
 */
struct num_node *create_num_node(int data);

/*
 * Responsável por inserir um nó de número em uma lista de números.
 * Recebe um ponteiro para uma lista de números e um inteiro como parâmetros.
 * Retorna um ponteiro para o nó de número inserido.
 */
void insert_num_node(struct num_list *list, int data);

/*
 * Responsável por remover um nó de caractere de uma lista de caracteres.
 * Recebe um ponteiro para uma lista de caracteres e um caractere como parâmetros.
 * Retorna um ponteiro para o nó de caractere removido.
 */
struct num_node *get_random_num_node(struct num_list *list);

/*
 * Responsável por remover um nó de caractere de uma lista de caracteres.
 * Recebe um ponteiro para uma lista de caracteres e um caractere como parâmetros.
 * Retorna um ponteiro para o nó de caractere removido.
 */
void print_num_list(struct num_list *list);

/*
 * Responsável por remover um nó de caractere de uma lista de caracteres.
 * Recebe um ponteiro para uma lista de caracteres e um caractere como parâmetros.
 * Retorna um ponteiro para o nó de caractere removido.
 */
void destroy_num_list(struct num_list *list);
