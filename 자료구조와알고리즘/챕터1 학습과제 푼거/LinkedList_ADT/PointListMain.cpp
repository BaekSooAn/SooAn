#include"DLinkedList.h"
#include<Windows.h>
#include "Point.h"


int WhoIsPrecede(int d1, int d2) //typedef int Ldata;
{
	if (d1 < d2)
		return 0; // d1이 정렧 순서상 앞선다. 오름차순
	else
 		return 1; // d2가 정렧 순서상 앞서거나 같다. 내림차순
}


int main(void)
{
	int Num1, Num2;
	LinkedList list;
	Point compPos;
	Point *ppos;

	ListInit(&list);	
	//SetSortRule(&list,)

	/*** 4개의 데이터 저장 ***/
	for (int i = 0; i < 4; i++)
	{
		ppos = (Point*)malloc(sizeof(Point));
		printf("%d번째 데이터 ) 두 수를 입력하세요 :",i+1);
		scanf_s("%d %d", &Num1, &Num2);
		SetPointPos(ppos, Num1, Num2);
		SInsert(&list, ppos);
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


/*
조건1. x좌표의 값을 기준으로
 오름차순 정렧이 되게 핚다.
조건2. x좌표의 값이 같은 경우에는
y좌표를 대상으로 오름차순 정렧이 되게 핚다.



해야할꺼

SetSortRule()이 리스트가 오름차순인지
내림차순ㅇ니지

WhoIsPrecede() <-메인에 이ㅇ응ㅁ
1.매개변수 뭐 받아서 넣어줘야하지


SInsert()
while 문 조건이랑 안에 들어갈꺼
plist->comp지정해야함
함수포인터 어째하는??

sortCompare()



삽입할때 정렬하면서


List->comp가 0이면


"pred 뉴노드 넥스트" 이 순서
*/