#include<iostream>
using namespace std;


void main()
{
	//1번 문제
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

	
	//2번 문제
	int Kor, Eng, Math,Sum;
	cout << "\n세 과목의 성적을 입력해 주세요" << endl << "국 : ";
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



	//3번 문제  // 3의 배수는 제외하고 3의 배수이면서5의 배수는 제외하지 않는
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



	//4번 문제
	Sum = 0;
	while (1)
	{
		cout << "정수를 입력하시오 : ";
		cin >> Num1;
		if (Num1 == 0)
			break;
	}
	cout << "입력한 정수의 합계는 : " << Sum << "입니다." << endl;
}

