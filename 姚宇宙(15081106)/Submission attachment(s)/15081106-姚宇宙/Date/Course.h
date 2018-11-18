#ifndef COURSE_H
#define COURSE_H

#include<iostream>

class Course
{
    public:
        Course();
        Course(const std::string &, int);
        Course(const Course&);
        virtual ~Course();
        std::string getName() const;
        int getCreditHour() const;
        void setName(const std::string &);
        void setCreditHour(int);
        virtual int getScore() const = 0;
        virtual void setScore(int) = 0;
        virtual bool testObligatory() const = 0;
        friend std::ostream& operator << (std::ostream&, const Course&);
    protected:

    private:
        std::string name;
        int creditHour;
};

#endif // COURSE_H
