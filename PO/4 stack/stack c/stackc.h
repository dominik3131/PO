#ifndef STACK_H
#define STACK_H
#define INITIAL_STACK_SIZE 8
#include <stdbool.h>

struct Stack
{
int top; /* pierwsze wolne miejsce na stosie */
int* data;
int size;
};

void init(struct Stack* s);

void destroy(struct Stack* s);

void push(struct Stack* s, int element);

int pop(struct Stack* s);

void clear(struct Stack* s);

bool isEmpty(struct Stack* s); 

bool doubleStack(struct Stack* s);

#endif
