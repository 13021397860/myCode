#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string>
using namespace std;

class Course
{
    public:
        Course(int =1,string = "Estatew");
        ~Course();
        int getCreditHour();
        string getName();
        void setCreditHour(const int);
        void setName(const string);
        void setCourse(const int ,const string);
        virtual int getScore() const =0;
        virtual void setScore(const int);
        friend ostream& operator<< (ostream& ,const Course &);

    private:
        int creditHour;//ังทึ 
        string name;
};

#endif // COURSE_H
