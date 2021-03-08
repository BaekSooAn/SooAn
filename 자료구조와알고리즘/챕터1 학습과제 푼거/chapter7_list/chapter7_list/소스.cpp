#ifndef __ARRAY_LIST_H__
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

#define ArrSize 10
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
}

void LInsert(List * plist, LData data)
{
	if (plist->NumOfData >= ArrSize)
	{
		cout << "데이터 입력 불가능 . . ." << endl;
		return;
	}
	plist->iArr[plist->NumOfData] = data;
	(plist->NumOfData)++;
}

int LFirst(List *plist, LData *pdata)
{
	if (plist->NumOfData == 0)
		return FALSE;
	(plist->curPosition) = 0;
	*pdata = plist->iArr[0];

	return TRUE;
}

int LNext(List *plist, LData *pdata)
{
	if (plist->curPosition >= (plist->NumOfData) - 1)
		return FALSE;
	(plist->curPosition)++;
	*pdata = plist->iArr[plist->curPosition];

	return TRUE;
}

LData LRemove(List *plist)
{
	int rpos = plist->curPosition;
	int num = plist->NumOfData;
	LData rdata = plist->iArr[rpos];

	for (int i = rpos; i < num - 1; i++)
		plist->iArr[i] = plist->iArr[i + 1];

	(plist->NumOfData)--;
	(plist->curPosition)--;
	return rdata;
}


void main()
{
	
}


#endif