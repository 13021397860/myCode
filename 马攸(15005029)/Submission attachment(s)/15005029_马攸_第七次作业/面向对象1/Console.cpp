#include "Console.h"
#include "MyException.h"
#include<typeinfo>
#include<fstream>
#include<iomanip>
Console::Console()
{
	buildStudent();
	buildCourse();
}
int Console::displayMenu() const
{
	cout<<"********************************************************************\n";
	cout<<"                          请输入指令\n";
	cout<<"                          1:选必修课\n";
	cout<<"                          2:选选修课\n";
	cout<<"                          3:设定成绩\n";
	cout<<"                          4:查询选课情况\n";
	cout<<"                          5:查询各门课程成绩\n";
	cout<<"                          6:查询绩点\n";
	cout<<"                          7:存入文件\n";
	cout<<"                          8:退出程序\n";
	cout<<"********************************************************************\n";
	int n;
	cin>>n;
	while(cin.fail()||n>8||n<1)
	{
		cout<<"请重新输入\n";
		cin.clear();
		cin.ignore();
		cin>>n; 
	}
	return n;
}
Course* Console::selectCourse(int i)
{
	if(i==1)	
	{
		cout<<"编号"<<"  "<<"课程名"<<"   "<<"学分"<<"\n";
        cout<<" 1    "<<"高等数学"<<"  "<<4<<"\n";
		cout<<" 2    "<<"线性代数"<<"  "<<5<<"\n";
		cout<<" 3    "<<"程序设计"<<"  "<<2<<"\n";
		cout<<" 4    "<<"数据结构"<<"  "<<3<<"\n";
		int bianhao1;
		while(1)
		{
			try
			{
				cin>>bianhao1;
				if(bianhao1<=0||bianhao1>ocNum)
				{
					throw MyException(RANGE_ERROR);
				}
				break;
			}catch(MyException ex)
			{
        		cout<<"系统异常："<<ex.what()<<"\n";
        		cout<<"请重新输入课程编号"<<"\n";
   			}
		}
		return oc[bianhao1-1];
		
		
		
	}
	else if(i==2)
	{
		cout<<"编号"<<"  "<<"课程名"<<"   "<<"学分"<<"\n";
		cout<<" 1    "<<"信息检索"<<"  "<<1<<"\n";
		cout<<" 2    "<<"安全教育"<<"  "<<2<<"\n";
		cout<<" 3    "<<"军事理论"<<"  "<<3<<"\n";
		int bianhao2;
		while(1)
		{
			try
			{
				cin>>bianhao2;
				if(bianhao2<=0||bianhao2>ecNum)
				{
					throw MyException(RANGE_ERROR);
				}
				break;
			}catch(MyException ex)
			{
        		cout<<"系统异常："<<ex.what()<<"\n";
        		cout<<"请重新输入课程编号"<<"\n";
   			}
		}
		return ec[bianhao2-1];
	}
}
int Console::run()
{
	int m,flag=1;
	while(flag==1)
	{
		m=displayMenu();
		if(m==1)
		{
			student->addCourse(selectCourse(1));
		}
		else if(m==2)
		{
			student->addCourse(selectCourse(2));
		}
		else if(m==3)
		{
			setCourseScore();
		}
		else if(m==4)
		{
			cout<<*student;
		}
		else if(m==5)
		{
			printScore();
		}
		else if(m==6)
		{
			printCalcCredit();
		}
		else if(m==7)
		{
			char fileName[]=".\\data\\StudentInformation.txt";
			ofstream *ofile;
			ofile=new ofstream(fileName);
			if(!ofile)
			{
				cerr<<"无法创建文件！\n";
				break;
			}
			(*ofile)<<*student;
			ofile->close();
			delete ofile;
		}
		else if(m==8)
		{
			flag=2;
		}	
	}
	return 1;
}
	
Console& Console::buildStudent()
{
	cout<<"请输入姓名"<<"\n"; 
	char name[20];
	int y,m,d;
	cin>>name;
	cout<<"请输入生日"<<"\n";
	while(1)
	{
		try
		{
			cin>>y>>m>>d;
			student=new Student(name,y,m,d);
			break;
		}catch(MyException ex)
		{
        	cout<<"系统异常："<<ex.what()<<"\n";
        	cout<<"请重新输入学生生日"<<"\n";
   		}
	}
	return *this;
}
Console& Console::buildCourse()
{
	char fileName[]=".\\data\\CourseList.txt";
	ifstream ifile(fileName);
	int catalog,credit;
	string cname;
	ocNum=ecNum=0;
	if(!ifile)
	{
		return *this;
	}
	while(ifile>>catalog>>cname>>credit)
	{
		if(catalog==1)
		{
			oc[ocNum++]=new ObligatoryCourse(cname,credit);
		}
		else if(catalog==2)
		{
			ec[ecNum++]=new ElectiveCourse(cname,credit);
		}
	}
	ifile.close();	
} 
bool Console::setCourseScore()
{
	int a;
	char b;
	for(int i=0;i<=student->getCourseNumber()-1;i++)
	{
		if(typeid(ObligatoryCourse)==typeid((*student)[i]))
		{
			cout<<"请输入必修课程 "<<(*student)[i].getname()<<" 的成绩(0~100之间)：";
			while(1)
			{
				try
				{
					cin>>a;
					if(false==(dynamic_cast<ObligatoryCourse&>((*student)[i]).setMark(a)))
					{
						throw MyException(SCORE_INVALID);
					}
					break;
				}catch(MyException ex)
				{
        			cout<<"系统异常："<<ex.what()<<"\n";
        			cout<<"请正确输入必修课程 "<<(*student)[i].getname()<<" 的成绩(0~100之间)：";
   				}
			}
		}
		else if(typeid(ElectiveCourse)==typeid((*student)[i]))
		{
			cout<<"请输入选修课程 "<<(*student)[i].getname()<<" 的成绩(A~E之间)：";
			while(1)
			{
				try
				{
					cin>>b;
					if(false==(dynamic_cast<ElectiveCourse&>((*student)[i]).setGrade(b)))
					{
						throw MyException(SCORE_INVALID);
					}
					break;
				}catch(MyException ex)
				{
        			cout<<"系统异常："<<ex.what()<<"\n";
					cout<<"请正确输入选修课程 "<<(*student)[i].getname()<<" 的成绩(A~E之间)：";
   				}
			}	
		}
		else
		{
			return false;
		}
	}
	return true;
}
void Console::printScore()
{
	for(int i=0;i<=student->getCourseNumber()-1;i++)
	{
		cout<<(*student)[i];
	}
}
void Console::printCalcCredit()
{
	double sum;
	sum=student->getCalcCredit();
	cout<<fixed<<setprecision(3)<<sum<<endl;
}
Console::~Console()
{
	if(student!=NULL) 
	{
		delete student;
	}
	int i;
    for(i=0;i<ocNum;i++)
    {
    	delete oc[i];
	}
	for(i=0;i<ecNum;i++) 
	{
		delete ec[i];
	}
}


	
