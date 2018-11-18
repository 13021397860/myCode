#ifndef ILLEGALGRADE_H
#define ILLEGALGRADE_H


class IllegalGrade
{
    public:
        IllegalGrade():messages("Illegal grade"){};
        virtual ~IllegalGrade();
        const char* what()const{return messages;};
        //
    protected:

    private:
        const char *messages;
};

#endif // ILLEGALGRADE_H
