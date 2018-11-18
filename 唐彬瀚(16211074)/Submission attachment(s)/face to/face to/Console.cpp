#include<iostream>
#include<cstring>
#include<typeinfo>
#include<fstream>
#include"Date.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include"Course.h"
#include"Student.h"
#include"Console.h"
#include"MyException.h"
using namespace std;
Console::Console()
{
	
}
Student Console::initi()
{
	MyException m1;
	char *a;
	int m,d,y;
	Date D;
	Student s;
	snumber++;
	cout<<"What's your birthday?(month day year)"<<endl;
	cin>>m>>d>>y;
	D.setDate(m,d,y);
	while(m1.checkd(D)!=1){
		cin>>m>>d>>y;
		D.setDate(m,d,y);
	}	
	cout<<"What's your name?"<<endl;
	a=new char[20];
	cin>>a;
	int A,B,C;
	for(int i=0;i<snumber-1;i++){
		A=sl[i].getBirthday().get_day();
		B=sl[i].getBirthday().get_month();
		C=sl[i].getBirthday().get_year();
		if(A==D.get_day()&&B==D.get_month()&&C==D.get_year()&&sl[i].getName()==*a){
			cout<<"What would you do?\n"<<"    0----Initialize\n"<<"    1----Select Courses\n"<<"    2----Remove Courses\n"<<"	3----Check Scores\n"<<"    4----Set grades\n"<<"    5----Get credit\n"<<"    6----Check course\n"<<"    7----Save information"<<endl;
			return sl[i];
		}
	}
	s.setBirthday(D);
	s.setName(a);
	sl[snumber-1]=s;
	cout<<"What would you do?\n"<<"    0----Initialize\n"<<"    1----Select Courses\n"<<"    2----Remove Courses\n"<<"    3----Check Scores\n"<<"    4----Set grades\n"<<"    5----Get credit\n"<<"    6----Check course\n"<<"    7----Save information"<<endl;
	return s;
}
void Console::select(Student &s)
{
	MyException m2;
	int i;
	cout<<"The obligatory courses you can choose are:"<<endl;
	for(int i=0;i<=3;i++){
		cout<<i+1<<"."<<*o[i]<<endl;
	}
	cout<<"The elective courses you can choose are:"<<endl;
	for(int i=0;i<=3;i++){
		cout<<5+i<<"."<<*e[i]<<endl;
	}
	cout<<"Choose the number of the course you want."<<endl;
	cin>>i;
	while(m2.checkc(i)!=1){
		cin>>i;
	}
	if(i<=4){
		s.addCourse(o[i-1]);
	}
	else if(i>4&&i<=8){
		s.addCourse(e[i-5]);
	}
	cout<<"The course whose number is "<<i<<" has been selected"<<endl;
	cout<<"What would you do?\n"<<"    0----Initialize\n"<<"    1----Select Courses\n"<<"    2----Remove Courses\n"<<"    3----Check Scores\n"<<"    4----Set grades\n"<<"    5----Get credit\n"<<"    6----Check course\n"<<"    7----Save information"<<endl;
}
void Console::remove(Student &s)
{
	if(s.getCourseNumber()==0){
		cout<<"You have nothing to remove."<<endl;
	}
	else{
		MyException m5;
		int i;
		cout<<"The course you can remove are:"<<endl;
		s.outputList();
		cout<<"Choose the number of the course you want to remove."<<endl;
		cin>>i;
		while(m5.checkc1(s,i)!=1){
			cin>>i;
		}
		s.removeCourse(i);
		cout<<"The course whose number is "<<i<<" has been removed"<<endl;
		cout<<"What would you do?\n"<<"    0----Initialize\n"<<"    1----Select Courses\n"<<"    2----Remove Courses\n"<<"    3----Check Scores\n"<<"    4----Set grades\n"<<"    5----Get credit\n"<<"    6----Check course\n"<<"    7----Save information"<<endl;
	}
	
}
void Console::check(Student &s)
{
	if(s.getCourseNumber()==0){
		cout<<"You have nothing to remove."<<endl;
	}
	else{
		MyException m4;
		int n;
		s.outputList();
		cout<<"Which course do you want to check?"<<endl;
		cout<<"Please input a NUMBER (or 0 for sum)"<<endl;
		cin>>n;
		while(m4.checkc1(s,n)!=1){
			cin>>n;
		}
		if(n>0){
			cout<<s.getList(n)->getScore()<<endl;
		}
		else if(n==0){
			cout<<s.getCaleCredit()<<endl;
		}
		cout<<"What would you do?\n"<<"    0----Initialize\n"<<"    1----Select Courses\n"<<"    2----Remove Courses\n"<<"    3----Check Scores"<<"    4----Set grades\n"<<"    5----Get credit\n"<<"    6----Check course\n"<<"    7----Save information"<<endl;
		}
	
}
void Console::load()
{
	ifstream A("Obligatory Course.txt");
	int c;
	string n;
	for(int i=1;i<=4;i++){
		A>>n>>c;
		ObligatoryCourse *a;
		a=new ObligatoryCourse(n);
		a->setCredit(c);
		o[i-1]=a;
	}
	ifstream B("Elective Course.txt");
	for(int i=1;i<=4;i++){
		B>>n>>c;
		ElectiveCourse *a;
		a=new ElectiveCourse(n);
		a->setCredit(c);
		e[i-1]=a;
	}
	char ch;
	ifstream C("Student.txt");
	C>>ch;
	if(ch==EOF){
		snumber=0;
	}
	else{
		char *a,*b;
		Date D;
		string cname;
		int d,m,y,cnumber,type,cre;
		for(int i=0;i<=snumber-1;i++){
			cin>>a>>d>>m>>y>>cnumber;
			D.setDate(d,m,y);
			sl[i]=Student(a,D);
			for(int i=0;i<=cnumber-1;i++){
				b=new char[2];
				C>>b;
				if(b=="O1"||b=="O2"||b=="O3"||b=="O4"){
					C>>cre;
					ObligatoryCourse *o;
					o=new ObligatoryCourse;
					o->setCourseName(b);
					o->setCredit(cre);
					sl[i].addCourse(o);
				}
				else if(b=="E1"||b=="E2"||b=="E3"||b=="E4"){
					ElectiveCourse *e;
					e=new ElectiveCourse;
					e->setCourseName(b);
					e->setCredit(cre);
					sl[i].addCourse(e);
				}
			}
		}
	}
}
void Console::setcredit()
{
	MyException m3;
	int i;
	char c;
	for(int i=0;i<=3;i++){
		cout<<"Please set "<<o[i]<<"'s point."<<endl;
		cin>>i;
		while(m3.checkg(i)!=1){
			cin>>i;
		}
		credit_[i]=o[i]->getScore();
	}
	for(int i;i<=3;i++){
		cout<<"Please set "<<e[i]<<"'s grade."<<endl;
		cin>>c;
		while(m3.checkg(c)!=1){
			cin>>c;
		}
		credit_[9+i]=e[i]->getGrade();
	}
	cout<<"Completed!"<<endl;
}
int Console::credit()
{
	int a=0,b=0,sum=0,credit;
	for(int i=0;i<=4;i++){
		sum+=credit_[i];
	}
	for(int i=0;i<=4;i++){
		sum+=credit_[9+i];
	}
	for(int i=0;i<=3;i++){
		credit=0.6*o[i]->getScore()*o[i]->getCredit()/sum;
	}
	for(int i=0;i<=3;i++){
		credit+=0.4*e[i]->getScore()*e[i]->getCredit()/sum;
	}
	return credit;
}
void Console::getList(Student &s)
{
	for(int i=0;i<=s.getCourseNumber();i++){
		cout<<i+1<<"."<<*(s.getList(i))<<endl;
	}
}
void Console::save(Student &s)
{
	ofstream A("Student.txt");
	int a,cn;
	for(int i=0;i<=snumber-1;i++){
		A<<sl[i].getName();
		cout<<" "; 
		A<<s.getBirthday().get_day()<<" "<<s.getBirthday().get_month()<<" "<<s.getBirthday().get_year()<<" ";
		cn=sl[i].getCourseNumber();
		cout<<cn<<endl;
		for(int j=1;j<=cn;j++){
			cout<<sl[i].getList(j)<<endl;
		}
	}
	cout<<"Information saved."<<endl;
}
