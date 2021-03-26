#ifndef __DBD_LINKED_LIST_H__
#define __DBD_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef enum
{
	DATA_EMPTY, //아무 데이터도 없는경우(head - tail만 존재)
	PREV_NULL, //이전노드 없는 경우
	NEXT_NULL, //다음노드 없는 경우
	SIDE_FULL //양쪽 모두 연결되어있는 경우
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
특징 1. 양방향 연결 리스트
특징 2. 더미 노드가 리스트의 앞과 뒤에 각각 존재한다.
특징 3. 포인터 변수 head와 tail이 있어서 리스트의 앞과 뒤를 각각 가리킨다.


구현을 보여주지 않았던 LRemove를 직접 구현해보기 바란다, LPrevious를 제거해주자.
DummyNode를 잘 활용하면 LRemove가 상당히 쉬워진다.
무작정 만들다기보다 그림으로 함수를 그려보고 작성해보자.
분명히 도움이 될 것이다.*/



