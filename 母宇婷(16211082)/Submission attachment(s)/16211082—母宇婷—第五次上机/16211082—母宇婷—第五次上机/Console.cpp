#include "Console.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include "MyExpection.h"
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;

int Console::num=0;

	
Console::Console()
{
}

int Console::run()
{
	char a;
	char* b;
	int occ=0;
	int ecc=0;
	cout<<"可选必修课程："<<endl;
	string name;
	int mark;
	char grade;
	int credit;
	ifstream infile("Course.txt",ios::in);
	if(!infile)
	{
		cout<<"error"<<endl;
	}
	for(int i=0;i<6;i++)
	{
		if(i<=2)
		{
			infile>>name>>credit>>mark;
			cout<<"课程："<<name<<" 学分:"<<credit<<endl;
		}
		else
		{
			infile>>name>>credit>>grade;
			cout<<"课程："<<name<<" 学分:"<<credit<<endl;
		}
	}
	infile.close();
	char f[100];
	char *h=f;
	int i,j,k; 
	cout<<"输入名字："; 
	cin>>h;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"输入错误请重新输入"<<endl;
		cin>>h;
	}
	cout<<endl;
	cout<<"输入生日：";
	cin>>i>>j>>k;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"输入错误请重新输入"<<endl;
		cin>>i>>j>>k;
	}
	int huhu=0;
	MyExpection ex("时间");
	try
	{
		cout<<"生日是"<<ex.time(i,j,k)<<endl; 
	}
	catch(MyExpection ex)
	{
		cout<<ex.what()<<"异常"<<endl;
		huhu=1;
	}
	if(huhu==1)
	{
		cout<<"重新输入"<<endl;
		cin>>i>>j>>k;
	}
	Student t1(h,Date(i,j,k));
	cout<<"请选择课程：(选完请按#,删除请按7,必修课成绩输入0~100，选修课为A-E)"<<endl;
	int n;
	int m;
	ObligatoryCourse *oc[3];
	ElectiveCourse *ec[3];
	cin>>a;
	char c;
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
			if(a=='1')
			{
				oc[occ]=(new ObligatoryCourse("数据结构",2,98));
				occ++;
				cout<<"已选"<<endl;
			}
			else if(a=='2')
			{
				oc[occ]=(new ObligatoryCourse("程序设计",2,98));
				occ++;
				cout<<"已选"<<endl;
			}
			else if(a=='3')
			{
				oc[occ]=(new ObligatoryCourse("离散数学",2,98));
				occ++;
				cout<<"已选"<<endl;
			}
			else if(a=='4')
			{
				c='A';
				ec[ecc]=(new ElectiveCourse("语文",1,c));
				ecc++;
				cout<<"已选"<<endl;
			}
			else if(a=='5')
			{
				c='A';
				ec[ecc]=(new ElectiveCourse("英语",1,c));
				ecc++;
				cout<<"已选"<<endl;
			} 
			else if(a=='6')
			{
				c='A';
				t1.addElectiveCourse(new ElectiveCourse("心理",1,c));
				ec[ecc]=(new ElectiveCourse("心理",1,c));
				ecc++;
				cout<<"已选"<<endl;
			}
			else if(a=='7')
			{
				cin>>n;
				if(n>=1&&n<=3)
				{
					if(n>occ)
					{
						cout<<"此操作错误"<<endl;
					}
					else
					{
						cout<<1<<endl;
						for(int i=n-1;i<occ-1;i++)
						{
							oc[i]=oc[i+1];
						}
						delete oc[occ-1];
						occ--;
						cout<<"此课程已退选"<<endl; 
					}
				}
				else
				{
					if(n>ecc)
					{
						cout<<"此操作错误"<<endl;
					}
					else
					{
						for(int i=n-1;i<ecc;i++)
						{
						ec[i]=ec[i+1];
						}
						delete ec[ecc-1];
						ecc--;
						cout<<"此课程已退选"<<endl;
					}
				}
			}
			else
			{
				cin.clear();
				cin.ignore();
				cout<<"输入错误请重新输入"<<endl;
			}
		}
		cin>>a;

}	
	int p;
	char q;
	string t;
	int d;
	for(int i=0;i<=2;i++)
	{
		cout<<"输入必修课"<<oc[i]->getCoursename()<<"的成绩："; 
		cin>>p;
		int u=0;
		MyExpection ex("成绩输入");
		try
		{
			cout<<ex.ograde(p)<<endl;;
		}
		catch(MyExpection ex)
		{
			u=1;
			cout<<ex.what()<<"异常"<<endl;
		}
		if(u==1)
		{
			i--;
		}
		else
		{
			t=oc[i]->getCoursename();
		d=oc[i]->getCoursecreditHour();
		oc[i]=new ObligatoryCourse(t,d,p);
		t1.addObligatoryCourse(oc[i]);
		}
	}
	for(int i=0;i<=2;i++)
	{
		int u=0;
		cout<<"输入选修课"<<ec[i]->getCoursename()<<"的等级："; 
		cin>>q;
		try
		{
			cout<<ex.egrade(q)<<endl;;
		}
		catch(MyExpection ex)
		{
			u=1;
			cout<<ex.what()<<"异常"<<endl;
		}
		if(u==1)
		{
			i--;
		}
		else
		{
			t=ec[i]->getCoursename();
		d=ec[i]->getCoursecreditHour();
		ec[i]=new ElectiveCourse(t,d,q);
		t1.addElectiveCourse(ec[i]);
		}
	}
	cout<<t1; 
	int g;
	cout<<"输入你所要查询的科目编号：（退出查询请输入#）"<<endl;
	t1.search();
	cout<<"需要查询积点请输入YES，否则随意输入"<<endl;
	char *chi;
	char chi1[100];
	chi=chi1;
	cin>>chi;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"输入错误请重新输入"<<endl;
		cin>>chi;
	}
	if(strcmp(chi,"YES")==0)
	{
		t1.calcCredit();
	}
	ofstream outfile("Student.txt",ios::out);
	if(!outfile)
	{
		cout<<"error"<<endl;
	}
	outfile<<t1;     
	outfile.close();
}
Console::~Console()
{

}
