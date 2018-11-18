#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#define MAX_SIZE 100
#include "Course.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Base.h"
class Student:virtual public Base
{
    public:
		virtual int classID() const;
		explicit Student(int stuID, const char* nam,const Date& birth);
		Student(const Student&);
        ~Student();
        virtual bool changeName(const char *);
        virtual void getName(char*&)const;
        //void showLength();
        virtual void getBirthday(Date&)const;
		virtual void getBirthday(int &Year, int &Month, int &Day);
        virtual void getID(int&)const;
        virtual void howMany(int&)const;
		virtual Student& addCourse(Course &course);
		virtual Student& addCourse(const std::string &courseName,int creditHour, bool ifAECourse);
		virtual int getCourseNumber()const;
		virtual bool removeCourse(int i);//删除第i个课程。
		virtual bool changeGrade(int i,int grade);//更改第i个课的成绩
		virtual bool changeGrade(int i, char grade);
		virtual double caleCredit() const;
		friend std::ostream& operator <<(std::ostream& output_student,const Student& student);
		friend std::ofstream& operator <<(std::ofstream& outputf_student,const Student& student);
		void printGrade(int i)const;//第i个课程成绩，这是临时函数
		virtual const Course& getCourse(int i)const;
    protected:

    private:
        char* name;
        int length;
        int ID;
        const Date birthDate;
        static int number;
		Course *courseList[MAX_SIZE];//别忘析构
		int courseNumber;//总课程数
		bool courseMax();
		static const int ClassID = 192021;
};
#endif
