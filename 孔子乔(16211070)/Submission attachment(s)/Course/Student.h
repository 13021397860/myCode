#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 50
#include "Date.h"
#include "Course.h"
#include<string>

using std::string;

class Student
{
    public:
        static int get_count();

        void set_name(const string name);
        void set_birthday(const int year,const int month,const int day);
        void set_birthday(const Date* birthdate);
        Date* get_birthday()const;
        string get_name()const;
        int load_course();
        void write_course();
        Student& add_course(Course* _course);
        //Student& add_course(const string &_coursename,const int _credithour);
        int get_coursenum()const;
        Course* const* get_courselist()const;
        bool remove_course(const string _coursename);
        bool remove_course(const int i);
        int create_coursefile()const;
        double calcreadit()const;

        friend ostream& operator<<(ostream &output,const Student &student);

        Student();
        Student(const string name,const Date* BirthDay);
        Student(const string name,const int year,const int month ,const int day);
        Student(const Student &Another);
        virtual ~Student();
    private:
        static int Count;
        string Name;
        Date* BirthDate;
        Course* CourseList[MAX_SIZE];
        int CourseNum;
};

#endif // STUDENT_H
