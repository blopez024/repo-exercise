#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void init_linkedlist(LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void free_linkedlist(LinkedList *list)
{
    Node *curr = list->head;
    int i = length(list);
    while (i > 0)
    {
        Node *temp = curr->next;
        free(curr);
        curr = temp;
        i--;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void insert_at_index(LinkedList *list, int index, int value)
{
    if (index < 0 || index > length(list))
    {
        printf("Index [%d] out bounds.\n", index);
        exit(1);
    }

    Node *node = (Node *)malloc(sizeof(Node));
    node->val = value;
    node->next = NULL;
    node->prev = NULL;

    if (length(list) == 0)
    {
        list->head = node;
        list->tail = node;
    }
    else if (index == 0)
    {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
        list->tail = (length(list) == 0) ? node : list->tail;
    }
    else if (index == length(list))
    {
        node->prev = list->tail;
        node->prev->next = node;
        list->tail = node;
    }
    else
    {
        Node *curr = list->head;
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }

        node->next = curr->next;
        node->prev = curr;
        curr->next = node;
        node->next->prev = node;
    }

    list->length++;
}

void insert_at_head(LinkedList *list, int value)
{
    insert_at_index(list, 0, value);
}

void insert_at_tail(LinkedList *list, int value)
{
    insert_at_index(list, length(list), value);
}

int get_at_index(LinkedList *list, int index)
{
    if (is_empty(list))
    {
        printf("List is empty.\n");
        exit(1);
    }

    if (index < 0 || index > length(list) - 1)
    {
        printf("Index [%d] out bounds.\n", index);
        exit(1);
    }

    if (index == length(list) - 1)
    {
        return list->tail->val;
    }
    else
    {
        Node *curr = list->head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->val;
    }
}

int get_at_head(LinkedList *list)
{
    return get_at_index(list, 0);
}

int get_at_tail(LinkedList *list)
{
    return get_at_index(list, length(list) - 1);
}

void delete_at_index(LinkedList *list, int index)
{
    if (is_empty(list))
    {
        printf("List is empty.\n");
        exit(1);
    }

    if (index < 0 || index > length(list) - 1)
    {
        printf("Index [%d] out bounds.\n", index);
        exit(1);
    }

    Node *node;
    if (length(list) == 1)
    {
        node = list->head;
        list->head = NULL;
        list->tail = NULL;
    }
    else if (index == 0)
    {
        node = list->head;
        list->head->next->prev = NULL;
        list->head = list->head->next;
    }
    else if (index == length(list) - 1)
    {
        node = list->tail;
        list->tail->prev->next = NULL;
        list->tail = list->tail->prev;
    }
    else
    {
        node = list->head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    free(node);
    list->length--;
}

void delete_at_head(LinkedList *list)
{
    delete_at_index(list, 0);
}

void delete_at_tail(LinkedList *list)
{
    delete_at_index(list, length(list) - 1);
}

int length(LinkedList *list)
{
    return list->length;
}

int is_empty(LinkedList *list)
{
    return length(list) == 0;
}

void print(LinkedList *list)
{
    Node *curr = list->head;
    printf("List: ");
    for (int i = 0; i < length(list); i++)
    {
        printf("%2d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}