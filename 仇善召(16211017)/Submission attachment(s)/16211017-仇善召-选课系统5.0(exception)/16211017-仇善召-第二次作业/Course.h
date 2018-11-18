#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
using namespace std;

class Course
{
    public:
        //Course(){};
        Course( const string &n="", int ch=0);
        string getname() const { return name;}
        int getHour() const {return creditHour;}
        void setname( string );
        void setHour( int  );

        virtual void setScore( int );
        virtual int getScore( ) const=0;
        virtual string toString() const;
        virtual ~Course();

        friend ostream &operator << ( ostream &, const Course& );

   private:

    protected:
       string name;
        int creditHour;
};

#endif // COURSE_H
