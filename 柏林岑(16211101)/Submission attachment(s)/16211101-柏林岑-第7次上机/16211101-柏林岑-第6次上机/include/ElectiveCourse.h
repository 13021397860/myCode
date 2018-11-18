#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include<string>
#include"Course.h"
using namespace std;

class ElectiveCourse:public Course
{
   public:
   ElectiveCourse();
   ~ElectiveCourse();
   ElectiveCourse(const string ,const int);
   void setgrade(const char);
   int getScore()const;

   private:
   char grade;

};

#endif // ELECTIVECOURSE_H
