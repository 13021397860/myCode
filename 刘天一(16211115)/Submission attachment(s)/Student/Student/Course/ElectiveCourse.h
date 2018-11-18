#ifndef STUDENT_ELECTIVECOURSE_H
#define STUDENT_ELECTIVECOURSE_H

#include "Course.h"

class ElectiveCourse:public Course
{
public:
    ElectiveCourse(std::string name,int hour)
            :Course(name,hour)
    {}
    virtual ~ElectiveCourse(){}
    void setGrade(char g){if((g>='A'&&g<='E')||g=='\0'){grade=g;}else throw MyException(GRADE_ERROR);}
    int getScore()const{ switch(grade){case 'A':return 95;break;case'B':return 85;break;case 'C':return 75;break;case'D':return 65;break;case 'E':return 55;break;default:return -1;break;}}
    void print();
protected:
    char grade;
private:

};

#endif //STUDENT_ELECTIVECOURSE_H
