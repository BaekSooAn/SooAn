#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	LInsert(&list, "일수안", 1);
	LInsert(&list, "십수안", 10);
	LInsert(&list, "백수안", 100);
	LInsert(&list, "천수안", 1000);
	//원형리스트에는 구조체변수 주소값 저장

	
	//직원 목록한번 프린트 하고
	


	//등록 순서대로 (일수안 ~천수안 순서)로 당직을 선다  
	//꼬리추가로 했으니까 재귀함수로 풀리면서 출력하게끔




	//직원이름과 숫자를 이용해서 당직 확인 

	//함수하나 만들어서 직원 이름, 숫자(날짜) 넘겨주고, 
	//해당 직원이 당직서고, 받은 숫자(날짜)만큼의 날짜가 지나고 당직 서는 직원정보 반환
	//ex) 일수안, 3 넘겨주면, 일수안이당직서고 천수안 정보 반환







	
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}

	// 2의 배수를 찾아서 모두 삭제 ///////
	nodeNum = LCount(&list);

	if (nodeNum != 0)
	{
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (i = 0; i < nodeNum - 1; i++)
		{
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	// 전체 데이터 1회 출력 ///////
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	return 0;
}

//linkedlist.cpp에 이름 변수 받는 부분 