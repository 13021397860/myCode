#include <iostream>
//#include<cstdio> 
#include "date.h"
#include "student.h"
#include"obligatorycourse.h"
#include"electivecourse.h"
#include<iostream>
#include<cstdio>
#include<string>
#include<iomanip>
#include"console.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int m,y,d;
string n;
ObligatoryCourse *oc[20];
ElectiveCourse *ec[20];
int t;
int type;
int main(int argc, char *argv[]) {
	Console c;
	c.run();
	return 0;
	/*cout<<"���캯������Date()"<<endl;
	date1.print();
	cout<<"setyear(y)���� ������ݣ�";
	cin>>y;
	 date1.setyear(y);
	 cout<<"setmonth(m)���� �����·ݣ�";
	 cin>> m;
	 date1.setmonth(m);
	 cout<<"setday(d)���� �������ڣ�";
	 cin>>d;
	 date1.setday(d);
	 date1.print();
	 date1.nextDay();
	 cout<<"nextDay()���� �����ǣ�";
	 date1.print();
	 cout<<"getday()����"<<date1.getday()<<endl;
		cout<<"getmonth()����"<<date1.getmonth()<<endl;
		cout<<"getyear()����"<<date1.getyear()<<endl;
	Date date2(date1);
	cout<<"�������캯������Date date2(date1)"<<endl;
	date2.print();
	return 0;*/
	/*char name[20];
	printf("������������\n");
	scanf("%s",name);
	printf("���������գ��Կո�ֿ������� �� �գ�\n");
	scanf("%d%d%d",&y,&m,&d);
	//Date a(1999,2,28);
	//Student person1("cody",a);
	//Student person2("CODY",2017,3,28);
	//Student person3(person1);
	Student person4(name,y,m,d);
	//person1.print(); 
	//person2.print();
	//person3.print();
	person4.print();
	//cout<<Student::getcount()<<endl;
	freopen("course.txt","r",stdin);
	for(int i=1;i<=5;i++){
		cin>>n>>t;
		oc[i]=new ObligatoryCourse(n,t,100);
	}
	for(int i=6;i<=10;i++){
		cin>>n>>t;
		ec[i]=new ElectiveCourse(n,t,'A');
	}
	cout<<"���ޣ�"<<endl; 
	for(int i=1;i<=5;i++){
		cout.setf(ios::left);
		cout<<setw(2)<<i; 
		oc[i]->print();
	}
	cout<<"ѡ�ޣ�"<<endl; 
	for(int i=6;i<=10;i++){
		cout.setf(ios::left);
		cout<<setw(2)<<i; 
		ec[i]->print();
	}
	freopen("CON", "r", stdin);
	cout<<"���������ѡ�Σ����Զ�ѡ����0��Ϊ������־"<<endl;
	scanf("%d",&type);
	//cin>>type;
	while(type!=0){
		if(type>5){
			person4.addCourse(ec[type]);
		}
		else{
			person4.addCourse(oc[type]);
		}
		//cin>>type;
		scanf("%d",&type);
	}
	//person4.print();
	//person4.printCourse();
	cout<<person4;*/
}
