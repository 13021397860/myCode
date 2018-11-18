#ifndef COURSE_H
#define COURSE_H
#include<string>
using namespace std;
class Course
{
    friend ostream& operator<<(ostream &, Course&);
    public:
        virtual int getScore() const = 0;
        Course(const string s, int hour);//构造函数
        void setCourse(const string s);//set函数，设置课程名称
        const string getName()const{return name;}//get函数，返回课程名称
        const int getcreditHour()const{return creditHour;}//get函数，返回课时数
        virtual ~Course();
        void print()const;
    protected:

    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
