#include "console.h"
#include "myexception.h" // class's header file
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<windows.h> 
#include<typeinfo>
using namespace std;
// class constructor
Console::Console()
{
	ocNum=ecNum=0;
	// insert your code here
}

// class destructor
Console::~Console()
{
	// insert your code here
}
Console& Console::buildCourse(){
	/*string n;
	int t;
	freopen("course.txt","r",stdin);
	for(int i=1;i<=5;i++){
		cin>>n>>t;
		oc[i]=new ObligatoryCourse(n,t,100);
	}
	for(int i=1;i<=5;i++){
		cin>>n>>t;
		ec[i]=new ElectiveCourse(n,t,'A');
	}
	ocNum=ecNum=5;
	freopen("CON", "r", stdin);
	return *this;*/
	string n;
	int t;
	ifstream infile;
	infile.open("course.txt",ios::in);
	for(int i=1;i<=5;i++){
		infile>>n>>t;
		oc[i]=new ObligatoryCourse(n,t,100);
	}
	for(int i=1;i<=5;i++){
		infile>>n>>t;
		ec[i]=new ElectiveCourse(n,t,'A');
	}
	ocNum=ecNum=5;
	infile.close();
	return *this;
}
Console& Console::buildStudent(){
	int y,m,d;
	char name[20];
	printf("������������\n");
	scanf("%s",name);
	printf("���������գ��Կո�ֿ������� �� �գ�\n");
	while(1){
		scanf("%d%d%d",&y,&m,&d);
		try{
			student=new Student(name,y,m,d);
			break;
		}catch(MyException ex){
			cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
        	cout<<"����������ѧ������\n";
		}
	}
	//scanf("%d%d%d",&y,&m,&d);
	//student=new Student(name,y,m,d);
	return *this;
}
void Console::selectCourse(int op){
	int type;
	if(op==1){
		Course *p;
		cout<<"���ޣ�"<<endl; 
		for(int i=1;i<=5;i++){
			cout.setf(ios::left);
			cout<<setw(2)<<i; 
			oc[i]->print();
		}
		cout<<"���������ѡ�Σ����Զ�ѡ����0��Ϊ������־"<<endl;
		scanf("%d",&type);
		while(type!=0){
				p=new ObligatoryCourse(oc[type]->getname(),oc[type]->getcreditHour());
				student->addCourse(p);
				//cin>>type;
				scanf("%d",&type);
		}
	}
	else if(op==2){
		Course *p;
		cout<<"���ޣ�"<<endl; 
		for(int i=1;i<=5;i++){
			cout.setf(ios::left);
			cout<<setw(2)<<i; 
			ec[i]->print();
		}
		cout<<"���������ѡ�Σ����Զ�ѡ����0��Ϊ������־"<<endl;
		scanf("%d",&type);
		while(type!=0){
				p=new ElectiveCourse(ec[type]->getname(),ec[type]->getcreditHour());
				student->addCourse(p);
				//cin>>type;
				scanf("%d",&type);
		}
	}
}
bool Console::setCourseScore(){
	int mark=0;
	char grade='\0';
	for(int i=0;i<student->getcourseNumber();i++){
		if(typeid(ObligatoryCourse)==typeid((*student)[i])){
			cout<<"���޿γ̡�"<<(*student)[i].getname()<<"���ĳɼ�(0-100)��";
			//cin>>mark;
			while(1){
                scanf("%d",&mark);
				try
                {
                    dynamic_cast<ObligatoryCourse &>((*student)[i]).setmark(mark);
                    break;
                }catch(MyException ex)
                {
                    cout<<"��ʽ���󣬱��޿γ̡�"<<(*student)[i].getname()<<"���ĳɼ�(0-100)��";
                }
			}
			//scanf("%d",&mark);
			//dynamic_cast<ObligatoryCourse &>((*student)[i]).setmark(mark);
		}
		else if (typeid(ElectiveCourse)==typeid((*student)[i])){
			cout<<"ѡ�޿γ̡�"<<(*student)[i].getname()<<"���ĳɼ�(A-E)��";
			//cin>>grade;
			while(1){
                scanf(" \n%c",&grade);
				try
                {
                    dynamic_cast<ElectiveCourse &>((*student)[i]).setgrade(grade);
                    break;
                }catch(MyException ex)
                {
                    cout<<"��ʽ����ѡ�޿γ̡�"<<(*student)[i].getname()<<"���ĳɼ�(A-E)��";
                }
			}
			//dynamic_cast<ElectiveCourse &>((*student)[i]).setgrade(grade);
		}
		else{
			return false;
		}
	}
	return true;
}
void Console::removeCourse(){
	int type;
	cout<<*student;
	cout<<"����������˿Σ�ÿ��ֻ����һ�ſ�"<<endl;
	scanf("%d",&type);
	student->removeCourse(type); 

}
int Console::displayMenu()const{
	int choice=0;
	cout<<"**********ѧ��ѡ��ϵͳ-���˵�**********\n"
		<<"\t1. ѡ���޿γ�\n"
		<<"\t2. ѡѡ�޿γ�\n"
		<<"\t3. �鿴ѡ�����(�����ɼ�)\n"
		<<"\t4. ���ÿγ̳ɼ�\n"
		<<"\t5. ��ѡ�γ�\n"
		<<"\t6. ��ѯѧ�ּ�\n"
		<<"\t7. ����ѧ����Ϣ\n"
		<<"\t0. �˳�ϵͳ\n"
		<<"��ѡ������Ĳ���(0~7)��";
	//scanf("%d",&choice);
	cin>>choice;
	while(cin.fail()||choice<0||choice>7){
		cout<<"���벻�Ϸ�����������"<<endl;
		cin.clear();
		cin.ignore();
		cin>>choice; 
	}
	return choice;
}
void Console::printCredit()const{
	if(student->calcCredit()<0){
		cout<<"�γ̳ɼ�δ¼���¼�벻��ȫ���޷�����"<<endl;
	} 
	else{
		cout<<"��ǰѧ�ּ�Ϊ��"<<student->calcCredit()<<endl;
	}
}
void Console::save(){
	char filename[100];
	cout<<"�������ļ���"<<endl;
	cin>>filename;
	ofstream *outfile;
	outfile=new ofstream(filename);
	*outfile<<*student;
	outfile->close();
	cout<<"����ɹ�������"<<endl; 
}
int Console::run(){
    buildCourse();
    buildStudent();
    system("cls");
    int choice=displayMenu();
    system("cls");
    while (choice!=0)
    {
        switch (choice)
        {
            case 1: 
				selectCourse(1);
                break;
            case 2: 
                selectCourse(2);
                break;
            case 3: 
                cout<<*student;
                break;
            case 4: 
                setCourseScore();
                break;
            case 5:  
                removeCourse();
                break;
            case 6:  
                printCredit();
                break;
            case 7:
				 save();
				 break;
        }
        choice=displayMenu();
        system("cls");
    }

    return 0;
}
