#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "Stu.h"

class UserInterface
{
    public:
        UserInterface();
        virtual ~UserInterface();
        void FirstMenu(Stu&);
        void Inputfromfile(Stu&);
        void SetInformation(Stu&);
        void FunctionList(Stu&);
        void AddCourse(Stu&);
        void Exit();
        void ShowInformation(Stu&);
        void TestFunction(Stu&);
        void RemoveCourse(Stu&);
        void SetCourseGrade(Stu&);
        void Output(Stu&);
        static bool InputChoice(int&,int,int);
        static bool InputChoiceEx(int&,int,int);
        static bool InputChoiceChar(char&,char,char);

    protected:

    private:
};

#endif // USERINTERFACE_H
