#include "ElectiveCourse.h"
#include<bits/stdc++.h>
#include "MyException.h"
using namespace std;

ElectiveCourse::ElectiveCourse()
{
	grade='0';
}

ElectiveCourse::ElectiveCourse(string name,int creditHour):Course(name,creditHour)
{
    grade='0';
}

/*void ElectiveCourse::setgrade(char Grade)
{
    grade=Grade;
    //strcpy(grade,Grade);
}*/

/*ElectiveCourse::ElectiveCourse(ElectiveCourse &e)
{
    grade='0';
}

ElectiveCourse::ElectiveCourse(Course &e)
{
    grade='0';
}*/

int ElectiveCourse::getScore()
{
    if(grade='A')
        return 95;
    if(grade='B')
        return 85;
    if(grade='C')
        return 75;
    if(grade='D')
        return 65;
    if(grade='E')
        return 55;
}

int ElectiveCourse::setgrade(char grd)
{
   while(true)
   {
       try
       {
           if(grd!='A'&&grd!='B'&&grd!='C'&&grd!='D'&&grd!='E') throw MyException();
           break;
       }
       catch(MyException GE)
       {
           cout<<GE.GradeError()<<endl;
           cin>>grd;
       }
   }
	grade=grd;

}

ostream& operator<<(ostream& output,const ElectiveCourse& c)
{
	int x=0;
	switch(c.grade)
	{
		case 'A':
			x= 95;
			break;
		case 'B':
			x= 85;
			break;
		case 'C':
			x= 75;
			break;
		case 'D':
			x= 65;
			break;
		case 'E':
			x= 55;
			break;
		default:
			x= 0;
			break;
	}
	output << "课程名："<<c.name<< " " << "学分：" << c.creditHour << " " << "成绩：" << x;
	return output;
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
