#include "Student.h"
#include "MyException.h"
#include<cstring>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int Student::count = 0;

Student::Student(){
    count++;
    CourseNumber = 0;
}

Student::Student(const char *const s, const int m, const int d, const int y)
    :birthDate(m, d, y)
{
    setName(s);
    count++;
    CourseNumber = 0;
}

Student::Student(const char *const s, const Date &d)
    :birthDate(d)
{
    setName(s);
    count++;
    CourseNumber = 0;
}

Student::~Student()
{
    delete name;
    for(int i=0; i<CourseNumber; i++) delete courseList[i];
    count--;
}

Student::Student(const Student &s)
    :birthDate(s.birthDate)
{
    setName(s.name);
    count++;
    CourseNumber = 0;
}

const char* Student::getName() const{
    return name;
}

const Date& Student::getBirthDate() const{
    return birthDate;
}

void Student::setName(const char* const s){
    if(name) delete[] name;
    name = new char[strlen(s)+1];
    strcpy(name, s);
}

int Student::getCount(){
    return count;
}
double Student::calcCredit() const{ //计算有误
    double credit = 0, Ob_sum_score = 0, El_sum_score = 0;
    int Ob_sum_credit = 0, El_sum_num = 0;
    for(int i=1; i<=CourseNumber; i++){
        if(typeid(*courseList[i]) == typeid(ObligatoryCourse)){
            Ob_sum_credit += courseList[i]->getCreditHour();
            Ob_sum_score += courseList[i]->getCreditHour() * courseList[i]->getScore();
        }
        else{
            El_sum_num++;
            El_sum_score += courseList[i]->getScore();
        }
    }
    //cout << "必修总分：" << Ob_sum_score << "必修总学时" << Ob_sum_credit << endl;
    //cout << "选修总分：" << El_sum_score << "选修总学时" << El_sum_credit << endl;
    credit = ObligatoryCourse_weight * Ob_sum_score / (Ob_sum_credit==0 ? 1:Ob_sum_credit) +
            ElectiveCourse_weight * El_sum_score / (El_sum_num==0 ? 1:El_sum_num);
    return credit;
}

Student& Student::addCourse(Course *course){
    if(course!=NULL && existCourse(course)==0 && CourseNumber<MAX_SIZE){
        courseList[++CourseNumber] = course;
    }
    else throw MyException(RANGE_ERROR);
    return (*this);
}

bool Student::removeCourse(int i){
    if(i<1 || i>CourseNumber){
        throw MyException(RANGE_ERROR);
    }
    else{
        cout << "课程名: " << courseList[i]->getName() << "\t";
        CourseNumber--;
        for(int j=i; j<=CourseNumber; j++) courseList[j] = courseList[j+1];
        //CourseNumber--;
    }
    return 1;
}

bool Student::setGrade(int i){
    int mark; char grade;
    if(i<1 || i>CourseNumber){
        throw MyException(RANGE_ERROR);
    }
    puts("输入成绩");
    if(typeid(*courseList[i])==typeid(ObligatoryCourse)){
        cout << "请输入0~100的数字" << endl;
        cin >> mark;
        while(1){
            while(cin.fail()){
                puts("输入错误，请输入0~100的数字");
                cin.clear();
                cin.ignore(1024, '\n');
                cin >> mark;
            }
            try{
                dynamic_cast<ObligatoryCourse *>(courseList[i])->setScore(mark);
                break;
            }catch(MyException ex){
                cout << ex.what() << "，重新输入0~100的数字: ";
                cin >> mark;
            }
        }


        //cout << *courseList[i];
    }
    else{
        cout << "请输入A,B,C,D,E中的一个等级" << endl;
        cin >> grade;
        while(1){
            while(cin.fail()){
                puts("输入错误，请输入A,B,C,D,E中的一个等级");
                cin.clear();
                cin.ignore(1024, '\n');
                cin >> grade;
            }
            try{
                dynamic_cast<ElectiveCourse *>(courseList[i])->setScore(grade);
                break;
            }catch(MyException ex){
                cout << ex.what() << ", 请重新输入A,B,C,D,E中的一个等级 ";
                cin >> grade;
            }

        }
        //cout << *courseList[i];
    }
    return 1;
}

ostream& operator <<(ostream &os, const Student &s){
    os << "\t姓名: " << s.name << "\r\n\t出生日期 " << s.birthDate << "\r\n\t平均绩点：" << s.calcCredit() << "\r\n"
     << "\r\n\t选课信息如下：\r\n";// << endl;
    for(int i=1; i<=s.CourseNumber; i++) os << "\t" << i << ". " << *s.courseList[i] << "\r\n";// << endl;
    return os;
}
Course &Student::operator[](int i){
    if(i<0 || i>CourseNumber){
//        puts("没有这门课程！");
//        exit(1);
        throw MyException(RANGE_ERROR);
    }
    return (*courseList[i]);
}
const Course &Student::operator[](int i)const{
    if(i<0 || i>CourseNumber){
        //puts("没有这门课程！");
        //exit(1);
        throw MyException(RANGE_ERROR);
    }
    return (*courseList[i]);
}

bool Student::existCourse(Course *c) const{
    for(int i=1; i<=CourseNumber; i++){
        if(courseList[i]==c) return 1;
    }
    return 0;
}
