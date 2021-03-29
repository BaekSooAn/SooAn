#include "LClass.h"


LClass::LClass()
{
	m_iNumOfData = 0;
}

void LClass::LInsert(Node *student)
{
	if (m_iNumOfData >= STUDENT_MAX)
	{
		cout << "더 이상 학생을 추가할 수 없습니다 ,," << endl;
		system("pause");
		return;
	}
	m_StList[m_iNumOfData] = *student;
	m_iNumOfData++;
}

void LClass::LSearch(string StName)
{
	for (int i = 0; i < m_iNumOfData; i++)
	{
		if (m_StList[i].Name == StName)
		{
			cout << StName << " 학생의 학번 : " << m_StList[i].StNum << endl;
			return;
		}
	}
	cout << "찾으시는 학생이 존재하지 않습니다." << endl;
	
}



void LClass::LShow()
{
	for(int i=0;i<m_iNumOfData;i++)
		cout << m_StList[i].Name << " 학생의 학번 : " << m_StList[i].StNum << endl;
	system("pause");
}

void LClass::LRemove(string StName)
{
	for (int i = 0; i < m_iNumOfData; i++)
	{
		if (m_StList[i].Name == StName)
		{
			for (int j = i+1; j < m_iNumOfData; j++)
			{
				m_StList[i] = m_StList[j];
			}
			cout << StName << " 학생 삭제 완료" << endl;
			m_iNumOfData--;
			system("pause");
			return;
		}
	}
}

LClass::~LClass()
{
	delete m_StList;
}
