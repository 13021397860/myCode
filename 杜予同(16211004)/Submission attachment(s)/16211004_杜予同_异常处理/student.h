#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#include "typeinfo"
#define MAX 15
class student
{
    public:
        student(char n[]="Nameless",Date bd={2008,8,8});
        static int Count;
        student(const student &s);
        virtual ~student();
        void setName(char n[]);
        void setBirthday(Date bd);
        char* getName();
        int getCoursenumber()
        {
            return Coursenumber;
        }
        Date getBirthday();
        Course* courselist[MAX];
        student& addCourse(Course *course);
        friend ostream& operator << (ostream& out, const student& c);
        bool removeCourse(int i);
        bool setscore(int i);
        void choseclass();
        double calcCredit();
    protected:
    private:

        char *name;
        Date birthday;
        int Coursenumber=0;
};

#endif // STUDENT_H
