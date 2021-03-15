#ifndef __NAME_CARD_H__
#define __NAME_CARD_H__

#include<iostream>
#include<Windows.h>
using namespace std;

#define NAME_LEN	30
#define PHONE_LEN	30

typedef struct __namecard
{
	const char *name[NAME_LEN];
	const char *phone[PHONE_LEN];
}NameCard;

// NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
NameCard * MakeNameCard(const char  *name, const char * phone);

// NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard * pcard);

// 이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard * pcard, char * name);

// 전화번호 정보를 변경
void ChangePhoneNum(NameCard * pcard, char * phone);

#endif


NameCard* MakeNameCard(const char *name, const char *phone) // NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
{
	NameCard *NCard = new NameCard;
	*NCard->name = name;
	*NCard->phone = phone;
	return NCard;
}

void ShowNameCardInfo(NameCard *pcard)// NameCard 구조체 변수의 정보 출력  
{
	if (pcard == NULL)
	{
		cout << "고객 정보 없음" << endl;
		return;
	}
	cout <<"고객  "<< *pcard->name << "  님의 전화번호 : " << *pcard->phone << endl;
}

int NameCompare(NameCard *pcard, char *name)// 이름이 같으면 0, 다르면 0이 아닌 값 반환 
{
	if (strcmp(*pcard->name, name) == 0)
		return 0;
	else
		return -1;
}

void ChangePhoneNum(NameCard *pcard, char *phone)// 전화번호 정보를 변경
{
	*pcard->phone = phone;
	cout << "전화번호 변경 완료" << endl;
}


void main()
{
	int iSelect;
	char SearchName[NAME_LEN],ChangePhone[PHONE_LEN];

	NameCard *arrNameCard[3];

	arrNameCard[0] = MakeNameCard("백수안", "01012345678");
	arrNameCard[1] = MakeNameCard("천수안", "01087654321");
	arrNameCard[2] = MakeNameCard("만수안", "01011112222");

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
			for (int i = 0; i < 3; i++)
			{
				if (NameCompare(arrNameCard[i], SearchName) == 0)
					ShowNameCardInfo(arrNameCard[i]);
			}
			system("pause");
			break;
		case 2:
			cout << "검색할 이름 입력 : ";
			cin >> SearchName;
			for (int i = 0; i < 3; i++)
			{
				if (NameCompare(arrNameCard[i], SearchName) == 0)
				{
					ShowNameCardInfo(arrNameCard[i]);
					cout << "변경할 전화번호 입력 : ";
					cin >> ChangePhone;
					ChangePhoneNum(arrNameCard[i], ChangePhone);
				}
			}
			system("pause");
			break;
		case 3:
			cout << "검색할 이름 입력 : ";
			cin >> SearchName;
			for (int i = 0; i < 3; i++)
			{
				if (NameCompare(arrNameCard[i], SearchName) == 0)
				{
					ShowNameCardInfo(arrNameCard[i]);
					for (int j = i + 1; j < 3; j++)
					{
						arrNameCard[i] = arrNameCard[j];
						i++;
					}
				}
			}
			arrNameCard[2] = NULL;
			cout << "정보 삭제 완료" << endl;
			system("pause");
			break;
		case 4:
			for (int i = 0; i < 3; i++)
				ShowNameCardInfo(arrNameCard[i]);
			system("pause");
			break;
		case 5:
			return;
		}
	}










}


