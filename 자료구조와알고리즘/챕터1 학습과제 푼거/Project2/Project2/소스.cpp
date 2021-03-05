#include<iostream>
#include<Windows.h>
using namespace std;

#define ArrSize 10

enum STICK
{
	STICK_A,
	STICK_B,
	STICK_C
};

int Fibo(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int BSearch(int arr[], int first, int mid, int last, int find)
{
	if (first > last)
		return -1;
	if (find == arr[mid])
		return find;
	else if (find < arr[mid])
		BSearch(arr, first, (first + last) / 2, mid - 1, find);
	else if (find > arr[mid])
		BSearch(arr, mid + 1, (first + last) / 2, last, find);
}

void Hanoi(int num,int before, int ing ,int after)
{	//1이 젤 작은 원판 숫자 클수록 큰 원판

	if (num == 1) 
		cout << "원판1 을 " << before << "에서" << after << "로 이동" << endl;
	else
	{
		Hanoi(num - 1, before, after, ing);
		cout << "원판" << num << " 을 " << before << "에서" << after << "로 이동" << endl;
		Hanoi(num - 1, ing, before, after);
	}
}

void main()
{
	int inum,imid;
	int iarr[ArrSize] = { 1,2,3,7,9,12,21,23,27,30 };
	//1번 문제
	cout << "피보나치 수열에서 몇 번째 수를 보고싶으신가요 ?" << endl;
	cin >> inum;
	cout << inum << "번째 수는 " << Fibo(inum) << " 입니다." << endl;
	system("pause");

	//2번 문제
	cout << "찾으시는 숫자를 알려주세요 : ";
	cin >> inum;
	cout << "결과 : " << BSearch(iarr, 0, ArrSize / 2, ArrSize, inum) << endl;
	system("pause");

	//3번 문제
	system("cls");
	cout << "★★★★★ 하노이 타워 ★★★★★" << endl;
	cout << "몇개의 원판을 사용하시겠습니까 ?" << endl;
	cin >> inum;
	cout << "\n원판의 크기는 원판 뒤 숫자가 클수록 큰 원판입니다." << endl<<endl;
	Hanoi(inum, STICK_A, STICK_B, STICK_C);
	system("pause");
}