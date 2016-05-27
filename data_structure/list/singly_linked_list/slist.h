/****************************************
 * single linked list.
 *
 * gaoc@dsp.ac.cn
 * 2009.09.10
 ***************************************/

#ifndef _S_LIST_H_
#define _S_LIST_H_

/* defined by gcc */
#include "stdbool.h"

typedef struct Node {
	struct Node *next;
	int data;
} Node, *pNode;

typedef struct List {
	Node *head;
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
		{ printf("[%s]:[%s()] return error.\n", \
				__FILE__, __FUNCTION__); \
			return false;\
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
pNode SearchNode(pList list, int element);
bool InsertNode(pList list, int element);
bool DeleteNode(pList list, int element);

/* Advance Operations */
bool SortList(pList list);
bool ReverseList(pList list);

void PrintList(pList list);

#endif // _S_LIST_H_

