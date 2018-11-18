#include "Student.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Date.h"
#include "ElectiveCourse.h"
#include "MyExpection.h"
#include "ObligatoryCourse.h"
#define MAX_SIZE 3
using namespace std;

int Student::count=0;
int Student::courseNumber1=0;
int Student::courseNumber2=0;

Student::Student(const char * n,const Date&d)
	:birthdate(d)
{
	name=NULL;
	setname(n);
	count++;	
}

Student&Student::addObligatoryCourse(ObligatoryCourse *course)
{
	if(courseNumber1<=MAX_SIZE)
	{
		courselist[courseNumber1++]=course;
	}
	return (*this);
}

Student&Student::addElectiveCourse(ElectiveCourse*course1)
{
	if(courseNumber2<=MAX_SIZE)
	{
		courselist2[courseNumber2++]=course1;
	}
	return (*this);
}
Student::Student(const Student &s)
	:birthdate(s.birthdate)
	{
		name=NULL;
		setname(s.name);
		count++;
	}

void Student::setname(const char*n)
{
	if(name)
	{
		delete[]name;
	}
	name=new char[strlen(n)+1];
	strcpy(name,n);
}

int Student::getcount()
{
	return count;
}

char *Student::getname()const 
{
	return name;
}

ostream& operator<<(ostream& output,const Student &s)
{
	int a;
	int n=1;
	output<<s.getname()<<"\n";
	output<<s.birthdate<<"\n";
	output<<"必修课如下：\n";
	for(int i=0;i<=2;i++)
	{
		output<<"科目编号"<<n<<":"; 
		output<<(*s.courselist[i]);
		n++;
	}
	output<<"选修课如下："<<endl;
	for(int i=0;i<=2;i++)
	{
		output<<"科目编号"<<n<<":"; 
		output<<(*s.courselist2[i]);
		n++; 
	}
}

bool Student::remove(const char *a,int b)
{
	if(strcmp(a,"o")==0)
	{
		delete courselist[b];
		for(int i=b;i<courseNumber1-1;i++)
		{
			courselist[i]=courselist[i+1];
		}
		delete courselist[courseNumber1];
		courseNumber1--;
	}
	else if(strcmp(a,"e")==0)
	{
		delete courselist2[b];
		for(int i=b;i<courseNumber2;i++)
		{
			courselist2[i]=courselist2[i+1];
		}
		delete courselist2[courseNumber2];
		courseNumber2--;
	}
	return 1;
}

int Student::search()
{
	char a;
	cin>>a;
	while(a!='#')
	{
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout<<"输入错误请重新输入"<<endl;
		}
		else
		{
			MyExpection ex("下标越界");
			try
			{
				cout<<ex.biao(a);
			}
			catch(MyExpection ex)
			{
				cout<<ex.what()<<"异常"<<endl;
			}
			if(a=='1')
			{
				cout<<"科目1："<<courselist[0]->name<<"  成绩是："<<courselist[0]->getScore()<<endl;
			}
			else if(a=='2')
			{
				cout<<"科目2："<<courselist[1]->name<<"  成绩是："<<courselist[1]->getScore()<<endl;
			}
			else if(a=='3')
			{
				cout<<"科目3："<<courselist[2]->name<<"  成绩是："<<courselist[2]->getScore()<<endl;
			}
			else if(a=='4')
			{
				cout<<"科目4："<<courselist2[0]->name<<"  成绩是："<<courselist2[0]->getScore()<<endl;
			}
			else if(a=='5')
			{
				cout<<"科目5："<<courselist2[1]->name<<"  成绩是："<<courselist2[1]->getScore()<<endl;
			}
			else if(a=='6')
			{
				cout<<"科目6："<<courselist2[2]->name<<"  成绩是："<<courselist2[2]->getScore()<<endl;
			}
			
		}
		cin>>a;
	}
	
}

int Student::calcCredit()
{
	double osum=0;
	double esum=0;
	double oosum=0;
	double eesum=0;
	double sum=0;
	for(int i=0;i<=courseNumber1-1;i++)
	{
		osum=osum+courselist[i]->getCoursecreditHour();
		oosum=oosum+(courselist[i]->getScore()*courselist[i]->getCoursecreditHour());
	}
	oosum=oosum/osum;
	for(int i=0;i<=courseNumber2-1;i++)
	{
		esum=esum+(courselist2[i]->getScore());
	}
	eesum=esum/courseNumber2;
	sum=oosum*courselist[0]->getWeight()+eesum*courselist2[0]->getWeight();
	cout<<sum<<endl;
}
Student::~Student()
{
	delete []name;
	for(int i=0;i<courseNumber1;i++)
	{
		delete courselist[i];
		courseNumber1--;
	}
	for(int i=0;i<courseNumber2;i++)
	{
		delete courselist2[i];
		courseNumber2--;
	}
	count--;
}
