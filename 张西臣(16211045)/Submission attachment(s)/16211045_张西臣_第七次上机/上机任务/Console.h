#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <string>
#include <cstring>
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#define MAX_SIZE 3
using namespace std;
class Console
{
    public:
        void run();
        Console();  //���캯������ʼ������̨����
        virtual ~Console();//�����������ͷ��ڴ�
        Student *student; //��ǰѧ������
private:
        int displaycaidan() const;
        int selectCourse(Course* course[], int );
        Console& buildStudent();//����ѧ������
        void buildCourse();//�������еĿ�ѡ�γ̣��������޺�ѡ�޿Σ�
        Course *ocke[MAX_SIZE];
        Course *ecke[MAX_SIZE];//ȫ����ѡ��ѡ�޿γ��嵥
        int ocnum;      //��ѡ�ı��޿γ�ʵ������
        int ecnum;	//��ѡ��ѡ�޿γ�ʵ������
};


#endif // CONSOLE_H
