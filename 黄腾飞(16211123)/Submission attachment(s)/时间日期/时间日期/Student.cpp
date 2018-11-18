#include "Student.h"
#include"Date.h"
#include"Course.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<typeinfo>
#include"ElectiveCourse.h"
#include"OblilgatoryCourse.h"
#include"MyException.h"
using namespace std;
//Course *courseList[max_size]={0};
int Student::count=0;
int Student::courseNumber=0;
Student::Student(){};
char* Student::getName()const
{
	return name;
}
Date Student::getDate()const
{
	return birthDate;
}
int Student::getCount()
{
    return count;
} 
Student::~Student()
{
	delete[]  name;
	/*for(int i=1;i<=courseNumber;i++)
	  free(courseList[i]);*/
}
void   Student::print()const
{ 
	  cout<<*this;
}
Student::Student( const char *s,const Date &a ):birthDate(a)
{
	  setName(s);
	  strcpy(name,s);
	  count++;
}
  void Student::setName(const char *s )
{
	int l = strlen(s);
    name=(char*)malloc(l+1);
}
Student::Student(const Student &a ):birthDate(a.birthDate)
{
	setName(name);
	strcpy(name,a.name);
	  count++;
}
Student& Student::addCourse(Course *course)
{
     if(courseNumber>10)
     	cout<<"Course Full!"<<endl; 
     else 
        courseList[++courseNumber]=course;
}
/*Student& Student::addCourse(const string &courseName, int creditHour) 
{
	    if(courseNumber>10)
     	cout<<"课程已满"<<endl;
		 else 
		 {
	    
		 Course *course=new Course(courseName,creditHour);
	     courseList[++courseNumber]=course; 
		  } 
	    
}*/
ostream &operator <<( ostream & out,const Student & a)
{
	out<<"Name："<<a.getName()<<" Birthdate："<<a.getDate()<<"calcCredit： "<<a.calcCredit()<<endl<<" Elective information is as follows："<<endl; 
	for(int i=1;i<=Student::courseNumber;i++)
	{
		out<<"Number："<<i<<"  "<<*(a.courseList[i])<<endl;
	}
}
bool Student::removeCourse(int i)
{ 
     if(i<=0||i>courseNumber)
     throw  MyException(Number_wrong);
     else 
	 {
	cout<<"Success!"<<endl; 
     free(courseList[i]);
    for(int a=i;a<courseNumber;a++)
      courseList[a]=courseList[a+1];
      courseNumber--;
	 }
}
int Student::dafen(int i)//打分 非法 
{ 
      if(i<=0||i>courseNumber)
      throw  MyException(Number_wrong);
     else
	  {
	  	if (typeid(*courseList[i])==typeid(ElectiveCourse))
	    {
	    	cout<<"Course:"<<courseList[i]->getName()<<endl;
	    	
           while(1)
           { 
	           	try 
	           	{
				   cout<<"Please input score（A，B,C,D,E）   "; 
			    	char grade;
		            cin>>grade;
	           		((ElectiveCourse*)courseList[i])->setGrade(grade);
	     	  	    cout<<"Success！"<<endl;
	     	  	    break;
				}
				catch(MyException ex)
				{
					cout<<ex.what()<<endl;
				}
		   }
		}
		else  if(typeid(*courseList[i])==typeid(OblilgatoryCourse))
		{
			cout<<"Course:"<<courseList[i]->getName()<<endl;
	        while(1)
	        {
	        	try
	        	{
				    cout<<"Please input score（0-100）     "; 
					int mark;
			        cin>>mark;
	        		((OblilgatoryCourse*)courseList[i])->setMark(mark);
	        	     cout<<"Success！"<<endl;
	        	     break;
				}
				catch(MyException ex)
				{
					cout<<ex.what()<<endl;
				}
			}
		}
		else  return false;
		 
	  } 
	
}
double Student::calcCredit()const
{
	int sum1=0,sum2=0,num=0,hour=0;
	double credit=0; 
	for(int i=1;i<=courseNumber;i++)
	{
		if (typeid(*courseList[i])==typeid(ElectiveCourse))//选修
		{
			sum2+=(*courseList[i]).getScore();
			num++;
		} 
		else 
		{
			sum1+=((*courseList[i]).getScore())*((*courseList[i]).getCreditHour());
			 hour+=(*courseList[i]).getCreditHour();
		}
	}
	if(num!=0&&hour!=0)
	{
		credit=0.6*(sum1/hour)+0.4*(sum2/num);
	    return credit;
	}
	else if(courseNumber==0)
	       cout<<"Fail";
	else if(num==0&&hour!=0)
	     {
	     	credit=0.6*(sum1/hour);
	        return credit;
		 }
	else 
	    {
	    	credit=0.4*(sum2/num);
	        return credit;
		}
		 
	
}
int  Student::getfen(int a)
{
	return  (*courseList[a]).getScore();
} 
string Student::getname(int a)const
{
	return (*courseList[a]).getName();
}
