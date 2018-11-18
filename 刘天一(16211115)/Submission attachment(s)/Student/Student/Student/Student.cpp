#include "Student.h"
#include "../Course/ObligatoryCourse.h"
#include <cstring>
using namespace std;
#define obli_weight 0.6
#define elec_weight 0.4
int Student::count=0;
Student::Student()
{

}
Student::Student(char *N,Date &D)
        :birthDate(D)
{
    name =new char[strlen(N)+1];
    strcpy(name,N);
    ++count;
}
Student::Student(const Student &S)
        :birthDate(S.birthDate)
{
    name=new char[strlen(S.name)+1];
    strcpy(name,S.name);
    ++count;
}

Student::~Student()
{
    delete []name;
    delete []courseList;
    --count;
}

ostream &operator<<(ostream& output,const Student& s)
{
    output<<"name:  ";
    int i=0;
    while(s.name[i]!='\0')
    {
        output<<s.name[i++];
    }
    output<<endl<<"Course information: ";
    output<<endl;
    int times=s.getCourseNumber();
    for(int i=1;i<=times;i++)
    {
        output<<i<<". ";
        output<<*s.courseList[i];
    }
    output<<"your Credit is: "<<s.calcCredit()<<endl;
    return output;
}

char* Student::getName()const
{
    char *N=new char[strlen(name)+1];
    strcpy(N,name);
    return N;
}
Date Student::getBirthDate()const
{
    return birthDate;
}
void Student::setName(const char *N)
{
    delete name;
    name=new char[strlen(N)+1];
    strcpy(name,N);
}
bool Student::removeCourse(int i)
{
    int m=courseNumber;
    delete getcourse(i);
    --courseNumber;--m;
    //delete courseList[i];
    for(int p=i;p<=m;p++)
    {
        courseList[p]=courseList[p+1];
    }
    return 1;
}
void Student::print()const
{
    cout<<*this;
}
int Student::getCount()
{
    return count;
}
Student& Student::addCourse(Course *course)
{
    courseList[++courseNumber]=course;
    return *this;
}

/*Student& Student::addCourse(const std::string &courseName,int creditHour)
{
    Course course(courseName,creditHour);
    courseList[++courseNumber]=&course;
    return *this;
}
 */
double Student::calcCredit() const {
    double obliCredit=0,elecCredit=0;
    int obliHour=0,elecNum=0;
    int courseNum=getCourseNumber();
    for(int i=1;i<=courseNum;i++) {
        if(typeid(*courseList[i])==typeid(ObligatoryCourse)) {
            obliHour += courseList[i]->getCreditHour();
            obliCredit += (courseList[i]->getScore() * courseList[i]->getCreditHour());
        }
        else {
        ++elecNum;
        elecCredit += courseList[i]->getScore();
        }
    }
    if(obliCredit)
    obliCredit/=obliHour;
    if(elecCredit)
    elecCredit/=elecNum;
    return obliCredit * obli_weight + elecCredit * elec_weight ;
}

