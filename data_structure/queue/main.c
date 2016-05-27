#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

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
	QUEUE *q;

	srand((unsigned)time(0));

	q = CreateQueue();

	count = (unsigned int)RANDOM(1, 30);
	count_bk = count;
	while(count)
	{
		EnQueue(q, RANDOM(0, 1024));
		count--;
	}

	PrintQueue(q);

	count = (unsigned int)RANDOM(1, count_bk+1);
	//count = count_bk + 1;
	while(count)
	{
		DeQueue(q, NULL);
		count--;
	}

	PrintQueue(q);

	DestroyQueue(q);
	return 0;
}

