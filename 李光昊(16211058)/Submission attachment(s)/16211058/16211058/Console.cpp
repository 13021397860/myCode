#include "Console.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <typeinfo>
#include <cstdio>
#include <cstring>
#include "Student.h"
#include "Date.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
using namespace std;
#define ecMax 10
#define ocMax 10

Console::Console()
{
	cout<<"***************************** 欢迎使用学生选课系统 *****************************\n";
	initConsole();
	/*
	string ecn[ecMax]={"ec1","ec2","ec3","ec4","ec5","ec6","ec7","ec8","ec9","ec10"};
	string ocn[ocMax]={"oc1","oc2","oc3","oc4","oc5","oc6","oc7","oc8","oc9","oc10"};
	int ecc[ecMax]={1,2,3,4,5,6,7,8,9,10};
	int occ[ocMax]={1,2,3,4,5,6,7,8,9,10};

	for(int i=0;i<ocMax;i++)
	{
		oc[i].setName(ocn[i]);
		oc[i].setCreditHour(occ[i]);
	}
	for(int i=0;i<ecMax;i++)
	{
		ec[i].setName(ecn[i]);
		ec[i].setCreditHour(ecc[i]);
	}
	*/
}



int Console::initConsole()//需要txt文件中的课程顺序及数目不大于宏定义的数
{
	ocn=0;ecn=0;
	string s;int c;

	ifstream in("InitObligatoryCourse.txt");
	if(!in.is_open())
	{
		cerr<<"预置课程文件打开失败！程序结束！\n";//************throw**************
		//exit(0);
	}
	while(in>>s>>c)
	{
		//cout<<1<<endl;
		if(ocn==ocMax)
		{
			cerr<<"必修课程数量过多！\n";
			break;
		}
		oc[ocn].setName(s);
		oc[ocn++].setCreditHour(c);
	}
	in.close();

	in.open("InitElectiveCourse.txt");
    while(in>>s>>c)
	{
		if(ecn==ecMax)
		{
			cerr<<"选修课程数量过多！\n";
			break;
		}
		ec[ecn].setName(s);
		ec[ecn++].setCreditHour(c);
	}
	in.close();
}

int Console::ObligatoryCourseElect(Student &a)
{
	int n;
	cout<<"\n必修选课中...\n";
	cout<<"请从以下课程里选择：\n";

	int ch[ocn];
	for(int i=0;i<ocn;i++)
	{
		if(a.checkCourse(oc[i].getName()))ch[i]=1;
		else ch[i]=0;
	}

	for(int i=0;i<ocn;i++)
	{
		if(ch[i]==0)cout<<setw(3)<<left<<i+1<<" 课程名称："<<setw(10)<<left<<oc[i].getName()<<"学分："<<oc[i].getCreditHour()<<"\n";
	}
	cout<<"请输入序号（警告：输入非数字会导致严重错误！）：";
	cin>>n;
	while(cin.fail()||n<1||n>ocn||ch[n-1]==1)
	{
		cin.clear();
		cin.ignore();
		cout<<"请正确输入：";
		cin>>n;
	}
	--n;

	ObligatoryCourse *acourse=new ObligatoryCourse(oc[n]);
	a.addCourse(acourse);
	cout<<"已添加课程<"<<oc[n].getName()<<">到"<<a.getName()<<"的课程列表。\n";
}

