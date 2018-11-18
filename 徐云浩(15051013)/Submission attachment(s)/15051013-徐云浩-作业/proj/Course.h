#ifndef COURSE_H
#define COURSE_H
#include <iomanip>
#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;
class Course
{
    public:
        Course();
        virtual ~Course();
        string getName()const;
        float getHour()const;
        void setName(string);
        void setHour(float);
        virtual void setScore(char a){};
        virtual int getScore()const = 0;
        virtual void setScore(int a){};
        friend ostream& operator<<(ostream& out,const Course& c)
        {
            out<<"CourseName: "<<setw(15)<<left<<c.getName()<<"  CreditHour: "<<c.getHour()<<"  ";
            if(c.getScore()==-1)
            {
                out<<"Score: N/A"<<endl;
            }
            else
            {
                out<<"Score: "<<c.getScore()<<endl;
            }

            return out;
        }

    protected:

    private:
        string name;
        float creditHour;
};

#endif // COURSE_H
