#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Console.h"
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#define MAX_SIZE 3
Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}
int Console::displaycaidan()const
{
	cout<<"~WTF~WTF学生选课系统-主菜单~WTF~WTF~WTF~WTF~\n";
    cout<<"\t1. 选必修课程\n";
    cout<<"\t2. 选选修课程\n";
    cout<<"\t3. 查看您已经选择的课程名称、学分、成绩（若未设置默认为0）等\n";
    cout<<"\t4. 退选课程\n";
    cout<<"\t5. 设置课程的成绩\n";
    cout<<"\t6. 查看学分绩点成绩\n";
    cout<<"\t7. 将学生信息和课程相关的信息储存到文件中\n";
    cout<<"\t0. 退出系统\n";
    cout<<"please choose from 0-7:";
    int choice=0;
	cin>>choice;
	/*while (choice < 0 || choice > 7)   {
      cout << "\nInvalid choice, please try again:";
      cin >> choice;
      if (cin.fail()){
         cin.clear();		//清除错误标记
	      cin.ignore();	//移除错误字符
      };

   }*///这一段代码问题因为没有提前判断cin.fail()所以输入字母就直接退出了
    while(cin.fail() || choice<0 || choice>7)//cin.fail()放在前面效率更高
    {
        cout<<"Invalid input, please re-enter\n";
        cin.clear();//清除错误标记
        cin.ignore(1314, '\n');//移除错误字符,以换行符结束
        cin>>choice;
    }
	return choice;
}
int Console::selectCourse(Course* course[], int Num)
{
	cout<<"please choose from following courses:\n";
	int i, choice=-1;
	while((choice>Num)||(choice<1))
    {
		for(i=0;i<Num;i++){
			cout<<"\t"<<i+1<<".";
			cout<<(*course[i]).getcoursename()<<" credit :"<<(*course[i]).getcreditHour()<<"\n";
		}
		cout<<"\tif you want cancel this selection, please input 0\n";
		cout<<"you chose :";
		cin>>choice;
		while(cin.fail() || choice<1 || choice>Num)//cin.fail()放在前面效率更高
    {
        cout<<"Invalid input, please re-enter\n";
        cin.clear();//清除错误标记
        cin.ignore(1314, '\n');//移除错误字符,以换行符结束
        cout<<"you chose :";
        cin>>choice;
    }
	}
	return choice;
}

Console& Console::buildStudent()
{
    (*student).setcourseNumber();
    cout<<"please input your name :";
    char *sname = new char[100];
    cin>>sname;
    (*student).setname(sname);
    delete[] sname;
    cout<<"\nplease input your birth-date(example:1024 5 23):";
    while(1)
    {

        try
        {
            int y,m,d;
            cin>>y>>m>>d;
            (*student).setbirthDate(y,m,d);
            break;
        }
        catch(MyException ex)
        {
            cout<<"输入异常："<<ex.errinfo()<<"\n";
            cout<<"请重新输入学生生日：";
        }
    }
    return (*this);
}
/*Console& Console::buildCourse()
{
     ocnum=3;
    //必修课总数
    ecnum=2;
    //选修课总数
    //但学生可选课程数目总共为3门
    ocke[0]=new ObligatoryCourse("Object-oriented program",3);
    ocke[1]=new ObligatoryCourse("Data structure",3);
    ocke[2]=new ObligatoryCourse("Advanced mathematics",2);
    ecke[0]=new ElectiveCourse("Information retrieval",1);
    ecke[1]=new ElectiveCourse("Website analysis",2);
    return (*this);
}*/

