#include "student.h"
#include "time.h"
#include <iostream>
#include <cstring>
#include <string>
#include "course.h"
#include "obligatorycourse.h"
#include "electivecourse.h"
#include <typeinfo>
#include "myexception.h"
#define MAX_SIZE 10
using namespace std;
using std::ostream;
using std::istream;
int Student::counter=0;
Student::Student():name(NULL),birthDate(1,1,1)
{
    Time d(1,1,1);
    counter++;
    coursenumber=0;
}
Student::Student(char *n):name(n),birthDate(1,1,1)
{
    name=NULL;
    Time d(0,0,0);
    setStudent(n,d);
    counter++;
    coursenumber=0;
}
Student::Student(char *n,const int y,int m,int d):name(n),birthDate(y,m,d)
{
    name=NULL;
    Time date(y,m,d);
    setStudent(n,date);
    counter++;
    coursenumber=0;
}
Student::Student(const Student &s)
{
    name=s.name;
    birthDate=s.birthDate;
    counter++;
    coursenumber=s.coursenumber;
    for(int i=0;i<=s.coursenumber-1;i++)
    {
        courseList[i]=s.courseList[i];
    }
}
Student::~Student()
{
    int i=coursenumber-1;	//释放课程信息
	for(;i>=1;i--)
    {
		removeCourse(i);
	}
    delete[] name;
    counter--;
}
void Student::setStudent(const char *a,const Time d)
{
    setname(a);
    setbirthDate(d);
}
void Student::setname(const char *a)
{
    //s.getbirthDate();
    if(name)
        delete []name;
    name=new char[strlen(a)+1];
    strcpy(name,a);
}
void Student::setbirthDate(const Time d)
{
    birthDate=d;
}
char* Student::getname()const
{
    return name;
}
int Student::getcoursenumber()const
{
    return coursenumber;
}
Time Student::getbirthDate()const
{
    return birthDate;
}
void Student::printcounter()const
{
    cout<<"学生个数是"<<counter<<endl;
}
void Student::printstudent()const
{
    cout<<"他的名字是"<<getname()<<endl;
    cout<<"他的生日是";
    Time t=getbirthDate();
    cout<<t<<endl;
}

Student& Student::addCourse(Course *course)
{
    if(coursenumber>=MAX_SIZE)
    {
        cout<<"最多只能选"<<MAX_SIZE<<"课"<<endl;
        return (*this);
    }
    courseList[coursenumber]=course;
    coursenumber++;
    return (*this);
}
/*Student& Student::addCourse(const string &courseName,const int creditHour)
{
    if(coursenumber>=MAX_SIZE)
    {
        cout<<"最多只能选"<<MAX_SIZE<<"课"<<endl;
        return (*this);
    }
    Course *course1;
    Course acourse(courseName,creditHour);
    course1=&acourse;
    courseList[coursenumber]=course1;
    coursenumber++;
    return (*this);
}*/
void Student::printcoursenumber()const
{
    cout<<"已选课程数目是"<<coursenumber<<endl;
}
void Student::printcourseList()const
{
    for(int i=0;i<coursenumber;i++)
    {
        cout<<"课程名称"<<courseList[i]->getname()<<" "<<"学分"<<courseList[i]->getcreditHour()<<endl;
    }
}


