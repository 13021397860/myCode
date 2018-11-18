#include "Console.h"
#include <iostream>
#include"Date.h"
#include"Student.h"
#include"Course.h"
#include"ElectiveCourse.h"
#include"OblilgatoryCourse.h"
#include<string>
#include<fstream>
#include"MyException.h"
Console::Console()
{
	ocnum=ecnum=0;
}
Console::~Console()
{
	
	  delete[]*oc;
	  delete[]*ec;
 } 
Student Console::student(char *name,Date &a)
{
		int n,y,r;
		cout<<"Please improve student information"<<endl;
		cout<<"Please enter name    " ;cin>>name; 
	    
		while(1)
		{
			try
			{
				cout<<"Please enter a date of birth"<<endl;
			    cout<<"Year   " ; cin>>n;
				cout<<"Month   "; cin>>y;
				cout<<"Day   ";   cin>>r; 
				a=Date(n,y,r);
		        Date b=a;
		        text(b);
		        break;
		    }
		    catch (MyException ex)
		    {
		    	cout<<ex.what()<<endl;
		    /*	cout<<"Please enter a date of birth"<<endl;
			    cout<<"Year   " ; cin>>n;
				cout<<"Month   "; cin>>y;
				cout<<"Day   ";   cin>>r; */
			}
		 }  
        Student s(name,a);
        return s;
}
void Console::menu()
{
	cout<<"                  Menu"<<endl; 
    cout<<"Course please intput ========================1"<<endl;//选课 
	cout<<"Withdraw please intput=======================2" <<endl;//退课 
	cout<<"Score please intput =========================3"<<endl; //打分 
	cout<<"View student information please intput=======4"<<endl; //输出学生信息 
	cout<<"View course results please input ============5"<<endl;//查询某一科成绩 
	//cout<<"Exit please input============================0"<<endl;//退出 
}
void Console::course(Student &s)
{					
 					 cout<<"Elective======1    Obligator======2"<<endl;
					 int  xuan,choice; 
					 cin>>xuan;
					 switch(xuan)
					   {
					 	case 1:
					 		{
					 		cout<<"Please choose from the course below"<<endl;
					 		for(int i=1;i<ecnum;i++)
					 		       cout<<i<<". "<<*ec[i]<<endl;
					 	    while(1)
					 	    {
					 	    	try
					 	    	{
					 	    		cout<<"Please enter the class serial number";cin>>choice;
								    if(choice>=ecnum||choice<=0)  throw  MyException(Number_wrong);
					 	    		s.addCourse(ec[choice]);
					 	    	    cout<<"Success"<<endl;
					 	    	    break;
								 }
								 catch(MyException ex)
								 {
								 	cout<<ex.what()<<endl;
								 }
							 }
					 	    	 
					 	     break;
							 }
					 	case 2:
					 		{
					 		cout<<"Please choose from the course below"<<endl;
					 		for(int i=1;i<ocnum;i++)
					 		   cout<<i<<". "<<*oc[i]<<endl;
					 		
					 		
					 	    while(1)
					 	    {
					 	    	
					 	    	try
					 	    	{
								        cout<<"Please enter the class serial number";cin>>choice;
					 	    	       if(choice>=ocnum||choice<=0)  throw  MyException(Number_wrong);
					 	    			s.addCourse(oc[choice]);
										 cout<<"Success"<<endl;
										 break;
								 }
								 catch(MyException ex)
								 {
								 	cout<<ex.what()<<endl;
								 }
							 }
					 	    	 break;
							 }
					 		
					 	default	:
							{
								cout<<"Unknown information"	<<endl; 
								break;
							}
					   }
}
void Console::withdraw(Student &s)
{
	int xuhao1;
	cout<<"Number  "; cin>>xuhao1;
	while(1)
	{
		try
		{
			s.removeCourse(xuhao1);
			break;
		}
		catch(MyException ex)
		{
			cout<<ex.what()<<endl;
			cout<<"Number  "; cin>>xuhao1;
		}
	}
	
}
void Console::score(Student &s)
{
	int xuhao2;
	
	while(1)
	{
		try
		{
		   cout<<"Number  ";cin>>xuhao2;
			s.dafen(xuhao2);
			break;
		}
		catch(MyException ex)
	    {
	    	cout<<ex.what()<<endl;
		}
	}
	
}
void Console::information(Student &s)
{
	
}
void Console::view(Student &s)
{
	    int xuhao3;
		cout<<"Number  ";cin>>xuhao3;
		if(xuhao3>=1&&xuhao3<=s.getcourseNumber())
		cout<<"CourseName:  "<<s.getname(xuhao3)<<"   Score：  "<<s.getfen(xuhao3)<<endl;
		else 
		cout<<"NO Massage!"<<endl;
}
void Console::run()
{
	     char number;
	     char A[]={"text.txt"};
         ofstream *ofile;
	     char*name=new char ;
	     Date a ;
	     Student s=student(name,a) ;
         buildCourse();
   		 menu();
		 cin>>number;
		while(1)
		{
			switch(number)
			{
				case '1':
					{ 
					 course(s);
					 menu();
					cin>>number;
					 break; 
				    } 
				case '2':
					{ 
					withdraw(s);
					menu();
					cin>>number;
					break;
					}
					
				case '3':
					{
		            score(s);
					menu();
					cin>>number;
					break;
					}
					
				case '4':
					{
						 //s.print();
					     ofile=new ofstream(A);//输出到文件里 
					     if(!ofile)
					     {
						 cerr<<"Fail！"<<endl;
						 break;
				     	 }
					    (*ofile)<<s;
					    ofile->close();//关闭 
					    delete ofile;
					    cout<<"Success"<<endl;
						menu(); 
						cin>>number;
						break;
					}
				case '5':
					{
					    view(s);
						menu();
			            cin>>number;
						break;
					}	
				default:
					{
						cout<<"Unknown information"	<<endl; 
						menu();
						cin>>number;
						break;
					}
		       
		   }
		}
		
}
void Console::text(Date a)
{
	Date b=a++;
    Date c=++a;
    cout<<"++Date  "<<b<<endl;
	cout<<"Date++  "<<c<<endl;
}
Console &Console::buildCourse()
{
	char  a[]="CourseList.dat";
	ifstream  add(a);//读取 
	int num, hour;
	string  cname;
	ocnum=ecnum=1;
	if (!add)
		return *this;
	while(add>>num>>cname>>hour)
	{
		switch (num)
		{
		case 1:
			oc[ocnum++]=new OblilgatoryCourse(cname,hour);
			break;
		case 2:
			ec[ecnum++]=new ElectiveCourse(cname,hour);
			break;
		}
	}
	add.close();

	return *this;
}
