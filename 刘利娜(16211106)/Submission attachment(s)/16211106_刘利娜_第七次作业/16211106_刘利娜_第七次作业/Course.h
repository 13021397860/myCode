#ifndef COURSE_H
#define COURSE_H

#include<string>
using namespace std;
class Course
{
    friend ostream& operator<<(ostream &,const Course&);
    public:
        Course(string ,int);
        virtual ~Course();
        virtual void setgrade(char){};
        virtual void setMark(int){};
        const string& getname()const{return name;}
        int getcreditHour() const{return creditHour;}
        void setCourse(const string ,int);
        void printcourse();
        virtual int getScore()const=0;

    protected:

    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
