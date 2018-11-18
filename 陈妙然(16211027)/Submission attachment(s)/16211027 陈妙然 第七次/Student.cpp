#include "Student.h"
#include "Course.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "MyException.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
using namespace std;
int Student::count=0;
int Student::coursenumber=0;

Student::Student()
{

}



Student::Student(const char *const n,int m,int d,int y)
    :birthDate(m, d, y)
{
    name=NULL;
    setname(n);

	count++;
}

Student::Student(const char* const n,const Date &d)
	:birthDate(d)
	{
        name=NULL;
        setname(n);
        count++;
    }

    Student::Student(const Student &s)
    :birthDate(s.birthDate)
    {
        name=NULL;
        setname(s.name);
        count++;
    }

void Student::setname(const char*n)
{
    if (name) delete[] name;
    name=new char[strlen(n)+1];
    strcpy(name, n);
}

char* Student::getname() const
{
    return name;
}
Date Student::getbirth() const
{
    return birthDate;
}
void Student::printeve() const
{
    cout<<getname()<<endl;
    cout<<birthDate;
    //cout<<"count is: "<<count<<endl;
}

Student& Student::addCourse(Course *course)
{
        if(coursenumber<maxsize)
        {
            courselist[coursenumber]=course;
            coursenumber++;
        }
        return (*this);
}

void Student::test()
{
               int timeob=0;
           int timeel=0;

            for(int i=0;i<coursenumber;i++)
        {
        if(typeid(ObligatoryCourse)==typeid(*courselist[i]))
        {
            timeob++;
            cout<<"nametest"<<courselist[i]->name<<endl;
            cout<<"testnumob"<<timeob<<endl;
        }
        else if(typeid(ElectiveCourse)==typeid(*courselist[i]))
        {
            timeel++;
            cout<<"nametest"<<courselist[i]->name<<endl;
            cout<<"testnumec"<<timeel<<endl;
        }
        }
}

void Student::calcCredit()
{
    double sumob=0.0;
    double sumec=0.0;
    int numob=0,numec=0;
    double result=0.0;
    for(int i=0;i<coursenumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courselist[i]))
        {
            numob+=courselist[i]->creditHour;
            //cout<<"testcredit"<<courselist[i]->creditHour<<endl;
            //cout<<"testnumob"<<numob<<endl;
        }
        else if(typeid(ElectiveCourse)==typeid(*courselist[i]))
        {
            numec++;
            //cout<<"testnumec"<<numec<<endl;
        }
    }
    for(int i=0;i<coursenumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courselist[i]))
        {
            //cout<<"testscore"<<courselist[i]->getmyscore()<<endl;
            sumob=(courselist[i]->myscore*courselist[i]->creditHour);
            sumob=sumob/numob;
           // cout<<"testnumob"<<numob<<endl;
           // cout<<"test"<<courselist[i]->myscore<<endl;
           // cout<<"test"<<courselist[i]->creditHour<<endl;
            result+=0.6*sumob;
           // cout<<"testresult"<<result<<endl;
        }
        else if(typeid(*courselist[i])==typeid(ElectiveCourse))
        {
           // cout<<"testcredit"<<courselist[i]->creditHour<<endl;
            sumec=courselist[i]->myscore/numec;
            result+=0.4*sumec;
        }
    }
    cout<<"Your GPA is :"<<endl;
    cout<<result<<endl;
}

void Student::printalone(int i,int score)
{
    courselist[i]->printcourseinfor();
    courselist[i]->myscore=score;
    cout<<"the score is"<<score<<endl;
}

void Student::printzifu(int i,char score)
{
    courselist[i]->printcourseinfor();
    int temp;
    temp=getscoreel(score);
    courselist[i]->myscore=temp;
    cout<<"the score is"<<temp<<endl;

}


void Student::printcourselist() const
{
    for(int i=0;i<coursenumber;i++)
    {
        courselist[i]->printcourseinfor();
    }
        cout<<"You have chosen "<<coursenumber<<" course"<<endl;

}

void Student::printcourselistfu() const
{
    for(int i=0;i<coursenumber;i++)
    {
        courselist[i]->printcourseinforfu();
    }
        cout<<"You have chosen "<<coursenumber<<" course"<<endl;
}


int Student::getcoursenumber() const
{
    return coursenumber;
}
int Student::getscoreel(char grade) const
{
    switch (grade)
    {
        case 'A':
            {
                return 95;
            }
        case 'B':
            {
                return 85;
            }

        case 'C':
            {
                return 75;
            }

        case 'D':
            {
                return 65;
            }

        case 'E':
            {
                 return 55;
            }

        default:
            return 0;
    }
}

bool Student::removeCourse(int i)
{
    if(i<coursenumber)
    {
        delete courselist[i];
        for(int j=i;i<coursenumber-1;j++)
        {
            courselist[j]=courselist[j+1];
        }
        coursenumber--;
        return true;
    }
    else
    {
        return false;
    }
}

ostream &operator <<(ostream &output,Student &xinxi)
{
    output<<xinxi.getname()<<"  "<<xinxi.getbirth();
    for(int i=0;i<xinxi.coursenumber;i++)
    {
        //xinxi.courselist[i]->printcourseinforfu();
        string name1;
        name1=xinxi.courselist[i]->getname();
        int cre;
        cre=xinxi.courselist[i]->getcredit();
        int sc;
        sc=xinxi.courselist[i]->getmyscore();
        output<<"the course is:"<<name1<<endl;
        output<<"the creditHour is:"<<cre<<endl;
        output<<"the score is:"<<sc<<endl;
    }
        output<<"You have chosen "<<xinxi.coursenumber<<" course"<<endl;
    return output;
}

void Student::shezhichengji(Student &s)
{
    int score;
    char grade;
    for(int i=0;i<s.getcoursenumber();i++)
    {

        if(typeid(*s.courselist[i])==typeid(ObligatoryCourse))
        {
            cout<<dynamic_cast<ObligatoryCourse&>(*s.courselist[i])<<endl;
            cout<<"type the score (1-100)"<<endl;
            //cout<<"testnameobli"<<s.courselist[i]->name<<endl;
            cin>>score;
                while(score<1||score>100)
            {
                cerr<<"Type the reasonable score(1-100)"<<endl;
                cout<<"The score is:"<<endl;
                MyException testscore;
                try
                {
                    cin>>score;
                    testscore.testsc(score);
                }
                catch(int score)
                {
                    cout<<"Invaild score!"<<endl;
                    cout<<"Please type it again!"<<endl;
                     cin>>score;
                }
            }
            s.printalone(i,score);
            cout<<endl;
        }
        if(typeid(*s.courselist[i])==typeid(ElectiveCourse))
        {
            cout<<dynamic_cast<ElectiveCourse&>(*s.courselist[i])<<endl;
            cout<<"type the grade (A-E)"<<endl;
           // cout<<"testnameele"<<s.courselist[i]->name<<endl;
                MyException gr;
                try
                {
                    cin>>grade;
                    gr.testgrade(grade);
                }
                catch(char grade)
                {
                    cout<<"Invaild grade!"<<endl;
                    cout<<"Please type it again!"<<endl;
                                    cout<<"The grade is:"<<endl;
                cin>>grade;
                }
            s.printzifu(i,grade);
            cout<<endl;
        }
        cout<<endl;
    }
}


Student::~Student()
{
    int i=coursenumber-1;
	while(i>0){
		if (removeCourse(i)) i--;
	}
    delete []name;
    count--;
}
