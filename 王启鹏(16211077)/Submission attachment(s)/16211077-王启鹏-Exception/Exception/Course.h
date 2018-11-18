#ifndef COURSE_H
#define COURSE_H
#include<string>
#include <bits/stdc++.h>
using namespace std;


class Course
{
    public:
        Course(const string="", const int=0);
        virtual ~Course();
        void setName(string);
        void setCreditHour(int);
        string getName()const;

        virtual double getNumber() const;
        //���޷���0��ѡ�޷���1
        virtual double getCreditHour() const;
        //���޷���ѧ�֣�ѡ�޷���0��

        virtual double getScore()const=0;
        virtual double getWeight()const=0;
        friend ostream& operator<<(ostream &, const Course&);
    protected:

    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
