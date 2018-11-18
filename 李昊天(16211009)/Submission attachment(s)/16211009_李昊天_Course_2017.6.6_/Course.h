#ifndef COURSE_H
#define COURSE_H
#include<string>
#include"MyException.h"

using namespace std;
class Course
{
    public:
        Course();
        Course(string,int);
        virtual ~Course();
        void setName(string);
        void setCreditHour(int);
        void setCourseType(string a){
            courseType=a;
        }
        string getName() const {return name;}
        string getCourseType() const {return courseType;}
        int getCreditHour() const {return creditHour;}
        virtual void setMark(int) {}
        virtual void setGrade(char){}
        virtual int getScore() = 0;
        virtual string toString();
        //void print();

    protected:
        string name;
        int creditHour;
    private:
        string courseType;
        friend ostream& operator<<(ostream& os,Course& p);
};

#endif // COURSE_H
