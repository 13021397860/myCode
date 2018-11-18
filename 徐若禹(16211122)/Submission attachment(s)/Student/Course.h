#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string>
using namespace std;

class Course
{
        friend ostream &operator<<(ostream &,const Course &);
    public:
        //Course(string , int = 0,int = 1);
        Course(string, int = 0);
        void setName(string);
        string getName() const;
        void setCreditHour(int);
        virtual void addOCreditHour(int){};
        virtual void addECreditHour(int){};
        virtual int getOCreHour() const{};
        virtual int getECreHour() const{};
        int getCreditHour() const;
        void setCourse(string , int ,int);
        void setCourse(string , int ,char);
        virtual char getGrade() const{};
        virtual int getMark() const{};
        virtual int getScore() const = 0;
        virtual void setGrade(char){};
        virtual void setMark(int){};

        virtual ~Course();


    protected:

    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
