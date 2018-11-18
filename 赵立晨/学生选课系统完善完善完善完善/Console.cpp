#include "console.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <typeinfo>
#include "Student.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "MyException.h"
#include <windows.h>
Console::Console()
{
    //ctor
}
void Console::test()
{
    char name[20];
    int y,m,d;
    string B;
//    Course Course0();
    ElectiveCourse CourseC("CourseC",1);
    ObligatoryCourse CourseD("CourseD",1);
    Date DATE(1000,12,20);
    DATE=DATE+5+10;
    DATE+=5+10;
    cout<<DATE++<<endl;
    cout<<++DATE<<endl;
    puts("name && birthday:");
    scanf("%s%d%d%d",name,&y,&m,&d);
    Student stuA(name,Date(y,m,d));
    stuA.print();
    stuA.addCourse(new ObligatoryCourse("CourseA",3,100))
        .addCourse(new ElectiveCourse("CourseB",4,'A'))
        .addCourse(new ElectiveCourse(CourseC,'B'));
//        .addCourse("CourseD",3);
    stuA.print();
    system("pause");
}
bool Console::init()
{
    ifstream ifile("data\\course.txt");
    courseNum=0;
    string type,name;
    int creditHour;
    while (ifile>>type>>name>>creditHour){
        if (type[0]=='O'||type=="1")
            allCourses[courseNum++]=new ObligatoryCourse(name,creditHour);
        else if (type[0]=='E'||type=="2")
            allCourses[courseNum++]=new ElectiveCourse(name,creditHour);
    }
    if (courseNum==0){
        cerr<<"�γ��ļ�����,������!\n";
        return 1;
    }
    ifile.close();
    return 0;
}
bool Console::addCourse(Student &A,bool Mark=0)
{
    int i;
    for (int i=0;i<courseNum;i++) {printf("%d ",i+1); allCourses[i]->printCourse(); puts("");}
    i=0;
    cin>>i;
    while ((i<=0||i>courseNum)||cin.fail()){
        cin.clear();
        cin.ignore();
        cerr<<"�������!����������!\n";
        cin>>i;
    }
    i--;
    if (Mark){
        if (typeid(*allCourses[i])==typeid(ObligatoryCourse)){
            cout<<"������һ������:\n";
            int mark;cin>>mark;
            while ((!(mark<=100&&mark>=0))||cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"�������ݸ�ʽ��������������\n";
                cin>>mark;
            }
            A.addCourse(new ObligatoryCourse(*((ObligatoryCourse*)allCourses[i]),mark));
        }
        if (typeid(*allCourses[i])==typeid(ElectiveCourse)){
            cout<<"������һ���ַ�:\n";
            char grade;cin>>grade;
            while ((!(grade<='E'&&grade>='A'))||cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"�������ݸ�ʽ��������������\n";
                cin>>grade;
            }
            A.addCourse(new ElectiveCourse(*((ElectiveCourse*)allCourses[i]),grade));
        }
    }
    else{
        if (typeid(*allCourses[i])==typeid(ObligatoryCourse))
            A.addCourse(new ObligatoryCourse(*((ObligatoryCourse*)allCourses[i])));
        if (typeid(*allCourses[i])==typeid(ElectiveCourse))
            A.addCourse(new ElectiveCourse(*((ElectiveCourse*)allCourses[i])));
    }
    cout<<"ѡ�γɹ�~~"<<"\n";
    return 0;
}
void Console::run()
{
    system("cls");
    if (init()) return;
    char name[20];Date D;
    puts("����:");
    cin>>name;
    while (1)
    {
        try{
            cin>>D;
            break;
        }catch(MyException ex){
            cout<<ex.what()<<endl;
        }
    }
    Student stuA(name,D);
    string courseName,A;
    int i;
//    system("cls");
//    cout<<stuA;
    puts("ѡ��: 'AddCourse' ���� 1  �е÷ֵ� : 2");
    puts("ѧ����Ϣ: 'Infomation' ���� 3");
    puts("ɾ���γ�: 'Delete' ���� 4");
    puts("�趨����: 'SetScore' ���� 5");
    puts("��ѯ����: 'Query' ���� 6");
    puts("��ѯ����: 'CalcCredit' ���� 7");
    puts("���ѧ��: 'Print' ���� 8");
    puts("��������: 'over' ���� 0");
    while (cin>>A){
        if (A[0]=='A'||A=="1"){
            addCourse(stuA);
        }
        else if (A=="2"){
            addCourse(stuA,1);
        }
        else if (A[0]=='I'||A=="3") cout<<stuA;
        else if (A[0]=='D'||A=="4"){
            cin>>i;
            if (cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"�������ݸ�ʽ��������������\n";
                continue;
            }
            if (!stuA.removeCourse(i)) puts("ɾ�����ɹ������ֶ�ɾ��!");
        }
        else if (A[0]=='S'||A=="5"){
            while (1)
            {
                try{
                    cin>>i;
                    while(cin.fail()){
                        cin.clear();
                        cin.ignore();
                        cerr<<"�������ݸ�ʽ��������������\n";
                        cin>>i;
                    }
                    stuA.setCourseScore(i);
                    break;
                }catch(MyException ex){
                    cout<<ex.what()<<endl;
                }
            }
            cout<<"�ķֳɹ�~~\n";
        }
        else if (A[0]=='Q'||A=="6"){
            while (1)
            {
                try{
                    cin>>i;
                    while(cin.fail()){
                        cin.clear();
                        cin.ignore();
                        cerr<<"�������ݸ�ʽ��������������\n";
                        cin>>i;
                    }
                    if (stuA.getCourseScore(i)!=-1) cout<<stuA.getCourseScore(i)<<"\n";
                    else puts("û����!");
                    break;
                }catch(MyException ex){
                    cout<<ex.what()<<endl;
                }
            }
        }
        else if (A[0]=='C'||A=="7"){
            if (abs(stuA.calcCredit()>0.000001)) cout<<stuA.calcCredit()<<"\n";
            else puts("ûѡ�λ�û����!");
        }
        else if (A[0]=='P'||A=="8"){
            puts("�����������ɵ��ļ���:");
            char fileName[108]="data\\";
            scanf("%s",fileName+5);
            ofstream *ofile;
            ofile=new ofstream(fileName);
            if (!ofile) cerr<<"�������!���Բ����!\n";
            else {
                (*ofile)<<stuA;
                ofile->close();
                delete ofile;
            }
        }
        else if (A=="over"||A=="0") break;
//        else{
//            cin>>courseName>>creditHour;
//            stuA.addCourse(new Course(courseName,creditHour));
//        }
        else puts("�����ʽ����!");
    }
    cout<<stuA;
}
Console::~Console()
{
    //dtor
}
