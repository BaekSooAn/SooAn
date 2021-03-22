#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "CLinkedList.h"

void ListInit(List * plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List * plist, const char *name, Data data) //머리추가
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	*newNode->name = name;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

void LInsert(List * plist,const char *name, Data data) //꼬리 추가
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	*newNode->name = name;
	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

int LSearch(List *plist,const char *name, int day)
{
	//받은 이름에 해당하는 직원이 있을 경우 day 뒤의 날짜에 당직서는 사람 출력
	if (LFirst(plist, plist->tail))
	{
		for (int i = 0; i < LCount(plist) - 1; i++)
		{
			if (strcmp(*plist->cur->name, name) == 0)
			{
				for (int i = 0; i < day; i++)
				{
					plist->before = plist->cur;
					plist->cur = plist->cur->next;
				}
				printf("사원 [ %s ]   사번 [ %d ]\n", plist->cur->name, plist->cur->data);
				return 1;
			}
			plist->before = plist->cur;
			plist->cur = plist->cur->next;
		}
	}
	else
		return 0;

}

int LFirst(List * plist, Node * pnode)
{
	if (plist->tail == NULL)    // 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	pnode = plist->cur;
	return TRUE;
}

int LNext(List * plist, Node * pnode)
{
	if (plist->tail == NULL)    // 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	pnode = plist->cur;
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail)    // 삭제 대상을 tail이 가리킨다면
	{
		if (plist->tail == plist->tail->next)    // 그리고 마지막 남은 노드라면
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}