#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dlist.h"

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
	unsigned int count = 0, count_bk = 0;
	pList list;
	srand((unsigned)time(0));

	list = CreateList();
	count = (unsigned int)RANDOM(1, 30);
	count_bk = count;

	while(count)
	{
		InsertNode(list, RANDOM(0, 99));
		count--;
	}

	InsertNode(list, 10);
	InsertNode(list, 11);
	InsertNode(list, 12);

	PrintList(list);

	count = (unsigned int)RANDOM(1, count_bk+1);
	while(count)
	{
		DeleteNode(list, RANDOM(0, 99));
		count--;
	}
	DeleteNode(list, 10);
	DeleteNode(list, 10);

	PrintList(list);

	DestroyList(list);
	return 0;
}

