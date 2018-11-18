#include "HelloStudent.h"
#include <iostream>
using namespace std;
HelloStudent::HelloStudent()
{
}

void HelloStudent::Caozuo()
{
	int year,month,day;
	char name[20];
	cout<<"Please enter your name"<<endl;
	cin>>name;
	cout<<"Please enter your birthday: Year Month Day"<<endl;
	cin>>year>>month>>day;
	Student student1(name,year,month,day);
	cout<<student1<<endl;
	cout<<"****************************\n1.Choose ObligatoryCourse \n2.Choose ElectiveCourse \n3.Check information \n4.Delete course \n5.Set score \n6.Check your GPA score \n7.Check course scores \n0.Quit \nPlease choose a number."<<endl;
	int choose,coursemark,coursecredit;
	string coursename;
	char coursegrade;
	while(cin>>choose)
	{
		if(choose==1)
		{
			cout<<"Please enter Course Name CreditHour and Mark"<<endl;
			cin>>coursename>>coursecredit>>coursemark;
			Course *course1=new ObligatoryCourse(coursename,coursecredit,coursemark);
			student1.addCourse(course1);
		}
		if(choose==2)
		{
			cout<<"Please enter Course Name CreditHour and Grade"<<endl;
			cin>>coursename>>coursecredit>>coursegrade;
			Course *course2=new ElectiveCourse(coursename,coursecredit,coursegrade);
			student1.addCourse(course2);
		}
		if(choose==0)
		{
			cout<<"Quit"<<endl;
			break;
		}
		if(choose==3)
		{
			cout<<student1<<endl;
		}
		if(choose==4)
		{
			cout<<"Pleae enter course number"<<endl;
			int cn;
			cin>>cn;
			student1.removeCourse(cn);
		}
		if(choose==5)
		{
			cout<<"Please enter course number"<<endl;
			int cn;
			cin>>cn;
			cout<<"Please enter your score"<<endl;
			int c;
			cin>>c;
			student1.SsetScore(cn,c);
		}
		if(choose==6)
		{
			cout<<"Your GPA score: "<<student1.caleCredit()<<endl;
		}
		if(choose==7)
		{
			student1.checkCScorse();
		}
		cout<<"****************************\n1.Choose ObligatoryCourse \n2.Choose ElectiveCourse \n3.Check information \n4.Delete course \n5.Set score \n6.Check your GPA score \n7.Check course scores \n0.Quit \nPlease choose a number."<<endl;
	}
}

HelloStudent::~HelloStudent()
{
	
}
