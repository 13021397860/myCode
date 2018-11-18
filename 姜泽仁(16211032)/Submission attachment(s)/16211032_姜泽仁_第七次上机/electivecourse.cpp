#include "electivecourse.h"
#include "MyException.h" // class's header file
#include<iostream>
#include<iomanip>
#include<string>
// class constructor
ElectiveCourse::ElectiveCourse(const string &n,const int &c,const char &g)
:Course(n,c)
{
	setgrade(g);
	// insert your code here
}
ElectiveCourse::ElectiveCourse(const string &n,const int &c)
:Course(n,c)
{
	setgrade('\0');
	// insert your code here
}

// class destructor
ElectiveCourse::~ElectiveCourse()
{
	//cout<<"选修课析构"<<endl; 
	// insert your code here
}
bool ElectiveCourse::setgrade(const char &g){
	if(((g>='A')&&(g<='E'))||(g=='\0')){
		grade=g;
		return 1;
	}else{
		throw MyException(SCORE_INVALID);
	}
	//grade=g;
	//return 1;
}
const int ElectiveCourse::getScore()const{
	switch(grade){
		case 'A':return 95;
		case 'B':return 85;
		case 'C':return 75;
		case 'D':return 65;
		case 'E':return 55;
		default :return -1;
	}
}
void ElectiveCourse::print()const{
	cout<<"课程名称：  "<<setw(12)<<name<<"[选修课]"<<"学分："<<creditHour<<endl;
}
