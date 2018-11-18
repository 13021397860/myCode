#ifndef COURSE_H
#define COURSE_H
#include<string>
using namespace std;
class Course
{
    friend ostream& operator<<(ostream &, Course&);
    public:
        virtual int getScore() const = 0;
        Course(const string s, int hour);//���캯��
        void setCourse(const string s);//set���������ÿγ�����
        const string getName()const{return name;}//get���������ؿγ�����
        const int getcreditHour()const{return creditHour;}//get���������ؿ�ʱ��
        virtual ~Course();
        void print()const;
    protected:

    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
