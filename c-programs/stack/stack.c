#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack(Stack *stack) { stack->top = -1; }

int is_empty(Stack *stack) { return stack->top == -1; }

int is_full(Stack *stack) { return stack->top == MAX_STACK_SIZE - 1; }

void push(Stack *stack, int value) {
  if (is_full(stack)) {
    printf("Stack is full\n");
    return;
  }

  stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty\n");
    exit(1);
  }

  return stack->data[stack->top--];
}

int peak(Stack *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty\n");
    exit(1);
  }
  return stack->data[stack->top];
}