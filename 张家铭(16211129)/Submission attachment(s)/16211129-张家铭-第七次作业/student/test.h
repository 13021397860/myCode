#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include "student.h"
#include "course.h"
class test
{
public:
    test();
    bool readFile(student &stu);
    bool createFile(student &stu);
    void run();
    virtual ~test();
private:
    course *choose[100];
};


#endif // TEST_H_INCLUDED
