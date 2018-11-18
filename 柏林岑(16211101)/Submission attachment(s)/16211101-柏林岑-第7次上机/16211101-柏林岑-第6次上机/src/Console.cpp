#include "Console.h"
#include "Student.h"
#include "MyException.h"
#include<iostream>
#include<fstream>
using namespace std;
int Console::countcourse=0;
Console::Console() {
    ifstream infile;
    infile.open(".\\test.txt", ios::in);
    if(!infile){cout<<"error!"<<endl;return;}
    int credit,flag;
    string name;
    while(!infile.eof()) {
        infile>>flag>>name>>credit;
        if(flag==1) {
            _course[countcourse++]=new ObligatoryCourse(name,credit);
        }
        if(flag==2) {
            _course[countcourse++]=new ElectiveCourse(name,credit);
        }
    }
    infile.close();
}
void Console::showchoose() {
    cout<<"Enter 1    --  ѡ��\n";
    cout<<"Enter 2    --  �˿�:\n";
    cout<<"Enter 3    --  ���óɼ�\n";
    cout<<"Enter 4    --  �鿴��Ϣ\n";
    cout<<"Enter 5    --  ����ѡ��\n";
    return;
}
void Console::Choose() {
    for(int i=0; i<countcourse; i++) {
        cout<<*_course[i];
    }
    cout<<"\n";
    cout<<"Enter 1-"<<countcourse<<"ѡ��\nEnter 0 ����\n";
    int x;
    while(1){
			cin>>x;      //��Ҫ��while(cin>>x)
		while(cin.fail()){
			cin.clear();
			cin.ignore();
			cout<<"Error!Please enter a number to select:\n";
			cin>>x;
		}
		try{
        if(x>=1&&x<=countcourse) {
            student->addCourse(_course[x-1]);
            cout<<"\nѡ�γɹ�~~\n\n";
            cout<<"Enter 1-"<<countcourse<<" ����ѡ��\nEnter 0 ����\n";
        }
        else if(x==0)break;
        else {
            throw MyException(1);
        }
        }
        catch(MyException ex){
        cout<<ex.message()<<"\n";
        cout<<"Enter 1-"<<countcourse<<" ����ѡ��\nEnter 0 ����\n";
        }
    }
    menu() ;
}
void Console::Remove() {
    cout<<"Enter x �˿�\n";
    int x;
    cin>>x;
    while(1){
		while(cin.fail())
			{
			cin.clear();      //��cin.fail()��0
			cin.ignore();     //���Ե�ǰ�����ַ�
			cout<<"Error!Please enter a number to select:\n";
			cin>>x;
	}try{
	if(x<1||x>student->getcoursenumber()){
		throw MyException(1);
	}
	else break;
        }
        catch(MyException ex){
        cout<<ex.message()<<"\n";
        cout<<"Enter 1-"<<countcourse<<" ����ѡ��\nEnter 0 ����\n";
        cin>>x;
        }
    }
    student->removeCourse(x-1);
    cout<<"�˿γɹ�~~\n";
    menu();
    return;
}
void Console::Setgrade() {
    cout<<"Enter  x ���óɼ�\n";
    int x;
    cin>>x;
    while(1){
		while(cin.fail())
			{
			cin.clear();
			cin.ignore();
			cout<<"Error!Please enter a number to select:\n";
			cin>>x;
	}
	try{
	if(x<1||x>student->getcoursenumber()){
		throw MyException(1);
	}
	else break;
	}
        catch(MyException ex){
        cout<<ex.message()<<"\n";
        cout<<"Enter 1-"<<countcourse<<" ����ѡ��\nEnter 0 ����\n";
        cin>>x;
        }
    }
    student->setGrade(x);
    menu();
    return;
}
void Console::initStudent() {
    char *name;
    name=new char[30];
    cout<<"Your name:\n";
    cin>>name;
    cout<<"Your birthday:\n";
    Date dd;
    cin>>dd;
    student=new Student(name,dd);
}
void Console::Show() {
    cout<<*student<<endl;
    cout<<"your total grade: "<<student->calcCredit()<<"\n\n";
    menu();
    return;
}
void Console::run() {
    initStudent();
    menu();
    ofstream outfile(".\\information.txt");      //ǰ����Ҫ��.\\����ȡ��ǰĿ¼
    if(!outfile){cout<<"error!"<<endl;return;}
    outfile<<*student;
    outfile.close();
    return;
}
void Console::menu() {
    showchoose();
    int command;
    cin>>command;
    while(1){
		while(cin.fail())
			{
			cin.clear();      //��cin.fail()��0
			cin.ignore();     //���Ե�ǰ�����ַ�
			cout<<"Error!Please enter a number to select:\n";
			cin>>command;
	        }
	if(command<1||command>5){
		cout<<"Error!Enter 1-5 to select\n";
		cin>>command;
	 }
	else break;
	}
    if(command==1) {
        Choose();
    } else if(command==2) {
        Remove();
    } else if(command==3) {
        Setgrade();
    } else if(command==4) {
        Show();
    } else if(command==5) {
        return;
    }
    return;

}
Console::~Console() {
    delete student;
}

