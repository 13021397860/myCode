#include "Console.h"
#include "MyException.h"
#include <iostream>
using namespace std;
Console::Console()
{
}

void Console::Caozuo()
{
	int year,month,day;
	char name[20];
	cout<<"Please enter your name"<<endl;
	cin>>name;
	cout<<"Please enter your birthday: Year Month Day"<<endl;
	//cin>>year>>month>>day;
	while(1)
    {
        try
		{
            cin>>year>>month>>day;
            if(cin.fail())
            {
            	cin.clear();
            	cin.sync();
            	throw(MyException(Date_Invalid));
			}
            break;
        }catch(MyException ex)
        {
            cout<<"系统异常："<<ex.what()<<endl;
            cout<<"请重新输入生日";
        }
    }
//	while(cin.fail())
//	{
//		cout<<"Wrong input,please enter again"<<endl;
//		cin.clear();
//		cin.sync();
//		cin>>year>>month>>day;
//	}
	Student student1(name,year,month,day);
	cout<<student1<<endl;
	cout<<"****************************"//\n1.Choose ObligatoryCourse "
		<<"\n1.Choose Course "<<"\n2.Check information "
		<<"\n3.Delete course "<<"\n4.Set score "
		<<"\n5.Check your GPA score "<<"\n6.Check course scores "
		<<"\n7.Print your information in the file "
		<<"\n0.Quit "<<"\nPlease choose a number."<<endl;
	int choose,coursemark,coursecredit;
	string coursename;
	char coursegrade;
	int state=1;
	student1.file_in();
	while(state)
	{
		cin>>choose;
		while(cin.fail())
		{
			cout<<"It's not a number,please choose again."<<endl;
			cin.clear();
			cin.sync();
			cin>>choose;
		}
		if(choose==1)
		{
			int k;
			int type=0;
			cout<<"Please enter a course number"<<endl;
			cout<<"You can choose:"<<endl;
			student1.showmecourse();
			cin>>k;
			student1.filecourse(coursecredit,coursename,type,k);
			if(type==1)
			{
				Course *course1=new ObligatoryCourse(coursename,coursecredit,0);
				student1.addCourse(course1);
			}
			else if(type==2)
			{
				Course *course2=new ElectiveCourse(coursename,coursecredit,'E');
				student1.addCourse(course2);
			}
			//cout<<"Please enter Course Name CreditHour and Mark"<<endl;
			//cin>>coursename>>coursecredit>>coursemark;
//			while(cin.fail())
//			{
//				cout<<"Wrong Input,please enter again"<<endl;
//				cin.clear();
//				cin.sync();
//				cin>>coursename>>coursecredit>>coursemark;
//			}
		}
//		if(choose==2)
//		{
//			cout<<"Please enter Course Name CreditHour and Grade"<<endl;
//			cin>>coursename>>coursecredit>>coursegrade;
//			while(cin.fail())
//			{
//				cout<<"Coursecredit is number,please enter again"<<endl;
//				cin.clear();
//				cin.sync();
//				cin>>coursename>>coursecredit>>coursegrade;
//			}
//			while(coursegrade<65||(coursegrade>69&&coursegrade<97)||coursegrade>101)
//			{
//				cout<<"coursegrade is not what we want,please enter again"<<endl;
//				cin>>coursegrade; 
//			}
//			Course *course2=new ElectiveCourse(coursename,coursecredit,coursegrade);
//			student1.addCourse(course2);
//		}
		if(choose==2)
		{
			cout<<student1<<endl;
		}
		if(choose==3)
		{
			cout<<"Pleae enter course number"<<endl;
			int cn;
			cin>>cn;
			student1.removeCourse(cn);
		}
		if(choose==4)
		{
			cout<<"Please enter course number"<<endl;
			int cn;
			cin>>cn;
			cout<<"Please enter your score"<<endl;
			int c;
			cin>>c;
			student1.SsetScore(cn,c);
		}
		if(choose==5)
		{
			cout<<"Your GPA score: "<<student1.caleCredit()<<endl;
		}
		if(choose==6)
		{
			student1.checkCScorse();
		}
		if(choose==7)
		{
			student1.file_print(student1);
		}
		if(choose==0)
		{
			cout<<"Quit"<<endl;
			break;
		}
		if(choose>7)
		{
			cout<<"Your choice is not in the menu,please choose again"<<endl;
		}
		cout<<"****************************"//\n1.Choose ObligatoryCourse "
		<<"\n1.Choose Course "<<"\n2.Check information "
		<<"\n3.Delete course "<<"\n4.Set score "
		<<"\n5.Check your GPA score "<<"\n6.Check course scores "
		<<"\n7.Print your information in the file "
		<<"\n0.Quit "<<"\nPlease choose a number."<<endl;
	}
}

Console::~Console()
{
	
}
