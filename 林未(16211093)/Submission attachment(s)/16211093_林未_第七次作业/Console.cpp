#include "Console.h"
#include "Student.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "DateException.h"
#include "StudentException.h"
#include "GradeException.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

Console::Console() : numberofOC(3), numberofEC(3)
{
	
}

bool Console::readSequentialFile(const char *fileName)
{
    ifstream inClientFile( fileName, ios::in );
    if ( !inClientFile )  return false;
    string courseName; int credit; int mark; char _mark;
    for(int i = 0; i < 3; i++)
    {
   		inClientFile >> courseName >> credit >> mark;
   		obligatoryCourse[i]	= new ObligatoryCourse(courseName, credit, mark);
    }
    for(int j = 0; j < 3; j++)
    {
   		inClientFile >> courseName >> credit >> _mark;
   		electiveCourse[j] = new ElectiveCourse(courseName, credit, _mark);
    }
    inClientFile.close();
    return true;
}
 
void Console::run()
{
	char studName[30];
	int studYear, studMonth, studDay, courseType = 0;
	cout << "请输入学生的姓名：";
	cin >> studName;
	Date lwDate;
	bool wrongDate = 1;
	while(wrongDate == 1)
	{
		try{
			cout << "\n请输入学生的生日（格式为 年 月 日）：";
			cin >> studYear >> studMonth >> studDay;
			lwDate.setDate(studYear, studMonth, studDay);
			wrongDate = 0;
		}catch(DateException &ex){
			cout << ex.what() << endl; 
		}		
	}

	Student LW(studName, lwDate);	
	readSequentialFile("course.txt");
	
	cout << "\n请输入想要执行的操作序号：" <<endl
		 << "--> 1 选择必修课程" <<endl
		 << "--> 2 选择选修课程" <<endl
		 << "--> 3 给已选择课程设定成绩" <<endl
		 << "--> 4 退选课程" <<endl
		 << "--> 5 查询课程积点成绩" <<endl
		 << "--> 6 将信息存储到文件中" <<endl
		 << "--> 0 退出菜单页并显示课程详情" <<endl;
	while(1)
	{
		cin >> courseType;
		if(cin.fail())
		{
			cout<<"序号输入非法，请重新输入！\n"<<endl;
	        cin.clear();
			cin.ignore();
			continue;
	    }
		if(courseType == 1)
		{
			printOC();
			int numofCourse;
			cout << "请输入你想要选择的必修课（按回车键确认，输入-1退出）：" << endl;
			
			while(cin >> numofCourse)
			{
				
				if(numofCourse == -1)
					break;
				else if(numofCourse > numberofOC || numofCourse <= 0) 
					cout << "没有这门课程，请重新选择！" <<endl;
				else
				{
					Course *str1 = obligatoryCourse[ numofCourse - 1 ];
					try{
						LW.addCourse(str1);
						cout << "选课成功！" <<endl;
					}catch(StudentException &ex){
						cout << ex.what() << endl; 
					}
										
				}				
			} 
		}
		else if(courseType == 2)
		{
			printEC();
			int numofCourse;
			cout << "请输入你想要选择的选修课（按回车键确认，输入-1退出）：" << endl;
			while(cin >> numofCourse)
			{
				if(numofCourse == -1)
					break;
				else if(numofCourse > numberofOC || numofCourse <= 0) 
					cout << "没有这门课程，请重新选择！" <<endl;
				else
				{
					Course *str2 = electiveCourse[ numofCourse - 1 ];
					try{
						LW.addCourse(str2);
						cout << "选课成功！" <<endl;
					}catch(StudentException &ex){
						cout << ex.what() << endl; 
					}		
				} 
			}
		}
		else if(courseType == 3)
		{
			if(!setCourseGrade(LW))
			{
				cout << "成绩设定失败！" <<endl;
			}
		}
		else if(courseType == 4)
		{
			cout << LW <<endl;
			int i = 0;
			while(i != -1)
			{
				cout << "请输入退选的课程序号（输入-1结束）：";
				cin >> i;
				if(i == -1) break; 
				
				try{
					LW.removeCourse(i);
					cout << "退选课成功！" <<endl;	
				}catch(StudentException &ex){
					cout << ex.what() << endl; 
				}	
				cout << LW <<endl;
			}
		}
		else if(courseType == 5)
		{
			double jidian = LW.calcCredit(); 
			cout << "您的绩点成绩为：" << jidian << endl;
		}	
		else if(courseType == 6)
		{
			ofstream outfile("information.txt", ios::out);
			if  (!outfile)
			{
				cerr << "无法创建文件！" << endl;
				exit(1);
			}
			outfile << LW;
			cout << "信息已存储到当前文件夹中的 information.txt 文件中！\n" << endl; 
			outfile.close();
		}	
		else if(courseType == 0)
		{
			cout << "您已退出菜单页，下面显示选课详情：\n" << endl;
			break;
		}
		else
		{
			cout << "序号超出范围，请重新输入！\n" << endl;
			continue;
		}
		cout << "\n请输入想要执行的操作序号：" <<endl
			 << "--> 1 选择必修课程" <<endl
			 << "--> 2 选择选修课程" <<endl
			 << "--> 3 给已选择课程设定成绩" <<endl
			 << "--> 4 退选课程" <<endl
			 << "--> 5 查询课程积点成绩" <<endl
			 << "--> 6 将信息存储到文件中" <<endl
			 << "--> 0 退出菜单页并显示课程详情" <<endl;
	}	
	cout << LW;
}

void Console::printOC()
{
	cout << "\n请从下列必修课程中选择一门课程（初始成绩为0）：" << endl;
	for(int i = 1; i <= numberofOC; i++)
	{
		cout << "（" << i << "） " << *obligatoryCourse[ i - 1 ] << endl;	
	}
}

void Console::printEC()
{
	cout << "\n请从下列选修课程中选择一门课程（初始成绩为55）：" << endl;
	for(int i = 1; i <= numberofEC; i++)
	{
		cout << "（" << i << "） " << *electiveCourse[ i - 1 ] <<endl;	
	}	
}

bool Console::setCourseGrade(Student &stud)
{
	int mark = 0;
	char grade = 'E';
	
	for(int i = 0; i < stud.getCourseNumber() ; i++ )
	{
		if(typeid(ObligatoryCourse) == typeid(*stud.courseList[i]))
		{
			bool wrongMark = 1;
			while(wrongMark == 1) 
			{
				try{
				cout << "请输入必修课程“" << (*stud.courseList[i]).getCourseName() << "”的成绩(0 ~ 100)：";
				cin >> mark;
				dynamic_cast <ObligatoryCourse &> (*stud.courseList[i]).setMark(mark);
				wrongMark = 0;				
				}catch(GradeException &ex){
					cout << ex.what() << endl; 
				}					
			}
		}
		else if(typeid(ElectiveCourse) == typeid(*stud.courseList[i])) 
		{
			bool wrongGrade = 1;
			while(wrongGrade == 1)
			{
				try{
					cout << "请输入选修课程“" << (*stud.courseList[i]).getCourseName() << "”的成绩(A ~ E)：";
					cin >> grade;
					dynamic_cast <ElectiveCourse &> (*stud.courseList[i]).setGrade(grade);
					wrongGrade = 0;					
				}catch(GradeException &ex){
					cout << ex.what() << endl; 
				}	
			}
		}
		else	return false;
	}
	return true;	
}

Console::~Console()
{
    for(int i = 0; i < numberofOC; i++)
	delete obligatoryCourse[i];
	for(int i = 0; i < numberofOC; i++)
	delete electiveCourse[i];	
}
