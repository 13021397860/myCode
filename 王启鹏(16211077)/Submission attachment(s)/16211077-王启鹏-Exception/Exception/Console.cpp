#include "Console.h"

Console::Console()
{
    //ctor
//    �����γ�
//    ocList[0]=new ObligatoryCourse("���ݽṹ", 5);
//    ocList[1]=new ObligatoryCourse("�ߵ���ѧ", 4);
//    ocList[2]=new ObligatoryCourse("��ѧӢ��", 2);
//    ocList[3]=new ObligatoryCourse("�������������", 3);
//    ocList[4]=new ObligatoryCourse("���ƴ�ѧ����", 4);
//    ocList[5]=new ObligatoryCourse("���Դ���", 4);
//
//    ecList[0]=new ElectiveCourse("����ǿ��", 0);
//    ecList[1]=new ElectiveCourse("ϵͳ����", 1);
//    ecList[2]=new ElectiveCourse("�߽����", 2);
//    ecList[3]=new ElectiveCourse("��վ��������", 1);
}

Console::~Console()
{
    for(int i=0; i<6; i++){
        if(ocList[i])
            delete ocList[i];
    }
    for(int i=0; i<4; i++){
        if(ecList[i])
            delete ecList[i];
    }
    cout<<"�˳�ϵͳ"<<endl;
    //dtor
}

void Console::run()
{
    int a;
    char fileName[20]="WriteFile.txt";
    buildStudent();
    //cout<<"*****"<<endl;
    buildCourse();
    a=display();
    while(a){
        if(a==0){
            break;
        }
        else if(a==1 || a==2){
            Course *tmp=chooseCourse(a);
            person->addCourse(tmp);
            cout<<"ѡ�γɹ�"<<endl;
        }
        else if(a==3){
            deleteCourse();
        }
        else if(a==4){
            cout<<"**********************************************"<<endl;
            cout<<*person;
            cout<<"**********************************************"<<endl;
        }
        else if(a==5){
            setCourseScore();
        }
        else if(a==6){
            cout<<"**********************************************"<<endl;
            cout<<"���㣺"<<fixed<<setprecision(4)<<person->calcCredit()<<endl;
            cout<<"**********************************************"<<endl;
        }
        else if(a==7){
            ofstream write(fileName);
            if(!write.is_open()){
                cout<<"�ļ���WriteFile.txt������ʧ��"<<endl;
            }
            else{
                cout<<"�ļ���WriteFile.txt������ɹ�"<<endl;
                write<<*person<<endl;
                write<<"���㣺"<<fixed<<setprecision(4)<<person->calcCredit()<<endl;
                write.close();
            }
        }
        a=display();
    }
    return ;
}

void Console::buildStudent()
{
    char name[100];
    int y, m, d;
    cout<<"������ѧ��������";
    cin>>name;
    cout<<"������ѧ������(���� �� �ա��ĸ�ʽ����)��";
    while(1){
        cin>>y>>m>>d;
        try{

            Date tmp(y, m, d);
            person=new Student(name, y, m, d);
            break;
        }
        catch(MyException){}
    }
    return ;
}

void Console::buildCourse()
{
    char fileName[20]="readFile.txt";
    ifstream read(fileName);
    if(!read.is_open()){
        cout<<"�����γ�ʧ��"<<endl;
    }
    else{
        string name;
        int credit;
        for(int i=0; i<6; i++){
            read>>name>>credit;
            ocList[i]=new ObligatoryCourse(name, credit);
        }
        for(int i=0; i<4; i++){
            read>>name>>credit;
            ecList[i]=new ElectiveCourse(name, credit);
        }
        read.close();
    }
    return ;
}

