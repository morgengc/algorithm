/****************************************
 * doubley linked list, but not loop.
 *
 * gaoc@dsp.ac.cn
 * 2008.11.24
 ***************************************/

#ifndef _D_LIST_H_
#define _D_LIST_H_

/* defined by gcc */
#include "stdbool.h"

typedef struct Node {
	struct Node *prev;
	struct Node *next;
	int data;
} Node, *pNode;

typedef struct List {
	Node *head;
	Node *tail;
	int count;
} List, *pList;

#define P_CHECK_MEMORY(x) \
	        if ((x) == NULL) \
		{ printf("[%s]:[%s()] no available memory.\n", \
				__FILE__, __FUNCTION__); \
			return NULL;\
		}

#define B_CHECK_MEMORY(x) \
	        if ((x) == NULL) \
		{ printf("[%s]:[%s()] no available memory.\n", \
				__FILE__, __FUNCTION__); \
			return false;\
		}

#define P_CHECK_RETURN(x) \
	        if ((x) == NULL) \
		{ printf("[%s]:[%s()] return error.\n", \
				__FILE__, __FUNCTION__); \
			return NULL;\
		}

#define B_CHECK_RETURN(x) \
	        if ((x) == NULL) \
		{ \
			return false; \
		}


#define P_CHECK_VALID(x) \
	        if ((x) == NULL) \
		{ printf("[%s]:[%s()] NULL, not valid.\n", \
				__FILE__, __FUNCTION__); \
			return NULL;\
		}

#define B_CHECK_VALID(x) \
	        if ((x) == NULL) \
		{ printf("[%s]:[%s()] NULL, not valid.\n", \
				__FILE__, __FUNCTION__); \
			return false;\
		}

#define V_CHECK_VALID(x) \
	        if ((x) == NULL) \
		{ printf("[%s]:[%s()] NULL, not valid.\n", \
				__FILE__, __FUNCTION__); \
			return;\
		}

pList CreateList();
void DestroyList(pList list);

/* Basic Operations */
pNode SearchNode(pList list, int data);
bool InsertNode(pList list, int data);
bool DeleteNode(pList list, int data);

void PrintList(pList list);

#endif // _D_LIST_H_

