#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
class Course
{
    public:
        Course();
        Course(string ,double);
        virtual ~Course();
        void setcourse(string , double);
        void setname(string );
        void setcreditHour(double );
        void setpd(int );
        virtual void setall(string ,double, double);
        virtual void setall(string ,double, char);
        virtual void setScore(double );
        virtual void setScore(char );
        virtual double getScore() = 0;
        string getname() const;
        double getcreditHour() const;
        int getpd() const;
        friend ostream& operator<<(ostream& os,Course& p)
        {
            os<<"#课程名："<<p.name<<"  学分:"<<fixed<<setprecision(1)<<p.creditHour<<"  分数：";
            os<<p.getScore()<<"\n";
            return os;
        }
    protected:
        string name;
        double creditHour;
        int pd;
    private:
};

#endif // COURSE_H
