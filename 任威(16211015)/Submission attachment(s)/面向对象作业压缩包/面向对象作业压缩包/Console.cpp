#include "Console.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include "MyException.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;

Console::Console()
{
    //ctor
    ocNum=0;
    ecNum=0;
}

Console::~Console()
{
    //dtor
    if(student!=NULL) delete student;//释放学生信息

    int i;
    for(i=0;i<ocNum;i++)
		delete oc[i];//释放所有的必修课程
	for(i=0;i<ecNum;i++)
		delete ec[i];//释放所有的选修课程
}


int Console::run()
{
    char fileName[256];
    ofstream *ofile;

    buildCourse();  //构造所有的可选课程对象
    buildStudent(); //构造学生对象

    int choice=displayMenu();
    while (choice!=0)
    {
        switch (choice)
        {
            case 1: //选必修课
            case 2: //选选修课
                student->addCourse(selectCourse(choice));
                break;
            case 3: //输出学生选课信息（暂时不包括成绩）
                cout<<*student;
                break;
            case 4: //设置学生成绩
                setCourseScore();
                break;
            case 5:
				cout<<"Please input the file's name ：";
				cin>>fileName;
				ofile=new ofstream("filename");
				if(!ofile){
					cerr<<"Built the file wrong ！\n";
					break;
				}
				(*ofile)<<*student;
				ofile->close();
				delete ofile;
				break;
        }
        choice=displayMenu();
    }

    return 0;
}

int Console::displayMenu() const
{
	int choice=0;
	cout<<"**********学生选课系统-主菜单**********\n"
		<<"\t1. 选必修课程\n"
		<<"\t2. 选选修课程\n"
		<<"\t3. 查看选课情况\n"
		<<"\t4. 设置课程成绩\n"
		<<"\t5. 保存课程成绩\n"
		<<"\t0. 退出系统\n"
		<<"the input must between 0 and 5：";
	cin>>choice;
	while (cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Wrong input ,Please input again from 0 to 5：";
        cin>>choice;
	}
    while(choice<0 || choice>5)
    {
        cout<<"the choice musr between 0 to 5, input again ：";
        cin>>choice;
        while (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Wrong input,please input again ：";
            cin>>choice;
        }
    }
	return choice;
}

Course* Console::selectCourse(int op)
{
    int i, choice=-1;
    switch(op)
    {
        case 1: //选必修课
            cout<<"Choosing one course from the following:\n";
            while((choice>ocNum)||(choice<0)){
                for(i=0;i<ocNum;i++){
                    cout<<"\t"<<i+1<<"."<<*oc[i];
                }
                cout<<"\t0.cancel choice\n";
                cout<<"the ObligatoryCourses you have choice are ：";
                cin>>choice;
            }
            if (choice!=0) return oc[choice-1];
            break;
        case 2: //选选修课
            cout<<"Choosing one course from the following ElectiveCourse:\n";
            while((choice>ecNum)||(choice<0)){
                for(i=0;i<ecNum;i++){
                    cout<<"\t"<<i+1<<"."<<*ec[i];
                }
                cout<<"\t0.Cancel choice\n";
                cout<<"the ElectiveCourse you have choice are ：";
                cin>>choice;
            }
            if (choice!=0) return ec[choice-1];
            break;
    }
    return NULL;
}

bool Console::setCourseScore()
{
	int mark=0;
	char grade='\0';
	for(int i=0;i<student->getCourseNumber();i++){
		if(typeid(ObligatoryCourse)==typeid((*student)[i])){//利用RTTI,判断是不是必修课
			cout<<"ObligatoryCourse“"<<(*student)[i].getName()<<"”grade(0-100)：";
			cin>>mark;
			/*while (!dynamic_cast<ObligatoryCourse &>((*student)[i]).setMark(mark)){
				cout<<"格式错误，必修课程“"<<(*student)[i].getName()<<"”的成绩(0-100)：";
				cin>>mark;
			}*/
			while(1){//采用异常处理处理成绩格式错误
                try
                {
                    dynamic_cast<ObligatoryCourse &>((*student)[i]).setMark(mark);
                    break;
                }catch(MyException ex)
                {
                    cout<<"Wrong inout，ObligatoryCourse“"<<(*student)[i].getName()<<"”grade(0-100)：";
                    cin>>mark;
                }
			}
		}else if (typeid(ElectiveCourse)==typeid((*student)[i])){//利用RTTI,判断是不是选修课
			cout<<"ElectiveCourse“"<<(*student)[i].getName()<<"”grade(A-E)：";
			cin>>grade;
			/*while (!dynamic_cast<ElectiveCourse &>((*student)[i]).setGrade(grade)){
				cout<<"格式错误，选修课程“"<<(*student)[i].getName()<<"”的成绩(A-E)：";
				cin>>grade;
			}*/
			while(1){//采用异常处理处理成绩格式错误
                try
                {
                    dynamic_cast<ElectiveCourse &>((*student)[i]).setGrade(grade);
                    break;
                }catch(MyException ex)
                {
                    cout<<"Wrong inout，ElectiveCourse“"<<(*student)[i].getName()<<"”grade(A-E)：";
                    cin>>mark;dynamic_cast<ElectiveCourse &>((*student)[i]).setGrade(grade);
                    break;
                }
			}

		}else{
			return false;
		}
	}
	return true;
}

Console& Console::buildStudent()
{
    char name[50];
	Date birthDate;

	cout<<"Please input the student's name: ";
	cin>>name;
	cout<<"Please input the student's birthday";
	while(1)
    {
        try{
            cin>>birthDate;
            break;
        }catch(MyException ex)
        {
            cout<<"Wrong input！："<<ex.what()<<"\n";
            cout<<"Please input again";
        }
    }

	student=new Student(name, birthDate);
	return *this;
}

Console& Console::buildCourse()
{
    char fileName[]=".\\data\\CourseList.dat";
	ifstream ifile(fileName);
	int catalog, credit;
	string cname;
	ocNum=ecNum=0;
	if (!ifile){
		return *this;
	}
	while(ifile>>catalog>>cname>>credit){
		switch (catalog){
		case 1:
			oc[ocNum++]=new ObligatoryCourse(cname, credit);
			break;
		case 2:
			ec[ecNum++]=new ElectiveCourse(cname, credit);
			break;
		}
	}
	ifile.close();

	return *this;
}
