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

// NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
NameCard * MakeNameCard(const char  *name, const char * phone);

// NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard * pcard);

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard * pcard, char * name);

// ��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard * pcard, char * phone);

#endif


NameCard* MakeNameCard(const char *name, const char *phone) // NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
{
	NameCard *NCard = new NameCard;
	*NCard->name = name;
	*NCard->phone = phone;
	return NCard;
}

void ShowNameCardInfo(NameCard *pcard)// NameCard ����ü ������ ���� ���  
{
	if (pcard == NULL)
	{
		cout << "�� ���� ����" << endl;
		return;
	}
	cout <<"��  "<< *pcard->name << "  ���� ��ȭ��ȣ : " << *pcard->phone << endl;
}

int NameCompare(NameCard *pcard, char *name)// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ 
{
	if (strcmp(*pcard->name, name) == 0)
		return 0;
	else
		return -1;
}

void ChangePhoneNum(NameCard *pcard, char *phone)// ��ȭ��ȣ ������ ����
{
	*pcard->phone = phone;
	cout << "��ȭ��ȣ ���� �Ϸ�" << endl;
}


void main()
{
	int iSelect;
	char SearchName[NAME_LEN],ChangePhone[PHONE_LEN];

	NameCard *arrNameCard[3];

	arrNameCard[0] = MakeNameCard("�����", "01012345678");
	arrNameCard[1] = MakeNameCard("õ����", "01087654321");
	arrNameCard[2] = MakeNameCard("������", "01011112222");

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
			for (int i = 0; i < 3; i++)
			{
				if (NameCompare(arrNameCard[i], SearchName) == 0)
					ShowNameCardInfo(arrNameCard[i]);
			}
			system("pause");
			break;
		case 2:
			cout << "�˻��� �̸� �Է� : ";
			cin >> SearchName;
			for (int i = 0; i < 3; i++)
			{
				if (NameCompare(arrNameCard[i], SearchName) == 0)
				{
					ShowNameCardInfo(arrNameCard[i]);
					cout << "������ ��ȭ��ȣ �Է� : ";
					cin >> ChangePhone;
					ChangePhoneNum(arrNameCard[i], ChangePhone);
				}
			}
			system("pause");
			break;
		case 3:
			cout << "�˻��� �̸� �Է� : ";
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
			cout << "���� ���� �Ϸ�" << endl;
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


