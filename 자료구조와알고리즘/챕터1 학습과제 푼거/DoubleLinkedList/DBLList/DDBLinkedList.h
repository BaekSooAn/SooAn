#ifndef __DBD_LINKED_LIST_H__
#define __DBD_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef enum
{
	DATA_EMPTY, //�ƹ� �����͵� ���°��(head - tail�� ����)
	PREV_NULL, //������� ���� ���
	NEXT_NULL, //������� ���� ���
	SIDE_FULL //���� ��� ����Ǿ��ִ� ���
}RETURN;

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
	struct _node * prev;
} Node;

typedef struct _dbDLinkedList
{
	Node * head;
	Node * tail;
	Node * cur;
	int numOfData;
} DBDLinkedList;

typedef DBDLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);

Data LRemove(List * plist);
int LCount(List * plist);

#endif


/*
Ư¡ 1. ����� ���� ����Ʈ
Ư¡ 2. ���� ��尡 ����Ʈ�� �հ� �ڿ� ���� �����Ѵ�.
Ư¡ 3. ������ ���� head�� tail�� �־ ����Ʈ�� �հ� �ڸ� ���� ����Ų��.


������ �������� �ʾҴ� LRemove�� ���� �����غ��� �ٶ���, LPrevious�� ����������.
DummyNode�� �� Ȱ���ϸ� LRemove�� ����� ��������.
������ ����ٱ⺸�� �׸����� �Լ��� �׷����� �ۼ��غ���.
�и��� ������ �� ���̴�.*/



