#include<iostream>
#include<time.h>
#include<Windows.h>
using namespace std;


void main()
{
	srand(time(NULL));
	cout << "1�� ���� = ====" << endl;
	int Num1, Num2;
	
	cout << "�� ���� �Է��Ͻÿ�." << endl;
	cin >> Num1 >> Num2;
	if (Num1 >= Num2)
	{
		if (Num1 % 2 == 0)
			cout << Num1 << "��(��) ¦���Դϴ�." << endl;
	}
	else if (Num1 < Num2)
	{
		if (Num2 % 2 == 0)
			cout << Num2 << "��(��) ¦���Դϴ�." << endl;
	}

	
	cout << "\n2�� ���� =====" << endl;
	int Kor, Eng, Math,Sum;
	cout << "�� ������ ������ �Է��� �ּ���" << endl << "�� : ";
	cin >> Kor;
	cout << "�� : ";
	cin >> Eng;
	cout << "�� : ";
	cin >> Math;
	Sum = Kor + Eng + Math;
	cout << "�� ������ �հ�� " << Sum << "�̰�, ����� " << Sum /3.0f<<"�Դϴ�"<<endl;

	if (Sum / 3.0f >= 90)
		cout << "��� : A" << endl;
	else if (Sum / 3.0f >= 80)
		cout << "��� : B" << endl;
	else if (Sum / 3.0f >= 70)
		cout << "��� : C" << endl;
	else if (Sum / 3.0f >= 60)
		cout << "��� : D " << endl;
	else
		cout << "��� : F" << endl;



	cout << "\n3�� ���� =====" << endl;
	Sum = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (i % 3 == 0)
		{
			if (i % 5 == 0)
			{
			}
			else
				continue;
		}
		Sum += i;
	}
	cout << "1~1000������ �հ� :  " << Sum<<endl;
	


	cout << "\n4�� ���� =====" << endl;
	Sum = 0;
	while (1)
	{
		cout << "������ �Է��Ͻÿ� : (0�� �Է��ϸ� ����)";
		cin >> Num1;
		if (Num1 == 0)
			break;

		Sum += Num1;
	}
	cout << "�Է��� ������ �հ�� : " << Sum << "�Դϴ�." << endl;
	system("pause");


	system("cls");
	cout << "5�� ���� =====" << endl;
	cout << "<UpDown ����>   1~100���� ���� �� ����" << endl;
	int RNum = (rand() % 100) + 1;
	while (1)
	{
		cout << "���ڸ� �Է��Ͻÿ� : ";
		cin >> Num1;
		if (RNum == Num1)
		{
			cout << "�����Դϴ� !!" << endl;
			break;
		}
		else if (RNum > Num1)
		{
			cout <<  "Up !!" << endl;
		}
		else
			cout << "Down !!" << endl;
	}
	system("Pause");


}

