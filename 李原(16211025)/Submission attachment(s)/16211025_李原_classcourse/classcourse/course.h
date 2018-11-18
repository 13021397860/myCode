#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
using namespace std;
class Course
{
	public:
		Course();
		Course(string ,int =0);
		Course(const Course &);
		virtual ~Course(){};
		void setName(string );
		void setCredit(int );
		virtual void setScore(int x){cout<<"int"<<endl;}
		virtual void setScore(char x){cout<<"char"<<endl;}
		virtual int getScore()const =0;
		string getName()const{return name;}
		int getCredit()const{return creditHour;}
		
		virtual string toString()const
		{
			string s;
			s=" 课程名:";
			s+=' ';
			s+=getName();
			s+=" 学分:";
			s+=' ';
			s+=(char)(getCredit()+48);
			s+="   成绩:";
			s+=(char)(getScore()/10+48);
			s+=(char)(getScore()%10+48);
			s+='\n';
			return s;
		}
		
		friend ostream& operator << (ostream& out,const Course & c)
		{
			out<<c.toString();
			return out;
		}
		
	protected:
		string name;
		int creditHour;
	private:
		
		
};
class ObligatoryCourse:public Course
{
	public:
		ObligatoryCourse();
		ObligatoryCourse(string ,int =0,int =0) ;
		ObligatoryCourse(const ObligatoryCourse &);
		~ObligatoryCourse(){};
		virtual void setScore(int );
		virtual void setScore(char){cout<<"ccchar"<<endl;}
		virtual int getScore()const{return mark;}
		virtual string toString()const
		{
			
			string s;
			s=" 课程名:";
			s+=' ';
			s+=getName();
			s+="   学分:";
			s+=' ';
			s+=(char)(getCredit()+48);
			s+="   成绩:";
			if(getScore()==100)
			{
				s+="100";
			}
			else
			{
				s+=(char)(getScore()/10+48);
				s+=(char)(getScore()%10+48);
			}
			
			s+='\n';
			return s;
		}
	private:
		int mark;
};

class ElectiveCourse:public Course
{
	public:
		ElectiveCourse();
		ElectiveCourse(string ,int =0,char ='E');
		ElectiveCourse(const ElectiveCourse &);
		~ElectiveCourse(){};
		virtual void setScore(int ){cout<<"iiint"<<endl;}
		virtual void setScore(char);
		virtual int getScore()const;
		virtual string toString()const
		{
			string s;
			s=" 课程名:";
			s+=' ';
			s+=getName();
			s+="   学分:";
			s+=' ';
			s+=(char)(getCredit()+48);
			s+="   成绩:";
			s+=(char)(getScore()/10+48);
			s+=(char)(getScore()%10+48);
			s+='\n';
			return s;
		}
	private:
		char grade;
};
#endif
