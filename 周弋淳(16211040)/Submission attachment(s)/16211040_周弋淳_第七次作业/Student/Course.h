#ifndef COURSE_H
#define COURSE_H

#include<string>

using namespace std;

class Course
{
    friend ostream& operator<<(ostream&, const Course&);
    public:
        Course(const string="none",const int=0,const int =0,const int =0);
        void setName(const string);
        void setCreditHour(const int);
        string getName() const;
        int getCreditHour() const;
        virtual int getScore() const =0;
        virtual ~Course();
        bool getIfCourseScoreSet() const;
        bool getIfCourseAdded() const;
        void setIfCourseScoreSet(const int);
        void setIfCourseAdded(const int);

    protected:

    private:
        string name;
        int creditHour;
        bool ifCourseScoreSet;
        bool ifCourseAdded;
};

#endif // COURSE_H
