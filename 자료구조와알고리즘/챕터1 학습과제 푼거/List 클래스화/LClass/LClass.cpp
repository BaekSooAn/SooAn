#include "LClass.h"


LClass::LClass()
{
	m_iNumOfData = 0;
}

void LClass::LInsert(Node *student)
{
	if (m_iNumOfData >= STUDENT_MAX)
	{
		cout << "�� �̻� �л��� �߰��� �� �����ϴ� ,," << endl;
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
			cout << StName << " �л��� �й� : " << m_StList[i].StNum << endl;
			return;
		}
	}
	cout << "ã���ô� �л��� �������� �ʽ��ϴ�." << endl;
	
}



void LClass::LShow()
{
	for(int i=0;i<m_iNumOfData;i++)
		cout << m_StList[i].Name << " �л��� �й� : " << m_StList[i].StNum << endl;
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
			cout << StName << " �л� ���� �Ϸ�" << endl;
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
