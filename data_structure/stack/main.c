#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

/* generate number [p, r) */
static int RANDOM(int p, int r)
{
	if (p >= r)
		return p;
	else
		return rand()%(r-p)+p;
}


int main()
{
	unsigned int count = 0, count_bk = 0;;
	STACK *s;

	srand((unsigned)time(0));

	s = CreateStack();

	count = (unsigned int)RANDOM(1, 30);
	count_bk = count;
	while(count)
	{
		Push(s, RANDOM(0, 1024));
		count--;
	}

	PrintStack(s);

	count = (unsigned int)RANDOM(1, count_bk+1);
	//count = count_bk + 1;
	while(count)
	{
		Pop(s, NULL);
		count--;
	}

	PrintStack(s);

	DestroyStack(s);
	return 0;
}

