#ifndef ILLEGALDATE_H
#define ILLEGALDATE_H

class IllegalDate
{
    public:
        IllegalDate():messages("Illegal Date"){};
        virtual ~IllegalDate();
        const char* what()const{return messages;};
        //
    protected:

    private:
        const char *messages;
};

#endif // ILLEGALDATE_H
