#include <stdio.h>
#include <stdlib.h>

#include "lib_char_list.h" 

struct char_list *create_char_list()
{
    struct char_list *list = malloc(sizeof(struct char_list));
    
    if (list == NULL)
        return NULL;

    list->head = NULL;

    return list;
}

struct char_node *create_char_node(char data)
{
    struct char_node *node = malloc(sizeof(struct char_node));

    if (node == NULL)
        return NULL;

    node->num_list = create_num_list();

    if (node->num_list == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

struct char_node *insert_char_node(struct char_list *list, char data)
{
    struct char_node *node = create_char_node(data);

    if (list->head == NULL)
    {
        list->head = node;
        return node;
    }

    struct char_node *current = list->head;
    struct char_node *previous = NULL;

    while (current != NULL && current->data < data)
    {
        previous = current;
        current = current->next;
    }

    if (previous == NULL)
    {
        node->next = list->head;
        list->head = node;
    }
    else
    {
        previous->next = node;
        node->next = current;
    }

    return node;
}

struct char_node *find_char_node(struct char_list *list, char data)
{
    struct char_node *node = list->head;

    while (node != NULL)
    {
        if (node->data == data)
            return node;

        node = node->next;
    }

    return NULL;
}

void print_char_list(struct char_list *list)
{
    struct char_node *node = list->head;

    while (node != NULL)
    {
        printf("%c", node->data);
        node = node->next;
    }

    printf("\n");
}

void destroy_char_list(struct char_list *list)
{
    struct char_node *node = list->head;
    struct char_node *next;

    while (node != NULL)
    {
        next = node->next;
        destroy_num_list(node->num_list);
        free(node);
        node = next;
    }

    free(list);
}
