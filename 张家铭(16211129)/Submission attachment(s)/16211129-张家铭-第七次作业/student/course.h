#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class course
{
private:
    string name;
    int creditHour;
public:
    course(const string ,const int );
    course();
    virtual ~course();
    virtual int getMark(){};
    virtual int getGrade(){};
    virtual void setMark(const int ){};
    virtual void setGrade(char ){};
    virtual int getScore(){};
    void setName(const string );
    void setHour(const int );
    void setCourse(const string ,const int );
    const string getName() const;
    const int getHour() const;
    void getCourse() const;
    friend ostream operator<<(ostream &,const course &);
};

#endif // COURSE_H_INCLUDED
