#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include "../Time.h"
#include "../Course.h"
#include "../Stu.h"
using namespace std;
#ifndef CONSOLE_H
#define CONSOLE_H


class console
{
    public:
        consle();
        virtual ~consle();
        int run();

    protected:

    private:
        int dispayMenu() const;
        Console& buildStu();
        Console& buildCoourse();

};

#endif // CONSLE_H
