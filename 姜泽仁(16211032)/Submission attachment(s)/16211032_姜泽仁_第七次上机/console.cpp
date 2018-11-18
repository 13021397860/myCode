#include "console.h"
#include "myexception.h" // class's header file
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<windows.h> 
#include<typeinfo>
using namespace std;
// class constructor
Console::Console()
{
	ocNum=ecNum=0;
	// insert your code here
}

// class destructor
Console::~Console()
{
	// insert your code here
}
Console& Console::buildCourse(){
	/*string n;
	int t;
	freopen("course.txt","r",stdin);
	for(int i=1;i<=5;i++){
		cin>>n>>t;
		oc[i]=new ObligatoryCourse(n,t,100);
	}
	for(int i=1;i<=5;i++){
		cin>>n>>t;
		ec[i]=new ElectiveCourse(n,t,'A');
	}
	ocNum=ecNum=5;
	freopen("CON", "r", stdin);
	return *this;*/
	string n;
	int t;
	ifstream infile;
	infile.open("course.txt",ios::in);
	for(int i=1;i<=5;i++){
		infile>>n>>t;
		oc[i]=new ObligatoryCourse(n,t,100);
	}
	for(int i=1;i<=5;i++){
		infile>>n>>t;
		ec[i]=new ElectiveCourse(n,t,'A');
	}
	ocNum=ecNum=5;
	infile.close();
	return *this;
}
Console& Console::buildStudent(){
	int y,m,d;
	char name[20];
	printf("请输入姓名：\n");
	scanf("%s",name);
	printf("请输入生日，以空格分开：（年 月 日）\n");
	while(1){
		scanf("%d%d%d",&y,&m,&d);
		try{
			student=new Student(name,y,m,d);
			break;
		}catch(MyException ex){
			cout<<"系统异常："<<ex.what()<<"\n";
        	cout<<"请重新输入学生生日\n";
		}
	}
	//scanf("%d%d%d",&y,&m,&d);
	//student=new Student(name,y,m,d);
	return *this;
}
void Console::selectCourse(int op){
	int type;
	if(op==1){
		Course *p;
		cout<<"必修："<<endl; 
		for(int i=1;i<=5;i++){
			cout.setf(ios::left);
			cout<<setw(2)<<i; 
			oc[i]->print();
		}
		cout<<"请输入号码选课，可以多选并以0作为结束标志"<<endl;
		scanf("%d",&type);
		while(type!=0){
				p=new ObligatoryCourse(oc[type]->getname(),oc[type]->getcreditHour());
				student->addCourse(p);
				//cin>>type;
				scanf("%d",&type);
		}
	}
	else if(op==2){
		Course *p;
		cout<<"必修："<<endl; 
		for(int i=1;i<=5;i++){
			cout.setf(ios::left);
			cout<<setw(2)<<i; 
			ec[i]->print();
		}
		cout<<"请输入号码选课，可以多选并以0作为结束标志"<<endl;
		scanf("%d",&type);
		while(type!=0){
				p=new ElectiveCourse(ec[type]->getname(),ec[type]->getcreditHour());
				student->addCourse(p);
				//cin>>type;
				scanf("%d",&type);
		}
	}
}
bool Console::setCourseScore(){
	int mark=0;
	char grade='\0';
	for(int i=0;i<student->getcourseNumber();i++){
		if(typeid(ObligatoryCourse)==typeid((*student)[i])){
			cout<<"必修课程“"<<(*student)[i].getname()<<"”的成绩(0-100)：";
			//cin>>mark;
			while(1){
                scanf("%d",&mark);
				try
                {
                    dynamic_cast<ObligatoryCourse &>((*student)[i]).setmark(mark);
                    break;
                }catch(MyException ex)
                {
                    cout<<"格式错误，必修课程“"<<(*student)[i].getname()<<"”的成绩(0-100)：";
                }
			}
			//scanf("%d",&mark);
			//dynamic_cast<ObligatoryCourse &>((*student)[i]).setmark(mark);
		}
		else if (typeid(ElectiveCourse)==typeid((*student)[i])){
			cout<<"选修课程“"<<(*student)[i].getname()<<"”的成绩(A-E)：";
			//cin>>grade;
			while(1){
                scanf(" \n%c",&grade);
				try
                {
                    dynamic_cast<ElectiveCourse &>((*student)[i]).setgrade(grade);
                    break;
                }catch(MyException ex)
                {
                    cout<<"格式错误，选修课程“"<<(*student)[i].getname()<<"”的成绩(A-E)：";
                }
			}
			//dynamic_cast<ElectiveCourse &>((*student)[i]).setgrade(grade);
		}
		else{
			return false;
		}
	}
	return true;
}
void Console::removeCourse(){
	int type;
	cout<<*student;
	cout<<"请输入号码退课，每次只能退一门课"<<endl;
	scanf("%d",&type);
	student->removeCourse(type); 

}
int Console::displayMenu()const{
	int choice=0;
	cout<<"**********学生选课系统-主菜单**********\n"
		<<"\t1. 选必修课程\n"
		<<"\t2. 选选修课程\n"
		<<"\t3. 查看选课情况(包括成绩)\n"
		<<"\t4. 设置课程成绩\n"
		<<"\t5. 退选课程\n"
		<<"\t6. 查询学分绩\n"
		<<"\t7. 保存学生信息\n"
		<<"\t0. 退出系统\n"
		<<"请选择所需的操作(0~7)：";
	//scanf("%d",&choice);
	cin>>choice;
	while(cin.fail()||choice<0||choice>7){
		cout<<"输入不合法请重新输入"<<endl;
		cin.clear();
		cin.ignore();
		cin>>choice; 
	}
	return choice;
}
void Console::printCredit()const{
	if(student->calcCredit()<0){
		cout<<"课程成绩未录入或录入不完全，无法计算"<<endl;
	} 
	else{
		cout<<"当前学分绩为："<<student->calcCredit()<<endl;
	}
}
void Console::save(){
	char filename[100];
	cout<<"请输入文件名"<<endl;
	cin>>filename;
	ofstream *outfile;
	outfile=new ofstream(filename);
	*outfile<<*student;
	outfile->close();
	cout<<"保存成功！！！"<<endl; 
}
int Console::run(){
    buildCourse();
    buildStudent();
    system("cls");
    int choice=displayMenu();
    system("cls");
    while (choice!=0)
    {
        switch (choice)
        {
            case 1: 
				selectCourse(1);
                break;
            case 2: 
                selectCourse(2);
                break;
            case 3: 
                cout<<*student;
                break;
            case 4: 
                setCourseScore();
                break;
            case 5:  
                removeCourse();
                break;
            case 6:  
                printCredit();
                break;
            case 7:
				 save();
				 break;
        }
        choice=displayMenu();
        system("cls");
    }

    return 0;
}
