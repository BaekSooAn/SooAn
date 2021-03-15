#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

Node AddHead(Node **head, Node **tail ,Node *node)
{
	if (head == NULL)
		*tail = node;
	else
		node->next = *head;

	*head = node;

	return *node;
}

Node AddTail(Node **head, Node **tail, Node *node)
{
	if (head == NULL)
		*head = node;
	else
		tail->next = node;

	*tail = node;
	return *node;
}


int main(void)
{
	Node * head = NULL;    // NULL ������ �ʱ�ȭ
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	/**** �����͸� �Է� �޴� ���� ****/
	while (1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		/*** ����� �߰����� ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (newNode->data % 2 == 0)
			*newNode= AddTail(&head, &tail, newNode);
		else
			*newNode = AddHead(&head, &tail, newNode);
	}
	printf("\n");

	/**** �Է� ���� �������� ��°��� ****/
	printf("�Է� ���� �������� ��ü���! \n");
	if (head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		cur = head;
		printf("%d  ", cur->data);   // ù ��° ������ ���

		while (cur->next != NULL)    // �� ��° ������ ������ ���
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** �޸��� �������� ****/
	if (head == NULL)
	{
		return 0;    // ������ ��尡 �������� �ʴ´�.
	}
	else
	{
		Node * delNode = head;
		Node * delNextNode = head->next;

		printf("%d��(��) �����մϴ�. \n", head->data);
		free(delNode);    // ù ��° ����� ����

		while (delNextNode != NULL)    // �� ��° ������ ��� ���� ���� �ݺ���
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);    // �� ��° ������ ��� ����
		}
	}

	return 0;
}