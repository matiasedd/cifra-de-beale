#include <stdio.h>
#include <stdlib.h>

#include "lib_list.h"

struct num_list *create_num_list()
{
    struct num_list *list = malloc(sizeof(struct num_list));
    
    if (list == NULL)
        return NULL;

    list->size = 0;
    list->head = NULL;

    return list;
}

struct char_list *create_char_list()
{
    struct char_list *list = malloc(sizeof(struct char_list));
    
    if (list == NULL)
        return NULL;

    list->head = NULL;

    return list;
}

struct num_node *create_num_node(int data)
{
    struct num_node *node = malloc(sizeof(struct num_node));

    if (node == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;

    return node;
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

void insert_num_node(struct num_list *list, int data)
{
    struct num_node *node = create_num_node(data);

    if (list->head == NULL)
    {
        list->head = node;
        list->size++;

        return;
    }

    struct num_node *current = list->head;
    struct num_node *previous = NULL;

    while (current != NULL && current->data > data)
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

    list->size++;
}

void insert_char_node(struct char_list *list, char data)
{
    struct char_node *node = create_char_node(data);

    if (list->head == NULL)
    {
        list->head = node;
        return;
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

struct num_node *get_random_num_node(struct num_list *list)
{
    int random = rand() % list->size;
    struct num_node *node = list->head;
    
    while (random > 0)
    {
        node = node->next;
        random--;
    }

    return node;
}

void print_num_list(struct num_list *list)
{
    struct num_node *node = list->head;

    while (node != NULL)
    {
        printf(" %d", node->data);
        node = node->next;
    }

    printf("\n");
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

void destroy_num_list(struct num_list *list)
{
    struct num_node *node = list->head;
    struct num_node *next;

    while (node != NULL)
    {
        next = node->next;
        free(node);
        node = next;
    }

    free(list);
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
