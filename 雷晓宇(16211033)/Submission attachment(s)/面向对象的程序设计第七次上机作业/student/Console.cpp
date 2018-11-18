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
	            	cout<<"��ļ���ɼ�Ϊ��"<<fixed<<setprecision(4)<<student->calcCredit()<<endl;  
	            	break;
				}
			case 6: 
	            {
	            	ofile=new ofstream(fileName);
	            	if (!ofile)
	            	{
	            		cerr<<"�ļ�����ʧ�ܣ�\n";
						break; 
					}
					(*ofile)<<*student;
					ofile->close();
					delete ofile; 
					cout<<"�ļ������ɹ���\n";
	            	break;
				}
			case 7: 
                {
                	break;
				}
			default:
				{
					cout<<"��������ȷ������Ŷ��\n"; 
					break;
				}
        }
        choice=displayMenu();
	}
}
Console& Console::buildStudent(){
	char* n=new char[21];
	int y,m,d;
	cout<<"��������������\n"; 
	cin>>n;
	cout<<"�������������գ���2017 4 18\n";
	while(1)
	{
		try{
			cin>>y>>m>>d;
			student=new Student(n,y,m,d);
			break;
		}catch(MyException ex)
		{
			cout<<"ϵͳ�쳣��"<<ex.what()<<endl;
			cout<<"������������������"; 
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
	//oc[0]=new ObligatoryCourse("�ߵ���ѧ",4);
	//oc[1]=new ObligatoryCourse("���Դ���",5);
	//oc[2]=new ObligatoryCourse("���ƴ�ѧ����",2);
	//ec[0]=new ElectiveCourse("��ѧ����ȫ֪ʶ����",1);
	//ec[1]=new ElectiveCourse("��ѧ������ѧ",2);
	
}
int Console::displayMenu() const{
	int operate;
	cout<<"��ã�������"<<student->getBirthdate().getYear()<<"��"<<student->getBirthdate().getMonth()<<"��"<<student->getBirthdate().getDay()<<"�յ�"<<student->getName()<<"ͬѧ�����������˵����������Ӧ����ѡ�������\n";
	cout<<"1. ѡ����޿γ�\n";
	cout<<"2. ѡ��ѡ�޿γ�\n";
	cout<<"3. �鿴���ѡ�����\n";
	cout<<"4. ���ÿγ̳ɼ�\n";
	cout<<"5. ��ѯ����ɼ�\n";
	cout<<"6. ��ѧ����Ϣ����Ϊ�ļ�\n";
	cout<<"7. �˳�\n";
	cout<<"�������������������Ӧ�����֣�";
	cin>>operate;
	while (cin.fail())
	{
		cout<<"����������������룡\n";
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
				cout<<"��ã������Ǳ��޿ε��б�\n";
				for(int i=1;i<=ocNum;i++)
				{
                	cout<<i<<"."<<*oc[i-1];
            	}
            	cout<<"��������Ҫѡ�ı��޿εı��:";
            	while(1)
            	{
            		try{
            			cin>>a;
            			if (a<=0||a>ocNum) throw MyException(RANGE_ERROR);
            			break;
					}catch(MyException et)
					{
						cout<<"ϵͳ�쳣��"<<et.what()<<endl;
						cout<<"��������ȷ������Ŷ��\n";
					} 
				}
				return oc[a-1];
				break;
			}
		case 2:
			{
				cout<<"��ã�������ѡ�޿ε��б�\n";
				for(int i=1;i<=ecNum;i++)
				{
                	cout<<i<<"."<<*ec[i-1];
            	}
            	cout<<"��������Ҫѡ��ѡ�޿εı��:";
            	while(1)
            	{
            		try{
            			cin>>a;
            			if (a<=0||a>ecNum) throw MyException(RANGE_ERROR);
            			break;
					}catch(MyException et)
					{
						cout<<"ϵͳ�쳣��"<<et.what()<<endl;
						cout<<"��������ȷ������Ŷ��\n";
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
			cout<<"��������޿γ� ��"<<(*student)[i].getName()<<"���ĳɼ�����0~100�ķ�Χ�ڣ�";
			while(1)
			{
				try{
					cin>>mark;
					if (mark<0||mark>100) throw MyException(SCORE_INVALID);
					break;
				}catch(MyException ex)
				{
					cout<<"ϵͳ�쳣��"<<ex.what()<<endl;
					cout<<"���󣡱��޿γ� ��"<<(*student)[i].getName()<<"���ĳɼ���0~100�ķ�Χ�ڣ����������룺";
				}
			}
			dynamic_cast<ObligatoryCourse&>((*student)[i]).setMark(mark);
		}
		else if (typeid(ElectiveCourse)==typeid((*student)[i]))
		{
			cout<<"ѡ�޿γ� ��"<<(*student)[i].getName()<<"���ĳɼ�����A~E�ķ�Χ�ڣ�";
			while(1)
			{
				try{
					cin>>grade;
					if (grade<'A'||grade>'E') throw MyException(SCORE_INVALID);
					break;
				}catch(MyException ex)
				{
					cout<<"ϵͳ�쳣��"<<ex.what()<<endl;
					cout<<"����ѡ�޿γ� ��"<<(*student)[i].getName()<<"���ĳɼ���A~E�ķ�Χ�ڣ����������룺";
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