bool Student::removeCourse(const int i)
{
    if(i>coursenumber)
    {
        return 0;
    }
    else
    {
        for(int j=i-1;j<=coursenumber-2;j++)
        {
            courseList[j]=courseList[j+1];
        }
        coursenumber--;
        return 1;
    }
}
bool Student::removeCourse(const string &s)
{
    int i=0;
    for(;i<=coursenumber-1;i++)
    {
        if(courseList[i]->getname()==s)
        {
            break;
        }
    }
    if(i>=coursenumber)
    {
        return 0;
    }
    else
    {
        i++;
        for(int j=i-1;j<=coursenumber-2;j++)
        {
            courseList[j]=courseList[j+1];
        }
        coursenumber--;
        return 1;
    }
}
bool Student::setCourseScore()
{
    int mark;
    char grade;
    for(int i=0;i<getcoursenumber();i++)
    {
        if(typeid(ObligatoryCourse)==typeid((*courseList[i])) )
        {
            cout<<"必修课程"<<(*courseList[i]).getname()<<"的成绩(0-100)：";
            cin>>mark;
            while(cin.fail())
                {
                    cout<<"请重新输入\n";
                    cin.clear();
                    cin.ignore();
                    cin>>mark;
                }
            if(mark>100||mark<0)
            {
                throw MyException(SCORE_INVALID);
            }
            dynamic_cast<ObligatoryCourse&> (*courseList[i]).setmark(mark);
        }
        else if(typeid(ElectiveCourse)==typeid((*courseList[i])))
        {
            cout<<"选修课程"<<(*courseList[i]).getname()<<"的成绩(A-E)：";
            cin>>grade;
           /* while(cin.fail())
            {
                    cout<<"请重新输入\n";
                    cin.clear();
                    cin.ignore();
                    cin>>grade;
            }
    cout<<grade<<endl;*/
            if((int)grade>(int)'E'||(int)grade<(int)'A')
            {
                throw MyException(SCORE_INVALID);
            }
            dynamic_cast<ElectiveCourse&>(*courseList[i]).setgrade(grade);
        }
        else
        {
            return 0;
        }
  }
  return 1;
}






int Student::calObligatorycredit() const
{
    int ans=0;
    for(int i=0;i<=coursenumber-1;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            ans=ans+(*courseList[i]).getcreditHour();
        }
    }
    return ans;
}
int Student::calElectivecredit() const
{
    int ans=0;
    for(int i=0;i<=coursenumber-1;i++)
    {
        if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            ans=ans+(*courseList[i]).getcreditHour();
        }
    }
    return ans;
}
int Student::calObligatoryNumber() const
{
    int ans=0;
    for(int i=0;i<=coursenumber-1;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            ans=ans+1;
        }
    }
    return ans;
}
int Student::calElectiveNumber() const
{
    int ans=0;
    for(int i=0;i<=coursenumber-1;i++)
    {
        if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            ans=ans+1;
        }
    }
    return ans;
}
double Student::calAchievement()
{
    //cout<<"  123"<<endl;
    //cout<<calObligatorycredit()<<endl;
    //cout<<calElectiveNumber()<<endl;

    int obligatoryCredit=calObligatorycredit();
    int electiveNumber=calElectiveNumber();
    int obligatoryAchievement=0;
    int electiveAchievement=0;
    for(int i=0; i<coursenumber;i++){
        if( typeid(ObligatoryCourse)==typeid((*courseList[i])))
            obligatoryAchievement+=(*courseList[i]).getScore()*(*courseList[i]).getcreditHour();
        if( typeid(ElectiveCourse)==typeid((*courseList[i])))
            electiveAchievement+=(*courseList[i]).getScore();
    }
    double result=0;
    if(obligatoryCredit>0)
        result+=(double)0.6*(double)obligatoryAchievement/(double)obligatoryCredit;
    if(electiveNumber>0)
        result+=(double)0.4*(double)electiveAchievement/(double)electiveNumber;
    return result;
    //return 1;
}
ostream& operator<<(ostream& output, const Student& s)
{
	Time t=s.getbirthDate();
	output<<"姓名："<<s.name<<"\n出生日期："<<t.getyear()<<"-"<<t.getmonth()<<"-"<<t.getday()
		//<<"\n积点成绩："<<s.calAchievement()
		<<"    "<<s.calObligatoryNumber()
		<<"\n选课信息如下：\n";
	for(int i=0;i<s.coursenumber;i++){
		 output<<(*s.courseList[i])<<"\n";
	}
	return output;
}
Course* Student::operator[](int sub) const
{
	if (sub< 0||sub>=coursenumber ){
	   throw MyException(RANGE_ERROR);
	}
	return (courseList[sub]);
}
