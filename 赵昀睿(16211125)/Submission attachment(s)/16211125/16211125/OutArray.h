#ifndef OUTARRAY_H
#define OUTARRAY_H


class OutArray
{
    public:
        OutArray():messages("Array index out of bounds"){};
        virtual ~OutArray();
        const char* what()const{return messages;};
        //
    protected:

    private:
        const char *messages;
};

#endif // OUTARRAY_H
