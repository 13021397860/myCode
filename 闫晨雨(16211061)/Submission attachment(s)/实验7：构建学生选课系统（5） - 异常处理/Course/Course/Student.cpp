#include "Student.h"
#include "Time.h"
#include "cstring"
#include <iostream>
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <typeinfo>
#include <string>
#include <cstring>
//#include "ObligatoryCourse.h"
//#include "ElectiveCourse.h"
using namespace std;

int Student::count = 0;

Student::Student(const char *const n, const int y1, const int m1, const int d1):birthDate(y1, m1, d1)
{
    name = new char [strlen(n) + 1];
    strcpy(name, n);
    count++;
    courseNumber = 0;
}

Student& Student::addCourse(const Course *const course)
{
    Course *c;
    if(typeid(*course) == typeid(ObligatoryCourse))
        c = new ObligatoryCourse;
    else
        c = new ElectiveCourse;
    *c = *course;
    courseList[courseNumber] = c;
    courseNumber++;
    return *this;
}

/*Student& Student::addCourse(const string &courseName, const int creditHour)
{
    Course *c;
    c = new Course;
    c->setCourse(courseName, creditHour);
    courseList[courseNumber] = c;
    courseNumber++;
    return *this;
}*/

Student::Student(const Student &a):birthDate(a.birthDate)
{
    name = new char [strlen(a.name) + 1];
    strcpy(name, a.name);
    count++;
    courseNumber = 0;
}

bool Student::removeCourse(const int i)
{
    if(i >= 0 && i < courseNumber)
    {
        delete courseList[i];
        for(int u = i; u < courseNumber-1; u++)
            courseList[u] = courseList[u+1];
        courseNumber--;
        return true;
    }
    else
        return false;
}

int Student::getCount()const
{
    return count;
}

int Student::setName(const char *const n)
{
    if(name)
        delete []name;
    name = new char [strlen(n) + 1];
    strcpy(name, n);
    return 1;
}

int Student::getName(char *&n)const
{
    if(!n)
        return 0;
    strcpy(n, name);
    return 1;
}

int Student::print()const
{
    cout << "name:" << name << "\nbirthDate:";
    cout << birthDate;
    cout << "count:" << count << "\n";
}

double Student::calcCredit()const
{
    double credit = 0;
    int h,sum1 = 0, sum2 = 0;
    string s;
    for(int i = 0; i < courseNumber; i++)
    {
        courseList[i]->getCourse(s,h);
        if(typeid(*courseList[i]) == typeid(ObligatoryCourse))
        {
            sum1 += h;
        }
        else if(typeid(*courseList[i]) == typeid(ElectiveCourse))
        {
            sum2 ++;
        }
    }
    for(int i = 0; i < courseNumber; i++)
    {
        courseList[i]->getCourse(s,h);
        if(typeid(*courseList[i]) == typeid(ObligatoryCourse))
        {
            credit += 0.6 * courseList[i]->getScore() * h / sum1;
        }
        else if(typeid(*courseList[i]) == typeid(ElectiveCourse))
        {
            credit += 0.4 * courseList[i]->getScore() / sum2;
        }
    }
    return credit;
}

int Student::askforScore()const
{
    for(int i = 0; i < courseNumber; i++)
        cout << *courseList[i] << endl;
    return 0;
}

ostream& operator <<(ostream &out, Student &s)
{
    string p;
    int h;
    out << "name:" << s.name << " birth date:" << s.birthDate << "\n";
    for(int i = 0; i < s.courseNumber; i++)
    {
        out << *s.courseList[i] << "\n";
    }
    return out;
}

int Student::setScore()
{
    int score;
    string s;
    int h;
    for(int i = 0; i < courseNumber; i++)
    {
        courseList[i]->getCourse(s, h);
        if(typeid(*courseList[i]) == typeid(ObligatoryCourse))
        {
            cout << "No." << i+1 <<" obligatory " << "course name:" << s << " credit hour:" << h << "\nPlease input the grade:";
            int mark;
            while(1)
            {
                cin >> mark;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "system error:score invalid\nPlease input the grade again\n";
                    continue;
                }
                try{
                    dynamic_cast<ObligatoryCourse*>(courseList[i])->setMark(mark);
                    break;
                }catch(MyException ex)
                {
                    cout << "system error:" << ex.what() << "\nPlease input the grade again\n";
                }
            }
            score = dynamic_cast<ObligatoryCourse*>(courseList[i])->getScore();
            cout << "new grade:" << score << "\n";
        }
        else
        {
            cout << "No." << i+1 <<" elective " << " course name:" << s << " credit hour:" << h << "\nPlease input the grade:";
            char grade;
            while(1)
            {
                cin >> grade;
                try{
                    dynamic_cast<ElectiveCourse*>(courseList[i])->setGrade(grade);
                    break;
                }catch(MyException ex)
                {
                    cout << "system error:" << ex.what() << "\nPlease input the grade again\n";
                }
            }
            score = dynamic_cast<ElectiveCourse*>(courseList[i])->getScore();
            cout << "new grade:" << score << "\n";
        }
    }
    return 0;
}

int Student::getBirthDate(int &y, int &m, int &d)const
{
    y = birthDate.getYear();
    m = birthDate.getMonth();
    d = birthDate.getDay();
    return 1;
}

Student::~Student()
{
    count--;
    for(int i = 0; i < courseNumber; i++)
        delete courseList[i];
    delete []name;
}
