#include "operation.h"
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<fstream>
using namespace std;
void outexception(int k,int num1)
{
    if(k<=0||k>num1)
        throw MyException();
}
operation::operation()
{
    //ctor
}
void operation::mainoperation()
{
    char n[100];
    Student s;
    operation a;
    printf("#��ѡ���Ǵ��ļ��ж�ȡѧ����Ϣ(������1)���������ڽ���һ��ѧ����Ϣ(������2)��\n");
    while(cin>>n)
    {
        if(n[0]=='1'&&n[1]=='\0')
        {
            a.getmessageformfile(s);
            break;
        }
        else if(n[0]=='2'&&n[1]=='\0')
        {
            a.setNameanData(s);
            break;
        }
        else
            printf("������Ϣ��������������:\n");
    }
    a.SelectionOperation();
    while(cin>>n)
    {
        if(n[0]=='1'&&n[1]=='\0')
        {
            a.showmessage(s);
        }
        else if(n[0]=='2'&&n[1]=='\0')
        {
            cout<<"#�Ƽ�ѡ��γ����£�\n";
            a.showcoursemessage();
            cout<<"\n";
            a.SelectCourses(s);
            cout<<"\n";
        }
        else if(n[0]=='3'&&n[1]=='\0')
        {
            a.showmessage(s);
            a.setScore(s);
            cout<<"\n";
        }
        else if(n[0]=='4'&&n[1]=='\0')
        {
            a.getScore(s);
            cout<<"\n";
        }
        else if(n[0]=='5'&&n[1]=='\0')
        {
            a.showmessage(s);
            a.dropCourses(s);
            cout<<"\n";
        }
        else if(n[0]=='6'&&n[1]=='\0')
        {
            a.showcoursemessage();
            cout<<"\n";
        }
        else if(n[0]=='7'&&n[1]=='\0')
        {
            a.outputuofile(s);
            cout<<"#���ݳɹ������ļ���!\n";
        }
        else if(n[0]=='8'&&n[1]=='\0')
            break;
        else
        {
            printf("#������Ϣ��������������!\n");
            cout<<"\n";
        }
        a.SelectionOperation();
    }
}
void operation::setNameanData(Student &s)
{
    printf("#������������(20���ֽ�����)\n");
    //printf("������������(20���ֽ�����)\n");
    char *names;
    names=new char [1000];
    cin>>names;
    printf("#���������գ�(������ �� �գ��м��ÿո����)\n");
    //printf("���������գ�(������ �� �գ��м��ÿո����)\n");
    int y,m,d;
    cin>>y>>m>>d;
    s.setmessage(names,y,m,d);
}
void operation::getmessageformfile(Student &s)
{
    ifstream cindata("Student information.txt",ios::in);
    char *names;
    string a,b,c; char d;
    int year,month,day;
    names=new char [1000];
    cindata>>a>>names>>b>>year>>d>>month>>d>>day>>d;
    s.setmessage(names,year,month,day);
    string CourseName,Subjecttype;
    double creditHour,Score;
    for(int i=0;i<12;i++)
        cindata>>a;
    while(cindata>>a>>CourseName>>Subjecttype>>b>>creditHour>>c>>Score)
    {
        if(Subjecttype=="Elective")
        {
            char grade;
            if(Score==95)
                grade='A';
            else if(Score==85)
                grade='B';
            else if(Score==75)
                grade='C';
            else if(Score==65)
                grade='D';
            else if(Score==55)
                grade='E';
            else if(Score==-1)
                grade='F';
            Course* a=new ElectiveCourse();
            a->setall(CourseName,creditHour,grade);
            a->setpd(2);
            s.addCourse(a);
        }
        else
        {
            Course* a=new ObligatoryCourse();
            a->setall(CourseName,creditHour,Score);
            a->setpd(1);
            s.addCourse(a);
        }
    }
}
void operation::SelectionOperation()
{
    printf("#���������Ĳ�����(1Ϊ��ʾѧ����Ϣ��2Ϊѡ�Σ�3Ϊ���óɼ���4Ϊ��ѯ�ɼ���5Ϊ�˿Σ�6Ϊ�鿴��ѡ�γ���Ϣ��7Ϊ��ѧ����Ϣ���뵽�ļ��У�8Ϊ��������)\n");
    //printf("#���������Ĳ�����(1Ϊ��ʾѧ����Ϣ��2Ϊѡ�Σ�3Ϊ���óɼ���4Ϊ��ѯ�ɼ���5Ϊ�˿Σ�6Ϊ��������)\n");
}
void operation::SelectCourses(Student &s)
{
    printf("#������Ҫѡ������Ƽ��γ̻��������γ̣�(1Ϊ�Ƽ��γ̣�2Ϊ�����γ�)\n");
    int m;
    cin>>m;
    if(m==1)
    {
        ifstream cindata("Course information.txt",ios::in);
        string CourseName[2][20];
        double creditHour[2][20];
        string Name,type;
        double credit;
        int num1=0,num2=0;
        while(cindata>>Name>>type>>credit)
        {
            if(type=="Elective")
            {
                num2++;
                CourseName[1][num2-1]=Name;
                creditHour[1][num2-1]=credit;
            }
            else
            {
                num1++;
                CourseName[0][num1-1]=Name;
                creditHour[0][num1-1]=credit;
            }
        }
        printf("#��������Ҫѡ����Ƽ��γ̵Ŀ�Ŀ����(1Ϊ���ޣ�2Ϊѡ��)�Լ���֮ǰ�ı�ţ�\n");
        int n,k;
        cin>>n>>k;
        if(n==1)
        {
            try{
                outexception(k,num1);
                int pd=1;
                for(int i=1;i<=s.getcourseNumber();i++)
                {
                    if(s.getcourseList(i)->getname()==CourseName[0][k-1])
                    {
                        printf("#�˿γ��Ѿ�ѡ����������ظ�ѡ��\n");
                        pd=0;
                        break;
                    }
                }
                if(pd==1)
                {
                    double mm=-1;
                    Course* a=new ObligatoryCourse();
                    a->setall(CourseName[0][k-1],creditHour[0][k-1],mm);
                    a->setpd(1);
                    s.addCourse(a);
                }
            }catch(MyException ex){
                cout<<"#�����쳣��"<<ex.what2()<<"\n";
                cout<<"#������ı������󣬴˴β�����Ч��\n";
            }
        }
        else if(n==2)
        {
            try{
                outexception(k,num2);
                int pd=1;
                for(int i=1;i<=s.getcourseNumber();i++)
                {
                    if(s.getcourseList(i)->getname()==CourseName[1][k-1])
                    {
                        printf("#�˿γ��Ѿ�ѡ����������ظ�ѡ��\n");
                        pd=0;
                        break;
                    }
                }
                if(pd==1)
                {
                    Course* a=new ElectiveCourse();
                    a->setall(CourseName[1][k-1],creditHour[1][k-1],'F');
                    a->setpd(2);
                    s.addCourse(a);
                }
            }catch(MyException ex){
                cout<<"#�����쳣��"<<ex.what2()<<"\n";
                cout<<"#������ı������󣬴˴β�����Ч��\n";
            }
        }
    }
    else if(m==2)
    {
        selectiveCourses(s);
    }
}
void operation::selectiveCourses(Student &s)
{
    printf("#������Ҫѡ�Ŀ�Ŀ����(1Ϊ���ޣ�2Ϊѡ��)��\n");
    //printf("������Ҫѡ�Ŀ�Ŀ����(1Ϊ���ޣ�2Ϊѡ��)��\n");
    char m[20];
    cin>>m;
    string Name;
    double score;
    if(m[0]=='1')
    {
        printf("#������Ҫѡ�ı��޿�Ŀ����ѧ���Լ��ɼ���(�м��ÿո��������û�гɼ���������-1)\n");
        //printf("������Ҫѡ�ı��޿�Ŀ����ѧ���Լ��ɼ���(��û�гɼ���������-1)\n");
        double grade;
        int pd=1;
        cin>>Name>>score>>grade;
        for(int i=1;i<=s.getcourseNumber();i++)
        {
            if(s.getcourseList(i)->getname()==Name)
            {
                printf("#�˿γ��Ѿ�ѡ����������ظ�ѡ��\n");
                pd=0;
                break;
            }
        }
        if(pd==1)
        {
            Course* a=new ObligatoryCourse();
            a->setall(Name,score,grade);
            a->setpd(1);
            s.addCourse(a);
        }
    }
    else if(m[0]=='2')
    {
        printf("#������Ҫѡ��ѡ�޿�Ŀ����ѧ���Լ��ɼ��ȼ���(�м��ÿո��������û�гɼ��ȼ���������F)\n");
        //printf("������Ҫѡ��ѡ�޿�Ŀ����ѧ���Լ��ɼ��ȼ���(��û�гɼ��ȼ���������F)\n");
        char grade;
        int pd=1;
        cin>>Name>>score>>grade;
        for(int i=1;i<=s.getcourseNumber();i++)
        {
            if(s.getcourseList(i)->getname()==Name)
            {
                printf("#�˿γ��Ѿ�ѡ����������ظ�ѡ��\n");
                pd=0;
                break;
            }
        }
        if(pd==1)
        {
            Course* a=new ElectiveCourse();
            a->setall(Name,score,grade);
            a->setpd(2);
            s.addCourse(a);
        }
    }
}
void operation::setScore(Student &s)
{
    printf("#������Ҫ���óɼ��Ŀ�Ŀ��ţ�\n");
    //printf("������Ҫ���óɼ��Ŀ�Ŀ��ţ�\n");
    int m;
    cin>>m;
    try{
        outexception(m,s.getcourseNumber());
        if(s.getcourseList(m)->getpd()==1)
        {
            double scores;
            printf("#������˱��޿εĳɼ���\n");//printf("������˱��޿εĳɼ���\n");
            cin>>scores;
            s.getcourseList(m)->setScore(scores);
        }
        else if(s.getcourseList(m)->getpd()==2)
        {
            char scores;
            printf("#�������ѡ�޿εĳɼ��ȼ���\n");//printf("�������ѡ�޿εĳɼ��ȼ���\n");
            cin>>scores;
            s.getcourseList(m)->setScore(scores);
        }
    }catch(MyException ex){
        cout<<"#�����쳣��"<<ex.what2()<<"\n";
        cout<<"#�����������󣬴˲�����Ч!\n";
    }
}
void operation::getScore(Student &s)
{
    int n;
    printf("#����������Ҫ��ѯ�ĳɼ�����(1Ϊ��ѯ��Ŀ�ɼ���2Ϊ��ѯ����ɼ�)\n");
    cin>>n;
    if(n==1)
    {
        cout<<"\n";
        for(int i=1;i<=s.getcourseNumber();i++)
        {
            cout<<" "<<i<<".�γ�����"<<s.getcourseList(i)->getname()<<"  ѧ��:"<<fixed<< setprecision(1)<<s.getcourseList(i)->getcreditHour();
            cout<<"\n";
        }
        int m;
        printf("#������Ҫ��ѯ�ɼ��Ŀ�Ŀ��ţ�\n");
        cin>>m;
        try{
            outexception(m,s.getcourseNumber());
            if(s.getcourseList(m)->getpd()==1)
                cout<<"#�˱��޿εĿγ���Ϊ:";
            else if(s.getcourseList(m)->getpd()==2)
                cout<<"#��ѡ�޿εĿγ���Ϊ:";
            cout<<s.getcourseList(m)->getname()<<" ѧ��:"<<fixed<<setprecision(1)<<s.getcourseList(m)->getcreditHour();
            cout<<" �ɼ�Ϊ��"<<s.getcourseList(m)->getScore()<<"(-1��ʾδ���óɼ���)\n";
        }catch(MyException ex){
            cout<<"#�����쳣��"<<ex.what2()<<"\n";
            cout<<"#�����������󣬴˲�����Ч!\n";
        }
    }
    else if(n==2)
    {
        double sum=0;
        int pd=s.calcCredit(sum);
        if(pd==0){}
        else
        {
            cout<<"#����ɼ�Ϊ��"<<fixed<<setprecision(1)<<sum<<"\n";
        }
    }
}
void operation::dropCourses(Student &s)
{
    printf("#������Ҫ�˿εĿγ̵ı�ţ�\n");
    //printf("������Ҫ�˿εĿγ̵ı�ţ�\n");
    int m;
    cin>>m;
    s.removeCourse(m);
}
void operation::showmessage(Student &s)
{
    cout<<s<<endl;
    cout<<"#������Ϊ-1�����ʾδ���óɼ���\n";
}
void operation::showcoursemessage()
{
    ifstream cindata("Course information.txt",ios::in);
    string CourseName,Subjecttype;
    double creditHour;
    cout<<"ObligatoryCourse:\n";
    int pd=1,i=1;
    while(cindata>>CourseName>>Subjecttype>>creditHour)
    {
        if(pd==1&&Subjecttype=="Elective")
        {
            cout<<"\nElectiveCourse:\n";
            pd=0;
            i=1;
        }
        cout<<i++<<"."<<std::left<<setw(14)<<CourseName<<fixed<<setprecision(1)<<creditHour<<"\n";
    }
}
void operation::outputuofile(Student &s)
{
    ofstream coutdata("Student information.txt",ios::out);
    coutdata<<"Name: "<<s.getname();
    coutdata<<"   Birthday: "<<s.getbirthday().get_year()<<"-"<<setfill('0')
    <<setw(2)<<s.getbirthday().get_month()<<"-"<<setfill('0')<<setw(2)<<s.getbirthday().get_day()<<endl;
    coutdata<<"Course: ( Score = -1 means no score have been set�� )\n";
    for(int i=1;i<=s.getcourseNumber();i++)
    {
        coutdata<<" Name: "<<s.getcourseList(i)->getname();
        if(s.getcourseList(i)->getpd()==1)
            coutdata<<"  Obligatory ";
        else if(s.getcourseList(i)->getpd()==2)
            coutdata<<"  Elective ";
        coutdata<<"  CreditHour: "<<fixed<<setprecision(1)<<s.getcourseList(i)->getcreditHour();
        coutdata<<"  Score: "<<s.getcourseList(i)->getScore()<<"\n";
    }
}
operation::~operation()
{
    //dtor
}
