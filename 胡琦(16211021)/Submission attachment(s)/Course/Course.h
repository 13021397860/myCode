#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;
class Course
{
    public:
        Course();
        Course(const string, const int);
        virtual ~Course();
        virtual void setScore(const int);
        virtual int getScore() const=0;
        void setCreditHour(const int);
        void setName(const string);
        void setKind(const int);
        int getCreditHour() const {return creditHour;}
        string getName() const {return name;}
        int getKind()const {return kind;}
        friend ostream& operator<<(ostream&, const Course&);
    protected:
        string name;
        int creditHour;
        int kind;
    private:
};

#endif // COURSE_H
