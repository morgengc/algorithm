/****************************************************************
 * doubley linked list, looping from tail to head.
 *
 *    +--+-+    +--+-+    +--+-+         +--+-+     +--+-+
 * <->|  |-|<-->|  |-|<-->|  |-| ... <-->|  |-|<--> |  |-|<->
 *    +--+-+    +--+-+|  |+--+-+         +--+-+     +--+-+
 *       |            |  |                  |          |
 *     head           |  |                 tail       head
 *                 prev  next
 *
 *
 * gaoc@dsp.ac.cn
 * 2009.09.11
 ***************************************************************/

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
 * 	Delete all the nodes from tail to head.
 * 	No need to update next or prev pointers.
 * */
void DestroyList(pList list)
{
	V_CHECK_VALID(list);

	if (!(list->tail))
		goto very_clean;

	pNode index = list->tail;
	pNode prev = NULL;
	do
	{
		prev = index->prev;
		printf("release %d\n", index->data);
		free(index);
		index = prev;
	}while(index != list->tail);

very_clean:
	free(list);
	list = NULL;
	printf("clearly.\n");
}

static pNode CreateNode(int data)
{
	pNode node = (pNode)malloc(sizeof(Node));
	P_CHECK_MEMORY(node);
	node->data = data;
	node->prev = node->next = node;
	return node;
}

/* NOTE:
 * 	Checking order is from head to tail.
 * */
pNode SearchNode(pList list, int data)
{
	P_CHECK_VALID(list);

	if (!(list->head))
		return NULL;

	pNode index = list->head;
	do
	{
		if (index->data == data)
		{
			printf("find node %d\n", data);
			return index;
		}
		else
			index = index->next;
	}while(index != list->head);
	
	printf("[WARN] Node %d not find.\n", data);
	return NULL;
}

/* NOTE:
 * 	Append Node to the end of List. You must
 * 	update tail pointer.
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
		node->prev = node->next = node;
	}
	else
	{
		list->tail->next = node;
		node->prev = list->tail;
		node->next = list->head;
		list->head->prev = node;
		list->tail = node;
	}

	return true;
}

/* NOTE:
 * 	Be careful while deleting head and tail elements.
 * 	Because you must update head or tail pointer after deleting.
 * */
bool DeleteNode(pList list, int data)
{
	B_CHECK_VALID(list);

	pNode index = SearchNode(list, data);
	B_CHECK_RETURN(index);

	(list->count)--;

	if (index == list->head) /* case head */
	{
		if (list->head == list->tail)
		{
			list->head = list->tail = NULL;
			free(index);
		}
		else
		{
			list->head = index->next;

			list->tail->next = list->head;
			list->head->prev = list->tail;

			free(index);
		}
	}
	else if (index == list->tail) /* case tail */
	{
		list->tail = index->prev;

		list->tail->next = list->head;
		list->head->prev = list->tail;

		free(index);
	}
	else /* the simplest case is inner node */
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

	printf("head <-> ");

	if (!(list->head))
	{
		printf("tail <-> head\n");
		return;
	}

	pNode node = list->head;
	do
	{
		printf("%d <-> ", node->data);
		node = node->next;
	}while(node != list->head);

	printf("tail <-> head\n");
}

