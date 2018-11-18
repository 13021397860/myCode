#include "student.h"
#include<string.h>
#include<iostream>
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "MyException.h"
using namespace std;
int student::Count=0;
student::student(char n[],Date bd)
{
    name=NULL;
    if(n==NULL)
    {
        Count++;
        name=new char[10];
        name="Nameless";
    }
    else
    {
        Count++;
        name=new char[strlen(n)+1];
        strcpy(name,n);
    }
    birthday=bd;
}
student::student(const student &s)
{
    Count++;
    name=new char[strlen(s.name)+1];
    strcpy(name,s.name);
    birthday=s.birthday;
}
student::~student()
{
    cout<<"xigou"<<endl;
    Count--;
    while(this->Coursenumber--)
    {
        cout<<this->Coursenumber;
        delete this->courselist[Coursenumber];
    }
    if(name!=NULL)
        {delete []name;
        }
}
Date student::getBirthday()
{
    return birthday;
}
char* student::getName()
{
    return name;
}
void student::setBirthday(Date bd)
{
    birthday=bd;
}
void student::setName(char n[])
{
    if(name!=NULL)
    {
        delete []name;
    }
    if(n!=NULL)
    {
        name=new char[strlen(n)+1];
        strcpy(name,n);
    }
    else
    {
        name=new char[9];
        name="Nameless";
    }
}
student& student::addCourse (Course *course)
{
    if(course==NULL) cout<<"Error"<<endl;
    else if(Coursenumber>=MAX) cout<<"FULL"<<endl;
    else
    {
        courselist[Coursenumber]=course;
        Coursenumber++;
    }
    return *this;
}
std::ostream& operator << (ostream& out, const student& c)
{
    out<<c.name<<"  "<<c.birthday.getYear()<<" "<<c.birthday.getMonth()<<" "<<c.birthday.getDay()<<endl;
    int i=c.Coursenumber;
    while(i--)
    {
        out<<*c.courselist[i]<<endl;
    }
    return out;
}
bool student::removeCourse(int i)
{
    if(i>0 && i<=this->Coursenumber)
    {Course *tt;
    tt=this->courselist[i-1];
    for(int j=i-1;j<this->Coursenumber-1;j++)
        this->courselist[j]=this->courselist[j+1];
    delete tt;
    this->Coursenumber--;
    return true;}
    else
        return false;

}
void student::choseclass()
{
    char cz;
    cout<<"1.Elective Course\n2.Obligatory Course"<<endl;
        cin>>cz;
        if(cz=='1')
        {
            int time;
            string nme;
            int sor;
            cout<<"input::time name grade"<<endl;
            while(1)
             {
                 try{
                    cin>>time>>name>>sor;
                    if(time<0 or sor>100 or sor<0) throw MyException (SCORE_INVALID);
             break;}
             catch(MyException ex)
        {
            cout<<"ERRor£º"<<ex.what()<<"\n";
            cout<<"input again\n";
        }
             }

            Course *c=new ElectiveCourse(time,nme,sor);
            this->addCourse(c);
        }
        else
        {
             int time;
            string nme;
            int  sor;
             while(1)
             {
                 try{
                    cin>>time>>name>>sor;
                    if(time<0 or sor>100 or sor<0) throw MyException (SCORE_INVALID);
             break;}
             catch(MyException ex)
        {
            cout<<"ERRor£º"<<ex.what()<<"\n";
            cout<<"input again\n";
        }
             }
           Course *c=new ObligatoryCourse(time,nme,sor);
            this->addCourse(c);
        }
}
bool student::setscore(int i)
{
    if(i>0 && i<=this->Coursenumber)
    {
         int k;
         cout<<"1.Elective Course\n2.Obligatory Course"<<endl;
         cin>>k;
         if(k==1)
         {
             cout<<"input score:"<<endl;
             char ss;
             while(1)
             {
                 try{
                    cin>>ss;
                    if(ss<'A' or ss>'E') throw MyException (SCORE_INVALID);
             break;}
             catch(MyException ex)
        {
            cout<<"ERRor£º"<<ex.what()<<"\n";
            cout<<"input again\n";
        }
             }
             this->courselist[this->Coursenumber-1]->setscore(ss);}
         else
         {
                int ss;
                cout<<"input mark:"<<endl;
                while(1)
             {
                 try{
                    cin>>ss;
                    if(ss<0 or ss>100) throw MyException (SCORE_INVALID);
             break;}
             catch(MyException ex)
        {
            cout<<"ERRor£º"<<ex.what()<<"\n";
            cout<<"input again\n";
        }
             }
             this->courselist[this->Coursenumber-1]->setscore(ss);
         }

    return true;
    }
    else
        return false;

}
double student::calcCredit()
{
    if(Coursenumber!=0)
    {double sumgXc=0.0,sumcredit=0.0,sumgrade=0.0,sumnum=0.0;
    for(int i=0;i<Coursenumber;i++)
    {
        if(typeid(*courselist[i])==typeid(ObligatoryCourse))
        {
            sumgXc=sumgXc+courselist[i]->getscore()*courselist[i]->getcredithour();
            sumcredit=sumcredit+this->courselist[i]->getcredithour();
        }
        else
        {
            sumnum++;
            sumgrade=sumgrade+courselist[i]->getscore();
        }
    }
    if(sumcredit!=0 && sumnum!=0)
    return 0.6*(sumgXc/sumcredit)+0.4*(sumgrade/sumnum);
    else if(sumcredit==0 && sumnum!=0)
        return 0.4*(sumgrade/sumnum);
    else if(sumcredit!=0 && sumnum==0)
        return 0.6*(sumgXc/sumcredit);
    }
    return 0;

}

