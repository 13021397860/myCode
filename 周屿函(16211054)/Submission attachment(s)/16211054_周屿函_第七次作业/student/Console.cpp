#include<iostream>
#include<stdlib.h>
#include<typeinfo>
#include<fstream>
#include"Exception.h"
#include"date.h"
#include"Course.h"
#include"Student.h"
#include"Console.h"
#define Max_Size 10
using namespace std;

Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

Console& Console::buildStudent()
{
    char name[20];
    int year,month,day;
    cout<<"Please write the student's name"<<endl;
    cin>>name;
    cout<<"Please write the student's birth year month day"<<endl;
    cin>>year>>month>>day;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(1024,'\n');
        cout<<"Wrong Input! Please write again!"<<endl;
        cin>>year>>month>>day;
    }
    while(1)
    {
        try
        {
            Student test(name,year,month,day);
            student=test;
            break;
        }
        catch(Exception ex)
        {
            cout<<"Error: "<<ex.what()
            <<"  Please write again!"<<endl;
            cin>>year>>month>>day;
        }
    }
    return (*this);
}
Console& Console::buildCourse()
{
    char fileName[]=".\\data\\CourseList.txt";
	ifstream ifile(fileName);
	int type,credit;
	string cname;
	ocNum=ecNum=0;
	if (!ifile)
    {
		return *this;
	}
    while(ifile>>type>>cname>>credit)
    {
        switch (type)
        {
        case 1:
            oc[ocNum++]=new ObligatoryCourse(cname,credit,0);
            break;
        case 2:
            ec[ecNum++]=new Elective(cname,credit,'F');
            break;
        }
	}
	ifile.close();
    for(int i=0;i<ocNum;i++)
        oc[i]->setHaveMark(0);
    for(int i=0;i<ecNum;i++)
        ec[i]->setHaveMark(0);
    return (*this);
}
Course* Console::selectCourse(int op)
{
	int i,num,choice=-1;
	op==1?num=ocNum:num=ecNum;
    cout<<"--------------Please choose---------------\n";
    for(i=0;i<num;i++)
    {
        cout<<i+1<<".";
        op==1?cout<<*oc[i]:cout<<*ec[i];
    }
    cout<<"Your choose is:";
    cin>>choice;
    while(cin.fail()||choice>num||choice<1)
    {
        cin.clear();
        cin.ignore(1024,'\n');
        cout<<"Wrong Input! Please write again!"<<endl;
        cin>>choice;
    }
	return op==1?oc[choice-1]:ec[choice-1];
}
void Console::removeC()
{
    int choice;
    student.printCourseList();
    cout<<"--------------Please choose---------------\n";
    cin>>choice;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(1024,'\n');
        cout<<"Wrong Input! Please write again!"<<endl;
        cin>>choice;
    }
    while(1)
    {
        try
        {
            student.removeCourse(choice-1);
            break;
        }
        catch(Exception ex)
        {
            cout<<"Error: "<<ex.what()
            <<"  Please write again!"<<endl;
            cin>>choice;
        }
    }
}
bool Console::setCourseScore()
{
    int choice,mark;
    char grade;
    cout<<student;
    cout<<"--------------Please choose---------------\n";
    student.printCourseList();
    cout<<"Your choice is:\n";
    cin>>choice;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(1024,'\n');
        cout<<"Wrong Input! Please write again!"<<endl;
        cin>>choice;
    }
    if(choice>student.getCourseNumber())
        return false;
    if(typeid(ObligatoryCourse&)==typeid(*(student.courseList[choice-1])))
    {
        cout<<"The mark is:\n";
        cin>>mark;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(1024,'\n');
            cout<<"Wrong Input! Please write again!"<<endl;
            cin>>mark;
        }
        while(1)
        {
            try
            {
                dynamic_cast<ObligatoryCourse*>(student.courseList[choice-1])->setScore(mark);
                break;
            }
            catch(Exception ex)
            {
                cout<<"Error: "<<ex.what()
                <<"  Please write again!"<<endl;
                cin>>mark;
            }
        }
        dynamic_cast<ObligatoryCourse*>(student.courseList[choice-1])->setHaveMark(1);
        return true;
    }
    else if(typeid(Elective&)==typeid(*(student.courseList[choice-1])))
    {
        cout<<"The grade is:\n";
        cin>>grade;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(1024,'\n');
            cout<<"Wrong Input! Please write again!"<<endl;
            cin>>grade;
        }
        while(1)
        {
            try
            {
                dynamic_cast<Elective*>(student.courseList[choice-1])->setGrade(grade);
                break;
            }
            catch(Exception ex)
            {
                cout<<"Error: "<<ex.what()
                <<"  Please write again!"<<endl;
                cin>>mark;
            }
        }
        dynamic_cast<Elective*>(student.courseList[choice-1])->setHaveMark(1);
        return true;
    }
    return false;
}
int Console::displayMenu()const
{
    int temp;
    cout<<"--------------Please choose your action--------------"
        <<"\n1.choose Obligatory Course"
        <<"\n2.choose Elective Course"
        <<"\n3.remove Course"
        <<"\n4.write choosing results"
        <<"\n5.write grades"
        <<"\n0.quit\n";
    cin>>temp;
    while(cin.fail()||temp>5||temp<0)
    {
        cin.clear();
        cin.ignore(1024,'\n');
        cout<<"Wrong Input! Please write again!"<<endl;
        cin>>temp;
    }

    return temp;
}
int Console::run()
{
    buildStudent(); //构造学生对象
    buildCourse();  //构造所有的可选课程对象
    int choice=displayMenu();
    while (choice!=0)
    {
        switch (choice)
        {
            case 1: //选必修课
            case 2: //选选修课
                student.addCourse(selectCourse(choice));
                break;
            case 3:
                removeC();
                break;
            case 4:
                {
                    ofstream ofile;
                    ofile.open(".\\data\\Student.txt");
                    if(!ofile)
                    {
                        cerr<<"Can't create file!\n";
                        break;
                    }
                    ofile<<student<<endl;
                    ofile.close();
                    break;
                }
            case 5:
                setCourseScore();
                break;
            default:
                cout<<"Unvaliable!"<<endl;
                break;
        }
        choice=displayMenu();
    }
    return 0;
}

