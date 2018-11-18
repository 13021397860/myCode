#include "Student.h"
#include "date.h"
#include<iostream>
#include<cstring>
#include<iomanip>
#include<typeinfo>
#include<cstdlib>
#include<exception>
using namespace std;
int Student::count_stu = 0;
Student::Student(char *const s,const int y,const int m,const int d)
{
    name = new char;
    Set(s,y,m,d);
    count_stu++;
    courseNumber = 0;
}
Student::Student(Student const &x)
{
    name = new char;
    int y,m,d;
    y = x.birthdate.getyear();
    m = x.birthdate.getmonth();
    d = x.birthdate.getday();
    Set(x.name,y,m,d);
    count_stu++;
}
Student::~Student()
{
    count_stu--;
    delete []name;
    int i=courseNumber-1;
    while(i>0){
        if(removeCourse(i)) i--;
    }

}
void Student::Set( char * const s,int y,int m,int d)
{
    strcpy(name,s);
    birthdate.Set(y,m,d);
}
void Student::get_name(char *&s) const
{
    s=new char;
    strcpy(s,name);
}
void Student::get_birthday(Date &D) const
{
     D = birthdate;
}
void Student::print()
{
    cout<<name<<" ";
    cout<<birthdate;
}
int Student::getCount()
{
    return count_stu;
}
Student& Student::addCourse(Course *course){
    courseList[courseNumber++] = course;
    return *this;
}
bool Student::removeCourse(int n){
    if(n<=0||n>courseNumber) throw -3;
    for(int i=n-1;i<courseNumber-1;i++){
        courseList[i] = courseList[i+1];
    }
    courseNumber--;
    cout<<"remove the course successfully!\n";
    return true;
}
ostream &operator << (ostream &output, const Student&p){
    cout << "name: ";
    output<<p.name;
    cout<<"\tbirthday: ";
    output<<" "<<p.birthdate.getyear()<<" "<<p.birthdate.getmonth()<<" "<<p.birthdate.getday()<<"\n";
    cout<<setw(32)<<left<<"\nselect course\t"<<"creditHour\t"<<"grade\t"<<"course_type\n";
    for(int i=0;i<p.courseNumber;i++){
        cout <<i+1<<". ";
        output <<*p.courseList[i];
        //output <<setw(4)<<left;

        if(typeid(ObligatorayCourse) == typeid(*p.courseList[i])){
            output<<"\t";
            output<<"Obligatory\n";
            //output<<1<<endl;
        }
        else{
            output<<"\t";
            output<<"Elective\n";
            //output<<2<<endl;
        }
    }
    return output;
}
double Student::calcCredit(){
    const double wo = 0.6,we = 0.4;
    double sum = 0;
    double o_credit = 0,e_num = 0;
    for(int i=0;i<courseNumber;i++){
        if(typeid(*courseList[i]) == typeid(ObligatorayCourse)){
            o_credit += courseList[i]->getcreditHour();
        }
        else if(typeid(*courseList[i]) == typeid(ElectiveCourse)){
            e_num++;
        }
    }
    for(int i=0;i<courseNumber;i++){
        if(typeid(*courseList[i]) == typeid(ObligatorayCourse)){
            ObligatorayCourse *ptr = dynamic_cast<ObligatorayCourse*>(courseList[i]);
            sum += wo*(ptr->getscore())*(ptr->getcreditHour())/o_credit;
        }
        else if(typeid(*courseList[i]) == typeid(ElectiveCourse)){
            ElectiveCourse *ptr = dynamic_cast<ElectiveCourse*>(courseList[i]);
            sum += we*(ptr->getscore())/e_num;
        }
    }
    return sum;
}
