#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/*
 * Verifica se um caractere é uma letra maiúscula.
 * Recebe um caractere como parâmetro.
 * Retorna 1 se for maiúscula ou 0 caso contrário.
 */
int is_uppercase(char c);

/*
 * Verifica se um caractere é uma letra minúscula.
 * Recebe um caractere como parâmetro.
 * Retorna 1 se for minúscula ou 0 caso contrário.
 */
int is_lowercase(char c);

/*
 * vVrifica se um caractere é um dígito numérico.
 * Recebe um caractere como parâmetro.
 * Retorna 1 se for um dígito ou 0 caso contrário.
 */
int is_numeric(char c);

/*
 * Verifica se um caractere é uma letra ou um dígito numérico.
 * Recebe um caractere como parâmetro.
 * Retorna 1 se for alfanumérico ou 0 caso contrário.
 */
int is_alphanumeric(char c);

/*
 * Converte um caractere em letra minúscula, caso seja uma letra maiúscula.
 * Recebe um caractere como parâmetro.
 * Retorna sua versão em minúscula, se aplicável.
 */
char to_lowercase(char c);

/*
 * Exibe uma mensagem de erro para o usuário e finaliza o programa.
 * Recebe um ponteiro para uma string como parâmetro, que será exibido como mensagem de erro.
 * Não possui retorno.
 */
void throw_error(char *message);
