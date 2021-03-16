#include"DLinkedList.h"
#include<Windows.h>
#include "Point.h"

int main(void)
{
	int Num1, Num2;
	LinkedList list;
	Point compPos;
	Point *ppos;

	ListInit(&list);

	/*** 4개의 데이터 저장 ***/
	for (int i = 0; i < 4; i++)
	{
		ppos = (Point*)malloc(sizeof(Point));
		printf("%d번째 데이터 ) 두 수를 입력하세요 :",i+1);
		scanf_s("%d %d", &Num1, &Num2);
		SetPointPos(ppos, Num1, Num2);
		LInsert(&list, ppos);
	}
	

	/*** 저장된 데이터의 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	/*** xpos가 입력한 데이터 삭제 ***/  
	printf("삭제할 데이터의 x 값을 입력하세요 :");
	scanf_s("%d", &Num1);
	printf("삭제할 데이터의 y 값을 입력하세요 :");
	scanf_s("%d", &Num2);
	compPos.xpos = Num1;
	compPos.ypos = Num2;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 0)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 0)
			{
				ppos = LRemove(&list);
				printf("삭제된 데이터 : [%d, %d]", ppos->xpos, ppos->ypos);
				free(ppos);
			}
		}
	}

	/*** 삭제 후 남은 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");
	system("pause");
	return 0;
}