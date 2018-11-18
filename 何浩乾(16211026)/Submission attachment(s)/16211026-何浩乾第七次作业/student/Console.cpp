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
    if(student!=NULL) delete student;

    int i;
    for(i=0;i<ocNum;i++)
		delete oc[i];
	for(i=0;i<ecNum;i++)
		delete ec[i];
}


int Console::run()
{
    char fileName[256];
    ofstream *ofile;

    buildCourse();
    buildStudent(); //����ѧ������

    int choice=displayMenu();
    while (choice!=0)
    {
        switch (choice)
        {
            case 1:
            case 2:
                student->addCourse(selectCourse(choice));
                break;
            case 3:
                cout<<*student;
                break;
            case 4:
                setCourseScore();
                break;
            case 5:
				cout<<"��������Ҫ������ļ�����";
				cin>>fileName;
				ofile=new ofstream(fileName);
				if(!ofile){
					cerr<<"�޷������ļ���\n";
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
		cout<<"1. choose the obligatorycourse\n";
		cout<<"2. choose the electivecourse\n";
		cout<<"3. studtent's basic contition\n";
		cout<<"4. set the course scores\n";
		cout<<"5. save the course scores\n";
		cout<<"0. end the program\n";
		cout<<"please enter the number(0~5)��"<<endl;
	cin>>choice;
	while (cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"you must enter the number(0~5),please enter again��\n";
        cin>>choice;
	}
    while(choice<0 || choice>5)
    {
        cout<<"you must enter the number(0~5),please enter again��\n";
        cin>>choice;
        while (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"error��please enter again (0~5)��";
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
        case 1:
            cout<<"��ѡ��һ�ſγ�:\n";
            while((choice>ocNum)||(choice<0)){
                for(i=0;i<ocNum;i++){
                    cout<<"\t"<<i+1<<"."<<*oc[i];
                }
                cout<<"\t0.ȡ��\n";
                cout<<"������ѡ����ţ�";
                cin>>choice;
            }
            if (choice!=0) return oc[choice-1];
            break;
        case 2: //
            cout<<"��ѡ��һ�ſγ�:\n";
            while((choice>ecNum)||(choice<0)){
                for(i=0;i<ecNum;i++){
                    cout<<"\t"<<i+1<<"."<<*ec[i];
                }
                cout<<"\t0.ȡ��\n";
                cout<<"������ѡ����ţ�";
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
		if(typeid(ObligatoryCourse)==typeid((*student)[i])){
			cout<<"���޿γ�"<<(*student)[i].getName()<<"(0~100)��";
			cin>>mark;
			while(1){
                try
                {
                    dynamic_cast<ObligatoryCourse &>((*student)[i]).setMark(mark);
                    break;
                }catch(MyException ex)
                {
                    cout<<"��ʽ����"<<(*student)[i].getName()<<"(0~100)��";
                    cin>>mark;
                }
			}
		}else if (typeid(ElectiveCourse)==typeid((*student)[i])){
			cout<<"ѡ�޿γ�"<<(*student)[i].getName()<<"(A~E)��";
			cin>>grade;
			while(1){
                try
                {
                    dynamic_cast<ElectiveCourse &>((*student)[i]).setGrade(grade);
                    break;
                }catch(MyException ex)
                {
                    cout<<"��ʽ����"<<(*student)[i].getName()<<"(A~E)��";
                    cin>>mark;
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
    char name[20];
	Date birthDate;

	cout<<"������ѧ������: ";
	cin>>name;
	cout<<"������ѧ�����գ�";
	while(1)
    {
        try{
            cin>>birthDate;
            break;
        }catch(MyException ex)
        {
            cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
            cout<<"����������ѧ������";
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
