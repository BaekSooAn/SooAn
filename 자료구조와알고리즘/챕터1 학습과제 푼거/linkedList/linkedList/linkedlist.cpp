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
	/**** �����͸� �Է� �޴� ���� ****/
	while (1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		///*** ����� �߰����� ***/ //���� ���� ����
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
		

		/*** ����� �߰����� ***/ //���� �ִ� ����
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
	
		/**** �Է� ���� �������� ��°��� ****/
		printf("�Է� ���� �������� ��ü���! \n");
		if (tail == NULL)
		{
			printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
		}
		else
		{
			tail = Dummy;
			cur =tail;
			printf("%d  \n", cur->next->data);   // ù ��° ������ ���
			printf("%d �� ���� ������ %d\n", cur->next->data, cur->next->data);
			cur = cur->next;
			while (cur->next != NULL)    // �� ��° ������ ������ ���
			{
				cur = cur->next;
				printf("%d  \n", cur->data);
				printf("%d �� ���� ������ %d ���� ������ %d\n", cur->data,cur->prev->data, cur->next->data);
			}
		}
		printf("\n\n");

		///**** �޸��� �������� ****/
		//if (head == NULL)
		//{
		//	return 0;    // ������ ��尡 �������� �ʴ´�.
		//}
		//else
		//{
		//	Node * delNode = head;
		//	Node * delNextNode = head->next;

		//	printf("%d��(��) �����մϴ�. \n", head->data);
		//	free(delNode);    // ù ��° ����� ����

		//	while (delNextNode != NULL)    // �� ��° ������ ��� ���� ���� �ݺ���
		//	{
		//		delNode = delNextNode;
		//		delNextNode = delNextNode->next;

		//		printf("%d��(��) �����մϴ�. \n", delNode->data);
		//		free(delNode);    // �� ��° ������ ��� ����
		//	}
		//}

		return 0;
	
}