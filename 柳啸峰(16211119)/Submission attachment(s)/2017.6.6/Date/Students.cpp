#include "Students.h"
#include <iostream>
#include <cstring>
#include "Time.h"
#include <typeinfo>
#include "MyException.h"
using namespace std;
int Students::counter=0;
Students::Students(char *a, const Date &b):birthDate(b)
{
    name=new char[strlen(a)+1];
    strcpy(name, a);
    counter++;
    courseNumber=0;
}
Students::Students(const Students &a):birthDate(a.birthDate)
{
    name=new char[strlen(a.name)+1];
    strcpy(name ,a.name);
}
void Students::getName(char *s)
{
    strcpy(s, name);
}
Date Students::getBirthDate()
{
    return birthDate;
}
int Students::getCounter()
{
    return counter;
}
void Students::print()const
{
    cout<<"����������"<<name<<endl;
    cout<<"������"<<birthDate.getYear()<<"�� ";
    cout<<birthDate.getMonth()<<"�� ";
    cout<<birthDate.getDay()<<"�� \n";
}
Students& Students::addCourse(Course *course)//����Ĳ���Ҳ���������������������ڴ���Ĺ��������Ͳ��� 
{
	if(courseNumber<MAX_SIZE) 
	{
		courseList[courseNumber++]=course;
	}
	return (*this);
}
Students& Students::addElectiveCourse(char grade, const string &courseName, int creditHour )
{
	if(courseNumber<MAX_SIZE)
	{
		courseList[courseNumber++]=new ElectiveCourse(grade, courseName, creditHour);//new ����Ӧ�ý�������󣬲�Ȼ 
	}                                                                                //֮��Ĳ������޷���ȷ�����麯 
	return (*this);																	//��		
}
Students& Students::addObligatoryCourse(int score, const string &courseName, int creditHour )
{
	if(courseNumber<MAX_SIZE)
	{
		courseList[courseNumber++]=new ObligatoryCourse(score, courseName, creditHour);
	}
	return (*this);
}
int Students::getCourseNumber()const
{
	return courseNumber;
}
Course* Students::getCourseList(int i)//����˽�г�Ա��courseList���� 
{
	return courseList[i];
}
bool Students::removeCourse(int i)//iΪ�ڼ��ſ� 
{
	if(i>courseNumber||i<1)
	{
	 	cout<<"������ѡ�Ŀ�Ŀ�����ڣ�" <<endl;
		return false;
	}
	else
	{
		cout<<"������ѡ�Ŀγ�Ϊ��\n"; 
		cout<<courseList[i-1]<<endl;
		Course *c=courseList[i-1];
		delete c;//ɾ��ָ����ָ��Ķ�������ʱcҲΪ�� 
		for(int j=i-1;j<courseNumber-1;j++)
		{
			courseList[j]=courseList[j+1];	
		}
		courseNumber--;
		return true;
	}
}
void Students::SetCourseGrade(MyException &MyEx)
{
	cout<<"���޿�������0-100��ѡ�޿�������A-E\n";
	for(int i=0;i<getCourseNumber();i++)
	{
		if(typeid(*courseList[i])==typeid(ObligatoryCourse))//ͨ��typeid���ж��������� 
		{                                                   //ͷ�ļ���<typeinfo> 
			int mark;
			while(cin>>mark)
			{
				try
				{
					if(cin.fail()||mark<0||mark>100)
					{
						cin.clear();
           				cin.ignore();
           				throw mark;
					}
				}catch(int )
				{
					cout<<"������ĳɼ����Ϸ������������룡"<<endl;
					MyEx.MyExceptionOfOCS(mark);
					continue;
				}
				
				break;		
			}
			((ObligatoryCourse*)courseList[i])->setMark(mark);//courseList����������Course 
		}                                                     //��Ҫת�������Ӧ�� �γ�����
		else                                                  //���ܵ������Ӧ��set���� 
		{
			char grade;
			while(cin>>grade)
			{
				try
				{
					if(grade!='A'&&grade!='B'&&grade!='C'&&grade!='D'&&grade!='E')
						throw grade;
				}catch(char grade)
				{
					cout<<"������ĳɼ����Ϸ������������룡"<<endl;
					MyEx.MyExceptionOfOES(grade);
					continue; 
				}
				break;
			}
			((ElectiveCourse*)courseList[i])->setGrade(grade);
		}
	 }
}
int Students::calcCredit()
{
	int totalOfOCC=0, numberOfECC=0;//ѡ�޿ε��ܿ��� 
	double GPA=0;
	for(int i=0;i<courseNumber;i++)
	{
		if(typeid(*courseList[i])==typeid(ObligatoryCourse))//����ѡ�޺ͱ��޿ε���ѧ�� 
			totalOfOCC+=courseList[i]->getCreditHour();
		else
			numberOfECC++;		
	} 
	for(int i=0;i<courseNumber;i++)
	{
		if(typeid(*courseList[i])==typeid(ObligatoryCourse))
			GPA+=0.6*(courseList[i]->getScore()*(static_cast<double>(courseList[i]->getCreditHour())/totalOfOCC));		
		else
			GPA+=0.4*(static_cast<double>(courseList[i]->getScore())/numberOfECC);//ǿ��ת�������� 
	} 
	return GPA;
}
Students::~Students()
{
    delete []name;
    for(int i=0;i<courseNumber;i++)//�ͷ�ָ��ռ� 
    {
    	delete courseList[i];
	} 
    counter--;
    cout<<"�����Ѿ����"<<endl;
}

