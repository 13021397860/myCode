#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 20
#include "Data.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <iomanip>
class Student
{
    public:
        Student();
        Student(char *,int =1900,int =1,int =1);
        Student(const Student &);
        virtual ~Student();
        Student& setname(const char *);
        void setbirthday(int ,int ,int );
        void setmessage(const char *,int ,int ,int );
        bool isLegal(const char *);
        char * getname();
        int getcount();
        int getcourseNumber();
        Course * getcourseList(int i);
        void showcount() const;
        Student& addCourse(Course *);
        bool removeCourse(int i);
        int calcCredit(double &sum);
        Data getbirthday();
        friend ostream& operator<<(ostream& os,const Student& p)
        {
            os<<"#�� ����"<<p.name<<"  �������ڣ�"<<p.birthday.get_year()<<"-"<<p.birthday.get_month()<<"-"<<p.birthday.get_day()<<", ѡ����Ϣ���£�\n";
            if(p.courseNumber==0)
                os<<"  �γ�Ϊ��\n";
            for(int i=0;i<p.courseNumber;i++)
            {
                os<<"  "<<i+1<<".�γ�����"<<p.courseList[i]->getname()<<"  ѧ��:"<<fixed<< setprecision(1)<<p.courseList[i]->getcreditHour()<<"  ������";
                os<<p.courseList[i]->getScore()<<"\n";
            }
            return os;
        }
    protected:
    private:
        char *name;
        Data birthday;
        static int count;
        Course *courseList[MAX_SIZE];
        int courseNumber=0;
};

#endif // STUDENT_H
/*friend ostream& operator<<(ostream& os,const Student& p)
        {
            os<<"�� ����"<<p.name<<"  �������ڣ�"<<p.birthday.get_year()<<"-"<<p.birthday.get_month()<<"-"<<p.birthday.get_day()<<", ѡ����Ϣ���£�\n";
            if(p.courseNumber==0)
                os<<"  �γ�Ϊ��\n";
            for(int i=0;i++;i<p.courseNumber)
            {
                os<<"  �γ�����"<<p.courseList[i]->getname()<<"  ѧ��"<<p.courseList[i]->getcreditHour()<<"\n";
            }
            return os;
        }*/
