#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include"Course.h"
using namespace std;

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(string ,int ,char );
        void addECreditHour(int);
        int getECreHour() const;
        void setGrade(char);
        char getGrade() const;
        int getScore() const;
        virtual ~ElectiveCourse();

    protected:

    private:
        char grade;
        int score;
        static int eCreditHour;
};

#endif // ELECTIVECOURSE_H
