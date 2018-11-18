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
	//cout<<"�γ�����"<<endl; 
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
	cout<<"�γ����ƣ�  "<<setw(12)<<name<<"ѧ�֣�"<<creditHour<<endl; 
} 
ostream & operator <<(ostream &output,Course &c){
	//c.print();
	if(c.getType()==1){
		output<<"�γ����ƣ�  "<<setw(12)<<c.name<<"[���޿�]"<<"ѧ�֣�"<<c.creditHour<<endl;
	}
	else{
		output<<"�γ����ƣ�  "<<setw(12)<<c.name<<"[ѡ�޿�]"<<"ѧ�֣�"<<c.creditHour<<endl;
	}
	if(c.getScore()==-1){
		output<<"�ɼ�(�ٷ���)��NaN"<<endl<<endl;
	}
	else{
		output<<"�ɼ�(�ٷ���)��"<<c.getScore()<<endl<<endl;
	}
	return output;
}
