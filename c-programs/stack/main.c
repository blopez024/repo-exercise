#include "stack.h"
#include <stdio.h>

int main(void) {

  Stack stack;
  init_stack(&stack);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);
  push(&stack, 40);
  push(&stack, 50);
  push(&stack, 60);
  push(&stack, 70);
  push(&stack, 80);
  push(&stack, 90);

  printf("Top element is %d\n", peak(&stack));

  printf("Popped elements: ");
  while (!is_empty(&stack)) {
    printf("%d ", pop(&stack));
  }
  printf("\n");

  return 0;
}