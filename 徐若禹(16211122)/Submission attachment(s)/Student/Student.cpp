#include "Student.h"

Student::Student(char *n,const Date &t)
    :birthDate(t)
{
    setName(n);
    strcpy(name,n);
    count++;
    flag = 0;
}

void Student::setFlag()
{
    flag = 1;
}

int Student::getFlag() const
{
    return flag;
}

Student::Student(const Student &s)
    :birthDate(s.birthDate)
{
    setName(name);
    strcpy(name,s.name);
    count++;
}

void Student::setName(char *n)
{
    int len = strlen(n);
    name = new char[len + 1];
}

char *Student::getName() const
{
    return name;
}

int Student::count = 0;

int Student::getCount()
{
    return count;
}

int Student::courseNumber = 0;

Student& Student::addCourse(Course *course)
{
    if(courseNumber < MAX_SIZE)
        courseList[courseNumber++] = course;
    return (*this);
}

Student& Student::addCourse(const string &courseName,int creditHour,int mark)
{
    if(courseNumber < MAX_SIZE)
    {
        courseList[courseNumber] = new ObligatoryCourse(courseName,creditHour,mark);
        courseList[courseNumber++]->addOCreditHour(creditHour);
    }
    return (*this);
}

Student& Student::addCourse(const string &courseName,int creditHour,char grade)
{
    if(courseNumber < MAX_SIZE)
    {
        courseList[courseNumber] = new ElectiveCourse(courseName,creditHour,grade);
        courseList[courseNumber++]->addECreditHour(creditHour);
    }
    return (*this);
}

void Student::addGrade(char g)
{
    courseList[courseNumber]->setGrade(g);
}

void Student::addMark(int m)
{
    courseList[courseNumber]->setMark(m);
}

void Student::removeCourse(int i,Student &student)
{
    Course *courseLis = student.getCourseList(i-1);
    ObligatoryCourse *ob = dynamic_cast<ObligatoryCourse*>(courseLis);
    int m = courseLis->getCreditHour();
    if(ob != NULL)//必修课
        courseLis->addOCreditHour(-m);
    else//选修课
        courseLis->addECreditHour(-m);
    for(int j = i-1; j < courseNumber-1; j++)
        courseList[j] = courseList[j+1];
    courseNumber--;
}

int Student::queryScore(int i)
{
    return courseList[i-1]->getScore();
}

ostream &operator<<(ostream &output,const Student &student)
{
    output << "Name:" << student.name << "     Birthday:" << student.birthDate << endl;
    if(student.flag == 0)
    {
        for(int i = 0;i < student.courseNumber;i++)
            output << i+1 << *student.courseList[i] << endl;
    }
    else
    {
        for(int i = 0;i < student.courseNumber;i++)
        {
            Course *courseList = student.getCourseList(i);
            ObligatoryCourse *ob = dynamic_cast<ObligatoryCourse*>(courseList);
            if(ob != NULL)
                output << i+1 << *courseList << "      mark:" << courseList->getScore() << endl;
            else
                output << i+1 << *courseList << "      grade:" << courseList->getGrade() << "      score:" << courseList->getScore() << endl;
        }
    }
    return output;
}

int Student::getCourseNumber() const
{
    return courseNumber;
}

Course* Student::getCourseList(int i)const
{
    return courseList[i];
}

double Student::calcCredit(Student &student)
{
    obSum = 0;
    elSum = 0;
    for(int i = 0;i < student.courseNumber;i++)
    {
        Course *courseList = student.getCourseList(i);
        ObligatoryCourse *ob = dynamic_cast<ObligatoryCourse*>(courseList);
        if(ob != NULL)//必修课
            obSum += (double)courseList->getMark()*courseList->getCreditHour()/courseList->getOCreHour();
        else//选修课
            elSum += (double)courseList->getScore()*courseList->getCreditHour()/courseList->getECreHour();
    }
    return obSum*0.6 + elSum*0.4;
}

Student::~Student()
{
    delete []name;
    count--;
    for(int i=0;i < courseNumber;i++)
        delete courseList[i];
}
