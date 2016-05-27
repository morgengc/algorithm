/****************************************************
 * Stack using Single list.
 *
 * Take care of the direction of the "next" pointer.
 *
 *           +--+-+   +--+-+   +--+-+   +--+-+   
 * <- Pop -- |  |-|-->|  |-|-->|  |-|-->|  |-|--> NIL
 *           +--+-+ | +--+-+   +--+-+   +--+-+
 * -- Push ->   |   |                       |
 *             top  |                      bottom
 *                  |
 *                 next
 *
 *
 * gaoc@dsp.ac.cn
 * 2009.09.10
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

/* NOTE: before using s->top->data, make sure
 *       that s->stop is not NULL! See Pop.
 * */
STACK *CreateStack()
{
	STACK *s;
	s = (STACK *)malloc(sizeof(STACK));
	CHECK_MEMORY(s);
	s->top = NULL;
	return s;
}

void DestroyStack(STACK *s)
{
	V_CHECK_VALID(s);

	while(!IsEmpty(s))
		Pop(s, NULL);

	free(s);
	s = NULL;
}

/* Get element at the top. 
 * NOTE: You must check the return value
 *       before you use the value of "e". 
 * */
bool GetTop(STACK *s, ELEMENT_TYPE *e)
{
	if (s == NULL)
	{
		*e = -1;
		return false;
	}
	else
	{
		if (!IsEmpty(s))
		{
			*e = s->top->data;
			return true;
		}
		else
		{
			*e = -1;
			return false;
		}
	}
}

STACK *Push(STACK *s, ELEMENT_TYPE e)
{
	CHECK_VALID(s);

	NODE *node;
	node = malloc(sizeof(NODE));
	CHECK_MEMORY(node);

	node->data = e;
	node->next = s->top;
	s->top = node;
	return s;
}

STACK *Pop(STACK *s, ELEMENT_TYPE *e)
{
	CHECK_VALID(s);

	if (!IsEmpty(s))
	{
		if (e != NULL)
			*e = s->top->data;

		NODE *node = s->top;
		s->top = s->top->next;
		free(node);
		node = NULL;
	}
	else
	{
		printf("[WARN] no more element can be poped.\n");
	}

	return s;
}

bool IsEmpty(STACK *s)
{
	return (s->top == NULL);
}

void PrintStack(STACK *s)
{
	V_CHECK_VALID(s);

	NODE *p;
	p = s->top;
	printf("top -> ");
	while(p != NULL)
	{
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("]\n");
}

