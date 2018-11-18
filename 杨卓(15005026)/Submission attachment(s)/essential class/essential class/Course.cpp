#include "Course.h"
#include <iostream>
#include <string>
using namespace std;
Course::Course(){

}
Course::Course(string names,int credit)
{
    setcoursename(names);
    setcredithour(credit);
    //ctor
}

Course::~Course()
{
    //dtor
}
void Course::setcoursename(string names){

    CourseName=names;
}
void Course::setcredithour(int credit){
    creditHour=credit;
}

ostream& operator << (ostream &os, const Course &cc){
    os<<"coursename:"<<cc.getcoursename()<<"    credithour:"<<cc.getcredithour()<<"    score:"<<cc.getScore()<<endl;
    return os;
}

