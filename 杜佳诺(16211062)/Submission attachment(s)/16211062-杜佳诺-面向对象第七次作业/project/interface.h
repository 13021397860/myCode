#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Student.h"
#include "obligatorycourse.h"
#include "electivecourse.h"

class interface
{
    public:
        interface();
        virtual ~interface();

        static Student createStudent();
        static void CZ( Student& );
        static void dateTest();
        static void fileText();

    protected:

    private:
};

#endif // INTERFACE_H
