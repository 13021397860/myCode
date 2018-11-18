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
	cout << "������ѧ����������";
	cin >> studName;
	Date lwDate;
	bool wrongDate = 1;
	while(wrongDate == 1)
	{
		try{
			cout << "\n������ѧ�������գ���ʽΪ �� �� �գ���";
			cin >> studYear >> studMonth >> studDay;
			lwDate.setDate(studYear, studMonth, studDay);
			wrongDate = 0;
		}catch(DateException &ex){
			cout << ex.what() << endl; 
		}		
	}

	Student LW(studName, lwDate);	
	readSequentialFile("course.txt");
	
	cout << "\n��������Ҫִ�еĲ�����ţ�" <<endl
		 << "--> 1 ѡ����޿γ�" <<endl
		 << "--> 2 ѡ��ѡ�޿γ�" <<endl
		 << "--> 3 ����ѡ��γ��趨�ɼ�" <<endl
		 << "--> 4 ��ѡ�γ�" <<endl
		 << "--> 5 ��ѯ�γ̻���ɼ�" <<endl
		 << "--> 6 ����Ϣ�洢���ļ���" <<endl
		 << "--> 0 �˳��˵�ҳ����ʾ�γ�����" <<endl;
	while(1)
	{
		cin >> courseType;
		if(cin.fail())
		{
			cout<<"�������Ƿ������������룡\n"<<endl;
	        cin.clear();
			cin.ignore();
			continue;
	    }
		if(courseType == 1)
		{
			printOC();
			int numofCourse;
			cout << "����������Ҫѡ��ı��޿Σ����س���ȷ�ϣ�����-1�˳�����" << endl;
			
			while(cin >> numofCourse)
			{
				
				if(numofCourse == -1)
					break;
				else if(numofCourse > numberofOC || numofCourse <= 0) 
					cout << "û�����ſγ̣�������ѡ��" <<endl;
				else
				{
					Course *str1 = obligatoryCourse[ numofCourse - 1 ];
					try{
						LW.addCourse(str1);
						cout << "ѡ�γɹ���" <<endl;
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
			cout << "����������Ҫѡ���ѡ�޿Σ����س���ȷ�ϣ�����-1�˳�����" << endl;
			while(cin >> numofCourse)
			{
				if(numofCourse == -1)
					break;
				else if(numofCourse > numberofOC || numofCourse <= 0) 
					cout << "û�����ſγ̣�������ѡ��" <<endl;
				else
				{
					Course *str2 = electiveCourse[ numofCourse - 1 ];
					try{
						LW.addCourse(str2);
						cout << "ѡ�γɹ���" <<endl;
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
				cout << "�ɼ��趨ʧ�ܣ�" <<endl;
			}
		}
		else if(courseType == 4)
		{
			cout << LW <<endl;
			int i = 0;
			while(i != -1)
			{
				cout << "��������ѡ�Ŀγ���ţ�����-1��������";
				cin >> i;
				if(i == -1) break; 
				
				try{
					LW.removeCourse(i);
					cout << "��ѡ�γɹ���" <<endl;	
				}catch(StudentException &ex){
					cout << ex.what() << endl; 
				}	
				cout << LW <<endl;
			}
		}
		else if(courseType == 5)
		{
			double jidian = LW.calcCredit(); 
			cout << "���ļ���ɼ�Ϊ��" << jidian << endl;
		}	
		else if(courseType == 6)
		{
			ofstream outfile("information.txt", ios::out);
			if  (!outfile)
			{
				cerr << "�޷������ļ���" << endl;
				exit(1);
			}
			outfile << LW;
			cout << "��Ϣ�Ѵ洢����ǰ�ļ����е� information.txt �ļ��У�\n" << endl; 
			outfile.close();
		}	
		else if(courseType == 0)
		{
			cout << "�����˳��˵�ҳ��������ʾѡ�����飺\n" << endl;
			break;
		}
		else
		{
			cout << "��ų�����Χ�����������룡\n" << endl;
			continue;
		}
		cout << "\n��������Ҫִ�еĲ�����ţ�" <<endl
			 << "--> 1 ѡ����޿γ�" <<endl
			 << "--> 2 ѡ��ѡ�޿γ�" <<endl
			 << "--> 3 ����ѡ��γ��趨�ɼ�" <<endl
			 << "--> 4 ��ѡ�γ�" <<endl
			 << "--> 5 ��ѯ�γ̻���ɼ�" <<endl
			 << "--> 6 ����Ϣ�洢���ļ���" <<endl
			 << "--> 0 �˳��˵�ҳ����ʾ�γ�����" <<endl;
	}	
	cout << LW;
}

void Console::printOC()
{
	cout << "\n������б��޿γ���ѡ��һ�ſγ̣���ʼ�ɼ�Ϊ0����" << endl;
	for(int i = 1; i <= numberofOC; i++)
	{
		cout << "��" << i << "�� " << *obligatoryCourse[ i - 1 ] << endl;	
	}
}

void Console::printEC()
{
	cout << "\n�������ѡ�޿γ���ѡ��һ�ſγ̣���ʼ�ɼ�Ϊ55����" << endl;
	for(int i = 1; i <= numberofEC; i++)
	{
		cout << "��" << i << "�� " << *electiveCourse[ i - 1 ] <<endl;	
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
				cout << "��������޿γ̡�" << (*stud.courseList[i]).getCourseName() << "���ĳɼ�(0 ~ 100)��";
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
					cout << "������ѡ�޿γ̡�" << (*stud.courseList[i]).getCourseName() << "���ĳɼ�(A ~ E)��";
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
