#ifndef COURSE_H
#define COURSE_H
#include <string>

class Course
{
	public:
		Course(const std::string ="",const int =0); 
		virtual ~Course();
		void setCourse(const std::string,const int);
		void setName(const std::string);
		void setCreditHour(const int);
		std::string getName() const;
		int getCreditHour() const;
		virtual int getScore() const=0;
		virtual void setScore(const int );
		friend std::ostream& operator<<(std::ostream&,const Course&);
		friend std::ofstream& operator<<(std::ofstream&,const Course&);
		
	protected:
		
	private:
		std::string name;
		int creditHour; 
};

#endif
