#include <iostream>
#include "Date.h"
#include "Student.h"
#include "Console.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <typeinfo>
using namespace std;

int main()
{
    /*Student *s=new Student("s",2,2,2);
    Student p=*s;
    Course *a=new ElectiveCourse("sd",1,'C');
    Course *b=new ObligatoryCourse("ds",3,100);
    p.addCourse(a);
    p.addCourse(b);
    cout<<p<<endl;
    cout<<p.calCredit()<<endl;
    p.getCourseScore(1);
    p.getCourseScore(2);*/
    Console a;
    Student s=a.informationcin();
    int counter=0;
    while ( a.initialscreem(s)==1)  counter++;
    cout<<"  "<<counter<<endl;


}
