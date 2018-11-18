#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <iostream>
#include <string>
#include <iomanip>
#define MAX_SIZE 10
class Student
{
    friend ostream& operator<<(ostream&, const Student &);
    public:
        Student(const char *const n ,int by,int bm,int bd);
        Student(Student &);
        virtual ~Student();

        int getCountNumber()const;
        int getCount()const;
        char * getName()const;

        Student& setName(const char *const n);
        //void printinf()const;

        Student& addCourse(Course *);
        //Student& addCourse(const string &, int );

       // void printCourseInf()const;
        bool removeCourse(int );
        //bool removeCourse(const string& );

        bool existCourse(Course *course);//�ж��Ƿ��Ѿ�����ĳ�ſγ�
        double calcAchievement() const;	//����ѧ���ĳɼ�

        Course *courseList[MAX_SIZE];

    protected:

    private:
        char *name;
        Date d;
        static int count;
        int countNumber;

        int calcObligatoryCredit() const;//������޿���ѧ��
        int calcElectiveNumber() const;//����ѡ�޿�������
};

#endif // STUDENT_H
