#include <stdio.h>
#include <Windows.h>
#include "DDBLinkedList.h"

int main(void)
{
	List list;
	Node *Dummy =NULL;
	list.head = Dummy;
	list.tail = Dummy;
	int data;
	ListInit(&list);



	// 8���� ������ ���� ///////
	LInsert(&list, 1);  LInsert(&list, 2);
	LInsert(&list, 3);  LInsert(&list, 4);
	LInsert(&list, 5);  LInsert(&list, 6);
	LInsert(&list, 7);  LInsert(&list, 8);

	// ����� �������� ��ȸ ///////
	if (LFirst(&list, &data) == DATA_EMPTY)
	{
		printf("����� �����Ͱ� �����ϴ�...\n");
	}
	else if (LFirst(&list, &data) == PREV_NULL)
	{
		//�� �ٷ� �ؿ� ������ PREV_NEXT_NULL ���⿡ �ش��Ҽ��� ����. ���������� ���� ��
		printf("%d ) ���������� : ����		���������� : %d\n", data, list.cur->data);
		while (1)
		{
			switch (LNext(&list,&data))
			{
			case NEXT_NULL:
				printf("%d ) ���������� : %d		���������� : ����\n", data, list.cur->prev->data);
				break;
			case SIDE_FULL:
				printf("%d ) ���������� : %d		���������� : %d\n", data, list.cur->prev->data,list.cur->next->data);
				break;
			}
			
		} 
	}

	//// 2�� ��� ���� ���� ///////
	//if (LFirst(&list, &data))
	//{
	//	if (data % 2 == 0)
	//		LRemove(&list);

	//	while (LNext(&list, &data))
	//	{
	//		if (data % 2 == 0)
	//			LRemove(&list);
	//	}
	//}

	//// ����� �������� �� ��ȸ ///////
	//if (LFirst(&list, &data))
	//{
	//	printf("%d ", data);

	//	while (LNext(&list, &data))
	//		printf("%d ", data);

	//	printf("\n\n");
	//}
	system("pause");
	return 0;
}