#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "slist.h"

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

	PrintList(list);

	ReverseList(list);
	PrintList(list);

	SortList(list);
	PrintList(list);
	
	count = (unsigned int)RANDOM(1, count_bk+1);
	while(count)
	{
		DeleteNode(list, RANDOM(0, 99));
		count--;
	}

	PrintList(list);

	DestroyList(list);
	return 0;
}

