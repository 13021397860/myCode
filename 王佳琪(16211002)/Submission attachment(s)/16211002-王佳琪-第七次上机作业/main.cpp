#include <iostream>
#include <cstring>
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Console.h"
using namespace std;

string str;
int main()
{
    /*Date date1(date);
    cout<<date1.isLeapYear()<<endl;
    cout<<date1.getYear()<<'/'<<date1.getMonth()<<'/'<<date1.getDay()<<endl;
    date1.print();
    date1.nextDay();
    date1.print();
    return 0;
    */
    
    /*
    string name;
    int hour;
    Student stu("tom");
    Date date;
    int y,m,d;
    
    cout<<"Please put in a name shorter than 10 characters :"<<endl;
    while(cin>>str)//控制名字长度 
    {
        if(str.length()>40)
        cout<<"Put in again."<<endl;
        else
        break;
    }

    char *n = new char[str.length()+1];
    strcpy(n,str.data());
    stu.SetName(n);

    
    cout<<"Please put in a date :"<<endl;
    cin>>y>>m>>d;
    date.setDate(y,m,d);

    stu.SetBirthday(&date);
    
    int num,num1,num2;
    cout<<"Input 1 to check your personal information , input 2 to elect courses , input 3 to quit courses:"<<endl;
	while(cin>>num)
  {
		if(num == 1)
	{
		cout<<stu<<endl;
	} 
	else if(num == 2)
	{
	 	cout<<"Please choose your courses :"<<endl;
	 	cout<<"Input 1 for obligatory courses , input 2 for elective courses :"<<endl;
			cin>>num1;
			if(num1 == 1)
			{
				Course *c1=new ObligatoryCourse();
				cout<<"Please input the name of the obligatorycourse :"<<endl;
				cin>>str;
				cout<<"Please input the credit of the obligatorycourse :"<<endl;
				cin>>hour;
				c1->setCourse(hour,str);
				stu.addCourse(c1);
			}
			else if(num1 == 2)
			{
				Course *c2=new ElectiveCourse();
				cout<<"Please input the name of the electivecourse :"<<endl;
				cin>>str;
				cout<<"Please input the credit of the electivecourse :"<<endl;
				cin>>hour;
				c2->setCourse(hour,str);
				stu.addCourse(c2);
			}
			else cout<<"Wrong!"<<endl;
	}
	else if(num == 3)
	{
		cout<<"Type in the course you want to quit :"<<endl;
		cin>>num1;
		if(stu.removeCourse(num1)) cout<<"Successed!"<<endl;
		else cout<<"Failed!"<<endl;
	}
	else return 0;
  }*/
  
  	Console console;
    console.run();
  
}
