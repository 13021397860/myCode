#ifndef CONSOLE_H
#define CONSOLE_H
#include"Date.h"
#include"student.h"
class Console
{
	public:
		Console();
		~Console();
		void run();
		void text(Date);
		Student  student(char *,Date&); //����ѧ����Ϣ 
		void menu();//��ӡ�˵� 
		void course(Student&);//ѡ�� 
		void  withdraw(Student&);//�˿�
		void  score(Student&);//��� 
		void  information(Student&);//��ӡѧ����Ϣ  
		void  view(Student& );//��ѯ���� 
		Console& buildCourse();
	protected:
	private:
	      Course *oc[max_size];
		  Course *ec[max_size];
		  int ocnum,ecnum;
};

#endif
