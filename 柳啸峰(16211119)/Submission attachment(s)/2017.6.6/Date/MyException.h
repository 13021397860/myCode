#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include "Date.h"
//#include "Students.h"
class MyException
{
	
	public:
		MyException();
		void MyExceptionOfDate(int ,int ,int ,char *);//�ռ�������д���󣬵�һ���β��Ǵ������ڣ��ڶ����β��ǡ�������������/�·�/�������� 
		void MyExceptionOfStud(int );//�ռ�ѧ������ѧ���γ���������β�Ϊ����������±�
		void MyExceptionOfOCS(int );//�ռ����޿γɼ����ô����β�Ϊ����ɼ�
		void MyExceptionOfOES(char );//�ռ�ѡ�޿γɼ����ô����β�Ϊ����ɼ� 
		~MyException();
	protected:
};

#endif
