#include "Point.h"
#ifndef __DLinked_List_H_
#endif __DLinked_List_H_

#define TRUE 1
#define FALSE 0

typedef Point *LData;

typedef struct NODE
{
	LData data;
	NODE *next;
}Node; 

typedef struct
{
	Node *head;
	Node *cur;
	Node *before;
	int NumOfData;
	int(*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
int SortCompare(LData data1, LData data2);
void SInsert(List *plist, LData data);
void LInsert(List * plist, LData data);
int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);
LData LRemove(List * plist);
int LCount(List * plist);
void SetSortRule(List * plist, int(*comp)(LData d1, LData d2));

