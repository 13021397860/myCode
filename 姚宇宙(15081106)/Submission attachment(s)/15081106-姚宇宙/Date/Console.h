#ifndef CONSOLE_H
#define CONSOLE_H
#include "Student.h"

class Console
{
    public:
        Console();
        Console(Student &);
        virtual ~Console();
        void runInstance();
        void buildStudent(Student &);
    protected:

    private:
        Student *s;
        int courseNum;
        std::string className[100];
        int creditHour[100];
        bool isObligatory[100];
        void displayWelcomeInfor();
        void selectCourse();
        void setCourseScore();
        void getStudentCredit() const;
        void writeStudentInformation();
        void editStudentInformation();
        void removeCourse();
};

#endif // CONSOLE_H