int Console::ElectiveCourseElect(Student &a)
{
	int n;
	cout<<"\n选修选课中...\n";
	cout<<"请从以下课程里选择：\n";

	int ch[ecn];
	for(int i=0;i<ecn;i++)
	{
		if(a.checkCourse(ec[i].getName()))ch[i]=1;
		else ch[i]=0;
	}

	for(int i=0;i<ecn;i++)
	{
		if(ch[i]==0)cout<<setw(3)<<left<<i+1<<" 课程名称："<<setw(10)<<left<<ec[i].getName()<<"  学分："<<ec[i].getCreditHour()<<"\n";
	}
	cout<<"请输入序号（警告：输入非数字会导致严重错误！）：";
	cin>>n;
	while(cin.fail()||n<1||n>ecn||ch[n-1]==1)
	{
		cin.clear();
		cin.ignore();
		cout<<"请正确输入：";
		cin>>n;
	}
	--n;

	ElectiveCourse *acourse=new ElectiveCourse(ec[n]);
	a.addCourse(acourse);
	cout<<"已添加课程<"<<ec[n].getName()<<">到"<<a.getName()<<"的课程列表。\n";
}

int Console::CourseRemove(Student &a)
{
	int n;
	cout<<"\n退课中...\n";
	cout<<"您的已选课程如下：\n\n";
	a.printCourse();
	cout<<"\n请输入退选课程的序号（警告：输入非数字会导致严重错误！）：";
	cin>>n;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"请输入数字：";
		cin>>n;
	}
	if(a.removeCourse(n))
	{
		cout<<"退选成功！\n";
	}
	else
	{
		cout<<"该序号对应课程不存在！\n";
	}
}

int Console::setCourseMark(Student &a)
{
	int n;
	cout<<"\n成绩录入中...\n";
	cout<<"您的已选课程如下：\n\n";
	a.printCourse();
	cout<<"\n请输入录入课程的序号（警告：输入非数字会导致严重错误！）：";
	cin>>n;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"请输入数字：";
		cin>>n;
	}
	/*
	if(n<1||n>a.getCourseNumber()+1)
	{
		cout<<"该序号对应课程不存在！\n";
	}
	else*/
	{
		Course *ptrc=a.getCourse(n);//************
		if(typeid(*ptrc)==typeid(ObligatoryCourse))
		{
			cout<<"请输入<"<<ptrc->getName()<<">的成绩（百分制）：";
			int ti;
			while(1)
			{
				try
				{
					cin>>ti;
					if(cin.fail())
					{
						cin.clear();
						cin.ignore();
						throw MyException("成绩非法！");
					}
					if(ti<0||ti>100)throw MyException("成绩非法！");
					break;
				}
				catch(MyException &me)
				{
					me.printerror();
				}
			}
			/*
			cin>>ti;
			while(cin.fail()||ti<0||ti>100)
			{
				cin.clear();
				cin.ignore();
				cout<<"请正确输入：";
				cin>>ti;
			}
			*/
			ObligatoryCourse *ptro=dynamic_cast<ObligatoryCourse*>(ptrc);
			if(ptro)
			{
				ptro->setMark(ti);
				cout<<"录入成功！<"<<ptrc->getName()<<">的成绩已设置为"<<ptro->getScore()<<".\n";
			}
			else
			{
				cout<<"录入失败！\n";
			}
		}
		else
		{
			cout<<"请输入<"<<ptrc->getName()<<">的成绩（ABCDE）：";
			char tc;

			while(1)
			{
				try
				{
					cin>>tc;
					if(tc<'A'||tc>'E')throw MyException("成绩非法！");
					break;
				}
				catch(MyException &me)
				{
					me.printerror();
				}
			}

			/*
			cin>>tc;
			while(tc<'A'||tc>'E')
			{
				//**********
					throw MyException("成绩非法！");
				//**********
				cout<<"请正确输入：";
				cin>>tc;
			}
			*/
			ElectiveCourse *ptre=dynamic_cast<ElectiveCourse*>(ptrc);
			if(ptre)
			{
				ptre->setGrade(tc);
				cout<<"录入成功！<"<<ptrc->getName()<<">的成绩已设置为"<<ptre->getGrade()<<".\n";
			}
			else
			{
				cout<<"录入失败！\n";
			}
		}
	}
}

int ten(int i)
{
	int sum=1;
	for(int j=0;j<i;j++)
	{
		sum*=10;
	}
	return sum;
}

