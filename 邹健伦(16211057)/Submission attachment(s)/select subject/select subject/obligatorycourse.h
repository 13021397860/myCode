#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "course.h"


class obligatorycourse : public course
{
    public:
        obligatorycourse(const string &,const int &);//name credit mark
        obligatorycourse(const obligatorycourse &);
        void setmark(const int &);
        int getscore()const{return mark;};
        friend ostream& operator<<(ostream& ,const obligatorycourse &);
        virtual ~obligatorycourse();

    protected:

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
