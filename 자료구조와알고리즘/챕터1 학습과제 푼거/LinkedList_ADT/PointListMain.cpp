#include"DLinkedList.h"
#include<Windows.h>
#include "Point.h"


int WhoIsPrecede(int d1, int d2) //typedef int Ldata;
{
	if (d1 < d2)
		return 0; // d1�� ���� ������ �ռ���. ��������
	else
 		return 1; // d2�� ���� ������ �ռ��ų� ����. ��������
}


int main(void)
{
	int Num1, Num2;
	LinkedList list;
	Point compPos;
	Point *ppos;

	ListInit(&list);	
	//SetSortRule(&list,)

	/*** 4���� ������ ���� ***/
	for (int i = 0; i < 4; i++)
	{
		ppos = (Point*)malloc(sizeof(Point));
		printf("%d��° ������ ) �� ���� �Է��ϼ��� :",i+1);
		scanf_s("%d %d", &Num1, &Num2);
		SetPointPos(ppos, Num1, Num2);
		SInsert(&list, ppos);
	}
	

	
	
	/*** ����� �������� ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	/*** xpos�� �Է��� ������ ���� ***/  
	printf("������ �������� x ���� �Է��ϼ��� :");
	scanf_s("%d", &Num1);
	printf("������ �������� y ���� �Է��ϼ��� :");
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
				printf("������ ������ : [%d, %d]", ppos->xpos, ppos->ypos);
				free(ppos);
			}
		}
	}

	/*** ���� �� ���� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

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
����1. x��ǥ�� ���� ��������
 �������� ������ �ǰ� ����.
����2. x��ǥ�� ���� ���� ��쿡��
y��ǥ�� ������� �������� ������ �ǰ� ����.



�ؾ��Ҳ�

SetSortRule()�� ����Ʈ�� ������������
��������������

WhoIsPrecede() <-���ο� �̤�����
1.�Ű����� �� �޾Ƽ� �־��������


SInsert()
while �� �����̶� �ȿ� ����
plist->comp�����ؾ���
�Լ������� ��°�ϴ�??

sortCompare()



�����Ҷ� �����ϸ鼭


List->comp�� 0�̸�


"pred ����� �ؽ�Ʈ" �� ����
*/