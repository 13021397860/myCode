#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;
class Course
{
	string name;//�γ����� 
	int creditHour;//�γ�ѧ�� 
	public:
		Course();
		Course(string , int );//�����ֱ�Ϊ���ƺ�ѧ�� 
		void setName(string );
		string getName()const;//���ؿγ��� 
		int getCreditHour()const;//���ؿγ�ѧ�� 
		void setCreditHour(int );
		inline friend ostream& operator<< (ostream& o, const Course *t)
		{
			o<<"�γ�����"<<t->getName()<<" ѧ�֣�"<<t->getCreditHour()<<" �ɼ�Ϊ��"<<t->getScore()<<endl;
			return o; 
		}
	virtual void printCourse(){}//�麯����1.������д��{}���д�ɲ�д��2.���ﲻ��{}����.cpp��дʵ�� 
	virtual int getScore()const = 0 ; //���麯�������ࣺcourse t������course *t�����ԣ� 
	//virtual void setScore(){}
	virtual ~Course();
};

#endif
