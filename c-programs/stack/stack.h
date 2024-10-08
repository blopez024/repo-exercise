#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 100

typedef struct {
  int data[MAX_STACK_SIZE];
  int top;
} Stack;

void init_stack(Stack *stack);
int is_empty(Stack *stack);
int is_full(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peak(Stack *stack);

#endif // STACK_H