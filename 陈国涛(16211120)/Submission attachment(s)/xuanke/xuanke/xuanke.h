#ifndef XUANKE_H
#define XUANKE_H
#include "Student.h"
#include "MyException.h"
static Obligatory *CourseList1[5];
static ElectiveCourse *CourseList2[5];
class xuanke
{
    public:
        xuanke();
        void SetScore(const int score, const int nCourse);
        void AddCourse(const int type, const int nCourse);
        void RemoveCourse(const int );
        const void print();
        const void save();
        bool init();
        const void printcourse();
        const void printindex();
        void testDate();
        void run() throw(MyException);
        virtual ~xuanke();

    protected:
      Student *stu;
      int coursetype[20];

    private:
};

#endif // XUANKE_H
