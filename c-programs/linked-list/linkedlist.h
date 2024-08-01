#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
  int val;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int length;
} LinkedList;

void init_linkedlist(LinkedList *linkedlist);
void free_linkedlist(LinkedList *linkedlist);

void insert_at_pos(LinkedList *linkedlist, int index, int value);
void insert_at_head(LinkedList *linkedlist, int value);
void insert_at_tail(LinkedList *linkedlist, int value);

int get_value_at_index(LinkedList *linkedlist, int index);
int get_head(LinkedList *linkedlist);
int get_tail(LinkedList *linkedlist);

void delete_at_index(LinkedList *linkedlist, int index);
void delete_at_head(LinkedList *linkedlist);
void delete_at_tail(LinkedList *linkedlist);

int is_empty(LinkedList *linkedlist);
int size(LinkedList *linkedlist);

void print_linkedlist(LinkedList *linkedlist);

#endif // LINKED_LIST_H