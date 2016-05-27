/****************************************
 * Stack using Single list.
 *
 * gaoc@dsp.ac.cn
 * 2009.09.10
 ***************************************/

#ifndef __STACK_H__
#define __STACK_H__

/* defined by gcc */
#include "stdbool.h"

#define ELEMENT_TYPE int

typedef struct Node{
	ELEMENT_TYPE data;
	struct Node *next;
}NODE;

typedef struct Stack{
	struct Node *top;
}STACK;

#define CHECK_MEMORY(x) \
	        if ((x) == NULL) \
		{ printf("[%s]:[%s()] no available memory.\n", \
				__FILE__, __FUNCTION__); \
			return NULL;\
		}

#define CHECK_RETURN(x) \
	        if ((x) == NULL) \
		{ printf("[%s]:[%s()] return error.\n", \
				__FILE__, __FUNCTION__); \
			return NULL;\
		}

#define CHECK_VALID(x) \
	        if ((x) == NULL) \
		{ printf("[%s]:[%s()] NULL, not valid.\n", \
				__FILE__, __FUNCTION__); \
			return NULL;\
		}

#define V_CHECK_VALID(x) \
	        if ((x) == NULL) \
		{ printf("[%s]:[%s()] NULL, not valid.\n", \
				__FILE__, __FUNCTION__); \
			return;\
		}

STACK *CreateStack();
void DestroyStack(STACK *s);
bool GetTop(STACK *s, ELEMENT_TYPE *e);
STACK *Push(STACK *s, ELEMENT_TYPE e);
STACK *Pop(STACK *s, ELEMENT_TYPE *e);
bool IsEmpty(STACK *s);
void PrintStack(STACK *s);

#endif // __STACK_H__

