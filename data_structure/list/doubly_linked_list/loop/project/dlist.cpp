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

/**
 * @brief 创建链表
 * @param 无
 * @return 指向链表的指针
 */
pList CreateList()
{
	pList list = new List();
    CHECK_STD_RETURN(list, NULL);

	list->count = 0;
	list->head = list->tail = NULL;

	return list;
}

/**
 * @brief 删除链表及其节点
 * @param list 指向链表的指针
 * @return 无
 */
void DestroyList(pList list)
{
    CHECK_STD(list);

    if (!(list->tail)) 
    {
        delete list;
        list = NULL;
        return;
    }

	pNode index = list->tail;
	pNode prev = NULL;
	do
	{
		prev = index->prev;
		printf("release %d\n", index->data);
        delete index;
		index = prev;
	}while(index != list->tail);

    delete list;
	list = NULL;
	printf("clearly.\n");
}

/**
 * @brief 创建节点
 * @param data 节点数据
 * @return 该节点指针
 */
static pNode CreateNode(int data)
{
	pNode node = new Node();
    CHECK_STD_RETURN(node, NULL);

	node->data = data;
	node->prev = node->next = node;
	return node;
}

/**
 * @brief 在链表中搜索某个节点
 * @param list 指向链表的指针
 * @param data 检索条件
 * @return 若有，则返回该节点指针；若无，则为NULL
 */
pNode SearchNode(pList list, int data)
{
    CHECK_STD_RETURN(list, NULL);

	if (!(list->head)) {
		return NULL;
    }

	pNode index = list->head;
	do
	{
		if (index->data == data) {
			printf("find node %d\n", data);
			return index;
		} else {
			index = index->next;
        }
	}while(index != list->head);
	
	printf("[WARN] Node %d not find.\n", data);
	return NULL;
}

/**
 * @brief 向链表尾部添加一个节点
 * @param list 指向链表的指针
 * @param data 节点值
 * @return 是否添加成功
 */
bool InsertNode(pList list, int data)
{
    CHECK_STD_RETURN(list, false);

	pNode node = CreateNode(data);
    CHECK_STD_RETURN(node, false);

	if (!(list->tail))
	{
		list->head = list->tail = node;
		node->prev = node->next = node;
	}
	else
	{
        CHECK_STD_RETURN(list->tail, false);
        CHECK_STD_RETURN(list->head, false);
		list->tail->next = node;
		node->prev = list->tail;
		node->next = list->head;
		list->head->prev = node;
		list->tail = node;
	}

	list->count += 1;

	return true;
}

/**
 * @brief 从链表中删除一个节点
 * @param list 指向链表的指针
 * @param data 节点值
 * @return 是否删除成功
 */
bool DeleteNode(pList list, int data)
{
    CHECK_STD_RETURN(list, false);

	pNode index = SearchNode(list, data);
    if (!index) {
        return false;
    }

	list->count -= 1;

	if (index == list->head) /* case head */
	{
		if (list->head == list->tail)
		{
			list->head = list->tail = NULL;
		}
		else
		{
			list->head = index->next;

            CHECK_STD_RETURN(list->tail, false);
            CHECK_STD_RETURN(list->head, false);
            list->tail->next = list->head;
            list->head->prev = list->tail;
		}
	}
	else if (index == list->tail) /* case tail */
	{
		list->tail = index->prev;

        CHECK_STD_RETURN(list->tail, false);
        CHECK_STD_RETURN(list->head, false);
        list->tail->next = list->head;
		list->head->prev = list->tail;
	}
	else /* the simplest case: inner node */
	{
        CHECK_STD_RETURN(index->prev, false);
        CHECK_STD_RETURN(index->next, false);
		index->prev->next = index->next;
		index->next->prev = index->prev;
	}

    delete index;
	return true;
}

/**
 * @brief 打印链表中的所有节点
 * @param list 指向链表的指针
 * @return 无
 */
void PrintList(pList list)
{
    CHECK_STD(list);

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

