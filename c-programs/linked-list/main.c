#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  LinkedList linkedlist;
  init_linkedlist(&linkedlist);
  insert_at_tail(&linkedlist, 0);
  insert_at_tail(&linkedlist, 1);
  insert_at_tail(&linkedlist, 2);
  insert_at_tail(&linkedlist, 3);
  insert_at_tail(&linkedlist, 4);
  insert_at_tail(&linkedlist, 5);

  print_linkedlist(&linkedlist);

  insert_at_pos(&linkedlist, 1, -1);
  print_linkedlist(&linkedlist);

  insert_at_pos(&linkedlist, 4, -3);
  print_linkedlist(&linkedlist);

  insert_at_tail(&linkedlist, -9);
  print_linkedlist(&linkedlist);

  printf("Head Value: %d\n", get_head(&linkedlist));
  printf("Tail Value: %d\n", get_tail(&linkedlist));
  printf("Index (1) Value: %d\n", get_value_at_index(&linkedlist, 1));

  delete_at_index(&linkedlist, 1);
  print_linkedlist(&linkedlist);

  delete_at_head(&linkedlist);
  print_linkedlist(&linkedlist);

  delete_at_tail(&linkedlist);
  print_linkedlist(&linkedlist);

  free_linkedlist(&linkedlist);
  return 0;
}