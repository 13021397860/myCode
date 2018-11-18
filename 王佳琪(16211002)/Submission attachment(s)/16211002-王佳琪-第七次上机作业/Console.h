#ifndef CONSOLE_H
#define CONSOLE_H
#include <cstring>
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"

using namespace std;
class Console
{
	public:
		Console();
		virtual ~Console();
		int run();//���п���̨
		 
	protected:
	private:
		void displayMenu() const; //��ʾϵͳ���˵�
		Course* selectCourse(int); //ѡ�� ���ؿγ̵�ַ op = 1 ���� op = 2 ѡ��
		void setCourseScore(); //�������пγ̳ɼ�
		
		void buildStudent(); //����ѧ������
		Console& buildcourse(); //�������п�ѡ�γ� 
		
		Student *student; 
		int num,num1,num2;
		string str; 
		Date date;
		
    	int y,m,d,hour;
    	char* n;
    	int courseNum,courseNum1,classy;
    	ElectiveCourse ele[10];
    	ObligatoryCourse obl[10];
};


#endif
