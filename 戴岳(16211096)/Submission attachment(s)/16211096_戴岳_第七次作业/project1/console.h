#ifndef CONSOLE_H
#define CONSOLE_H
#include "student.h"
using namespace std;
class Console
{
    public:
        Console();
        virtual ~Console();
    void run();
    void daytest();
    bool createSequentialFile(const char *);
    bool readSequentialFile(const char *,Course *[]);
    int daysOfMonth(int,int) const;
    protected:

    private:
        Student *c;

};

#endif // CONSOLE_H