int Console::display()
{
    cout<<"============ѧ��ѡ��ϵͳ===========\n"
        <<"\t 0���˳�ϵͳ\n"
        <<"\t 1��ѡ���޿�\n"
        <<"\t 2��ѡѡ�޿�\n"
        <<"\t 3���˿�\n"
        <<"\t 4���鿴ѡ�����\n"
        <<"\t 5������ÿ�ſγ̵ĳɼ�\n"
        <<"\t 6����ѯ����\n"
        <<"\t 7����ѧ����ѡ����Ϣ�����ڡ�WriteFile.txt����\n"
        <<"===================================\n"
        <<"���������";
    int a;
    cin>>a;
    while(cin.fail() || a<0 || a>7){
        cout<<"����������������룺";
        cin.clear();
        cin.ignore();
        cin>>a;
    }
    return a;
}

Course* Console::chooseCourse(int a)
{
    int which;
    if(a==1){
        cout<<"==============���޿�===============\n"
            <<"\t 1.���ݽṹ   5\n"
            <<"\t 2.�ߵ���ѧ   4\n"
            <<"\t 3.��ѧӢ��   2\n"
            <<"\t 4.�������������   3\n"
            <<"\t 5.���ƴ�ѧ����   4\n"
            <<"\t 6.���Դ���   4\n"
            <<"===================================\n"
            <<"������γ̱�ţ�";
        cin>>which;
        while(cin.fail() || which<1 || which>6){
            cout<<"����������������룺";
            cin.clear();
            cin.ignore();
            cin>>which;
        }
        return ocList[which-1];
    }
    else {
        cout<<"==============ѡ�޿�===============\n"
            <<"\t 1.����ǿ��  0\n"
            <<"\t 2.ϵͳ����   1\n"
            <<"\t 3.�߽����   2\n"
            <<"\t 4.��վ��������   1\n"
            <<"===================================\n"
            <<"������γ̱�ţ�";
        cin>>which;
        while(cin.fail() || which<1 || which>4){
            cout<<"����������������룺";
            cin.clear();
            cin.ignore();
            cin>>which;
        }
        return ecList[which-1];
    }
}

void Console::deleteCourse()
{
    if(person->getCourseNumber()==0)
        return ;
    int which;
    cout<<"**********************************************"<<endl;
    cout<<"��ѡ�γ̣�\n";
        for(int i=0; i<person->getCourseNumber(); i++)
            cout<<i+1<<"��"<<(*person)[i]<<endl;
    cout<<"**********************************************"<<endl;
    cout<<"�������˿εı�ţ�";
    while(1){
        cin>>which;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"�������"<<endl;
        }
        else{
            try{
                person->removeCourse(which);
                cout<<"�˿γɹ�"<<endl;
                return ;
            }
            catch(MyException){}
        }
    }
    return ;
}

void Console::setCourseScore()
{
    char grade;//ElectiveCourse.setGrade
    int mark;//ObligatoryCourse.setMark
    for(int i=0; i<person->getCourseNumber(); i++){
        if( typeid(ObligatoryCourse)==typeid((*person)[i]) ){
            cout<<"��������޿Σ���"<<(*person)[i].getName()<<"�� �ĳɼ���0-100����";
            cin>>mark;
            while(cin.fail()){
                cout<<"����������������루0-100����";
                cin.clear();
                cin.ignore();
                cin>>mark;
            }
            while(1){
                try{
                    dynamic_cast<ObligatoryCourse&>((*person)[i]).setMark(mark);
                    break;
                }
                catch(MyException my){}
                cin>>mark;
            }
        }
        else{
            cout<<"������ѡ�޿Σ���"<<(*person)[i].getName()<<"�� �ĳɼ���A-E����";
            cin>>grade;
            while(cin.fail()){
                cout<<"����������������루A-E����";
                cin.clear();
                cin.ignore();
                cin>>grade;
            }
            while(1){
                try{
                    dynamic_cast<ElectiveCourse&>((*person)[i]).setGrade(grade);
                    break;
                }
                catch(MyException){}
                cin>>grade;
            }

        }
        cout<<"���óɹ�"<<endl;
    }
    return ;
}
/*
WQP
21 32 3
1 1 1
1
1
2
2
5
123
87
T
A
3
a
6
3
1
4
0
*/
