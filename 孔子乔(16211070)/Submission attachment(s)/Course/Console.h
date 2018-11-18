#ifndef CONSOLE_H
#define CONSOLE_H
#define MAX_SIZE 50
#include"Student.h"

class Console
{
    public:
        Console(int type);
        bool init_course();
        void load_course();
        char main_page();
        void login();
        void list_page();
        bool select_page();
        bool remove_page();
        bool grade_page();
        virtual ~Console();
    private:
        Student* user;
        Course* course_list[MAX_SIZE];
        int total;
};

#endif // CONSOLE_H