void Console::buildCourse()
{
     ocnum=3;
    //必修课总数
    ecnum=2;
    //选修课总数
	string s;int xuefen;
	int i,j;
	i=0;j=0;
	ifstream infile;
	infile.open("ObligatoryCourse.txt");
	if(!infile.is_open())
    {
        cout<<"the ObligatoryCourse information is empty"<<endl;
    }
	else
	{
	    while(infile>>s>>xuefen)
        {

                ocke[i]=new ObligatoryCourse(s,xuefen);
                i++;
            //addEC(ElectiveCourse(s,point));
            //cout<<s<<" "<<xuefen<<"\n";
        }
	}
	infile.close();
	infile.open("ElectiveCourse.txt");
	if(!infile.is_open())
    {
        cout<<"the ElectiveCourse information is empty"<<endl;
    }
	else
	{
		while(infile>>s>>xuefen)
        {
                ecke[j]=new ElectiveCourse(s,xuefen);
                j++;
            //addEC(ElectiveCourse(s,point));
            //cout<<s<<" "<<xuefen<<"\n";
        }
	}
	infile.close();
}
void Console::run()
{
    buildCourse();  //构造所有的可选课程对象
    buildStudent(); //构造学生对象
   cout<<"welcome!\n";
   cout<<"Please do not choose the same course again!\n";
    int menuchoice=displaycaidan();
    bool flag=true;//用来判断用户是否进行了将学生信息和课程信息储存到文件中的操作
    while(menuchoice)
    {
        if(menuchoice == 1)
        {
            int ocselect=selectCourse(ocke,ocnum);
            if(ocselect)
            {
                //两种方式，第二种比较简单
                if((*student).getcourseNumber() < MAX_SIZE)
                {
                    (*student).addcourse(ocke[ocselect-1]);
                    cout<<"Select successfully! \n";
                }
                else
                {
                    cout<<"Full,Select failed\n";
                }
            }
        }
        else if(menuchoice == 2)
        {
             int ecselect=selectCourse(ecke,ecnum);
             if(ecselect)
             {
                 //两种方式，第二种比较简单
                 if((*student).getcourseNumber() < MAX_SIZE)
                {
                    (*student).addcourse(ecke[ecselect-1]);
                   cout<<"Select successfully! \n";
                }
                else
                {
                    cout<<"Full,Select failed\n";
                }
             }
        }
        else if(menuchoice == 3)
        {
                 cout<<(*student)<<"\n";
        }
        else if(menuchoice == 4)
        {
            cout<<"please check your course list to make choice:\n";
            cout<<"please input the number of withdraw course(range from 1-3 ):\n";
             while(1)
            {

                try
                {
                    int tuinum;
                    cin>>tuinum;
                    (*student).removeCourse(tuinum-1);
                    break;
                }
                catch(MyException ex)
                {
                    cout<<"输入异常："<<ex.errinfo()<<"\n";
                    cout<<"请重新输入序号：";
                }
            }
        }
        else if(menuchoice == 5)
        {
            cout<<"please check your course list to make choice:\n";
            cout<<(*student)<<"\n";
            cout<<"please input the choice of course:";
            while(1)
            {

                try
                {
                       int di;
                       cin>>di;
                       if((*student).setCourseScore(di))
                       {
                           cout<<"set succeed!\n";
                       }
                       else
                       {
                            cout<<"set failed!\n";
                       }
                    break;
                }
                catch(MyException ex)
                {
                    cout<<"输入异常："<<ex.errinfo()<<"\n";
                    cout<<"请重新输入序号：";
                }
            }
        }
         else if(menuchoice == 6)
        {
            cout<<"please make sure the score is set\n";
            cout<<"your calcCredit is :";
            double ans=student->calcCredit();
            cout<<ans<<"\n";
        }
        else if(menuchoice == 7)
        {
            ofstream outfile("student.txt",ios::app);//如果文本文档里面已经有信息了，则会追加到里面
	        outfile<<(*student);
	        cout<<"Mission success!\n";
	        flag=false;
        }
        cout<<"please choose what you want again!\n";
        menuchoice=displaycaidan();
    }
    if(flag)
    {
        ofstream outfile("student.txt",ios::app);
        outfile<<(*student);
        cout<<"The student information has been saved to the file student.txt when you exit!\n";
    }
    cout<<"Thank you for using the student elective system and expect the next meeting with you!\n";
}
