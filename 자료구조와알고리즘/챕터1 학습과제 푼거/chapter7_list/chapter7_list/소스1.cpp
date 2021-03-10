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

// NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
NameCard * MakeNameCard(char * name, char * phone);

// NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard * pcard);

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard * pcard, char * name);

// ��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard * pcard, char * phone);

#endif


/*
main.cpp ����(����ü�� �̸��̶� ���� char������ ����)

1. �� 3���� ��ȭ��ȣ ������, ArrayList�� �����Ѵ�. ����Ʈ �ȿ� ����ü 3��?
2. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ ����Ѵ�.
3. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ��ȭ��ȣ ������ �����Ѵ�.
4. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ �����Ѵ�.
5. ������ �����ִ� ��� ����� ��ȭ��ȣ ������ ����Ѵ�.
*/



NameCard* MakeNameCard(char *name, char *phone) // NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
{
	NameCard *NCard = new NameCard;
	*NCard->name = *name;
	*NCard->phone = *phone;
	return NCard;
}

void ShowNameCardInfo(NameCard *pcard)// NameCard ����ü ������ ���� ���  
{
	cout <<"��  "<< pcard->name << "  ���� ��ȭ��ȣ : " << pcard->phone << endl;

}

int NameCompare(NameCard *pcard, char *name)// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ 
{

}

void ChangePhoneNum(NameCard *pcard, char *phone)// ��ȭ��ȣ ������ ����
{

}

void main()
{
	int iSelect;
	char SearchName[NAME_LEN],ChangePhone[PHONE_LEN];
	char Name1[] = "�����",Phone1[]="01012345678";
	char Name2[] = "õ����", Phone2[] = "01087654321";
	char Name3[] = "������", Phone3[] = "01022446688";

	NameCard *arrNameCard[3];
	for (int i = 0; i < 3; i++)
		arrNameCard[i] = new NameCard;
	arrNameCard[0] = MakeNameCard(Name1, Phone1);
	arrNameCard[1] = MakeNameCard(Name2, Phone2);
	arrNameCard[2] = MakeNameCard(Name3, Phone3);

	while (1)
	{
		system("cls");
		cout << "1. �̸� �˻�(�������)" << endl;
		cout << "2. �̸� �˻�(��������)" << endl;
		cout << "3. �̸� �˻�(��������)" << endl;
		cout << "4. ��� ���� ���" << endl;
		cout << "5. ����" << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "�˻��� �̸� �Է� : ";
			cin >> SearchName;
			if (NameCompare(*arrNameCard, SearchName) == 0)
				ShowNameCardInfo(*arrNameCard);
			break;
		case 2:
			cout << "�˻��� �̸� �Է� : ";
			cin >> SearchName;
			if (NameCompare(*arrNameCard, SearchName) == 0)
			{
				cout << "�����Ͻ� ��ȭ��ȣ �Է�(- ����) : ";
				cin >> ChangePhone;
				ChangePhoneNum(*arrNameCard, ChangePhone);
			}
			break;
		case 3:
			cout << "�˻��� �̸� �Է� : ";
			cin >> SearchName;
			//�����ϴ°�
			break;
		case 4:
			break;
		case 5:
			return;
		}
	}










}


