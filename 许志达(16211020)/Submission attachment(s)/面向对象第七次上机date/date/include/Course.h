#ifndef COURSE_H
#define COURSE_H
#include<string>
using namespace std;
class Course
{
    public:
        Course();
       friend ostream &operator <<(ostream& ,const Course &);
        Course(const string & ,int =2);
        void setcreditHour(int);
        void setname(string);
        void setmark(int );
       int  getmark();
        int getcreditHour()const;
        // void print()const;
        virtual ~Course();
         virtual  void setScore(int );
        virtual int getScore()=0;
        virtual void setScore(char);


    protected:
            string name;
            char Score;
            int creditHour;
            int mark;
    private:

};

#endif // COURSE_H
