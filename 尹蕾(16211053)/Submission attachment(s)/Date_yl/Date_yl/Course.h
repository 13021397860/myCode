#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include "Exception.h"
using namespace std;
class Course
{
    friend ostream& operator<<(ostream &,const Course&);
    public:
        Course(const string , int );
        virtual ~Course();

        void setName(const string );
        void setCreditHour(int );

        string getName() const;
        int getCreditHour() const;

        virtual int getObligatoryCredit() const { return creditHour;}//计算课程学分（用于必修课）
        virtual int getElectiveNumber() const {return 1;}           //计算课程门数（用于选修课）

        virtual int getScore() const=0 ;        //获得课程成绩
        virtual double getWeight() const=0;		//获得课程权重

    protected:
        string name;
        int creditHour;
    private:
};

#endif // COURSE_H
