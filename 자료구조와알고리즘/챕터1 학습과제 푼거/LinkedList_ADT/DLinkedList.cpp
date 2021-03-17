#include"DLinkedList.h"


void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->NumOfData = 0;
}

void LInsert(List * plist, LData data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data; 
	newNode->next = plist->head->next; 
	plist->head->next = newNode; 
	(plist->NumOfData)++;
}

int *comp(LData data1, LData data2)
{
	if (data1->xpos < data2->xpos)
		return 0;
	else if (data1->xpos == data2->xpos &&data1->ypos < data2->ypos)
		return 0;
	else
		return -1;
}

void SInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node)); 
	Node * pred = plist->head; 
	newNode->data = data; 

	While(pred->next != NULL & plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next; 
	}
	newNode->next = pred->next; 
	pred->next = newNode;
	(plist->NumOfData)++; 
}


int LFirst(List * plist, LData * pdata)
{
	if (plist->head->next == NULL) 
		return FALSE; 
	plist->before = plist->head; 
	plist->cur = plist->head->next; 
	*pdata = plist->cur->data; 
	return TRUE;
}
int LNext(List * plist, LData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node *rpos = plist->cur;
	LData rData = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	plist->NumOfData--;
	return rData;
}

int LCount(List * plist)
{
	return plist->NumOfData;
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

