#include"LClass.h"



void Menu(LClass *list,const char *ClassName)
{
	int Select;
	string StName;
	Node *ST;

	while (1)  //각 학생은 학번으로 조회
	{
		system("cls");
		cout << "===== " << ClassName << "반 출석부 ===== (학생수 : "<<list->LCount()<<" 명)" << endl;
		cout << "1. 학생 추가" << endl;
		cout << "2. 학생 조회" << endl;
		cout << "3. 학생 삭제" << endl;
		cout << "4. 전체학생 출력" << endl;
		cout << "5. 전체 출석부로 돌아가기" << endl;
		cout << "입력 : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			ST = new Node;
			cout << "추가할 학생의 이름, 학번 입력 : ";
			cin >> ST->Name >> ST->StNum;
			list->LInsert(ST);
			break;
		case 2:
			cout << "조회할 학생의 이름 입력 : ";
			cin >> StName;
			list->LSearch(StName);
			system("pause");
			break;
		case 3:
			cout << "삭제할 학생의 이름 입력 :";
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
		system("cls"); //일단은 한번 열람하고 나올때 리스트 할당해제 하는걸루
		cout << "======== 수안 학교 출석부 ========" << endl;
		cout << " A반(1)		B반(2)		C반(3)" << endl<<endl;
		cout << "출석부를 열람할 반을 입력하세요(종료는 0) : " << endl;
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