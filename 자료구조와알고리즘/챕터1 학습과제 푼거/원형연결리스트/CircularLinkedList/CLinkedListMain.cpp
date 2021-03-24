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

	LInsert(&list, "�ϼ���", 1);
	LInsert(&list, "�ʼ���", 10);
	LInsert(&list, "�����", 100);
	LInsert(&list, "õ����", 1000);

	printf("========= ���� IT ������ ��� =========\n\n");
	if (LFirst(&list,list.tail))
	{
		printf("Day 1 : ��� [ %s ]   ��� [ %d ]\n", *list.cur->name,list.cur->data);

		for (i = 0; i < LCount(&list)*2 - 1; i++)
		{
			if (LNext(&list, list.cur))
				printf("Day %d : ��� [ %s ]   ��� [ %d ]\n",i+2, *list.cur->name, list.cur->data);
		}
	}

	printf("\n\n ������ Ȯ���ϱ� ,,, \n������� �Է��ϼ��� : ");
	scanf_s("%s", SearchName,sizeof(SearchName));
	printf("���� ���� �����ڸ� ���ðڽ��ϱ�? ");
	scanf_s("%d",&day);

	if (LSearch(&list, SearchName, day) == 0) //0�̸� �ش����� ����
		printf("�ش��ϴ� ������ �������� �ʽ��ϴ�,,, \n");


	system("pause");
	return 0;
}

