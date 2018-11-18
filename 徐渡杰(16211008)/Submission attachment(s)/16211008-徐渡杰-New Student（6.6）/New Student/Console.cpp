#include "Console.h"
#include "Student.h"
#include "MyException.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

bool isLeapYear(const int &year)
{
    if((year%400==0)||(year%4==0&&year%100!=0))
        return true;
    return false;
}

bool isStandard(const int &year,const int &month,const int &day)
{
    int LMonth_day[]={31,29,31,30,31,30,31,31,30,31,30,31};
    int NMonth_day[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(year<0)
    {
        return false;
    }
    if(month>12||month<=0)
    {
        return false;
    }
    if(isLeapYear(year))
    {
        if(day<=0||day>LMonth_day[month-1])
            return false;
    }
    else
    {
        if(day<=0||day>NMonth_day[month-1])
            return false;
    }
    return true;
}

void Console::output_OcourseList(){
    string b="\n";
    ifstream fileopen;
    fileopen.open("ZO_Course.txt",ios::out);
    char a=fileopen.get();
    while(a!=EOF)
    {
        b+=a;
        a=fileopen.get();
    }
    cout<<b<<endl;
}

void Console::output_EcourseList(){
    string b="\n";
    ifstream fileopen;
    fileopen.open("ZE_Course.txt",ios::out);
    char a=fileopen.get();
    while(a!=EOF)
    {
        b+=a;
        a=fileopen.get();
    }
    cout<<b<<endl;
}

void Console::add_stuInformation(Student &A){
    cout<<"\n������ѧ������:"<<endl;
    char name[10];
    cin>>name;
    cout<<"\n������ѧ����������:\nʾ����1999 01 01"<<endl;
    int year,month,day;
    while(cin>>year>>month>>day){
        try{
            if(cin.fail()||!isStandard(year,month,day))throw MyException("invalid_Date");
            A.setStudentName(name);
            A.setStudentBirth(year,month,day);
            cout<<"\n���ѧ����Ϣ�ɹ�!"<<endl;
            break;
        }
        catch(MyException &X){
            X.what();
        }
    }
}

void Console::query_stuInformation(Student &A){
    int n;
    while(1){
        cout<<"\n1.��ѯѧ��ȫ����Ϣ\n2.��ѯѧ������ɼ�\n3.��ѯѧ���γ̳ɼ�\n4.�˳����β���\n";
        cin>>n;
        if(n==1)
        {
            cout<<A<<endl;
            ofstream file("zout.txt",ios::out);
            file<<A;
        }
        else if(n==2)
        {
            cout<<"\nѧ������ɼ�Ϊ��"<< setprecision(4) << A.calcCredit() << endl;
        }
        else if(n==3)
        {
            cout<<"\n������Ҫ��ѯ�Ŀγ̺ţ�";
            int i;
            cin>>i;
            if(A.consultCourse(i)==-1)cout<<"\n�����ڴ˿γ̻�ÿγ���δ¼��ɼ�"<<endl;
            else
                cout<<A.getConsultCourseName(i)<<": "<<A.consultCourse(i)<<endl;
        }
        else
            break;
    }
}
//���ÿγ̳ɼ�//
void Console::add_stuCourse(Student &A){
    int n;
    while(1){
        cout<<"\n1.���޿γ�\n2.ѡ�޿γ�\n3.����\n";
        cin>>n;
        if(n==1){
            output_OcourseList();
            cout<<"\n������γ̱�ţ�";
            string str;
            while(cin>>str){
                try{
                    if(str.length()>1)
                        throw MyException("invalid_CourseNum");
                    else if(str[0]>'4'||str[0]<'1')
                        throw MyException("invalid_CourseNum");
                    else{break;}
                }
                catch(MyException &X){X.what();}
            }
            string CourseName;
            double Credit;
            int tag=1;
            switch(str[0]){
                case '1':CourseName="data_structure";Credit=3;break;
                case '2':CourseName="OOP";Credit=3;break;
                case '3':CourseName="advanced_math";Credit=4;break;
                case '4':CourseName="linear_algebra";Credit=4;break;
                case '5':
                         cout<<"\n������γ����ƣ�";
                         cin>>CourseName;
                         cout<<"\n������γ�ѧ�֣�";
                         cin>>Credit;
                         break;
                default:tag=0;cout<<"\n��ӿγ�ʧ�ܣ�"<<endl;break;
            }
            if(tag==1){
                cout<<"\n�γ���ӳɹ���"<<endl;
                Course *ptr1=new ObligatoryCourse(CourseName,Credit,1,-1);
                A.addCourse(ptr1);
            }
        }
        else if(n==2){
            output_EcourseList();
            cout<<"\n������γ̱�ţ�";
            string str;
            while(cin>>str){
                try{
                    if(str.length()>1)
                        throw MyException("invalid_CourseNum");
                    else if(str[0]>'4'||str[0]<'1')
                        throw MyException("invalid_CourseNum");
                    else{break;}
                }
                catch(MyException &X){X.what();}
            }
            string CourseName;
            double Credit;
            int tag=1;
            switch(str[0]){
                case '1':CourseName="Google_Analytics";Credit=1;break;
                case '2':CourseName="Aerospace_overview";Credit=1.5;break;
                case '3':CourseName="Information_retrieval";Credit=1;break;
                case '4':
                         cout<<"\n������γ����ƣ�";
                         cin>>CourseName;
                         cout<<"\n������γ�ѧ�֣�";
                         cin>>Credit;
                         break;
                default:tag=0;cout<<"\n��ӿγ�ʧ�ܣ�"<<endl;break;
            }
            if(tag==1){
                Course *ptr2=new ElectiveCourse(CourseName,Credit,2,'F');
                A.addCourse(ptr2);
            }
        }
        else
            break;
    }
}

void Console::remove_stuCourse(Student &A){
    cout<<"\n��������Ҫ��ѡ�γ̱�ţ�"<<endl;
    int t;
    int times=0;
    while(cin>>t){
        try{
            if(A.removeCourse(t)){cout<<"\n�˿γɹ�"<<endl;break;}
            else throw MyException("invalid_CourseNum");
        }
        catch(MyException &X){
            X.what();
        }
        if(++times>3)
            break;
    }

}

void Console::add_courseSorce(Student &A){
    cout<<"\n��������Ҫ��ӳɼ��γ̱�ţ�"<<endl;
    int t;
    cin>>t;
    if(t<=A.getcourseNum()&&t>0){
        if(A.courseList[t-1]->Tag()==1){
            cout<<"\n������γ̳ɼ���\n(0~100)"<<endl;
            double sorce;
            while(cin>>sorce){
                try{
                    if(sorce<0||sorce>100)throw MyException("invalid_Sorce");
                    break;
                }
                catch(MyException &X){
                    X.what();
                }
            }
            A.courseList[t-1]->setScore(sorce);
        }
        else{
            cout<<"\n������γ̳ɼ���\n(A,B,C,D,E)"<<endl;
            string sorce;
            while(cin>>sorce){
                try{
                    if(sorce.length()>1)
                        throw MyException("invalid_Sorce");
                    else if(sorce[0]<'A'||sorce[0]>'E')
                        throw MyException("invalid_Sorce");
                    else{break;}
                }
                catch(MyException &X){
                    X.what();
                }
            }
            A.courseList[t-1]->setScore(sorce[0]);
        }
    }
    else
        cout<<"\n�γ̱�Ŵ���"<<endl;
}

void Console::set_stuInformation(){
    int Num=0;
    Student A;
    cout<<"#�������ѧ����Ϣ#";
    if(Num==0)
    {
        add_stuInformation(A);
    }
    while(1){
        cout<<"\n1.��ѯѧ����Ϣ\n2.��ӿγ�\n3.��ѡ�γ�\n4.��ӿγ̳ɼ�\n5.�˳���ǰѧ����Ϣ\n";
        cin>>Num;
        if(Num==1){
            query_stuInformation(A);
        }
        else if(Num==2){
            add_stuCourse(A);
        }
        else if(Num==3){
            remove_stuCourse(A);
        }
        else if(Num==4){
            add_courseSorce(A);
        }
        else
            break;
    }
}
