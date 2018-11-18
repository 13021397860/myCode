#include "Console.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
using namespace std;
Console::Console()
{
	int yy,mm,dd;
	char nn[200];
	cout<<"PLZ input Stu's information\n";
	while(1)
	{
		yy=get_uint(); mm=get_uint(); dd=get_uint();
		b.setDate_Force(yy,mm,dd);
		try
		{
			MyException my;
			my.DateException(b);
			s.setBirthDate(b);
			break;
		}
		catch(Date d1)
		{
			cout<<"Illicit date input!\n";
		}
	}
	cin>>nn;
	s.setName(nn);
	cnum=0;
}

Console::~Console()
{
}

void Console::ops()
{
	while(1)
	{
		cout<<"1.Get/Set Stu's information\n2.Choose Classes\n3.Delete Classes\n4.Set Grade\n5.Exit\n";
		t=get_uint();
		if(t==1)
		{
			op1();
		}
		else if(t==2)
		{
			op2();
		}
		else if(t==3)
		{
			op3();
		}
		else if(t==4)
		{
			op4();
		}
		else if(t==5)
		{
			op5();
			break;
		}
		else
			printf("PLZ input again\n");
	}
}

void Console::op1()
{
	printf("PLZ input 1 for showing on UI, 2 for showing in the file\n");
	while(1)
	{
		t=get_uint();
		if(t==1) 
		{
			cout<<s<<endl;break;
		}
		else if(t==2)
		{
			ofstream fout("student.txt");
			fout<<s<<endl;break;
			fout.close();
		}
		else
			printf("PLZ input again\n");
	}
}

void Console::op2()
{
	t=-1;
	while(t!=1&&t!=2)
		printf("PLZ input 1 for inputting from UI, 2 for inputting from the file\n"),t=get_uint();
	if(t==1)
	{
		t=-1;
		while(t!=1&&t!=2)
			cout<<"1.Obligatory 2.Elective\n",t=get_uint();
		cout<<"Please Input CourseName&CreditHour\n";
		cin>>clist;
		cre=-1;
		while(cre<0)
			cre=get_udou();
		if(t==1)
		{
			if(cnum<1000)
			{
				p[cnum]=new ObligatoryCourse;
				p[cnum]->setCourse(clist,cre);
				s.addCourse(p[cnum]);
				++cnum;
			}
		}
		else
		{
			if(cnum<1000)
			{
				p[cnum]=new ElectiveCourse;
				p[cnum]->setCourse(clist,cre);
				s.addCourse(p[cnum]);
				++cnum;
			}
		}
		cout<<'\n';
	}
	else if(t==2)
	{
		ifstream fin("data.txt");
		while(fin>>t>>clist>>cre)
		{
			if(t==1)
			{
				if(cnum<1000)
				{
					p[cnum]=new ObligatoryCourse;
					p[cnum]->setCourse(clist,cre);
					s.addCourse(p[cnum]);
					++cnum;
				}
			}
			else
			{
				if(cnum<1000)
				{
					p[cnum]=new ElectiveCourse;
					p[cnum]->setCourse(clist,cre);
					s.addCourse(p[cnum]);
					++cnum;
				}
			}
			cout<<'\n';
		}
		fin.close();
	}
}

void Console::op3()
{
	int c1;
	t=-1;
	cout<<"Please input course number\n";
	while(1)
	{
		t=get_uint();
		try
		{
			MyException my;
			my.CourseException(t,cnum);
			break;
		}
		catch(int c1)
		{
			cout<<"Illicit Course Number Input!\n";
		}
	}
	if(s.removeCourse(t))
	{
		delete p[t-1];
		--cnum;
		--t;
		for(i=0;i<cnum;++i)
			if(i>=t)
				p[i]=p[i+1];
		cout<<"Delete Completed\n";
	}
	else
		cout<<"Failed\n";
}

void Console::op4()
{
	int c1,s1;
	cout<<"Please input classnumber and score\n";
	t=-1;
	while(1)
	{
		t=get_uint();
		try
		{
			MyException my;
			my.CourseException(t,cnum);
			break;
		}
		catch(int c1)
		{
			cout<<"Illicit Course Number Input!\n";
		}
	}
	score=-1;
	while(1)
	{
		score=get_uint();
		try
		{
			MyException my;
			my.GradeException(score);
			break;
		}
		catch(int s1)
		{
			cout<<"Illicit Grade Input!\n";
		}
	}
	if(s.setGrade(t,score))
		cout<<"Set Completed\n";
	else
		cout<<"Failed\n";
}

void Console::op5()
{
	while(cnum)
	{
		--cnum;
		delete p[cnum];
	}
	cout<<"Bye~\n";
}

int Console::get_uint()
{
    int num=-1;
    char ch=' ';
    cin>>num;
    if(cin.fail())
    {
    	cin.clear();
    	cin.ignore();
    }
    ch=getchar();
    while(ch!=-1&&ch!=' '&&ch!='\n'&&ch!='\r')
    {
		ch=getchar();num=-1;
	}
    return num;
}

double Console::get_udou()
{
    double num=-1;
    char ch=' ';
    cin>>num;
    if(cin.fail())
    {
    	cin.clear();
    	cin.ignore();
    }
    ch=getchar();
    while(ch!=-1&&ch!=' '&&ch!='\n'&&ch!='\r')
    {
		ch=getchar();num=-1;
	}
    return num;
}

