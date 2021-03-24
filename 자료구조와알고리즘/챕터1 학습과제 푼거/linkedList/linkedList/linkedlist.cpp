#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *prev;
	struct _node * next;
} Node;



int main(void)
{
	Node * tail = NULL;
	Node * cur = NULL;
	Node *Dummy;
	Node * newNode = NULL;
	int readData;

	Dummy = (Node*)malloc(sizeof(Node));
	Dummy->next = NULL;
	tail=Dummy;
	/**** 데이터를 입력 받는 과정 ****/
	while (1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		///*** 노드의 추가과정 ***/ //더미 없는 버젼
		//newNode = (Node*)malloc(sizeof(Node));
		//newNode->data = readData;
		//newNode->next = NULL;
		//cur = tail;

		//if (tail == NULL)
		//{
		//	tail = newNode;
		//	newNode->prev = NULL;
		//}
		//else
		//{
		//	while (cur->next != NULL)
		//	{
		//		cur = cur->next;
		//	}
		//	cur->next = newNode;
		//	newNode->prev = cur;
		//}
		

		/*** 노드의 추가과정 ***/ //더미 있는 버젼
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		cur =tail;

		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
		newNode->prev = cur;
		
	}
		printf("\n");
	
		/**** 입력 받은 데이터의 출력과정 ****/
		printf("입력 받은 데이터의 전체출력! \n");
		if (tail == NULL)
		{
			printf("저장된 자연수가 존재하지 않습니다. \n");
		}
		else
		{
			tail = Dummy;
			cur =tail;
			printf("%d  \n", cur->next->data);   // 첫 번째 데이터 출력
			printf("%d 의 다음 데이터 %d\n", cur->next->data, cur->next->data);
			cur = cur->next;
			while (cur->next != NULL)    // 두 번째 이후의 데이터 출력
			{
				cur = cur->next;
				printf("%d  \n", cur->data);
				printf("%d 의 이전 데이터 %d 다음 데이터 %d\n", cur->data,cur->prev->data, cur->next->data);
			}
		}
		printf("\n\n");

		///**** 메모리의 해제과정 ****/
		//if (head == NULL)
		//{
		//	return 0;    // 해제할 노드가 존재하지 않는다.
		//}
		//else
		//{
		//	Node * delNode = head;
		//	Node * delNextNode = head->next;

		//	printf("%d을(를) 삭제합니다. \n", head->data);
		//	free(delNode);    // 첫 번째 노드의 삭제

		//	while (delNextNode != NULL)    // 두 번째 이후의 노드 삭제 위한 반복문
		//	{
		//		delNode = delNextNode;
		//		delNextNode = delNextNode->next;

		//		printf("%d을(를) 삭제합니다. \n", delNode->data);
		//		free(delNode);    // 두 번째 이후의 노드 삭제
		//	}
		//}

		return 0;
	
}