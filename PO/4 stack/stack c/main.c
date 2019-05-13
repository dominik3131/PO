#include <stdlib.h>
#include <stdio.h>
#include "stackc.h"
#include <string.h>


int main()
{
	struct Stack stos;
	struct Stack* s=&stos;
	init(s);
	int i;
	
	for(i=0;i<10000;i++)
	{
		
		push(s,i);
	}
	printf("%d",pop(s));
	destroy(s);

	return 0;
}

