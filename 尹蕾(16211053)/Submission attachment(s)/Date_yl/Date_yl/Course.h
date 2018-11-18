#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include "Exception.h"
using namespace std;
class Course
{
    friend ostream& operator<<(ostream &,const Course&);
    public:
        Course(const string , int );
        virtual ~Course();

        void setName(const string );
        void setCreditHour(int );

        string getName() const;
        int getCreditHour() const;

        virtual int getObligatoryCredit() const { return creditHour;}//����γ�ѧ�֣����ڱ��޿Σ�
        virtual int getElectiveNumber() const {return 1;}           //����γ�����������ѡ�޿Σ�

        virtual int getScore() const=0 ;        //��ÿγ̳ɼ�
        virtual double getWeight() const=0;		//��ÿγ�Ȩ��

    protected:
        string name;
        int creditHour;
    private:
};

#endif // COURSE_H
