#include <stdio.h>
#include<Windows.h>
#include "CLinkedList.h"

int main(void)
{
	List list;
	Data data;
	int i;
	int	day=0;
	char SearchName[NAMEMAX] = {"\0"};
	ListInit(&list);

	LInsert(&list, "일수안", 1);
	LInsert(&list, "십수안", 10);
	LInsert(&list, "백수안", 100);
	LInsert(&list, "천수안", 1000);

	printf("========= 수안 IT 당직자 목록 =========\n\n");
	if (LFirst(&list,list.tail))
	{
		printf("Day 1 : 사원 [ %s ]   사번 [ %d ]\n", *list.cur->name,list.cur->data);

		for (i = 0; i < LCount(&list)*2 - 1; i++)
		{
			if (LNext(&list, list.cur))
				printf("Day %d : 사원 [ %s ]   사번 [ %d ]\n",i+2, *list.cur->name, list.cur->data);
		}
	}

	printf("\n\n 당직자 확인하기 ,,, \n사원명을 입력하세요 : ");
	scanf_s("%s", SearchName,sizeof(SearchName));
	printf("몇일 뒤의 당직자를 보시겠습니까? ");
	scanf_s("%d",&day);

	if (LSearch(&list, SearchName, day) == 0) //0이면 해당직원 없음
		printf("해당하는 직원이 존재하지 않습니다,,, \n");


	system("pause");
	return 0;
}

