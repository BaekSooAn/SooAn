#ifndef __ARRAY_LIST_H__ //����� ������ �ϽŰ� �̰��� Ŭ������������ �𸣰ڽ��ϴ�,,

#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

#define ArrSize 32
#define TRUE 1
#define FALSE 0

typedef int LData;
typedef struct ArrayList
{
	LData iArr[ArrSize];
	int NumOfData;
	int curPosition;
}List;


void ListInit(List *plist)
{
	(plist->NumOfData) = 0;
	(plist->curPosition) = 0;
	for (int i = 0; i < ArrSize;i++)
		plist->iArr[i] = 0;
}

void LInsert(List *plist, LData data)
{
	if (plist->NumOfData >= ArrSize)
	{
		cout << "������ �Է� �Ұ��� . . ." << endl;
		return;
	}
	plist->iArr[plist->NumOfData] = data;
	(plist->NumOfData)++;
}


LData LRemove(List *plist,LData CulPosition)
{
	int rpos = CulPosition;
	int num = plist->NumOfData;
	LData rdata = plist->iArr[rpos];

	for (int i = rpos; i < num - 1; i++)
		plist->iArr[i] = plist->iArr[i + 1]; //?? ���࿡ 12345 �ְ� 3 ����� 12455 �Ǵ°� �ƴѰ���...?

	(plist->NumOfData)--;
	(plist->curPosition)--;
	return rdata;
}

void SelectRemove(List *plist) //2�� ��� 3�� ��� ����
{
	int DelNum;
	if (plist->NumOfData == 0)
		return;

	(plist->curPosition) = 0;
	while (plist->curPosition <= (plist->NumOfData) - 1)
	{
		if (plist->iArr[plist->curPosition] % 2 == 0 || plist->iArr[plist->curPosition] % 3 == 0)
		{
			cout << LRemove(plist, plist->curPosition) << "\t";
		}
		(plist->curPosition)++;
	}
}

void Show(List *plist)
{
	if (plist->NumOfData == 0)
		return;

	(plist->curPosition) = 0;
	while (plist->curPosition <= (plist->NumOfData) - 1)
	{
		cout << plist->iArr[plist->curPosition] << "\t";
		(plist->curPosition)++;
	}
}

int AddList(List *plist)//������ �հ�
{
	int i= plist->NumOfData,sum=0;
	while (1)
	{
		if (i < 0)
			return sum; 
		sum+= plist->iArr[i];
		i--;
	}
}


void main()
{
	List *iList=new List;
	ListInit(iList);

	for (int i = 1; i <= 9; i++)
		LInsert(iList, i);
	cout << "����Ʈ�� �� ���� �Ϸ�,,," << endl<<endl;
	cout << "����Ʈ�� ����� ������ �� : " << AddList(iList) << endl << endl;
	cout << "����Ʈ�� ����� ���� �� 2�� ����� 3�� ��� ���" << endl;
	SelectRemove(iList);
	cout << "\n\n����Ʈ�� ����� ���� �� 2�� ����� 3�� ��� ���� �Ϸ�,,," << endl;
	cout << "\n\n����Ʈ�� ����� �� ���� ��� " << endl;
	Show(iList);
}
#endif