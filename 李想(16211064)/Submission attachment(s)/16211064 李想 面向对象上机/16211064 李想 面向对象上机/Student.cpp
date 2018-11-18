#include "Student.h"
#include<bits/stdc++.h>
using namespace std;

int Student::sum=0;

void Student::printnum()
{
	cout<<sum<<endl;
}

Student::Student()
{
	name=NULL;
	for (int i=0;i<MAX_SIZE;i++)
	{
		courseList[i]=NULL;
		courseType[i]=new bool;
	}
	courseNumber=0;
	sum++;
}

Student::Student(char* nm, int y, int m, int d)
{
	name=new char[strlen(nm)+1];
	strcpy(name,nm);
	for (int i=0;i<MAX_SIZE;i++)
	{
		courseList[i]=NULL;
		courseType[i]=new bool;
	}
	courseNumber=0;
	sum++;
	setDate(y, m, d);
}

Student::Student(Student&s)
{
	strcpy(name,s.name);
	for (int i=0;i<MAX_SIZE;i++)
	{
		courseList[i]=NULL;
		courseType[i]=new bool;
	}
	courseNumber=0;
	sum++;
}

void Student::print()
{
	if(name==NULL) printf("0\n");
	else cout<<name<<endl;
}

int Student::getName()
{
	if(name==NULL) return 0;
	else return *name;
}

int Student::setName(char*nm)
{
	if(name==NULL) name=new char[strlen(nm)+1];
	strcpy(name,nm);
	return 0;
}

Student::~Student()
{
	if(name!=NULL)
	{
		delete[] name;
		for (int i=0;i<courseNumber;i++)
		{
			delete courseList[i];
			delete courseType[i];
		}
	}
	sum--;
}

int Student::setDate(int yr, int mon, int dy)
{
	birthDate.setDate(yr, mon, dy);
	return 0;
}

Student& Student::addCourse(Course *course)
{
	courseList[courseNumber++]=course;
	return *this;
}

Student& Student::addCourse(const string &courseName,int creditHour)
{
	courseList[courseNumber]->name=courseName;
	courseList[courseNumber]->creditHour=creditHour;
	courseNumber++;
	return *this;
}

ostream& operator<<(ostream& output,const Student& a)
{
	output<<"学生姓名:"<<a.name<<"\t"<<"出生日期:"<<a.birthDate<<"，选课信息如下："<<endl;
	for(int i=0;i<a.courseNumber;i++)
	{
		output<<*a.courseList[i]<<'\t';
		if(a.courseList[i]!=0) output <<"考试成绩："<< (*a.courseList[i]).getScore() << endl;
		else output << endl;
	}
	return output;
}

float Student::calcCredit()
{
	bool _ObligatoryCourse=false,_ElectiveCourse=false;
	float GPA=0;
	float O_credit=0,E_credit=0;
	for (int i=0;i<courseNumber;i++)
	{
		if(*courseType[i]==1)
		{
			O_credit+=(*courseList[i]).creditHour;
			_ObligatoryCourse=true;
		}
		else
		{
			E_credit++;
			_ElectiveCourse=true;
		}
	}
	for (int i=0;i<courseNumber;i++)
	{
		if(*courseType[i]==1)
		{
			if(_ElectiveCourse==1)
				GPA+=(0.6*static_cast<float>(((*courseList[i]).getScore())*((*courseList[i]).creditHour))/O_credit);
			else
				GPA+=(1*static_cast<float>(((*courseList[i]).getScore())*((*courseList[i]).creditHour))/O_credit);
		}
		else
		{
			if (_ObligatoryCourse==1)
				GPA+=(0.4*static_cast<float>((*courseList[i]).getScore())/E_credit);
			else
				GPA+=(1*static_cast<float>((*courseList[i]).getScore())/E_credit);
		}
	}
	return GPA;
}

int Student::getscore(string subject)
{
	int score=0;
	bool exist=0;
	for (int i=0;i<courseNumber;i++)
	{
		if(subject==courseList[i]->name)
		{
			exist=1;
			score=courseList[i]->getScore();
		}
	}
	if (exist==0)
	{
		printf("该科目不存在！\n");
		return 0;
	}
	cout<<subject<<"的成绩是：";
	cout<<score<<endl;
	return score;
}
void Student::removeCourse(int i)
{
    if(i>courseNumber)
    {
        cout<<"输入错误"<<endl;
    }
    else
    {
        for(int j=i-1; j<courseNumber-1; j++)
        {
            courseList[j]=courseList[j+1];
        }
        courseNumber--;
    }
}

int Student::GetCourseNumber()
{
    return courseNumber;
}

Course& Student::operator[](int i)
{
    if(i<=courseNumber)
    {
        return *courseList[i];
    }
    else
    {
        cout<<"下标越界"<<endl;
    }
}
