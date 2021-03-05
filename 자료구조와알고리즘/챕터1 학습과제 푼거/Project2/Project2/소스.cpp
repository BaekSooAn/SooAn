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
{	//1�� �� ���� ���� ���� Ŭ���� ū ����

	if (num == 1) 
		cout << "����1 �� " << before << "����" << after << "�� �̵�" << endl;
	else
	{
		Hanoi(num - 1, before, after, ing);
		cout << "����" << num << " �� " << before << "����" << after << "�� �̵�" << endl;
		Hanoi(num - 1, ing, before, after);
	}
}

void main()
{
	int inum,imid;
	int iarr[ArrSize] = { 1,2,3,7,9,12,21,23,27,30 };
	//1�� ����
	cout << "�Ǻ���ġ �������� �� ��° ���� ��������Ű��� ?" << endl;
	cin >> inum;
	cout << inum << "��° ���� " << Fibo(inum) << " �Դϴ�." << endl;
	system("pause");

	//2�� ����
	cout << "ã���ô� ���ڸ� �˷��ּ��� : ";
	cin >> inum;
	cout << "��� : " << BSearch(iarr, 0, ArrSize / 2, ArrSize, inum) << endl;
	system("pause");

	//3�� ����
	system("cls");
	cout << "�ڡڡڡڡ� �ϳ��� Ÿ�� �ڡڡڡڡ�" << endl;
	cout << "��� ������ ����Ͻðڽ��ϱ� ?" << endl;
	cin >> inum;
	cout << "\n������ ũ��� ���� �� ���ڰ� Ŭ���� ū �����Դϴ�." << endl<<endl;
	Hanoi(inum, STICK_A, STICK_B, STICK_C);
	system("pause");
}