#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	LInsert(&list, "�ϼ���", 1);
	LInsert(&list, "�ʼ���", 10);
	LInsert(&list, "�����", 100);
	LInsert(&list, "õ����", 1000);
	//��������Ʈ���� ����ü���� �ּҰ� ����

	
	//���� ����ѹ� ����Ʈ �ϰ�
	


	//��� ������� (�ϼ��� ~õ���� ����)�� ������ ����  
	//�����߰��� �����ϱ� ����Լ��� Ǯ���鼭 ����ϰԲ�




	//�����̸��� ���ڸ� �̿��ؼ� ���� Ȯ�� 

	//�Լ��ϳ� ���� ���� �̸�, ����(��¥) �Ѱ��ְ�, 
	//�ش� ������ ��������, ���� ����(��¥)��ŭ�� ��¥�� ������ ���� ���� �������� ��ȯ
	//ex) �ϼ���, 3 �Ѱ��ָ�, �ϼ����̴������� õ���� ���� ��ȯ







	
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}

	// 2�� ����� ã�Ƽ� ��� ���� ///////
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

	// ��ü ������ 1ȸ ��� ///////
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

//linkedlist.cpp�� �̸� ���� �޴� �κ� 