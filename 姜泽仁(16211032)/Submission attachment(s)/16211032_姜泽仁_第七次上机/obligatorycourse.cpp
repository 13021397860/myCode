#include "obligatorycourse.h" 
#include "MyException.h"// class's header file
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
// class constructor
ObligatoryCourse::ObligatoryCourse(const string &n,const int &c,const int &m)
:Course(n,c)
{
	setmark(m);
	// insert your code here
}
ObligatoryCourse::ObligatoryCourse(const string &n,const int &c)
:Course(n,c)
{
	setmark(-1);
	// insert your code here
}

// class destructor
ObligatoryCourse::~ObligatoryCourse()
{
	//cout<<"必修课析构"<<endl; 
	// insert your code here
}
bool ObligatoryCourse::setmark(const int &m){
	if(m>=-1&&m<=100){
		mark=m;
		return 1;
	}
	else{
		throw MyException(SCORE_INVALID);
	}
}
void  ObligatoryCourse::print()const{
	cout<<"课程名称：  "<<setw(12)<<name<<"[必修课]"<<"学分："<<creditHour<<endl;
}

