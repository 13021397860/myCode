#include<iostream>
#include<cstring>
#include"Date.h"
#include"MyException.h"
#include"Student.h"
using namespace std;
MyException::MyException()
{
	
}
bool MyException::checkd(Date D)
{
	int m,d,y;
	m=D.get_month();
	d=D.get_day();
	y=D.get_year();
	if(m>12||d>31||m<=0||d<=0||m==2&&d>=30||(m==4||m==6||m==9||m==11)&&d==31||D.isLeapYear(y)!=1&&m==2&&d==30){
		cout<<"Are you kidding me?"<<endl;
		cout<<"Wrtie it again, seriously."<<endl;
		return 0;
	}
	else{
		return 1;
	}
}
bool MyException::checkc(int i)
{
	if(i<=4){
		return 1;
	}
	else if(i>4&&i<=8){
		return 1;
	}
	else {
		cout<<"Are you kidding me, again? There is no such a class!"<<endl;
		cout<<"Choosing correctly, OK?"<<endl;
		return 0;
	}
	
}
bool MyException::checkg(int i)
{
	if(i>100||i<0){
		cout<<"You made my patience lost!"<<endl;
		return 0;
	}
	else{
		return 1;
	}
}
bool MyException::checkg(char i)
{
	if(i!='A'||i!='B'||i!='C'||i!='D'||i!='E'||i!='F'){
		cout<<"You made my patience lost!"<<endl;
		return 0;
	}
	else{
		return 1;
	}
}
bool MyException::checkc1(Student s,int i)
{
	if(i>s.getCourseNumber()){
		cout<<"Kidding me is funny?"<<endl;
		return 0;
	}
	else{
		return 1;
	}
}
