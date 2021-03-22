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

void LInsertFront(List * plist, const char *name, Data data) //�Ӹ��߰�
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

void LInsert(List * plist,const char *name, Data data) //���� �߰�
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
	//���� �̸��� �ش��ϴ� ������ ���� ��� day ���� ��¥�� �������� ��� ���
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
				printf("��� [ %s ]   ��� [ %d ]\n", plist->cur->name, plist->cur->data);
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
	if (plist->tail == NULL)    // ����� ��尡 ���ٸ�
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	pnode = plist->cur;
	return TRUE;
}

int LNext(List * plist, Node * pnode)
{
	if (plist->tail == NULL)    // ����� ��尡 ���ٸ�
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

	if (rpos == plist->tail)    // ���� ����� tail�� ����Ų�ٸ�
	{
		if (plist->tail == plist->tail->next)    // �׸��� ������ ���� �����
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