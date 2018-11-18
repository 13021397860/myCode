#ifndef COURSE_H
#define COURSE_H
#include<string>
using namespace std;

class Course
{
    public:
        Course();
        Course(string,int);
        virtual ~Course();
        void setcoursename(string);
        void setcredithour(int);

        string getcoursename() const {return CourseName;}
        int getcredithour() const{return creditHour;}
        virtual void setmark(int){}
        virtual void setgrade(char){}
        virtual int getScore()const =0;
        friend ostream& operator << (ostream &,const Course &);



    protected:
        string CourseName;
        int creditHour;




    private:

};

#endif // COURSE_H
