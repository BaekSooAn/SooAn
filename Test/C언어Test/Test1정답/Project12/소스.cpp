#include<iostream>
#include<time.h>
#include<Windows.h>
using namespace std;


void main()
{
	srand(time(NULL));
	cout << "1번 문제 = ====" << endl;
	int Num1, Num2;
	
	cout << "두 수를 입력하시오." << endl;
	cin >> Num1 >> Num2;
	if (Num1 >= Num2)
	{
		if (Num1 % 2 == 0)
			cout << Num1 << "은(는) 짝수입니다." << endl;
	}
	else if (Num1 < Num2)
	{
		if (Num2 % 2 == 0)
			cout << Num2 << "은(는) 짝수입니다." << endl;
	}

	
	cout << "\n2번 문제 =====" << endl;
	int Kor, Eng, Math,Sum;
	cout << "세 과목의 성적을 입력해 주세요" << endl << "국 : ";
	cin >> Kor;
	cout << "영 : ";
	cin >> Eng;
	cout << "수 : ";
	cin >> Math;
	Sum = Kor + Eng + Math;
	cout << "세 과목의 합계는 " << Sum << "이고, 평균은 " << Sum /3.0f<<"입니다"<<endl;

	if (Sum / 3.0f >= 90)
		cout << "등급 : A" << endl;
	else if (Sum / 3.0f >= 80)
		cout << "등급 : B" << endl;
	else if (Sum / 3.0f >= 70)
		cout << "등급 : C" << endl;
	else if (Sum / 3.0f >= 60)
		cout << "등급 : D " << endl;
	else
		cout << "등급 : F" << endl;



	cout << "\n3번 문제 =====" << endl;
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
	cout << "1~1000까지의 합계 :  " << Sum<<endl;
	


	cout << "\n4번 문제 =====" << endl;
	Sum = 0;
	while (1)
	{
		cout << "정수를 입력하시오 : (0을 입력하면 종료)";
		cin >> Num1;
		if (Num1 == 0)
			break;

		Sum += Num1;
	}
	cout << "입력한 정수의 합계는 : " << Sum << "입니다." << endl;
	system("pause");


	system("cls");
	cout << "5번 문제 =====" << endl;
	cout << "<UpDown 게임>   1~100사이 숫자 중 랜덤" << endl;
	int RNum = (rand() % 100) + 1;
	while (1)
	{
		cout << "숫자를 입력하시오 : ";
		cin >> Num1;
		if (RNum == Num1)
		{
			cout << "정답입니다 !!" << endl;
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

