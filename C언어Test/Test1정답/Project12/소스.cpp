#include<iostream>
using namespace std;


void main()
{
	//1�� ����
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

	
	//2�� ����
	int Kor, Eng, Math,Sum;
	cout << "\n�� ������ ������ �Է��� �ּ���" << endl << "�� : ";
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



	//3�� ����  // 3�� ����� �����ϰ� 3�� ����̸鼭5�� ����� �������� �ʴ�
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



	//4�� ����
	Sum = 0;
	while (1)
	{
		cout << "������ �Է��Ͻÿ� : ";
		cin >> Num1;
		if (Num1 == 0)
			break;
	}
	cout << "�Է��� ������ �հ�� : " << Sum << "�Դϴ�." << endl;
}

