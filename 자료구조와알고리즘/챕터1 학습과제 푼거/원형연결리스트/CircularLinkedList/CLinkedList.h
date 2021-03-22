#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0
#define NAMEMAX 32

typedef int Data;

typedef struct node
{
	const char *name[NAMEMAX];
	Data data;
	node *next;
} Node;

typedef struct CLL
{
	Node *tail;
	Node *cur;
	Node *before;
	int numOfData;
}CList;


typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist,const char *name, Data data);
void LInsertFront(List * plist, const char *name, Data data);
int LSearch(List *plist, const char *name, int day);
int LFirst(List * plist, Node * pnode);
int LNext(List * plist, Node * pnode);
Data LRemove(List * plist);
int LCount(List * plist);

#endif
