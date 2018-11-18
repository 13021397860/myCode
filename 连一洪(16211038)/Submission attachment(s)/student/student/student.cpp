#include "student.h"
#include "date.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include<iostream>
#include<cstring>
#include <typeinfo>
#include <fstream>
using namespace std;
using std::ostream;

int Student::counter=0;
Student::Student():birthdate(2000,1,1){
    const string n="Barry";
    setName(n);
    ++counter;
    //cout<<"This is NO."<<counter<<" student."<<endl;
}

Student::Student(const Student &a):birthdate(a.birthdate){
    //name = new char[strlen(a.name)+1];
    name = a.name;
    ++counter;

    //cout<<"This is NO."<<counter<<" student."<<endl;
}
Student::~Student(){
    int i=coursenumber-1;
    while(i>0){
        if(removeCourse(i))
            i--;
    }
   // delete name;

  //  delete name;
    --counter;
   // cout<<"After deleting,"<<endl;
    //cout<<"The number of the students is: "<<counter<<endl;
    //dtor
}
int Student::getCounter(){
    return counter;
}

string Student::getName()const{
    return name;
}

int Student::getbirthdateYear()const{
    return birthdate.getYear();
}

int Student::getbirthdateMonth()const{
    return birthdate.getMonth();
}

int Student::getbirthdateDay()const{
    return birthdate.getDay();
}

int Student::getcoursenumber()const{
    return coursenumber;
}

void Student::setcoursenumber(){
    coursenumber=0;
}

void Student::setName(string n){
   /* if(name)
    delete name;
    name = new char[n.length()+1];*/
    name=n;
}
void Student::setbirthdate(int y,int m,int d){

    birthdate.setDate(y,m,d);
}
/*
void Student::printStudent()const{
    cout<<"Name:"<<name<<endl;
    cout<<"Birth date: ";
    birthdate.printDate();
    cout<<endl;
}
*/
ofstream fout("f:\\Student.txt",ios::out);

ostream& operator << (ostream& output, const Student &s)
{
    output<<"Name: "<<s.name<<"\tBirth date: "<<s.birthdate<<",   The information of courses selection: "<<"\n";
    for(int i=0; i<s.getcoursenumber(); i++){
        output<<*(s.courseList[i])<<endl ;
    }
    return output;
}


Student& Student::addCourse(Course *course){
    if(dynamic_cast<ObligatoryCourse*>(course)){
         courseList[coursenumber] = new ObligatoryCourse;
    }
    else if(dynamic_cast<ElectiveCourse*>(course)){
         courseList[coursenumber] = new ElectiveCourse;
    }
    courseList[coursenumber++]=course;
}
/*
Student& Student::addCourse2(const string &courseName, int creditHour){
    if(coursenumber<Total_Num){
        courseList[coursenumber++]=new Course(courseName, creditHour);
    }
}
/*
bool Student::removeCourse(const string& courseName){
    int i=0;
    for(int i=0;i<courseNumber;i++){
        if(courseName==courseList[i]->getName())
        break;
    }
    if(i<courseNumber){
        return removeCourse(i);

    }
    else{
        return false;
    }
}*/

bool Student::removeCourse(int i){
    if(i<coursenumber){
        //cout<<coursenumber<<endl;
        delete courseList[i];
        for(int j=i;j<coursenumber-1;j++)
        {
            courseList[j]=courseList[j+1];
        }
        coursenumber--;
        //cout<<coursenumber<<endl;
        return true;
    }
    else{
        throw Course_exception();
        return false;
    }
}

bool Student::setCourseScore(int num){
    if(num<coursenumber+1){
        if(typeid(ObligatoryCourse)==typeid(*courseList[num-1])){
            cout<<"Please input your ObligatoryCourse's mark:";
            int marks;
            cin>>marks;
            if(marks<0||marks>100){
                throw Mark_exception();
                return false;
            }
            else if(cin.fail()){
                cin.clear();
                cin.ignore();
                throw Mark_exception();
                return false;
            }
            else{
                dynamic_cast<ObligatoryCourse*>(courseList[num-1])->setMark(marks);
                cout<<"courseScore:"<<marks<<endl;
                return true;
            }

        }
        else if(typeid(ElectiveCourse)==typeid(*courseList[num-1])){
             cout<<"Please input your ElectiveCourse's grade from 'A' to 'E':";
             char grades;
             cin>>grades;
             if(grades<'A'||grades>'E'){
                throw Mark_exception();
                return false;
             }
             else if(cin.fail()){
                 cin.clear();
                 cin.ignore();
                 throw Mark_exception();
                 return false;
             }
             else{
                 dynamic_cast<ElectiveCourse*>(courseList[num-1])->setGrade(grades);
                 cout<<"courseScore:"<<grades<<endl;
                 return true;
             }
        }
        else{
            throw Course_exception();
            return false;
        }
    }
    else{
        throw Course_exception();
        return false;
    }
}

int Student::totalObCreditHour(){
    int total=0;
    for(int i=0;i<coursenumber;i++){
        if(typeid(ObligatoryCourse)==typeid(*courseList[i])){
            total+=courseList[i]->getCreditHour();
        }
    }
    return total;
}

int Student::sumObliCourse(){
    int sum=0;
    for(int i=0;i<coursenumber;i++){
        if(typeid(ObligatoryCourse)==typeid(*courseList[i])){
            sum+=(courseList[i]->getscore()*courseList[i]->getCreditHour());
        }
    }
    return sum;
}

int Student::totalElCourseNumber(){
    int total=0;
    for(int j=0;j<coursenumber;j++){
        if(typeid(ElectiveCourse)==typeid(*courseList[j])){
            total++;
        }
    }
    return total;
}

int Student::sumElecCourse(){
    int sum=0;
    for(int j=0;j<coursenumber;j++){
        if(typeid(ElectiveCourse)==typeid(*courseList[j])){
            sum+=courseList[j]->getscore();
        }
    }
    return sum;
}

float Student::calcCredit(){
    float totalcalcCredit;
    //cout<<sumObliCourse()<<"***!!!***"<<sumElecCourse()<<"***!!!***"<<totalObCreditHour()<<"***!!!***"<<totalElCourseNumber()<<"***!!!***\n";
    totalcalcCredit=0.6*sumObliCourse()/totalObCreditHour()+0.4*sumElecCourse()/totalElCourseNumber();
    return totalcalcCredit;
}










