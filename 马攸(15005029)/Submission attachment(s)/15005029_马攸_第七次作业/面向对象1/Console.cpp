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
	cout<<"                          ������ָ��\n";
	cout<<"                          1:ѡ���޿�\n";
	cout<<"                          2:ѡѡ�޿�\n";
	cout<<"                          3:�趨�ɼ�\n";
	cout<<"                          4:��ѯѡ�����\n";
	cout<<"                          5:��ѯ���ſγ̳ɼ�\n";
	cout<<"                          6:��ѯ����\n";
	cout<<"                          7:�����ļ�\n";
	cout<<"                          8:�˳�����\n";
	cout<<"********************************************************************\n";
	int n;
	cin>>n;
	while(cin.fail()||n>8||n<1)
	{
		cout<<"����������\n";
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
		cout<<"���"<<"  "<<"�γ���"<<"   "<<"ѧ��"<<"\n";
        cout<<" 1    "<<"�ߵ���ѧ"<<"  "<<4<<"\n";
		cout<<" 2    "<<"���Դ���"<<"  "<<5<<"\n";
		cout<<" 3    "<<"�������"<<"  "<<2<<"\n";
		cout<<" 4    "<<"���ݽṹ"<<"  "<<3<<"\n";
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
        		cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
        		cout<<"����������γ̱��"<<"\n";
   			}
		}
		return oc[bianhao1-1];
		
		
		
	}
	else if(i==2)
	{
		cout<<"���"<<"  "<<"�γ���"<<"   "<<"ѧ��"<<"\n";
		cout<<" 1    "<<"��Ϣ����"<<"  "<<1<<"\n";
		cout<<" 2    "<<"��ȫ����"<<"  "<<2<<"\n";
		cout<<" 3    "<<"��������"<<"  "<<3<<"\n";
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
        		cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
        		cout<<"����������γ̱��"<<"\n";
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
				cerr<<"�޷������ļ���\n";
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
	cout<<"����������"<<"\n"; 
	char name[20];
	int y,m,d;
	cin>>name;
	cout<<"����������"<<"\n";
	while(1)
	{
		try
		{
			cin>>y>>m>>d;
			student=new Student(name,y,m,d);
			break;
		}catch(MyException ex)
		{
        	cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
        	cout<<"����������ѧ������"<<"\n";
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
			cout<<"��������޿γ� "<<(*student)[i].getname()<<" �ĳɼ�(0~100֮��)��";
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
        			cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
        			cout<<"����ȷ������޿γ� "<<(*student)[i].getname()<<" �ĳɼ�(0~100֮��)��";
   				}
			}
		}
		else if(typeid(ElectiveCourse)==typeid((*student)[i]))
		{
			cout<<"������ѡ�޿γ� "<<(*student)[i].getname()<<" �ĳɼ�(A~E֮��)��";
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
        			cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
					cout<<"����ȷ����ѡ�޿γ� "<<(*student)[i].getname()<<" �ĳɼ�(A~E֮��)��";
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


	
