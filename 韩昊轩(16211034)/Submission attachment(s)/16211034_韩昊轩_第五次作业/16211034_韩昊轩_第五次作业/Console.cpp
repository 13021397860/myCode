#include "Console.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include <iostream>
#include <typeinfo>
#include<cstdlib>
using namespace std;
#define MAX_SIZE 200
Console::Console()
{
    ObligatoryNumber = 0;//ctor
    ElectiveNumber = 0;
}

Console::~Console()
{
    if(student!=NULL) delete student;
    for(int i = 0; i < ObligatoryNumber; i++)
        delete obligatory[i];
    for(int i = 0; i < ElectiveNumber; i++)
        delete elective[i];
}
void Console::newStudent()
{
    char s[200];
    Date birthDate;
    cout<<"����������\n";
    cin>>s;
    cout<<"�������������(�� �� ��)\n";
    cin>>birthDate;
    student = new Student(s, birthDate);
}
void Console::newCourse()
{
    ObligatoryNumber = 4;
    ElectiveNumber = 6;
    obligatory[0] = new ObligatoryCourse("�������ĳ������", 3);
    obligatory[1] = new ObligatoryCourse("���Դ���", 5);
    obligatory[2] = new ObligatoryCourse("���ݽṹ", 4);
    obligatory[3] = new ObligatoryCourse("�ߵ���ѧ", 4);
    elective[0] = new ElectiveCourse("ְҵ�滮", 2);
    elective[1] = new ElectiveCourse("��վ��������", 2);
    elective[2] = new ElectiveCourse("���պ������", 2);
    elective[3] = new ElectiveCourse("Ӣ�����ǿ��", 1);
    elective[4] = new ElectiveCourse("ϵͳ����", 2);
    elective[5] = new ElectiveCourse("�������", 2);
}

Course*& Console::selectCourse(int option)
{
    int choice = -1;
    if(option == 1)
    {
        cout<<"��ѡ����޿Σ�\n";
        while(choice > ObligatoryNumber || choice < 0)
        {
            for(int i = 0; i < ObligatoryNumber; i++)
            {
                cout<<i+1<<".";
                cout<<*obligatory[i];
            }
            cout<<"������ѡ��γ̵ı��,����0ȡ������ѡ��\n";
            cin>>choice;
        }
        if(choice) return obligatory[choice-1];

    }
    else
    {
        cout<<"��ѡ��ѡ�޿Σ�\n";
        while(choice > ElectiveNumber || choice < 0)
        {
            for(int i = 0; i < ElectiveNumber; i++)
            {
                cout<<i+1<<".";
                cout<<*elective[i];
            }
            cout<<"������ѡ��γ̵ı��,����0ȡ������ѡ��\n";
            cin>>choice;
        }
        if(choice) return elective[choice-1];

    }
}
void Console::run()
{
    newStudent();
    newCourse();
    int n;
    int operate = Menu();
    while(operate)
    {
        if(!operate) return;
        switch(operate)
        {
            case 1:student->addCourse(selectCourse(operate));
                cout<<endl;break;
            case 2:student->addCourse(selectCourse(operate));
                cout<<endl;break;
            case 3:cout<<*student;
                cout<<endl;break;
            case 4:setCourseScore();
                cout<<endl;break;
            case 5:for(int i = 0; i < student->getCourseNumber(); i++)
                cout<<i<<"."<<*(student->courseList[i]);
                cout<<"��������Ҫ��ѯ�Ŀγ̱�ţ�������ѡ˳��";
                cin>>n;
                getCourseGrade(n); break;
            case 6:student->getCredit();break;
            default: return ;
        }
        operate = Menu();
    }
}
void Console::getCourseGrade(int num)
{

    student->getScore(num);
}
int Console::Menu() const
{
	int choice=0;
	cout<<"**********���˵�**********\n";
	cout<<"1. ѡ���޿γ�\n";
	cout<<"2. ѡѡ�޿γ�\n";
    cout<<"3. �鿴ѡ�����\n";
    cout<<"4. ���ÿγ̳ɼ�\n";
    cout<<"5. �鿴�γ̳ɼ�\n";
    cout<<"6. �鿴����ɼ�\n";
    cout<<"0. �˳�ϵͳ\n";
    cout<<"�����������ţ�";
	cin>>choice;
    system("cls");
	return choice;
}
void Console::setCourseScore()
{
    int mark;
    char grade;
    for(int i = 0; i < student->getCourseNumber(); i++)
        cout<<*(student->courseList[i]);
    for(int i = 0; i < student->getCourseNumber(); i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*(student->courseList[i])))
        {//����RTTI,�ж��ǲ��Ǳ��޿�
			cout<<"���޿γ̡�"<<student->courseList[i]->getName()<<"���ĳɼ�(0-100)��";
			cin>>mark;
			dynamic_cast<ObligatoryCourse &>(*(student->courseList[i])).setMark(mark);
		}
		else if(typeid(ElectiveCourse)==typeid(*(student->courseList[i])))
        {//����RTTI,�ж��ǲ���ѡ�޿�
			cout<<"ѡ�޿γ̡�"<<student->courseList[i]->getName()<<"���ĳɼ�(A-E)��";
			cin>>grade;
			dynamic_cast<ElectiveCourse &>(*(student->courseList[i])).setGrade(grade);
		}
    }
}
