#include "course.h" // class's header file
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
// class constructor
Course::Course(const string &n,const int &c)
{
	setname(n);
	setcreditHour(c);
	// insert your code here
}

// class destructor
Course::~Course()
{
	//cout<<"课程析构"<<endl; 
	// insert your code here
}
void Course::setname(const string &n){
	name=n;
}
void Course::setcreditHour(const int &c){
	creditHour=c;
}
void Course::print()const{
	cout.setf(ios::left);
	cout<<"课程名称：  "<<setw(12)<<name<<"学分："<<creditHour<<endl; 
} 
ostream & operator <<(ostream &output,Course &c){
	//c.print();
	if(c.getType()==1){
		output<<"课程名称：  "<<setw(12)<<c.name<<"[必修课]"<<"学分："<<c.creditHour<<endl;
	}
	else{
		output<<"课程名称：  "<<setw(12)<<c.name<<"[选修课]"<<"学分："<<c.creditHour<<endl;
	}
	if(c.getScore()==-1){
		output<<"成绩(百分制)：NaN"<<endl<<endl;
	}
	else{
		output<<"成绩(百分制)："<<c.getScore()<<endl<<endl;
	}
	return output;
}
