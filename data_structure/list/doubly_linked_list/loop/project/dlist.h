/******************************************************
 * doubley linked list, looping from tail to head.
 *
 * 双向循环列表
 *
 * gaoc@dsp.ac.cn
 * 2009.09.11
 *****************************************************/

#ifndef _D_LIST_H_
#define _D_LIST_H_

/* defined by gcc */
#include "stdbool.h"

#include "utils.h"
#include "check.h"
#include "numeric.h"

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

pList   CreateList();
void    DestroyList(pList list);

pNode   SearchNode(pList list, int data);
bool    InsertNode(pList list, int data);
bool    DeleteNode(pList list, int data);

void    PrintList(pList list);

#endif // _D_LIST_H_