int Console::run()
{
	int n;

	cout<<"请选择您的操作：\n";
	cout<<"1：新建学生（注意：已保存的学生会被覆盖！）\n";
	cout<<"2：读取学生\n";
	cout<<"-1: 退出程序\n";
	cout<<"请输入序号（警告：输入非数字会导致严重错误！）：";
	cin>>n;
	while(cin.fail()||n!=1&&n!=2&&n!=-1)
	{
		cin.clear();
		cin.ignore();
		cout<<"请正确输入：";
		cin>>n;
	}
	char *x=new char;
	int y,m,d;
	Date adate;
	Course *acourselist[Maxsize];
	int acoursenum=-1;

	if(n==1)
	{
		cout<<"请输入您的姓名、出生日期（格式为：<姓名> <年> <月> <日>）\n";
		cin>>x>>y>>m>>d;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout<<"请正确输入：\n";
			cin>>x>>y>>m>>d;
		}

		while(1)
		{
			try
			{
				adate.set(y,m,d);
				break;
			}
			catch(MyException &me)
			{
				me.printerror();
			}
			//cout<<"请输入合法日期（格式为：<年> <月> <日>）\n";
			cin>>y>>m>>d;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout<<"请正确输入：\n";
				cin>>y>>m>>d;
			}
		}
		//Student a(x,adate);
		//
	}
	else if(n==2)
	{
		ifstream in("Student.txt");
	    if(in.is_open())
	    {
			//char *aname;
	    	char f;
	    	int fl;
	    	//int y,m,d;
	    	in>>x;
	    	in>>y>>f>>m>>f>>d;
	    	adate.set(y,m,d);
	    	//Student b(aname,y,m,d);
	    	int sum,num;
	    	string cna,fstr,agrade;
	    	in>>sum;
	    	if(sum>0)
	    	{
	    		for(int i=0;i<sum;i++)
	    		{

	    			in>>fstr;
	    			//cout<<fstr<<endl;//
					in>>cna>>fstr;
					//cout<<fstr<<endl;//
					in>>fstr;
					//cout<<fstr<<endl;//
					in>>fstr>>agrade;
	    			fl=-1;
	    			for(int j=0;j<ocn;j++)
	    			{
	    				if(oc[j].getName()==cna)
	    				{
	    					fl=j;
	    					ObligatoryCourse *acourse=new ObligatoryCourse(oc[j]);
	    					if(agrade!="none")
	    					{
	    						int agr=0;
	    						for(int k=0;k<agrade.size();k++)
	    						{
	    							agr+=(agrade[k]-'0')*ten(agrade.size()-k-1);
								}

								acourse->setMark(agr);
							}
							acourselist[++acoursenum]=acourse;
	    					break;
						}
					}

					if(fl==-1)
					{
						for(int j=0;j<ecn;j++)
		    			{

							if(ec[j].getName()==cna)
		    				{
		    					fl=j;
		    					ElectiveCourse *acourse=new ElectiveCourse(ec[j]);
		    					if(agrade!="none")
		    					{
		    						char agr;
		    						if(agrade=="95")agr='A';
		    						else if(agrade=="85")agr='B';
		    						else if(agrade=="75")agr='C';
		    						else if(agrade=="65")agr='D';
		    						else if(agrade=="55")agr='E';
									acourse->setGrade(agr);
								}

								acourselist[++acoursenum]=acourse;
		    					break;
							}
						}
					}
				}
			}
			cout<<"学生信息读取完成。\n";
			in.close();
		}
		else
		{
			cerr<<"学生信息读取失败！\n";//************throw**************
			//exit(0);
		}
	}
	else
	{
		return 0;
	}

	Student a(x,adate);
	if(n==2)
	{
		a.initCourse(acourselist,acoursenum);
		//cout<<acoursenum<<endl;
	}

	cout<<a.getName()<<"已添加至学生列表。\n\n";

	while(1)
	{
		cout<<"--------------------------------------------------------------------------------\n";
		cout<<a.getName()<<"同学，请选择操作：\n";
		cout<<"1: 必修选课\n";
		cout<<"2: 选修选课\n";
		cout<<"3: 已选课程\n";
		cout<<"4：退选课程\n";
		cout<<"5：成绩录入\n";
		cout<<"6：成绩查询\n";
		cout<<"7：绩点查询\n";
		cout<<"-1: 退出程序\n";
		cout<<"请输入序号（警告：输入非数字会导致严重错误！）：";
		cin>>n;
		while(cin.fail()||n!=1&&n!=2&&n!=3&&n!=4&&n!=5&&n!=6&&n!=7&&n!=-1)
		{
			cin.clear();
			cin.ignore();
			cout<<"请正确输入：";
			cin>>n;
		}

		if(n==1)
		{
			do
			{
				if(a.courseFull())
				{
					cout<<"课程已满，请选择其他操作\n";
					break;
				}
				ObligatoryCourseElect(a);
				cout<<"\n您是否需要继续选课？(1/其他数)（警告：输入非数字会导致严重错误！）\n";
				cin>>n;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout<<"请正确输入：\n";
					cin>>n;
				}
			}
			while(n==1);
		}
		else if(n==2)
		{
			do
			{
				if(a.courseFull())
				{
					cout<<"课程已满，请选择其他操作\n";
					break;
				}
				ElectiveCourseElect(a);
				cout<<"\n您是否需要继续选课？(1/其他数)（警告：输入非数字会导致严重错误！）\n";
				cin>>n;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout<<"请正确输入：\n";
					cin>>n;
				}
			}
			while(n==1);
		}
		else if(n==3)
		{
			cout<<"\n";
			a.printCourse();
		}
		else if(n==4)
		{
			do
			{
				if(a.getCourseNumber()==-1)
				{
					cout<<"您的课程列表为空！\n";
					break;
				}
				try
				{
					CourseRemove(a);
				}
				catch(MyException &me)
				{
					me.printerror();
				}

				cout<<"\n您是否需要继续退课？(1/其他数)\n";
				cin>>n;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout<<"请正确输入：\n";
					cin>>n;
				}
			}
			while(n==1);
		}
		else if(n==5)
		{
			do
			{
				if(a.getCourseNumber()==-1)
				{
					cout<<"您的课程列表为空！\n";
					break;
				}
				try
				{
					setCourseMark(a);
				}
				catch(MyException &me)
				{
					me.printerror();
				}

				cout<<"\n您是否需要继续录入？(1/其他数)\n";
				cin>>n;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout<<"请正确输入：\n";
					cin>>n;
				}
			}
			while(n==1);
		}
		else if(n==6)
		{
			cout<<"\n";
			a.printCourse();
		}
		else if(n==7)
		{
			cout<<"\n";
			cout<<"您的GPA为："<<a.calcCredit()<<"\n";
		}
		else if(n==-1)
		{
			break;
		}
		cout<<"\n";
		//system("pause");
	}
	if(saveStudent(a))
	{
		cout<<"学生信息存储成功！\n";
	}
	delete []x;
	return 0;
}

int Console::saveStudent(Student &a)
{
	ofstream out("Student.txt");
    if(out.is_open())
    {
    	out<<a.getName()<<"\n"<<a.getDate2()<<"\n";
    	out<<a.getCourseNumber()+1<<"\n";
    	Course *p;
    	for(int i=0;i<=a.getCourseNumber();i++)
    	{
    		p=a.getCourse(i+1);
    		out<<*p<<"\n";
		}
		out<<a.calcCredit()<<"\n";
		out.close();
	}
	else
	{
		cerr<<"学生信息存储失败！\n";//************throw**************
		return 0;//exit(0);
	}

	return 1;
}

Console::~Console()
{
	cout<<"\n***************************** 感谢使用学生选课系统 *****************************\n";
}
