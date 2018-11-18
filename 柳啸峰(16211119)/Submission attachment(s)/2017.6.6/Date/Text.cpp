#include "Text.h"
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Students.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h" 
#include <cstdio>
#include <cstring>
#include <typeinfo>
#include <fstream> 
#include "MyException.h"
Text::Text(){
}
void Text::run()
{
	cout<<"请输入学生姓名：";
	char p[10]; 
	cin>>p;
	MyException MyEx;
	cout<<"请输入学生生日：";
	int a, b, c;
	Date t1;
	while(cin>>a>>b>>c)
	{	
		Date t2(a, b, c);
		try
		{
			if(t2.getMonth()==0||t2.getDay()==0)
				throw t2;
		 }catch(Date t2)
		 {
		 	cout<<"您所输入的生日不合法！请重新输入！"<<endl; 
		 	MyEx.MyExceptionOfDate(a ,b, c, "您所输入的生日不合法");
			continue; 
		  }
		t1=t2;
		break; 		
	}
	/*try
        {
            if(num>2||num<0)
            {
                throw MyException("The array bounds");//类型名（参数）：直接含参构造 
            }
            else
                cout<<a.getCourse(num)->getScore()<<"分"<<endl;
        }
        catch (MyException &e)//catch到MyException类型的，直接赋给e（&引用的意义） 
        {
            e.what();
        }*/ 
	cout<<"该学生出生于："; 
	cout<<t1<<endl;
	cout<<(t1++)<<endl;//a++重载函数需要引用传递&，否则报错：[Error]no match for 'operator<<' (operand types are 'std::ostream {aka std::basic_ostream<char>}' and 'Date')
	cout<<t1<<endl;
	cout<<++t1<<endl;
	cout<<t1<<endl;
    Students s1(p,t1);
    cout<<"这是第"<<s1.getCounter()<<"个学生"<<endl;
	//s1.print();
	ifstream infileo("必修课.txt",ios::in);
	string x;
	int t;
	ObligatoryCourse *o[10];
	int ii=1;
	while(infileo>>x>>t)
	{
		if(x!="0")
		{
			o[ii++]=new  ObligatoryCourse(0 ,x ,t );
		}
		else
			break;
	} 
	infileo.close();
	ifstream infilee("选修课.txt",ios::in);
	ElectiveCourse *e[10];
	string xx;
	int tt;
	int jj=1;
	while(infilee>>xx>>tt)
	{
		if(xx!="0")
		{
			e[jj++]=new  ElectiveCourse('A' ,xx ,tt );
		}
		else
			break;
	 } 
	 infilee.close();
	/*ObligatoryCourse *o1=new  ObligatoryCourse(0 ,"Chinese" ,4 );
    ObligatoryCourse *o2=new  ObligatoryCourse(0 ,"maths" ,5 );
    ObligatoryCourse *o3=new  ObligatoryCourse(0 ,"English" ,3 );
    ElectiveCourse *e1=new ElectiveCourse('A' ,"PE" ,2 );
    ElectiveCourse *e2=new ElectiveCourse('B' ,"music" ,2 );*/
    /*ObligatoryCourse o1(90 ,"Chinese" ,32 );这种创建对象，在main程序结尾系统会默认的free掉这些对象 
    ObligatoryCourse o2(90 ,"maths" ,32 );所以如果再在析构函数中delete一边的话就会崩 
    ObligatoryCourse o3(90 ,"English" ,32 );
    ElectiveCourse e1('A' ,"PE" ,16 );
    ElectiveCourse e2('D' ,"music" ,16 );*/
    cout<<"必修课有："<<endl; 
    cout<<"编号：o1 "<<"课程名："<<o[1]->getName()<<" 学分："<<o[1]->getCreditHour()<<endl;//o1是指针 
    cout<<"编号：o2 "<<"课程名："<<o[2]->getName()<<" 学分："<<o[2]->getCreditHour()<<endl;
    cout<<"编号：o3 "<<"课程名："<<o[3]->getName()<<" 学分："<<o[3]->getCreditHour()<<endl;
	cout<<"选修课有："<<endl; 
	cout<<"编号：e1 "<<"课程名："<<e[1]->getName()<<" 学分："<<e[1]->getCreditHour()<<endl;
	cout<<"编号：e2 "<<"课程名："<<e[2]->getName()<<" 学分："<<e[2]->getCreditHour()<<endl;
	cout<<"请问您想选的必修课程编号是(输入0停止)：\n";
	string oo;
	while(cin>>oo)
	{
		if(oo=="0")
			break;
		else if(oo=="o1")
			s1.addCourse(o[1]);
		else if(oo=="o2")
			s1.addCourse(o[2]); 
		else if(oo=="o3")
			s1.addCourse(o[3]);
		else 
			cout<<"该课程不存在\n"; 
	 } 
	cout<<"请问你想选的选修课程编号为（输入0停止）：\n";
	string ee;
	while(cin>>ee)
	{
		if(ee=="0")
			break;
		else if(ee=="e1")
			s1.addCourse(e[1]);
		else if(ee=="e2")
			s1.addCourse(e[2]);
		else
			cout<<"该课程不存在\n";
	}	
	/*for(int i=0;i<s1.getCourseNumber();i++)
	{
		s1.getCourseList(i)->printCourse();//虚函数的使用 
	}*/
	if(s1.getCourseNumber()==0)
		cout<<"该学生并没有选课！请退学！"<<endl;
	else
	{
		cout<<"请按照您的选课顺序为相应课程设定目标成绩:\n";
		s1.SetCourseGrade(MyEx);
		ofstream *outClientFile;
		outClientFile=new ofstream("stud.txt");
		if(!outClientFile) cout<<"filed"<<endl;
		(*outClientFile)<<s1;//输出学生选课情况
		outClientFile->close(); 
		cout<<s1;
		cout<<"请问你想退选第几门课？"<<endl;
		int i;
		while(cin>>i)
		{
			try
			{
				if(i<0||i>=s1.getCourseNumber())
					throw i;
			}catch(int i)
			{
				cout<<"您所选的科目不存在!请重新输入！"<<endl;
				MyEx.MyExceptionOfStud(i);
				continue;
			}
			break;
		}
		s1.removeCourse(i); 
		int Gpa=s1.calcCredit();
		cout<<"该生所选课程的绩点成绩是："<<Gpa<<endl;
	}
	 
}
Text::~Text(){
}
