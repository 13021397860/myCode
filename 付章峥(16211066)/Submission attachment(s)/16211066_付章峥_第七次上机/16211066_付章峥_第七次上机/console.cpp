#include "console.h"
#include "date.h"
#include <fstream>
#include <exception>
#include <stdexcept>
#include "myexception.h"

using namespace std;

#define MAX_CLS 6

Console::Console()
{
    m.setName("User");//ctor
}

void Console::start()
{
    ifstream inClientFile("classes.txt",ios::in);
    if (!inClientFile)
        {system("cls");cerr<<"文件操作失败";exit(1);}
    string tep,blak;
    const char*name;
    int mark,j,yr,ms,dy;
        inClientFile>>blak>>tep>>blak;
        name=tep.c_str();
        m.setName(name);

        inClientFile>>yr>>ms>>dy>>blak;
        m.setBirthDate(ms,dy,yr);

        for(j=1;j<MAX_CLS+1;j++)
        {
            inClientFile>>tep>>mark;
            a[j].setObligatoryCourse(tep,mark);
        }
        inClientFile>>blak;
        for(j=1;j<MAX_CLS+1;j++)
        {
            inClientFile>>tep>>mark;
            b[j].setElectiveCourse(tep,mark);
        }
    inClientFile.close();
    for(int i=1;i<MAX_CLS+1;i++){p[i]=0;q[i]=0;}
}

void Console::open()throw(exception)
{
    start();
    exc.excDate(m.getDate());
    int ipt=10;
    while(ipt)
    {
        system("cls");
        cout<<m.getName()<<"的课表操作：\n"<<endl;
        cout<<"  请按照数字输入操作\n"<<endl;
        cout<<"    1)必修选课\n"<<endl;
        cout<<"    2)选修选课\n"<<endl;
        cout<<"    3)已选课程\n"<<endl;
        cout<<"    4)退选课程\n"<<endl;
        cout<<"    5)成绩设置\n"<<endl;
        cout<<"    6)输出信息\n"<<endl;
        cout<<"  0)结束选课\n"<<endl;
        cout<<"输入：";
        cin>>ipt;
        if(cin.fail())
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        else if(ipt==1)
            addO();
        else if(ipt==2)
            addE();
        else if(ipt==3)
            show();
        else if(ipt==4)
            rm();
        else if(ipt==5)
            setgrade();
        else if(ipt==6)
            rout();
        else if(ipt==0)
            exit(1);
        else
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        cin.clear();
        cin.sync();
        ipt=10;
    }
    return;
}

void Console::addE()
{
    int tmp=10;
    while(tmp!=0)
    {
        system("cls");
        cout<<"选课操作：\n"<<endl;
        cout<<"  选修选课：\n"<<endl;
        for(int i=1;i<=MAX_CLS;i++)
        {
            if(!q[i])
            {
                cout<<"    "<<i<<")"<<left<<setw(15)<<b[i].getName()
                <<"学分："<<left<<setw(5)<<b[i].getCredit()<<"\n"<<endl;
            }
        }
        cout<<"  0)结束选课\n"<<endl;
        cout<<"输入：";
        cin>>tmp;
        if(cin.fail())
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        if(tmp!=0)
        {
        exc.excStd(m.getcourseNumber());
        if(!exc.st&&tmp<=MAX_CLS&&tmp>0&&q[tmp]==0)
        {
            m.addCourse(&b[tmp]);
            q[tmp]=1;
            m.newG();exc.st=0;
        }
        //else if(tmp==0){exc.st=0;}
        else if(exc.st==0)
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        exc.st=0;
        }
        cin.clear();
        cin.sync();
    }
}

void Console::addO()
{
    int tmp=10;
    while(tmp!=0)
    {
        system("cls");
        cout<<"选课操作：\n"<<endl;
        cout<<"  必修选课：\n"<<endl;
        for(int i=1;i<=MAX_CLS;i++)
        {
            if(!p[i])
            {
                cout<<"    "<<i<<")"<<left<<setw(15)<<a[i].getName()
                <<"学分："<<left<<setw(5)<<a[i].getCredit()<<"\n"<<endl;
            }
        }
        cout<<"  0)结束选课\n"<<endl;
        cout<<"输入：";
        cin>>tmp;
        if(cin.fail())
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        if(tmp!=0)
        {
        exc.excStd(m.getcourseNumber());
        if(!exc.st&&tmp<=MAX_CLS&&tmp>0&&p[tmp]==0)
        {
            m.addCourse(&a[tmp]);
            p[tmp]=1;
            m.newG();
        }
        //else if(tmp==0){exc.st=0;}
        else
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        exc.st=0;
        }
        cin.clear();
        cin.sync();
    }
}

void Console::setgrade()
{
    int tmp=10;
    while(tmp)
    {
        system("cls");
        cout<<m.getName()<<"的课表：\n"<<endl;
        //cout<<"  已选课程量："<<m.getcourseNumber()<<"\n"<<endl;
        cout<<m;
        cout<<"  0)返回\n"<<endl;
        cout<<"请选择课程\n"<<endl;
        cout<<"输入：";
        cin>>tmp;
        if(cin.fail())
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        else if(tmp>0&&tmp<=m.getcourseNumber())
        {
            system("cls");
            m.setgrade(tmp);
            m.newG();exc.st=0;
        }
        else if(tmp==0)return;
        else if(exc.st==0)
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        exc.st=0;
        cin.clear();
        cin.sync();
    }
}

void Console::show()
{
    system("cls");
    int tmp=10;
    cout<<m.getName()<<"的课表：\n"<<endl;
    //cout<<"  已选课程量："<<m.getcourseNumber()<<"\n"<<endl;
    cout<<m;
    cout<<"  任意键返回\n"<<endl;
    cout<<"输入：";
    cin>>tmp;
    cin.clear();
    cin.sync();
}

void Console::rm()
{
    int tmp=10;
    while(tmp)
    {
        system("cls");
        cout<<m.getName()<<"的课表：\n"<<endl;
        //cout<<"  已选课程量："<<m.getcourseNumber()<<"\n"<<endl;
        cout<<m;
        cout<<"  0)返回\n"<<endl;
        cout<<"输入：";
        cin>>tmp;
        if(cin.fail())
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        else if(tmp>=1&&tmp<=m.getcourseNumber())
        {
            if(typeid(m[tmp-1])==typeid(ObligatoryCourse))
            {
                for(int i=1;i<=MAX_CLS;i++)
                {
                    if(a[i].getName()==m.getcourseName(tmp-1))
                    {
                        p[i]=0;a[i].setMark(0);break;
                    }
                }
            }
            else
            {
                for(int i=1;i<=MAX_CLS;i++)
                {
                    if(b[i].getName()==m.getcourseName(tmp-1))
                    {
                        q[i]=0;b[i].setGrade(0);break;
                    }
                }
            }
            m.removeCourse(tmp);
            m.newG();
        }
        else if(tmp==0)return;
        else
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        cin.clear();
        cin.sync();
    }
}

void Console::rout()
{
    ofstream outfile("student.txt",ios::out);
    outfile<<m;
    system("cls");
    cout<<"\n   已输出\n";
    exit(1);
}

Console::~Console()
{
    delete &m;//dtor
}

Console::Console(const Console& other)
{
    m=other.m;//copy ctor
}
