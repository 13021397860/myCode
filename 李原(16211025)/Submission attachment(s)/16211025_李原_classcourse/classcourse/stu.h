#ifndef STU_H
#define STU_H
#include"date.h"
#include"course.h"
#define Max 1000
#define Oweight 0.6
#define Eweight 0.4
class Stu
{
	public:
		Stu();
		Stu(char *);
		Stu(const Stu &St);
		virtual ~Stu();

		bool setName(char *);
		bool setBirth(int,int,int);
		
		const int getCount()const{return count;}
		const char * getName()const{return name;}
		const Date * getBirth()const{return &birthDate;}
		
		Stu & addCourse(Course * );
		Stu & addCourse(const string & ,int );
		
		static int count;
		
		bool removeCoourse(int);
		void vaCourse(int);
		
		double calcCredit();
		
		friend ostream& operator << (ostream& out, Stu & c)
		{
			out<<" 姓名: ";
			out<<c.getName()<<endl;
			out<<" 出生日期: ";
			//c.birthDate++;
			out<<*c.getBirth();
			out<<" 选课信息如下: "<<endl;
			for(int i=0;i<c.courseNumber;i++)
			{
				out<<i<<":";
				out<<*c.courseList[i];
			}
			out<<" 积点成绩为： ";
			out<<c.calcCredit()<<endl;
			return out;
			
		}
		
		
	protected:
	private:
		int OzongCredit;
		int Ezong;
		Course * courseList[Max];
		char* name;
		Date birthDate;
		int courseNumber;
};

#endif
