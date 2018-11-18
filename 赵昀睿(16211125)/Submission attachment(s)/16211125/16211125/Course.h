#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course
{
    public:
        Course( string n, int c );
        virtual ~Course();
        void setName( string n );
        void setCreditHour( int c );
        string getName()const;
        int getCreditHour()const;
        //
        virtual void printScore()const{};
        virtual void setGrade( char ){};
        virtual void setMark( int ){};
        //
        friend ostream& operator<<(ostream &, Course &);
        //
        virtual int getScore()const = 0;

    protected:

    private:
        string name;
        int creditHour;

};

#endif // COURSE_H
