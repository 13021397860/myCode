#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;
class Course
{
    friend ostream& operator<<(ostream &, const Course &);
public:
    Course();
    Course(const string, const int);
    void setName(const string);
    string getName()const;
    void SetCreditHour(const int);
    int GetCreditHour()const;
    virtual void setMark(int) {};
    virtual int getMark() {};
    virtual void setGrade(char) {};
    virtual int getScore()=0;
    virtual ~Course();

protected:

private:
    string name;
    int creditHour;
};

#endif // COURSE_H
