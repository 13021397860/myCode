#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <cstring>

#define Max_Size 3
#define Total_Num 5
using namespace std;
using std::ostream;
class Course
{
    friend ostream& operator<<(ostream& ,Course&);
    public:
        Course();
        Course(const string na, const int cr);
        virtual ~Course();
        string getName()const;
        virtual int getscore() const=0;
        int getCreditHour()const;
        void setcourseName(const string couname);
        void setCreditHour(const int stuCre);


    protected:
        string name;
        int creditHour;

    private:


};

#endif // COURSE_H
