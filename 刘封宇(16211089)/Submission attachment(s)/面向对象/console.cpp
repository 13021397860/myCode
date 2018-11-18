#include "console.h"
#include "student.h"
#include "obligatoryCourse.h"
#include "electiveCourse.h"
#include "dateException.h"
#include "courseException.h"
#include "arrException.h"
#include "date.h"
#include <typeinfo>
#include <iostream>
#include <fstream>
#define maxnum 3
using namespace std;
Console::Console(){;} 
 
void Console::setCourseGrade(Student &stud)
{
	CourseException ce; //---------3 
	int mark = 0;
	char grade[10] ;
	grade[0] = 'E' ;
	 
	for(int i = 0; i < stud.getcourseNumber() ; i++ )
	{
		if(typeid(ObligatoryCourse) == typeid(*(stud.courseList[i])))
		{
			cout << "\n��������޿γ̡�" << (*(stud.courseList[i])).getCourseName() << "���ĳɼ�(0 ~ 100)��";
			while(1)
			{
				cin >> mark;
				if (cin.fail())
				{
         		cin.clear();
				cin.ignore();
				mark=-1;
      			}
				if(ce.CourseExceptionCheck(mark))
				{
					cout<<"\n���óɼ��ɹ���"<<endl; 
					dynamic_cast <ObligatoryCourse &> (*(stud.courseList[i])).setMark(mark);
					break;
				}
			}
			
		}
		else if (typeid(ElectiveCourse) == typeid(*(stud.courseList[i]))) 
		{
			cout << "\n������ѡ�޿γ̡�" << (*(stud.courseList[i])).getCourseName() << "���ĳɼ�(A ~ E)��";
			while(1)
			{
				cin >> grade;
				if(ce.CourseExceptionCheck(grade[0]))
				{
					cout<<"\n���óɼ��ɹ���"<<endl;
					dynamic_cast <ElectiveCourse &> (*(stud.courseList[i])).setGrade(grade[0]);
					break;
				}
			}
			
		}
	}	
}

int Console::run()
{
	char Name[99];
	int Year, Month, Day,courseType,num,number;
	
	DateException de;//-------1
	
	cout << "����������: ";
	cin >> Name;
	cout << "\n����������: ";
	while(cin >> Year >>Month >>Day)
	{
		if(de.DateExceptionCheck(Year,Month,Day))
		break;
	}
	Date date(Year, Month, Day);
	
	cout << "\n���� ++ �����: "<<endl;
	cout<<date<<endl;
	cout<<date++<<endl;
	cout<<++date<<endl;
	
	Student Test(Name, Year, Month, Day);
	
	ifstream file("course.txt", ios::in);
	if(!file)
	{
		cerr<<"error"<<endl;
	}
	char a[20],b[20],c[20],d[20];
   	file.getline(a,20,'\n');
   	file.getline(b,20,'\n');
	file.getline(c,20,'\n');
	file.getline(d,20,'\n');
	file.close();
	
	ArrException ae;//--------2
 
	bool numobl[maxnum];
	bool numele[maxnum];
	for(int i=0;i<maxnum;i++)
	{
		numobl[i]=1;
		numele[i]=1;
	}
	
	obligatoryCourse[1]	= new ObligatoryCourse(a, 1, 0);
	obligatoryCourse[2]	= new ObligatoryCourse(b, 2, 0);
	electiveCourse[1] = new ElectiveCourse(c, 3, 'E');
	electiveCourse[2] = new ElectiveCourse(d, 4, 'E');
		 
	while(1)
	{
		cout << "\n��ѡ��: " <<endl
		 << "1-------ѡ��" <<endl
		 << "2-------�˿�" <<endl
		 << "3-------���óɼ�" <<endl 
		 << "4-------�鿴����" <<endl
		 << "5-------��ӡ��Ϣ" <<endl 
		 << "0-------�˳�" <<endl;
		cin >> number;
		if (cin.fail())
		{
         	cin.clear();
			cin.ignore();
			number=-1;
      	}  
		if(number==0)
		{
			break;
		}
			
		if(ae.ArrExceptionCheck(number,5,1))
		{
			if(number==1)
			{
				while(1)
			{
				cout << "\n��ѡ��: " <<endl
			 	<< "1-------���޿�" <<endl
			 	<< "2-------ѡ�޿�" <<endl
			 	<< "0-------�˳�" <<endl;
				 cin>>courseType;
				 if (cin.fail())
				{
         			cin.clear();
					cin.ignore();
					courseType = -1; 
      			}
      			if(courseType==0)
				{
					break;
				}
      			
      			
      			else if(ae.ArrExceptionCheck(courseType,2,1))
      			{
				  if(courseType == 1)
				{
					cout << "\n����������Ҫѡ��ı��޿Σ�" << endl;
					if(numobl[1])
					cout <<"1."<< a <<endl;
					if(numobl[2])
					cout <<"2."<< b <<endl; 
					cin>> num;
					if(ae.ArrExceptionCheck(num,maxnum-1,numobl[num]))
					{
						numobl[num]=0;
						Course *str1 = obligatoryCourse[num];
						Test.addCourse(str1);
						cout << "\nѡ�γɹ���" <<endl;
					}
					
				}
					else if(courseType==2)
				{
					cout << "\n����������Ҫѡ���ѡ�޿Σ�" << endl;
					if(numele[1])
					cout <<"1."<< c <<endl;
					if(numele[2])
					cout <<"2."<< d <<endl;
					cin>> num;
					if(ae.ArrExceptionCheck(num,maxnum-1,numobl[num]))
					{
						numele[num]=0;
						Course *str2 = electiveCourse[ num ];
						Test.addCourse(str2);
						cout << "\nѡ�γɹ���" <<endl;
					} 
				}
				} 
				
			}
			
			
			
		}
		else if(number==2)
		{
			while(1)
			{
			cout<<Test<<endl;
			cout << "\n������Ҫɾ���Ŀγ����,����-1�˳���" <<endl;
			cin>>courseType;
			if (cin.fail())
			{
         		cin.clear();
				cin.ignore();
      		}
			if(courseType!=-1)
			{
				if(courseType==0)
				cout<<"\n�˿�ʧ�ܣ�"<<endl;
				else if(Test.removeCourse(courseType))
				cout<<"\n�˿γɹ���"<<endl; 
				else
				cout<<"\n�˿�ʧ�ܣ�"<<endl;
			}
			else
			break;
			}
			
		}
		else if(number==3)
		{
			cout<<"\n�����óɼ���" <<endl;
			setCourseGrade(Test);
		}
		
		else if(number==4)
		{
			double x=Test.calcCredit();
			cout<<"\n��ͬѧ�ļ���Ϊ  "<<x<<endl;
		}
		else if(number==5)
		{
			ofstream outfile("student.txt", ios::out);
			if(!file)
			{
				cerr<<"error"<<endl;
				break;
			}
			outfile<<Test;
			outfile.close();
			cout<<"\n��ӡ�ɹ���"<<endl; 
		}
			
			
		}
		
		
		
		
		
	}
	cout<<Test;

		                                                                                                                                                         
	return 0;
	
}



Console::~Console()
{
	
}

