#ifndef COURSE_H
#define COURSE_H
#include<string>
#include"Exception.h"

using namespace std;
class Course
{
    friend ostream& operator<<(ostream&,Course&);
    public:
        Course();
        Course(const string coursename,int credithour)
        {
            name=coursename;
            creditHour=credithour;
        }
        Course(const Course &x)
        {
            name=x.name;
            creditHour=x.creditHour;
        }
        virtual ~Course();
        string getName(){return name;}
        int getcreditHour(){return creditHour;}
        void setName(string x){name=x;}
        void setcreditHour(int x){creditHour=x;}
        bool getHaveMark(){return haveMark;}
        void setHaveMark(int x){haveMark=x;}
        virtual int getScore()=0;
    protected:
        string name;
        int creditHour;
        bool haveMark;
    private:
};

#endif // COURSE_H
