#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#define MAX_SIZE 20
class Student
{
    public:
        Student();
        Student( const Student& );
        void setName( char* );
        void setDate(  Date );
        char* getname() const;
        Date getdate() const;
        int getcount();
        // void print();
        int getnumber()const{return courseNumber;}
        //void printcourse();
        friend ostream &operator << ( ostream &, const Student& );
        Student& addCourse ( Course * ) ;
        double calcCredit() const;
        double calcElectiveCourse() const;
        double calcObligatoryCourse() const;
        bool removeCourse( int  );
        virtual ~Student();
         Course* courseList[MAX_SIZE];
         int courseNumber;

    protected:

    private:
        char *name;
        Date birthdate;
       int calElectivenum() const;
        int calObligatoryCredit() const;
        static int count;





};

#endif // STUDENT_H
