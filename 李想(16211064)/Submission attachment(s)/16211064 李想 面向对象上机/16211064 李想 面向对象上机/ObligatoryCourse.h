#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"
#include<bits/stdc++.h>
using namespace std;

class ObligatoryCourse : public Course
{
    public:

        ObligatoryCourse();

        friend ostream& operator<<(ostream&,const ObligatoryCourse&);

        ObligatoryCourse(string name,int creditHour);

        ObligatoryCourse(ObligatoryCourse &o);

         ~ObligatoryCourse();

        void setmark(int);

        virtual int getScore();

		 //int setScore(int);

    protected:

    private:

        int mark;
};

ostream& operator<<(ObligatoryCourse&,ostream);


#endif // OBLIGATORYCOURSE_H
