/*******************************************************
 * Queue using Single list.
 *
 * Take care of the direction of the "next" pointer.
 *
 *             +--+-+   +--+-+   +--+-+   +--+-+   
 * <-DeQueue-- |  |-|-->|  |-|-->|  |-|-->|  |-|--> NIL
 *             +--+-+ | +--+-+   +--+-+   +--+-+
 *                |   |                       |
 *               head |                      tail
 *                    |                   
 *                   next                 <- EnQueue -- 
 *
 * gaoc@dsp.ac.cn
 * 2009.09.10
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/* NOTE: before using q->head->data, make sure
 *       that q->head is not NULL!
 * */
QUEUE *CreateQueue()
{
	QUEUE *q;
	q = (QUEUE *)malloc(sizeof(QUEUE));
	CHECK_MEMORY(q);
	q->head = NULL;
	q->tail = NULL;
	return q;
}

void DestroyQueue(QUEUE *q)
{
	V_CHECK_VALID(q);

	while(!IsEmpty(q))
		DeQueue(q, NULL);

	free(q);
	q = NULL;
}

QUEUE *EnQueue(QUEUE *q, ELEMENT_TYPE e)
{
	CHECK_VALID(q);

	NODE *node;
	node = malloc(sizeof(NODE));
	CHECK_MEMORY(node);

	node->data = e;
	node->next = NULL;

	if (IsEmpty(q))
	{
		q->head = q->tail = node;
		q->head->next = q->tail;
		q->tail->next = NULL;
	}
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
	return q;
}

QUEUE *DeQueue(QUEUE *q, ELEMENT_TYPE *e)
{
	CHECK_VALID(q);

	if (!IsEmpty(q))
	{
		if (e != NULL)
			*e = q->head->data;

		NODE *node = q->head;
		q->head = q->head->next;
		free(node);
		node = NULL;
	}
	else
	{
		printf("[WARN] no more element can be dequeued.\n");
	}

	return q;
}

bool IsEmpty(QUEUE *q)
{
	return (q->head == NULL);
}

void PrintQueue(QUEUE *q)
{
	V_CHECK_VALID(q);

	NODE *p;
	p = q->head;
	printf("head -> ");
	while(p != NULL)
	{
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("tail\n");
}

