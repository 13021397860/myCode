#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "Console.h"
#include "MyException.h"
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <fstream>
using namespace std;
static int count=0;
Student::Student(char* n,int y,int m,int d)
{
	setName(n);
	setBirthdate(y,m,d);
	count++;
	courseNumber=0;
	canchoose=0;
}

Student::Student(const Student&S)
{
	name=NULL;
	setName(S.name);
	birthDate=S.birthDate;
	count++;	
}

void Student::setName(char* n)
{	
	int length=0;
	if(n!=NULL)
	length=strlen(n);
	if(n==NULL)
	{
		cout<<"WrongName"<<endl;
		char change[20]="Lucy";
		name=new char[20];
		strcpy(name,change);
	}
	else if(length>20)
	{
		cout<<"TooLong"<<endl;
		char change[20]="Tom";
		name=new char[20];
		strcpy(name,change);
	}
	else
	{
		name=NULL;
		name=new char[20];
		strcpy(name,n);
	}
}

void Student::setBirthdate(int y,int m,int d)
{
	birthDate.setDate(y,m,d);
}

char* Student::getName()
{
	return name;
} 

int Student::getBirth_y()
{
	return birthDate.getYear();
}

int Student::getBirth_m()
{
	return birthDate.getMonth();
}

int Student::getBirth_d()
{
	return birthDate.getDay();
}

void Student::print()
{
	cout<<name<<": ";
	cout<<birthDate<<endl;
	//birthDate.print(); 
}

//ofstream outfile("student.txt",ios::out);

ostream &operator<<(ostream& output,const Student&S)
{
	output<<"姓名: "<<S.name<<"  出生日期: "<<S.birthDate<<" 选课信息如下\n";
	if(S.courseNumber==0)
	{
		output<<"No Course"<<endl;
	}
	else
	for(int i=0;i<S.courseNumber;i++)
	{
		output<<" 课程名: "<<S.courseList[i]->getName()<<" 学分: "<<S.courseList[i]->getCredit()<<" 成绩: "<<S.courseList[i]->getScore()<<endl;
	}
	
	return output;
}

void Student::file_in()
{
	ifstream infile("course.txt",ios::in);
	char course[30];
	int type;
	int credit;
	int i=0;
	string tt;
	while(infile>>type>>course>>credit)
	{
		canchoose++;
		Type[i]=type;
		//cout<<course<<endl;
		courses[i]=course;
		//cout<<courses[i]<<endl;
		Credit[i]=credit;
		//cout<<credit<<" "<<Credit[i]<<endl;
		//cout<<i+1<<". "<<"课程类型: "<<tt<<" 课程名: "<<course<<" 学分: "<<credit<<endl;
		i++;
	}
//	for(int p=0;p<canchoose;p++)
//	{
//		cout<<Credit[p]<<" "<<courses[p]<<" "<<Type[p]<<" "<<canchoose<<endl;
//	}
}

void Student::showmecourse()
{
	//cout<<canchoose<<endl;
	string tt;
	for(int p=0;p<canchoose;p++)
	{
		if(Type[p]==1)
		{
			tt="ObligatoryCourse";
		}
		else if(Type[p]==2)
		{
			tt="ElectiveCourse";
		}
		cout<<p+1<<". "<<"课程类型: "<<tt<<" 课程名: "<<courses[p]<<" 学分: "<<Credit[p]<<endl;
	}
}

void Student::filecourse(int& d,string& c,int& t,int l)
{
//	for(int p=0;p<canchoose;p++)
//	{
//		cout<<Credit[p]<<" "<<courses[p]<<" "<<Type[p]<<endl;
//	}
	l=l-1;
	if(l<0||l>canchoose)
	{
		cout<<"Wrong choose"<<endl;
	}
	else
	{
		d=Credit[l];
		c=courses[l];
		t=Type[l];
	}
	//cout<<l<<" "<<Credit[l]<<" "<<courses[l]<<" "<<Type[l]<<endl;
}

