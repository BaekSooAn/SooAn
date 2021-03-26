#include <stdio.h>
#include <Windows.h>
#include "DDBLinkedList.h"

int main(void)
{
	List list;
	int data;
	ListInit(&list);



	// 8개의 데이터 저장 ///////
	LInsert(&list, 1);  LInsert(&list, 2);
	LInsert(&list, 3);  LInsert(&list, 4);
	LInsert(&list, 5);  LInsert(&list, 6);
	LInsert(&list, 7);  LInsert(&list, 8);

	// 저장된 데이터의 조회 ///////
	if (LFirst(&list, &data) == DATA_EMPTY)
	{
		printf("저장된 데이터가 없습니다...\n");
	}
	else if (LFirst(&list, &data) == PREV_NULL)
	{
		printf("%d ) 이전데이터 : 없음		다음데이터 : %d\n", data, list.cur->next->data);
		while (1)
		{
			switch (LNext(&list,&data))
			{
			case NEXT_NULL:
				printf("%d ) 이전데이터 : %d		다음데이터 : 없음\n", data, list.cur->prev->data);
				system("pause");
				return 0;
			case SIDE_FULL:
				printf("%d ) 이전데이터 : %d		다음데이터 : %d\n", data, list.cur->prev->data,list.cur->next->data);
				break;
			}
			
		} 
	}

	//// 2의 배수 전부 삭제 ///////
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

	//// 저장된 데이터의 재 조회 ///////
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