#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stackc.h"

void init(struct Stack* s)
{
	s->data=(int*)malloc(sizeof(int)*INITIAL_STACK_SIZE);
	if(s->data)
	{
		s->top=0;
		s->size=INITIAL_STACK_SIZE;	
	}
	else
	{
		printf("nie mozna utworzyc stosu")	;
	}

}

//finalizes stack and frees memory
void destroy(struct Stack* s)
{
	free(s->data);
};

//place element on stack or doubles stack size if there is no space in stack
void push(struct Stack* s, int element)
{
	if(s->size==s->top)
	{
		if(doubleStack(s)) s->data[s->top++]=element;
		else
		{
			puts("Nie mozna powiekszyc stosu, program zostanie zamkniety");
			exit(1);
		}
	}
	else
	{
		s->data[s->top++]=element;
	}
}

// gets element from stack and lowers top
int pop(struct Stack* s)
{
	if(!isEmpty(s))
	{
		s->top--;
		return s->data[s->top];
	}
	else
	{
		puts("brak elementow na stosie, zwrocono 0");
		return 0;
	}
}

//clears stack by making top value 0
void clear(struct Stack* s)
{
	s->top=0;
}

//if stack is empty returns 1
// otherwise 0
bool isEmpty(struct Stack* s)
{
	if(s->top>0) return 0;
	else return 1;
}

//doubles stack size
//returns 1 if successful
//else 	  0
bool doubleStack(struct Stack* s)
{
	int *wsk;
	puts("podwojenie");
	s->size=s->size*2;
	wsk=(int*)realloc(s->data,s->size*sizeof(int));
	s->data=wsk;
	if(s->data) return 1;
	return 0;
}















