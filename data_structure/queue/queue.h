/****************************************
 * Queue using Single list.
 *
 * gaoc@dsp.ac.cn
 * 2009.09.10
 ***************************************/

#ifndef __QUEUE_H__
#define __QUEUE_H__

/* defined by gcc */
#include "stdbool.h"

#define ELEMENT_TYPE int

typedef struct Node{
	ELEMENT_TYPE data;
	struct Node *next;
}NODE;

typedef struct Queue{
	struct Node *head;
	struct Node *tail;
}QUEUE;

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

QUEUE *CreateQueue();
void DestroyQueue(QUEUE *q);
QUEUE *EnQueue(QUEUE *q, ELEMENT_TYPE e);
QUEUE *DeQueue(QUEUE *q, ELEMENT_TYPE *e);
bool IsEmpty(QUEUE *q);
void PrintQueue(QUEUE *q);

#endif // __QUEUE_H__

