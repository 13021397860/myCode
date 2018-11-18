#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#include<iostream>
#include<typeinfo>
using namespace std;
#include<cstring>

int Student::count=0;

double Student::calcGPA() const
{
    int obCredit=calcObligatoryCredit();
    int elNumber=calcElectiveNumber();
    int obGPA=0;
    int elGPA=0;
    for(int i=0; i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            obGPA+=courseList[i]->getScore() * courseList[i]->getHour();
        }
        if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            elGPA+=courseList[i]->getScore();
        }
    }
    double GPA=0;
    if(obCredit>0)
    {
        GPA+=0.6*obGPA/obCredit;
    }
    if(elNumber>0)
    {
        GPA+=0.4*elGPA/elNumber;
    }
    return GPA;
}

int Student::calcObligatoryCredit() const
{
    int sum=0;
	for(int i=0;i<courseNumber;i++)
    {
		if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
			sum+=courseList[i]->getHour();
		}
	}
	return sum;
}

int Student::calcElectiveNumber() const
{
	int number=0;
	for(int i=0;i<courseNumber;i++)
    {
		if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
			number++;
		}
	}
	return number;
}

ostream& operator<<(ostream& output, const Student& st)
{
    output<<"name£º"<<st.name<<"    birthdate£º"<<st.getY()<<"-"<<st.getM()<<"-"<<st.getD()<<",class chosen£º\n";
    for (int i=0;i<st.courseNumber;i++)
    {
        output<<(st.courseList[i]);
    }
    output<<"GPA:"<<st.calcGPA()<<endl;
    return output;
}


bool Student::setCourseScore()
{
    int x;
    cin>>x;
    while ( x<1|| x>courseNumber || cin.fail())
    {
        cout << "Invalid choice, try again:";
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cin >> x;
    }
    if (typeid(ObligatoryCourse)==typeid(*courseList[x-1]))
    {
        cout<<"input score:";
        int y;
        cin>>y;
        while (y < 0 || y > 100 ||cin.fail())
        {
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                    }
                    throw MyException("wrong score.\n");
                    cin >> y;
        }
        dynamic_cast<ObligatoryCourse*>(courseList[x-1])->setMark(y);
        return 1;
    }
    else if (typeid(ElectiveCourse)==typeid(*courseList[x-1]))
    {
        cout<<"input grade:";
        char z[100];
        cin>>z;
        while (strlen(z)>1 || z[0]<'A' || z[0]>'E')
        {
            throw MyException("wrong score.\n");
            cin >> z;
        }
        dynamic_cast<ElectiveCourse*>(courseList[x-1])->setGrade(z[0]);
        return 1;
    }
}

bool Student::removeCourse(int i)
{
    if(i<courseNumber)
    {
        delete courseList[i];
        for(int j=i;j<courseNumber-1;j++)
        {
            courseList[j]=courseList[j+1];
        }
        courseNumber--;
        return 1;
    }
    else
    {
        return 0;
    }
}

Student::Student(const char* n,int y,int m,int d):birthDate(y,m,d)
{
    name=NULL;
    setName(n);
    courseNumber=0;
    ++count;
}

Student::Student(const Student& n, const Date& d):birthDate(d)
{
    name=NULL;
    setName(n.name);
    courseNumber=0;
    ++count;
}

const char* Student::getStudentName() const
{
    return name;
}

Student& Student::setName (const char* const n)
{
    if (name) delete name;
    int length=strlen(n);
	name=new char[length+1];
	strcpy(name, n);
    return *this;
}

void Student::getBirthDate() const
{
    cout<<birthDate.getYear()<<"."<<birthDate.getMonth()<<"."<<birthDate.getDay()<<endl;
}

Student& Student::addCourse(Course *course)
{

	if(courseNumber<MAX_SIZE)
    {
		courseList[courseNumber++]=course;
	}
	return *this;
}





Student::~Student()
{
	int i=courseNumber-1;
	while(i>0)
    {
		if (removeCourse(i))
		{
		    i--;
		}
	}
	delete[] name;
	count--;
}

