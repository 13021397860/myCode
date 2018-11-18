#include "Student.h"
#include "MyException.h"
#include<iostream>
#include<cstring>
using namespace std;

int Student::count=0;

Student::Student(char *n,int y,int m,int d)
{
    name =NULL;
    courseNumber=0;
    Credit=0;
    //name=new char[1000];
    if(n==NULL)setNameBirthday("ABC",y,m,d);
    else setNameBirthday(n,y,m,d);
    count++;
}

Student::Student(const Student &s)
{
    name=s.name;
    birthDate=s.birthDate;
}
Student::~Student()
{
    delete[] name;
    for(int i=1;i<=courseNumber;i++){
        delete courseList[i-1];
        courseList[i-1]=NULL;
    }
}

void Student::setNameBirthday(char *n,int y,int m,int d)
{
    delete []name;
    if(n==NULL)strcpy(name,"ABC");
    else {
        int len=strlen(n);
        name=new char[len+1];
        strcpy(name,n);
        //strncpy(name,n,999);
        CheckNamelen();
        birthDate.setDate(y,m,d);
    }
}

void Student::CheckNamelen()
{
    int n=strlen(name);
    if(n>20 || n==0){
        name="ABC";
        cout<<"长度超出20，已重置为ABC"<<endl;
    }
}

void Student::print()
{
    for(int i=0;i<courseNumber;i++){
    cout<<"Course name:\n";
    cout<<courseList[i]->getName()<<endl;
    cout<<"Course type:\n";
    cout<<courseList[i]->getCourseType()<<endl;
    cout<<"Course Credit Hour:\n";
    cout<<courseList[i]->getCreditHour()<<endl;
    cout<<"Course Score:\n";
    cout<<courseList[i]->getScore()<<endl;
    cout<<endl;
    }
}

ostream& operator<<(ostream& os,const Student & p){
    os << "Name:"<<p.getName();
    os << " ";
    os << "Birthday:"<<p.getBirthDateyear() << "-" << p.getBirthDatemonth() << "-" << p.getBirthDateday() << "\n";
    os << "Credit:"<<p.Credit<<"\n";
       for(int i=1;i<=p.getCourseNumber();i++){
            if(p.getCourse(i)!=NULL){
            os<<i<<": ";
            os<<p.getCourse(i)->toString()<<endl;
         }
    }
    return os;
}

bool Student::removeCourse(int i)
{
    if(i>courseNumber || i<=0){throw MyException(range);return false;}
    else{
        delete courseList[i-1];
        courseList[i-1]=NULL;
        for(int j=i;j<courseNumber;j++){
            courseList[j-1]=courseList[j];
            courseList[j]=NULL;
        }
        courseNumber--;
        if(courseNumber==0)Credit=0;
        else{
            Student::calcCourseType();
            Student::calcCredit();
        }
        return true;
    }
}

Course* Student::getCourse(int n) const{
    if(n<=0 || n>courseNumber){throw MyException(range); return NULL;}
    else
    return courseList[n-1];
}

Student& Student::addCourse(Course *course){
    if(course){
        courseList[courseNumber]=NULL;
        courseList[courseNumber++]=course;
    }
    Student::calcCourseType();
    Student::calcCredit();
    return *this;
}

Student& Student::addCourse(const string &courseName, int creditHour){
    return *this;
}

void Student::calcCourseType()
{
    ObCourseNum=ElCourseNum=ObCourseCreditHour=ObCourseScore=ElCourseScore=0;
    string a;
    for(int i=0;i<courseNumber;i++){
        a=courseList[i]->getCourseType();
        if(a=="ObligatoryCourse"){
            ObCourseNum++;
            ObCourseCreditHour+=courseList[i]->getCreditHour();
            ObCourseScore+=courseList[i]->getScore()*courseList[i]->getCreditHour();
        }
        else if(a=="ElectiveCourse"){
            ElCourseNum++;
            ElCourseScore+=courseList[i]->getScore();
        }
    }
}

void Student::calcCredit()
{
    if(ElCourseNum==0)ElCourseNum=1;
    if(ObCourseCreditHour==0)ObCourseCreditHour=1;
    Credit=(ObCourseWeight*ObCourseScore)/ObCourseCreditHour+(ElCourseWeight*ElCourseScore)/ElCourseNum;
}
