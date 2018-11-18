#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course
{
    friend ostream &operator<<( ostream&, const Course& );

    public:
        Course( string, int );
        virtual ~Course();
        string getName();
        int getCreditHour();

        virtual void setGrade( int ) = 0;
        virtual int getScore() const = 0;
        virtual double getWeight() const = 0;

    protected:
        string name;
        int creditHour;
        double weight;

    private:
};

#endif // COURSE_H
