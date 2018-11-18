#ifndef Consolo_H
#define Consolo_H
#include<iostream>
#include <windows.h>
#include <fstream>
#include<typeinfo>
#include<conio.h>
#include<string>
#include "student.h"
using namespace std;
class Consolo
{
	public:
		Consolo(); 
		Consolo(int a); 
		void run();
		void ChooseModeFace();//�ص���ҳ 
		void StudentInformationFace();
		void ChooseCourseFace(); 
		void DeleteCourseFace(); 
		void setScoreFace();
		void SavaFileFace();
		void move(char _op);//�ƶ���� 
		void gotoxy(int _x,int _y);//�ƶ����ķ���
		void hide();//���ع��
		~Consolo();
	protected:
		int x,y;//���ƹ�� 
		int top,bottom;//���ƹ��
		int mode;//ͨ�����֪���Լ����ĸ�����(1~4) 
		Student *student;
		Course* ChooseCourseList[MAX_SIZE+1];
		int ChooseCourseNumber;
		Course* DeleteCourseList[MAX_SIZE+1];
		int DeleteCourseNumber;
};

#endif

