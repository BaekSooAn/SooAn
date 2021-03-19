#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0
#define NAMEMAX 32

typedef int Data;

typedef struct node
{
	const char name[NAMEMAX];
	Data data;
	Node *next;
} Node;

typedef struct CLL
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
} CList;


typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist,const char name[NAMEMAX], Data data);
void LInsertFront(List * plist, const char name[NAMEMAX], Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
Data LRemove(List * plist);
int LCount(List * plist);

#endif
