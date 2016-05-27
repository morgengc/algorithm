/************************************************
 * single linked list.
 *
 * +--+-+   +--+-+   +--+-+   +--+-+   
 * |  |-|-->|  |-|-->|  |-|-->|  |-|--> NIL
 * +--+-+   +--+-+ | +--+-+   +--+-+
 *    |            |         
 *  head           |             
 *                next
 *
 * gaoc@dsp.ac.cn
 * 2009.09.10
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>

#include "slist.h"

pList CreateList()
{
	pList list = (pList)malloc(sizeof(List));
	P_CHECK_MEMORY(list);
	list->head = NULL;

	return list;
}

void DestroyList(pList list)
{
	V_CHECK_VALID(list);

	pNode index = list->head;
	pNode tmp;
	while(index)
	{
		tmp = index->next;
		printf("release %d\n", index->data);
		free(index);
		index = tmp;
	}

	free(list);
	list = NULL;
	printf("DestroyList clearly.\n");
}

static pNode CreateNode(int element)
{
	pNode node = (pNode)malloc(sizeof(Node));
	P_CHECK_MEMORY(node);
	node->data = element;
	node->next = NULL;
	return node;
}

pNode SearchNode(pList list, int element)
{
	P_CHECK_VALID(list);

	pNode index = list->head;
	while(index)
	{
		if (index->data == element)
		{
			printf("find node %d\n", element);
			return index;
		}
		else
			index = index->next;
	}
	
	printf("Node %d not find.\n", element);
	return NULL;
}

/* NOTE: 
 * 	Insert a new created node before the list head. 
 * RETURN:
 * 	A "bool" return value is more useful than a "pList"
 * 	return value. The former can indicate an operation is
 * 	successful or not.
 * */
bool InsertNode(pList list, int element)
{
	B_CHECK_VALID(list);

	pNode node = CreateNode(element);
	B_CHECK_RETURN(node);

	if (!(list->head))
	{
		// the first Node
		list->head = node;
	}
	else
	{
		node->next = list->head;
		list->head = node;
	}

	return true;
}

/* NOTE: 
 * 	As single list, you can not access the previous 
 * 	node after you find it using SearchNode().
 * RETURN:
 * 	Same as InsertNode().
 * */
bool DeleteNode(pList list, int element)
{
	B_CHECK_VALID(list);

	if (!(list->head))
	{
		printf("[WARN] list is empty.\n");
		return false;
	}

	pNode index = list->head;
	pNode prev;

	if (index->data == element)
	{
		list->head = index->next;
		free(index);
		return true;
	}
	else
	{
		prev = index;
		index = index->next;
		while(index)
		{
			if (index->data == element)
			{
				prev->next = index->next;
				free(index);
				return true;
			}

			prev = index;
			index = index->next;
		}
	}

	printf("[WARN] can not find %d\n", element);
	return false;
}

bool SortList(pList list)
{
	B_CHECK_VALID(list);

	/* If list->head is NULL, it will finish condition check 
	 * before it checks list->head->next, so this is correct */
	if (!(list->head) || !(list->head->next))
		return true;

	int value = 0;
	pNode outter_index = list->head;
	pNode inner_index = list->head;

	while(outter_index)
	{
		inner_index = outter_index;
		while(inner_index)
		{
			if ((outter_index->data) > (inner_index->data))
			{
				value = outter_index->data;
				outter_index->data = inner_index->data;
				inner_index->data = value;
			}
			inner_index = inner_index->next;
		}
		outter_index = outter_index->next;
	}

	return true;
}

bool ReverseList(pList list)
{
	B_CHECK_VALID(list);
	
	/* If list->head is NULL, it will finish condition check 
	 * before it checks list->head->next, so this is correct */
	if (!(list->head) || !(list->head->next))
		return true;

	pNode prev = list->head;
	pNode index = list->head->next;
	pNode next = index->next;

	prev->next = NULL;

	while(next)
	{
		index->next = prev;

		prev = index;
		index = next;
		next = index->next;
	}

	index->next = prev;
	list->head = index;

	return true;
}

void PrintList(pList list)
{
	V_CHECK_VALID(list);

	printf("head -> ");

	pNode index = list->head;
	while(index)
	{
		printf("%d -> ", index->data);
		index = index->next;
	}
	printf("NIL\n");
}