void Student::SsetScore(int cn,int c)
{
	int j=-1,j2=1;
	while(1)
	{
		try
		{
			if(cn==j||j2<0)
			{
				cin>>cn>>c;
				j2=1;
			}
			if(courseNumber==0)
			{
				cout<<"No Course"<<endl;
				break;
			}
			if(cn-1<0||cn-1>=courseNumber)
			{
				j=cn;
				throw MyException(Range_Error);
				cout<<"Wrong Choose"<<endl;
			}
			else if(c<0||c>100)
			{
				j2=-1;
				throw MyException(Score_Invalid);
			}
			else
			{
				courseList[cn-1]->setScore(c);	
				break;
			}
		
		}
		catch(MyException e)
		{
			cout<<e.what()<<endl;
			cout<<"Please choose class and set score again"<<endl;
		}
	}
	
}

bool Student::removeCourse(int i)
{
	int j=-1;
	while(1)
	{
		try
		{
			if(i==j)
			cin>>i;
			if(courseNumber==0)
			{
				cout<<"No Course"<<endl;
				break;
			}
			if(i-1>=courseNumber||i<=0)
			{
				j=i;
				throw MyException(Range_Error);
				cout<<"Wrong Choose"<<endl;
				return 0;
			}
			else
			{
				for(int j=i-1;j<courseNumber;j++)
				{
					courseList[j]=courseList[j+1];
				}
				courseNumber--;
				cout<<"Success"<<endl;
				return 1;
				break;
			}
		}
		catch(MyException e)
		{
			cout<<e.what()<<endl;
			cout<<"Please choose again"<<endl;
		}
	}
}

Student& Student::addCourse(Course *course)
{
	//cout<<courseNumber<<endl;
	if(course==NULL)
	{
		cout<<"Wrong Answer"<<endl;
	}
	else if(courseNumber>=MAX_SIZE)
	{
		cout<<"Full Courses"<<endl;
	}
	else
	{
		courseList[courseNumber]=course;
		courseNumber++;
		cout<<"Success"<<endl;
		return *this;
	}
}

void Student::printcourse()const
{
	if(courseNumber==0)
	{
		cout<<"No Course"<<endl;
	}
	else
	for(int i=0;i<courseNumber;i++)
	{
		cout<<" 课程名: "<<courseList[i]->getName()<<" 学分: "<<courseList[i]->getCredit()<<" 成绩: "<<courseList[i]->getScore()<<endl;
	}
}

float Student::caleCredit()
{
	float SumO=0,SumE=0,ans=0;//(必修课成绩*必修课学分/所选必修课总学分/选修课成绩/所选选修课总门数
	int OCsum=0,ECsum=0;//credit && number
	ElectiveCourse *EC=new ElectiveCourse("test",0,'A');
	ObligatoryCourse *OC=new ObligatoryCourse("test",0,0);
	for(int i=0;i<courseNumber;i++)
	{
		if(typeid(*courseList[i]).name()==typeid(*EC).name())
		{
			ECsum+=1;
		}
		else if(typeid(*courseList[i]).name()==typeid(*OC).name())
		{
			OCsum+=courseList[i]->getCredit();
		}
	}
	for(int i=0;i<courseNumber;i++)
	{
		if(typeid(*courseList[i]).name()==typeid(*EC).name())
		{
			SumE+=(courseList[i]->getScore()/ECsum);
		}
		else if(typeid(*courseList[i]).name()==typeid(*OC).name())
		{
			SumO+=(courseList[i]->getScore()*courseList[i]->getCredit()/OCsum);
		}
	}
	ans=0.6*SumO+0.4*SumE;
	cout<<ans<<endl;
	return ans;
	//cout<<typeid(*EC).name()<<endl;
	//cout<<typeid(*OC).name()<<endl;
}

void Student::file_print(const Student &S)
{
	
	ofstream outfile("student.txt",ios::out);
	if(!outfile)
	cout<<"File Wrong"<<endl;
	else
	{
		cout<<"Success"<<endl;
		outfile<<S<<endl;
		outfile.close();
	}
}

void Student::checkCScorse()
{
	if(courseNumber==0)
	{
		cout<<"No Course"<<endl;
	}
	for(int i=0;i<courseNumber;i++)
	{
		cout<<courseList[i]->getName()<<": "<<courseList[i]->getScore()<<endl;
	}
}

void Student::printnum()
{
	cout<<count<<endl;
}
//int test=10;
Student::~Student()
{
	//cout<<count<<endl;
	//count--;
	if(name!=NULL)
	delete []name;
	//cout<<test<<endl;
}
