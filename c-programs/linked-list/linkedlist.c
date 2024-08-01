#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void init_linkedlist(LinkedList *linkedlist) {
  linkedlist->head = NULL;
  linkedlist->length = 0;
}

void free_linkedlist(LinkedList *linkedlist) {
  Node *curr = linkedlist->head;
  while (curr != NULL) {
    Node *next = curr->next;
    free(curr);
    curr = next;
  }
  linkedlist->head = NULL;
  linkedlist->length = 0;
}

void insert_at_pos(LinkedList *linkedlist, int index, int value) {

  if (index < 0 || index > size(linkedlist)) {
    printf("Invalid index\n");
    exit(1);
  }

  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->val = value;

  if (index == 0) {

    new_node->next = linkedlist->head;
    linkedlist->head = new_node;

  } else {

    Node *curr = linkedlist->head;
    for (int i = 0; i < index - 1; i++) {
      curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
  }

  linkedlist->length++;
  return;
}

void insert_at_head(LinkedList *linkedlist, int value) {
  insert_at_pos(linkedlist, 0, value);
}

void insert_at_tail(LinkedList *linkedlist, int value) {
  insert_at_pos(linkedlist, size(linkedlist), value);
}

int get_value_at_index(LinkedList *linkedlist, int index) {
  if (index < 0 || index >= size(linkedlist)) {
    printf("Invalid index\n");
    exit(1);
  }

  Node *curr = linkedlist->head;
  for (int i = 0; i < index; i++) {
    curr = curr->next;
  }

  return curr->val;
}

int get_head(LinkedList *linkedlist) {
  if (is_empty(linkedlist)) {
    printf("Empty Linked List\n");
    exit(1);
  }

  return linkedlist->head->val;
}

int get_tail(LinkedList *linkedlist) {
  Node *curr = linkedlist->head;

  for (int i = 0; i < size(linkedlist) - 1; i++) {
    curr = curr->next;
  }

  return curr->val;
}

void delete_at_index(LinkedList *linkedlist, int index) {
  if (index < 0 || index >= size(linkedlist)) {
    printf("Invalid index\n");
    exit(1);
  }

  Node *node_to_delete;

  if (index == 0) {

    node_to_delete = linkedlist->head;
    linkedlist->head = linkedlist->head->next;

  } else {

    Node *curr = linkedlist->head;
    for (int i = 0; i < index - 1; i++) {
      curr = curr->next;
    }
    node_to_delete = curr->next;
    curr->next = curr->next->next;
  }

  free(node_to_delete);
  linkedlist->length--;
  return;
}

void delete_at_head(LinkedList *linkedlist) {
  if (is_empty(linkedlist)) {
    printf("Empty Linked List\n");
    exit(1);
  }

  delete_at_index(linkedlist, 0);
  return;
}

void delete_at_tail(LinkedList *linkedlist) {
  if (is_empty(linkedlist)) {
    printf("Empty Linked List\n");
    exit(1);
  }

  delete_at_index(linkedlist, size(linkedlist) - 1);
  return;
}

int is_empty(LinkedList *linkedlist) { return linkedlist->length == 0; }

int size(LinkedList *linkedlist) { return linkedlist->length; }

void print_linkedlist(LinkedList *linkedlist) {
  Node *curr = linkedlist->head;
  for (int i = 0; i < size(linkedlist); i++) {
    printf("%2d -> ", curr->val);
    curr = curr->next;
  }
  printf("NULL\n");
  return;
}