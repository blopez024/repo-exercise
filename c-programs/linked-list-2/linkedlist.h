#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int length;
} LinkedList;

// init
void init_linkedlist(LinkedList *list);
void free_linkedlist(LinkedList *list);

// insert
void insert_at_index(LinkedList *list, int index, int value);
void insert_at_head(LinkedList *list, int value);
void insert_at_tail(LinkedList *list,  int value);

// get
int get_at_index(LinkedList *list, int index);
int get_at_head(LinkedList *list);
int get_at_tail(LinkedList *list);

// delete
void delete_at_index(LinkedList *list, int index);
void delete_at_head(LinkedList *list);
void delete_at_tail(LinkedList *list);

// length
int length(LinkedList *list);

// empty
int is_empty(LinkedList *list);

// print
void print(LinkedList *list);

#endif // LINKED_LIST_H