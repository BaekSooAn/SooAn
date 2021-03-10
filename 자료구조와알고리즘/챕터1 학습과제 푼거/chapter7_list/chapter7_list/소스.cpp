#ifndef __ARRAY_LIST_H__ //헤더를 만들라고 하신게 이건지 클래스파일인지 모르겠습니당,,

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
		cout << "데이터 입력 불가능 . . ." << endl;
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
		plist->iArr[i] = plist->iArr[i + 1]; //?? 만약에 12345 있고 3 지우면 12455 되는거 아닌가요...?

	(plist->NumOfData)--;
	(plist->curPosition)--;
	return rdata;
}

void SelectRemove(List *plist) //2의 배수 3의 배수 삭제
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

int AddList(List *plist)//데이터 합계
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
	cout << "리스트에 값 저장 완료,,," << endl<<endl;
	cout << "리스트에 저장된 값들의 합 : " << AddList(iList) << endl << endl;
	cout << "리스트에 저장된 값들 중 2의 배수와 3의 배수 목록" << endl;
	SelectRemove(iList);
	cout << "\n\n리스트에 저장된 값들 중 2의 배수와 3의 배수 삭제 완료,,," << endl;
	cout << "\n\n리스트에 저장된 값 순차 출력 " << endl;
	Show(iList);
}
#endif