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
		void ChooseModeFace();//回到首页 
		void StudentInformationFace();
		void ChooseCourseFace(); 
		void DeleteCourseFace(); 
		void setScoreFace();
		void SavaFileFace();
		void move(char _op);//移动光标 
		void gotoxy(int _x,int _y);//移动光标的方法
		void hide();//隐藏光标
		~Consolo();
	protected:
		int x,y;//控制光标 
		int top,bottom;//控制光标
		int mode;//通过这个知道自己在哪个界面(1~4) 
		Student *student;
		Course* ChooseCourseList[MAX_SIZE+1];
		int ChooseCourseNumber;
		Course* DeleteCourseList[MAX_SIZE+1];
		int DeleteCourseNumber;
};

#endif

