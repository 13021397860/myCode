#ifndef CHOOSECOURSEGUI_H
#define CHOOSECOURSEGUI_H
#include "student.h"
#include "obligatorycourse.h"
#include "electivecourse.h"
#include <iostream>
#include <vector>
class ChooseCourseGUI
{
    public:
        ChooseCourseGUI();
        virtual ~ChooseCourseGUI();
        void chooseCourse(student &);
        void addCourse(student &);
        void loadCourse();
        void showCourse(student &);
        void cmd(student &);
        bool judgeCin();
    protected:
        vector <ObligatoryCourse> ObligatoryCourseList;
        vector <ElectiveCourse> ElectiveCourseList;
        bool is_Course_Loaded;
        enum ErrorType{InputError=1,InvalidDate,OutOfRange,InvalidScore};
    private:
};

#endif // CHOOSECOURSEGUI_H
