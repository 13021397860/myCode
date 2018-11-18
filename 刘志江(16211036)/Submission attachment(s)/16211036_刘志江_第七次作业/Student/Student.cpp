#include "Student.h"
#include <iomanip>
int Student::count=0;

ostream& operator<<(ostream& output, Student& s)
{
    output << "Name: " << s.name << " Birthday: " << s.birthDate << ", the information about his/her course:" << endl;
    for (int i=0; i<s.courseNumber; i++){
        output << "  " << *s.courseList[i] << endl;
    }
    output << fixed << setprecision(4) << "Credit: " << s.calcCredit() << endl;
    return output;
}

Student::Student(const char *const s, const int y, const int m, const int d):birthDate(y,m,d)
{
    count++;
    name=NULL;
    setName(s);
    courseNumber=0;
}

Student::Student(const Student &s):birthDate(s.birthDate)
{
    count++;
    name=NULL;
    setName(s.name);
    courseNumber=s.courseNumber;
}

void Student::setName(const char *const s)
{
    if(name) delete []name;
    int len=strlen(s);
    name=new char[len+1];
    strcpy(name,s);
}

void Student::printCourse() const
{
    for (int i=0; i<courseNumber; i++)
        cout << i+1 << "." << *courseList[i] << endl;
}

void Student::setGrade(const int i)
{
    int g;
    char s;

    if (i<=0||i>courseNumber) {
        cout << "Wrong input!\n";
        return ;
    }
    if (typeid(ObligatoryCourse)==typeid(*courseList[i-1])){
        cout << "Input 0-100 to set up the grade: ";
        cin >> g;
        if (g<0||g>100) throw MyException("Invalid grade.\n");
        else {
            dynamic_cast<ObligatoryCourse*>(courseList[i-1])->setMark(g);
            cout << "You have set up the grade successfully!\n";
        }
    }
    else if (typeid(ElectiveCourse)==typeid(*courseList[i-1])){
        cout << "Input A-E to set up the grade: ";
        cin >> s;
        if (s<65||s>69) throw MyException("Invalid grade.\n");
        else {
            dynamic_cast<ElectiveCourse*>(courseList[i-1])->setGrade(s);
            cout << "You have set up the grade successfully!\n";
        }
    }
}

Date Student::getBirthDate() const
{
    return birthDate;
}

int Student::getCourseNumber()
{
    return courseNumber;
}

int Student::getCount()
{
    return count;
}

char * Student::getName() const
{
    return name;
}

Student& Student::addCourse(Course *course)
{
    if (courseNumber<MAX_SIZE){
        if(dynamic_cast<ObligatoryCourse*>(course))
            courseList[courseNumber]=new ObligatoryCourse;
        else if (dynamic_cast<ElectiveCourse*>(course))
            courseList[courseNumber]=new ElectiveCourse;
        courseList[courseNumber]->setName(course->getName());
        courseList[courseNumber]->setCreditHour(course->getCreditHour());
        courseNumber++;
    }
    return *this;
}

bool Student::removeCourse(int i)
{
    if (i>courseNumber||i<=0) return 0;
    else {
        delete courseList[i-1];
        for (int j=i-1; j<courseNumber-1; j++){
            courseList[j]=courseList[j+1];
        }
        courseNumber--;
        return 1;
    }
}

bool Student::selected(const Course *c) const
{
    for (int i=0; i<courseNumber; i++){
        if (courseList[i]->getName()==c->getName())
            return 0;
    }
    return 1;
}

double Student::calcCredit() const
{
    double sum1=0, sum2=0;
    double creditO=0, numE=0;
    double val=0;
    for (int i=0; i<courseNumber; i++){
        if (typeid(ElectiveCourse)==typeid(*courseList[i])&&courseList[i]->getSetSc()){
            numE++;
            sum2+=courseList[i]->getScore();
        }
        else if (typeid(ObligatoryCourse)==typeid(*courseList[i])&&courseList[i]->getSetSc()){
            creditO+=courseList[i]->getCreditHour();
            sum1+=courseList[i]->getScore()*courseList[i]->getCreditHour();
        }
    }
    if (creditO!=0) val+=0.6*sum1/creditO;
    if (numE!=0) val+=0.4*sum2/numE;
    return val;
}

Student::~Student()
{
    count--;
    delete []name;
    for (int i=0; i<courseNumber; i++) delete courseList[i];
}
