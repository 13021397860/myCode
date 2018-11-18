#ifndef STUDENTS_H
#define STUDENTS_H
#include <iostream>
#include <cstdio>
#include "Date.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#define MAX_SIZE 100
#include "MyException.h"
class Students
{
    public:
        Students(char *,const Date &);//����Ϊָ�����ֵ�ָ�룬data���͵ı��� 
        Students(const Students &);//�������� 
        void getName(char *);
        static int getCounter();//��̬���������ڼ���ѧ���� 
        void print()const;
        Date getBirthDate();
        Students& addCourse(Course *course);//������ָ�������д�����ѡ�γ̵������Ϣ������Ϊ&�γ������������͵ı���Ҳ�У� 
        Students& addElectiveCourse(char grade, const string &courseName, int creditHour);//������޿� 
        Students& addObligatoryCourse(int score, const string &courseName, int creditHour);//����ѡ�޿� 
        int getCourseNumber()const;
        Course *getCourseList(int);//����courseList���飬����Ϊ�����±� 
        ~Students();
        inline friend ostream& operator<< (ostream& o, Students& s)
		{
			char *S;
			S=new char[20];//һ��Ҫ�����ڴ棬�������׸��ǵ�������Ҫ���� 
			s.getName(S);
			o<<"������"<<S<<" �������ڣ�"<<s.birthDate<<", ѡ����Ϣ���£�"<<endl;//birthDate��const���ͣ�����<<�����ز�����Ҫconst 
			for(int i=0;i<s.getCourseNumber();i++)
		{
			o<<s.getCourseList(i);
		} 
			return o;
		} 
		bool removeCourse(int);//����ڼ��ſ� 
		void SetCourseGrade(MyException &);
		int calcCredit();
    private:
        static int counter;//��̬���ݳ�Ա������ѧ������ 
        char *name;
        const Date birthDate;
        Course *courseList[MAX_SIZE];//ָ�����飬���ڴ洢ѧ����ѡ�γ� 
        int courseNumber;
};

#endif // STUDENTS_H
