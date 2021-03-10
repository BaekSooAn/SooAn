#ifndef __NAME_CARD_H__
#define __NAME_CARD_H__

#include<iostream>
#include<Windows.h>
using namespace std;

#define NAME_LEN	30
#define PHONE_LEN	30

typedef struct __namecard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}NameCard;

// NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
NameCard * MakeNameCard(char * name, char * phone);

// NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard * pcard);

// 이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard * pcard, char * name);

// 전화번호 정보를 변경
void ChangePhoneNum(NameCard * pcard, char * phone);

#endif


/*
main.cpp 조건(구조체는 이름이랑 전번 char형으로 가짐)

1. 총 3명의 전화번호 정보를, ArrayList에 저장한다. 리스트 안에 구조체 3개?
2. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력한다.
3. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호 정보를 변경한다.
4. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제한다.
5. 끝으로 남아있는 모든 사람의 전화번호 정보를 출력한다.
*/



NameCard* MakeNameCard(char *name, char *phone) // NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
{
	NameCard *NCard = new NameCard;
	*NCard->name = *name;
	*NCard->phone = *phone;
	return NCard;
}

void ShowNameCardInfo(NameCard *pcard)// NameCard 구조체 변수의 정보 출력  
{
	cout <<"고객  "<< pcard->name << "  님의 전화번호 : " << pcard->phone << endl;

}

int NameCompare(NameCard *pcard, char *name)// 이름이 같으면 0, 다르면 0이 아닌 값 반환 
{

}

void ChangePhoneNum(NameCard *pcard, char *phone)// 전화번호 정보를 변경
{

}

void main()
{
	int iSelect;
	char SearchName[NAME_LEN],ChangePhone[PHONE_LEN];
	char Name1[] = "백수안",Phone1[]="01012345678";
	char Name2[] = "천수안", Phone2[] = "01087654321";
	char Name3[] = "만수안", Phone3[] = "01022446688";

	NameCard *arrNameCard[3];
	for (int i = 0; i < 3; i++)
		arrNameCard[i] = new NameCard;
	arrNameCard[0] = MakeNameCard(Name1, Phone1);
	arrNameCard[1] = MakeNameCard(Name2, Phone2);
	arrNameCard[2] = MakeNameCard(Name3, Phone3);

	while (1)
	{
		system("cls");
		cout << "1. 이름 검색(정보출력)" << endl;
		cout << "2. 이름 검색(정보변경)" << endl;
		cout << "3. 이름 검색(정보삭제)" << endl;
		cout << "4. 모든 정보 출력" << endl;
		cout << "5. 종료" << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "검색할 이름 입력 : ";
			cin >> SearchName;
			if (NameCompare(*arrNameCard, SearchName) == 0)
				ShowNameCardInfo(*arrNameCard);
			break;
		case 2:
			cout << "검색할 이름 입력 : ";
			cin >> SearchName;
			if (NameCompare(*arrNameCard, SearchName) == 0)
			{
				cout << "변경하실 전화번호 입력(- 제외) : ";
				cin >> ChangePhone;
				ChangePhoneNum(*arrNameCard, ChangePhone);
			}
			break;
		case 3:
			cout << "검색할 이름 입력 : ";
			cin >> SearchName;
			//삭제하는거
			break;
		case 4:
			break;
		case 5:
			return;
		}
	}










}


