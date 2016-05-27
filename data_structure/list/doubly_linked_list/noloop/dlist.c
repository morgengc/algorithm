/*****************************************************
 * doubley linked list, but not loop.
 *
 *         +--+-+    +--+-+    +--+-+    +--+-+   
 * NIL <-- |  |-|<-->|  |-|<-->|  |-|<-->|  |-| --> NIL
 *         +--+-+    +--+-+|  |+--+-+    +--+-+
 *            |            |  |             |    
 *          head           |  |            tail
 *                      prev  next
 *
 * gaoc@dsp.ac.cn
 * 2008.11.24
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dlist.h"

pList CreateList()
{
	pList list = (pList)malloc(sizeof(List));
	P_CHECK_MEMORY(list);
	list->count = 0;
	list->head = list->tail = NULL;

	return list;
}

/* NOTE:
 *      Delete all the nodes from tail to head.
 *      No need to update next or prev pointers.
 * */
void DestroyList(pList list)
{
	V_CHECK_VALID(list);

	pNode index = list->tail;
	pNode prev;
	while(index)
	{
		prev = index->prev;
		printf("release %d\n", index->data);
		free(index);
		index = prev;
	}

	free(list);
	list = NULL;
	printf("clearly.\n");
}

static pNode CreateNode(int data)
{
	pNode node = (pNode)malloc(sizeof(Node));
	P_CHECK_MEMORY(node);
	node->data = data;
	node->prev = node->next = NULL;
	return node;
}

/* NOTE:
 *      Checking order is from head to tail.
 * */
pNode SearchNode(pList list, int data)
{
	P_CHECK_VALID(list);

	pNode index = list->head;
	while(index)
	{
		if (index->data == data)
		{
			printf("find node %d\n", data);
			return index;
		}
		else
			index = index->next;
	}
	
	printf("[WARN] Node %d not find.\n", data);
	return NULL;
}

/* NOTE:
 *      Append Node to the end of List. You must
 *      update tail pointer.
 * */
bool InsertNode(pList list, int data)
{
	B_CHECK_VALID(list);

	pNode node = CreateNode(data);
	B_CHECK_RETURN(node);

	(list->count)++;

	if (!(list->tail))
	{
		list->head = list->tail = node;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		list->tail->next = node;
		node->prev = list->tail;
		node->next = NULL;
		list->tail = node;
	}

	return true;
}

/* NOTE:
 *      Be careful while deleting head and tail elements.
 *      Because you must update head or tail pointer after deleting.
 * */
bool DeleteNode(pList list, int data)
{
	B_CHECK_VALID(list);

	pNode index = SearchNode(list, data);
	B_CHECK_RETURN(index);

	(list->count)--;

	if (index == list->head)
	{
		if (list->head == list->tail)
		{
			list->head = list->tail = NULL;
			free(index);
		}
		else
		{
			list->head = index->next;
			list->head->prev = NULL;
		}
	}
	else if (index == list->tail)
	{
		list->tail = index->prev;
		list->tail->next = NULL;
		free(index);
	}
	else
	{
		index->prev->next = index->next;
		index->next->prev = index->prev;
		free(index);
	}

	return true;
}

void PrintList(pList list)
{
	V_CHECK_VALID(list);

	printf("head -> ");

	pNode node = list->head;
	while(node)
	{
		printf("%d ", node->data);
		node = node->next;
		if (node)
			printf("<-> ");
	}

	printf(" <- tail\n");
}

