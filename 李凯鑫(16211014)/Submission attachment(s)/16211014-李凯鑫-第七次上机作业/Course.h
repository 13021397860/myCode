#ifndef COURSE_H
#define COURSE_H
#include<iostream>
using namespace std;

class Course
{
    public:
        Course(string = "a", int =0);
        virtual ~Course();
        void setName(string);
        void setCreditHour(int);
        void setCourseType(string);
        string getName(){return name;}
        int getCreditHour(){return creditHour;}
        string getCourseType(){return CourseType;}
        virtual void setMark(int){};
        virtual void setGrade(string){};
        virtual int getScore() = 0;
        friend ostream& operator<<(ostream& ,Course& );
    protected:
        string name;
        string CourseType;
        int creditHour;
    private:

};

#endif // COURSE_H
