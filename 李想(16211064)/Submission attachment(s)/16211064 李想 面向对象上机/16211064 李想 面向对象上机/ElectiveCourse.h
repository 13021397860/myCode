#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"
#include<bits/stdc++.h>
using namespace std;

class ElectiveCourse : public Course
{
    public:

        friend ostream& operator<<(ostream&,const ElectiveCourse&);

        ElectiveCourse();

        ElectiveCourse(string name,int creditHour);

       // ElectiveCourse(Course &e);

        virtual ~ElectiveCourse();

        //void setgrade(char Grade);

        virtual int getScore();

		 int setgrade(char);

    protected:

    private:

        char grade;
};
ostream& operator<<(ElectiveCourse&,ostream);

#endif // ELECTIVECOURSE_H
