#include"LClass.h"



void Menu(LClass *list,const char *ClassName)
{
	int Select;
	string StName;
	Node *ST;

	while (1)  //�� �л��� �й����� ��ȸ
	{
		system("cls");
		cout << "===== " << ClassName << "�� �⼮�� ===== (�л��� : "<<list->LCount()<<" ��)" << endl;
		cout << "1. �л� �߰�" << endl;
		cout << "2. �л� ��ȸ" << endl;
		cout << "3. �л� ����" << endl;
		cout << "4. ��ü�л� ���" << endl;
		cout << "5. ��ü �⼮�η� ���ư���" << endl;
		cout << "�Է� : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			ST = new Node;
			cout << "�߰��� �л��� �̸�, �й� �Է� : ";
			cin >> ST->Name >> ST->StNum;
			list->LInsert(ST);
			break;
		case 2:
			cout << "��ȸ�� �л��� �̸� �Է� : ";
			cin >> StName;
			list->LSearch(StName);
			system("pause");
			break;
		case 3:
			cout << "������ �л��� �̸� �Է� :";
			cin >> StName;
			list->LRemove(StName);
			break;
		case 4:
			list->LShow();
			break;
		case 5:
			return;
		default:
			break;
		}

	}
}

void main()
{
	int iSelect,iData;
	LClass *A, *B, *C;

	while (1)
	{
		system("cls"); //�ϴ��� �ѹ� �����ϰ� ���ö� ����Ʈ �Ҵ����� �ϴ°ɷ�
		cout << "======== ���� �б� �⼮�� ========" << endl;
		cout << " A��(1)		B��(2)		C��(3)" << endl<<endl;
		cout << "�⼮�θ� ������ ���� �Է��ϼ���(����� 0) : " << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			A = new LClass;
			Menu(A,"A");
			break;
		case 2:
			B = new LClass;
			Menu(B,"B");
			break;
		case 3:
			C = new LClass;
			Menu(C,"C");
			break;
		case 0:
			return;
		}
	}
}