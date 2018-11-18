#include "Student.h"
#include "Date.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <typeinfo>
#include<fstream>
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"

int Student::count=0;

Student::Student(char *s,int y,int m,int d)
{
    setMessage(s,y,m,d);
    courseNumber=0;
    ++count;
}

Student::Student(char *s,Date birthday)
{
    setName(s);
    birthDate=birthday;
    courseNumber=0;
    ++count;
}

Student::Student(const Student& t)
{
    name=NULL;
	setName(t.name);
	birthDate=t.birthDate;
	courseNumber=0;
	++count;
}

void Student::setMessage(char *s,int y,int m,int d)
{
    setName(s);
    setBirthDate(y,m,d);
}

void Student::setName(char *s)
{
    name=new char[20];
    if(s==NULL){
        cout<<"Your name is null, system will set a name for you."<<endl;
        char change_name[20]="Lucy";
        strcpy(name,change_name);
    }
    else{
        int len=strlen(s);
        if(len>20){
            cout<<"Your name is too long, system will set a name for you."<<endl;
            char change_name[20]="Andy";
            strcpy(name,change_name);
        }
        else{
            strcpy(name,s);
        }
    }
}

void Student::setBirthDate(int y,int m,int d)
{
    birthDate.setDate(y,m,d);
}

char* Student::getName() const
{
    return name;
}

Date Student::getBirthDate() const
{
    return birthDate;
}

int Student::getCount()
{
    return count;
}

int Student::getCourseNumber() const
{
    return courseNumber;
}

Student& Student::addCourse(Course *course)
{
    if(courseNumber>=MAX_SIZE){
        cout<<"You can't choose more than "<<MAX_SIZE<<" courses."<<endl;
    }
    else{
        int flag=0;
        for(int i=0;i<courseNumber;i++){
            if(stricmp(course->getName().c_str(),courseList[i]->getName().c_str())==0){
                cout<<"You can't choose the course '"<<course->getName()<<"' again"<<endl;
                flag=1;
                break;
            }
        }
        if(!flag){
            cout<<"Congratulations. Enjoy your new course."<<endl;
            courseList[courseNumber]=course;
            courseNumber++;
        }
    }
    return *this;
}

//Student& Student::addCourse(const string &courseName, int creditHour)
//{
//    if(courseNumber>MAX_SIZE){
//        cout<<"You can't choose more than "<<MAX_SIZE<<" courses"<<endl;
//    }
//    else{
//        Course *course=new Course();
//        course->setName(courseName);
//        course->setCreditHour(creditHour);
//        courseList[courseNumber]=course;
//        courseNumber++;
//    }
//    return *this;
//}

bool Student::removeCourse(int num)
{
    int x=getCourseNumber();
    if(num>x||num<1){
        return false;
    }
    for(int i=num;i<x;i++){
        courseList[i-1]=courseList[i];
    }
    courseNumber--;
    return true;
}


void Student::setCourseScore(int num,int score)
{
    Course *cPtr=courseList[num-1];
    cPtr->setScore(score);
}

float Student::calcCredit()
{
    float oblNumerator=0,oblDenominator=0,eleNumerator=0,eleDenominator=0;
    float oblSum=0,eleSum=0,oblWeight=0.6,eleWeight=0.4,res=0;
    ObligatoryCourse *obl=new ObligatoryCourse();
    ElectiveCourse *ele=new ElectiveCourse();
    Course *cPtr;
    for(int i=0;i<getCourseNumber();i++){
        cPtr=courseList[i];
        if(typeid(*cPtr).name()==typeid(*obl).name()){
            oblNumerator+=cPtr->getScore()*cPtr->getCreditHour();
            oblDenominator+=cPtr->getCreditHour();
        }
        else if(typeid(*cPtr).name()==typeid(*ele).name()){
            eleNumerator+=cPtr->getScore();
            eleDenominator++;
        }
    }
    if(oblDenominator!=0){
        oblSum=oblNumerator/oblDenominator;
    }
    if(eleDenominator!=0){
        eleSum=eleNumerator/eleDenominator;
    }
    res=oblWeight*oblSum+eleWeight*eleSum;
    delete obl;
    delete ele;
    obl=NULL;
    ele=NULL;
    return res;
}

void Student::getCourseScore(int i) const
{
    cout<<*courseList[i-1]<<endl;
}

void Student::readCourseMessage() const
{
    readObligatoryCourseMessage();
    readElectiveCourseMessage();
}

void Student::readObligatoryCourseMessage() const
{
    ifstream inFile("obligatoryCourseMessage.dat", ios::in);
    if(inFile){
        string line;
        while(getline(inFile,line)){
            cout<<line<<endl;
        }
    }
    else{
        cout<<"There are some errors when open the file."<<endl;
    }
    inFile.close();
}

void Student::readElectiveCourseMessage() const
{
    ifstream inFile("electiveCourseMessage.dat", ios::in);
    if(inFile){
        string line;
        while(getline(inFile,line)){
            cout<<line<<endl;
        }
    }
    else{
        cout<<"There are some errors when open the file."<<endl;
    }
    inFile.close();
}

void Student::safeMessage() const
{
    ofstream outfile("studentMessage.txt",ios::out);
    outfile<<*this;
    outfile.close();
    cout<<"Safe succeed."<<endl;
}

ostream &operator<<(ostream &output,const Student &student)
{
    output<<"Name:"<<left<<setw(15)<<student.getName()<<
        "BirthDate:"<<student.birthDate<<endl;
    int x=student.getCourseNumber();
    if(x==0){
       output<<"You haven't chosen any courses. Why not choose a course?"<<endl;
    }
    else{
        output<<"You have chosen "<<x<<" course";
        if(x>1){
            output<<'s';
        }
        output<<'.'<<endl;
        Course *cPtr;
        for(int i=0;i<student.getCourseNumber();i++){
            cPtr=student.courseList[i];
            output<<'('<<i+1<<')'<<*cPtr<<endl;
        }
    }
    return output;
}

Student::~Student()
{
    delete []name;
    name=NULL;
    count--;
}
