#include "Console.h"
#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<typeinfo>
#include<fstream>
using namespace std;

Console::Console()
{
	buildCourse();
    buildStudent();
}
int Console::run(){
    char fileName[]="StudentInformation.txt";
	ofstream *ofile;
	int choice;
    choice=displayMenu();
    while (choice!=7)
    {
        switch (choice)
        {
            case 1: 
            case 2: 
                {
                	student->addCourse(selectCourse(choice));
                	break;
				}
            case 3:
                {
                	cout<<*student;
                	break;
				}
            case 4: 
                {
                	setCourseScore();
                	break;
				}
			case 5: 
	            {
	            	cout<<"你的绩点成绩为："<<fixed<<setprecision(4)<<student->calcCredit()<<endl;  
	            	break;
				}
			case 6: 
	            {
	            	ofile=new ofstream(fileName);
	            	if (!ofile)
	            	{
	            		cerr<<"文件创建失败！\n";
						break; 
					}
					(*ofile)<<*student;
					ofile->close();
					delete ofile; 
					cout<<"文件创建成功！\n";
	            	break;
				}
			case 7: 
                {
                	break;
				}
			default:
				{
					cout<<"请输入正确的数字哦！\n"; 
					break;
				}
        }
        choice=displayMenu();
	}
}
Console& Console::buildStudent(){
	char* n=new char[21];
	int y,m,d;
	cout<<"请输入您的姓名\n"; 
	cin>>n;
	cout<<"请输入您的生日，如2017 4 18\n";
	while(1)
	{
		try{
			cin>>y>>m>>d;
			student=new Student(n,y,m,d);
			break;
		}catch(MyException ex)
		{
			cout<<"系统异常："<<ex.what()<<endl;
			cout<<"请重新输入您的生日"; 
		}
	}
}
Console& Console::buildCourse(){
	char fileName[]=".\\CourseList.dat";
	ifstream ifile(fileName);
	int catalog,credit;
	string cname;
	ocNum=0;
	ecNum=0;
	if (!ifile)
	{
		return *this;
	}
	while (ifile>>catalog>>cname>>credit)
	{
		switch (catalog)
		{
			case 1:
				oc[ocNum++]=new ObligatoryCourse(cname,credit);
				break;
			case 2:
				ec[ecNum++]=new ElectiveCourse(cname,credit);
				break;
		}
	}
	ifile.close();
	//ocNum=3;
	//ecNum=2;
	//oc[0]=new ObligatoryCourse("高等数学",4);
	//oc[1]=new ObligatoryCourse("线性代数",5);
	//oc[2]=new ObligatoryCourse("工科大学物理",2);
	//ec[0]=new ElectiveCourse("大学生安全知识教育",1);
	//ec[1]=new ElectiveCourse("大学生心理学",2);
	
}
int Console::displayMenu() const{
	int operate;
	cout<<"你好！出生于"<<student->getBirthdate().getYear()<<"年"<<student->getBirthdate().getMonth()<<"月"<<student->getBirthdate().getDay()<<"日的"<<student->getName()<<"同学。这里是主菜单，请输入对应数字选择操作。\n";
	cout<<"1. 选择必修课程\n";
	cout<<"2. 选择选修课程\n";
	cout<<"3. 查看你的选课情况\n";
	cout<<"4. 设置课程成绩\n";
	cout<<"5. 查询绩点成绩\n";
	cout<<"6. 将学生信息保存为文件\n";
	cout<<"7. 退出\n";
	cout<<"请输入你所需操作所对应的数字：";
	cin>>operate;
	while (cin.fail())
	{
		cout<<"输入错误！请重新输入！\n";
		cin.clear();
		cin.ignore();
		cin>>operate;
	}
	return operate; 
	
}
Course* Console::selectCourse(int op){
	int a;	
	ifstream openfile;
	char c;
	switch (op)
	{
		case 1:
			{
				cout<<"你好！这里是必修课的列表：\n";
				for(int i=1;i<=ocNum;i++)
				{
                	cout<<i<<"."<<*oc[i-1];
            	}
            	cout<<"请输入你要选的必修课的编号:";
            	while(1)
            	{
            		try{
            			cin>>a;
            			if (a<=0||a>ocNum) throw MyException(RANGE_ERROR);
            			break;
					}catch(MyException et)
					{
						cout<<"系统异常："<<et.what()<<endl;
						cout<<"请输入正确的数字哦！\n";
					} 
				}
				return oc[a-1];
				break;
			}
		case 2:
			{
				cout<<"你好！这里是选修课的列表：\n";
				for(int i=1;i<=ecNum;i++)
				{
                	cout<<i<<"."<<*ec[i-1];
            	}
            	cout<<"请输入你要选的选修课的编号:";
            	while(1)
            	{
            		try{
            			cin>>a;
            			if (a<=0||a>ecNum) throw MyException(RANGE_ERROR);
            			break;
					}catch(MyException et)
					{
						cout<<"系统异常："<<et.what()<<endl;
						cout<<"请输入正确的数字哦！\n";
					} 
				}
				return ec[a-1];
				break;
			}
		default:
			{
				break;
			}
	}
	return NULL;
}
bool Console::setCourseScore(){
	int mark;
	char grade;
	for(int i=0;i<=student->getCourseNumber()-1;i++)
	{
		if(typeid(ObligatoryCourse)==typeid((*student)[i]))
		{
			cout<<"请输入必修课程 “"<<(*student)[i].getName()<<"”的成绩，在0~100的范围内：";
			while(1)
			{
				try{
					cin>>mark;
					if (mark<0||mark>100) throw MyException(SCORE_INVALID);
					break;
				}catch(MyException ex)
				{
					cout<<"系统异常："<<ex.what()<<endl;
					cout<<"错误！必修课程 “"<<(*student)[i].getName()<<"”的成绩在0~100的范围内，请重新输入：";
				}
			}
			dynamic_cast<ObligatoryCourse&>((*student)[i]).setMark(mark);
		}
		else if (typeid(ElectiveCourse)==typeid((*student)[i]))
		{
			cout<<"选修课程 “"<<(*student)[i].getName()<<"”的成绩，在A~E的范围内：";
			while(1)
			{
				try{
					cin>>grade;
					if (grade<'A'||grade>'E') throw MyException(SCORE_INVALID);
					break;
				}catch(MyException ex)
				{
					cout<<"系统异常："<<ex.what()<<endl;
					cout<<"错误！选修课程 “"<<(*student)[i].getName()<<"”的成绩在A~E的范围内，请重新输入：";
				}
			}
			dynamic_cast<ElectiveCourse&>((*student)[i]).setGrade(grade);
		}
		else
		{
			return false;
		}
	}
	return true;
}
Console::~Console()
{
	if (student!=NULL) delete student;
	for(int i=0;i<ecNum;i++)  
	{
		delete ec[i];
	}
	for(int i=0;i<ocNum;i++) 
	{
		delete oc[i];
	}
    
}
