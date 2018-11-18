#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include "Exception.h"

class Course
{
    public:
        Course();
        Course(const std::string&, const int& = 0);
        Course(const Course&);
        virtual ~Course();

        bool operator ==(const Course&);

//        friend std::istream& operator >>(std::istream&, Course&);
        friend std::ostream& operator <<(std::ostream&, const Course&);

        void setCreditHour(const int&);

        std::string getName() const;
        int getCreditHour() const;
        virtual int getScore() const = 0;

    private:
        const std::string name;
        int creditHour;
};


#endif // COURSE_H
