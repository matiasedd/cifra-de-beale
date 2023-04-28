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

struct num_list *create_num_list();

struct char_list *create_char_list();

struct char_node *create_char_node(char data);

struct num_node *create_num_node(int data);

struct char_node *insert_char_node(struct char_list *list, char data);

void insert_num_node(struct num_list *list, int data);

struct char_node *find_char_node(struct char_list *list, char data);

struct char_node *find_char_node_by_num(struct char_list *list, int num);

struct num_node *get_random_num_node(struct num_list *list);

void print_char_list(struct char_list *list);

void print_num_list(struct num_list *list);

void destroy_char_list(struct char_list *list);

void destroy_num_list(struct num_list *list);
