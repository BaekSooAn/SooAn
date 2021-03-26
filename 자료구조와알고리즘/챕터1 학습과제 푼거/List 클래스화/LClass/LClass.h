#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
#define FALSE 0
#define TRUE 1
#define STUDENT_MAX 20

typedef struct node
{
	string Name;
	int StNum; //ÇÐ¹ø
}Node;

class LClass
{
private:
	//Node *Head;
	Node m_StList[STUDENT_MAX];
	int m_iNumOfData;

public:
	LClass();
	void LInsert(Node *student);
	void LSearch(string StName);
	void LShow();
	void LRemove(string StName);
	inline int LCount()
	{
		return m_iNumOfData;
	}
	~LClass();
};

