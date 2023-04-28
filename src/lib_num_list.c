#include <stdio.h>
#include <stdlib.h>

#include "lib_num_list.h"

struct num_list *create_num_list()
{
    struct num_list *list = malloc(sizeof(struct num_list));
    
    if (list == NULL)
        return NULL;

    list->size = 0;
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
