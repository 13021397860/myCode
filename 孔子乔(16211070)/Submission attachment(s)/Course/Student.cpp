#define MAX_SIZE 50
#define STU_FOLDER "./Students/"
#define ELEC_WEIGHT 0.4
#define OBLI_WEIGHT 0.6

#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iomanip>

using std::string;
using std::setw;
using std::left;

int Student::Count=0;

int Student::get_count(){return Count;}

Student::Student()
{
    Name = "NULL";
    BirthDate = NULL;
    CourseNum = -1;
    for(int i=0;i<MAX_SIZE;i++)CourseList[i]=NULL;
}

Student::Student(const string name,const int year,const int month,const int day)
{
    Name = name;
    BirthDate = new Date(year, month, day);
    Count++;
    CourseNum = -1;
    for(int i=0;i<MAX_SIZE;i++)CourseList[i]=NULL;
}

Student::Student(const Student &Another)
{
    Name = Another.Name;
    BirthDate = new Date(*Another.BirthDate);
    Count++;
    CourseNum = -1;
    for(int i=0;i<Another.get_coursenum();i++)
    {
        if(dynamic_cast<ObligatoryCourse*>(Another.get_courselist()[i])!=NULL)
            CourseList[i]= new ObligatoryCourse(*dynamic_cast<ObligatoryCourse*>(Another.get_courselist()[i]));
        else
            CourseList[i]= new ElectiveCourse(*dynamic_cast<ElectiveCourse*>(Another.get_courselist()[i]));
    }
}

Student::Student(const string name, const Date* birthdate)
{
    /*
    for(int i=0;name[i-1]!='\0';i++)
    {
        Name = new char;
        Name[i] = name;
    }
    */
    Name = name;
    BirthDate = new Date(birthdate->GetDay(), birthdate->GetMonth(), birthdate->GetYear());
    Count++;
    CourseNum = -1;
    for(int i=0;i<MAX_SIZE;i++)CourseList[i]=NULL;
}

void Student::set_name(const string name)
{
    Name = name;
    return;
}

void Student::set_birthday(const int year, const int month, const int day)
{
    BirthDate->SetDay(day);
    BirthDate->SetMonth(month);
    BirthDate->SetYear(year);
    return;
}

void Student::set_birthday(const Date* birthday)
{
    BirthDate->SetDay(birthday->GetDay());
    BirthDate->SetMonth(birthday->GetMonth());
    BirthDate->SetYear(birthday->GetYear());
    return;
}

Student& Student::add_course(Course* _course)
{
    if(CourseNum == MAX_SIZE-1)return *this;
    else
    {
        CourseNum++;
        if(dynamic_cast<ObligatoryCourse*>(_course)!=NULL)
            CourseList[CourseNum] = new ObligatoryCourse(*dynamic_cast<ObligatoryCourse*>(_course));
        else if(dynamic_cast<ElectiveCourse*>(_course)!=NULL)
            CourseList[CourseNum] = new ElectiveCourse(*dynamic_cast<ElectiveCourse*>(_course));
        return *this;
    }
}

/*Student& Student::add_course(const string &_coursename,const int _credithour)
{
    if(CourseNum == MAX_SIZE-1)return *this;
    else
    {
        CourseNum++;
        CourseList[CourseNum] = new Course;
        CourseList[CourseNum]->setname(_coursename);
        CourseList[CourseNum]->setcredithour(_credithour);
        return *this;
    }
}*/

int Student::get_coursenum()const
{
    return CourseNum+1;
}

Date* Student::get_birthday()const{return BirthDate;}

string Student::get_name()const{return Name;}

Course* const* Student::get_courselist()const
{
    return CourseList;
}

bool Student::remove_course(const string _coursename)
{
    for(int i=0;i<=CourseNum;i++)
    {
        if(CourseList[i]->getname()==_coursename)
        {
            for(int j=i+1;j<=CourseNum;j++)CourseList[j-1]=CourseList[j];
            CourseNum--;
            return 1;
        }
    }
    return 0;
}

bool Student::remove_course(const int i)
{
    if(i>CourseNum||i<0)return 0;
    else
    {
        for(int j=i+1;j<=CourseNum;j++)
            CourseList[j-1]=CourseList[j];
        CourseNum--;
        return 1;
    }
}

double Student::calcreadit()const
{
    double oblgpa=0;
    double elegpa=0;
    int oblch=0;
    int elech=0;
    for(int i=0;i<=CourseNum;i++)
    {
        double tpsc = CourseList[i]->getscore();
        if(tpsc==-1)tpsc=0;
        int tpch = CourseList[i]->getcredithour();
        if(dynamic_cast<ObligatoryCourse*>(CourseList[i])!=NULL)
        {
            oblch += tpch;
            oblgpa += OBLI_WEIGHT*tpch*tpsc;
        }
        else if(dynamic_cast<ElectiveCourse*>(CourseList[i])!=NULL)
        {
            elech ++;
            elegpa += ELEC_WEIGHT*tpsc;
        }
    }
    if(oblch == 0)return elegpa / (double)elech;
    else if(elegpa == 0)return oblgpa / (double)oblch;
    else return elegpa / (double)elech + oblgpa / (double)oblch;
}

int Student::create_coursefile()const
{
    FILE *coursefile;
    //string path;
    //path = STU_FOLDER + Name + ".txt";
    char path[300] = STU_FOLDER;
    strcat(path, Name.c_str());
    strcat(path, ".txt");
    coursefile = fopen(path, "r");
    if(coursefile != NULL)return 1;
    coursefile = fopen(path, "w+");
    if(coursefile == NULL)return -1;
    else
    {
        fprintf(coursefile, "// This file supports to use \"//\" to comment\n");
        char t[150]="// This file is courses of student:";
        strcat(t, Name.c_str());
        fprintf(coursefile, "%s\n", t);
        fprintf(coursefile, "// The format is [1,0]|[name]|[credithour]|[grade or mark]|[\\n]\n");
        fprintf(coursefile, "// 1 means obligatory course and 0 means elective course.\n");
        fprintf(coursefile, "// Not supported for any Chinese.\n");
        fprintf(coursefile, "// Here is an example:\n");
        fprintf(coursefile,"1|OOP|2|99\n");
    }
    fclose(coursefile);
    return 0;
}

int Student::load_course()
{
    //string defaultname = "NULL";
    if(strcmp(Name.c_str(), "NULL")==0) return -1;
    else
    {
        FILE *coursefile;
        //string path = STU_FOLDER + Name + ".txt";
        char path[300] = STU_FOLDER;
        strcat(path, Name.c_str());
        strcat(path, ".txt");
        coursefile = fopen(path, "r+");
        if(coursefile == NULL)return -2;
        for(int i=0;i<=CourseNum;i++)CourseList[i]->clearcourse();
        CourseNum = -1;
        char temp[2000];
        while(fgets(temp,2000,coursefile)!=NULL)
        {
            if(temp[0]=='/'&&temp[1]=='/')continue;
            else if(temp[0]=='\n')continue;
            else
            {
                char *pch = strtok(temp, "|");
                CourseNum++;
                if(atoi(pch)==1)
                {
                    ObligatoryCourse* course = new ObligatoryCourse;
                    pch = strtok(NULL,"|");
                    course->setname(pch);
                    pch = strtok(NULL,"|");
                    course->setcredithour(atoi(pch));
                    pch = strtok(NULL,"|");
                    course->setmark(atoi(pch));
                    CourseList[CourseNum]=course;
                }
                else if(atoi(pch)==0)
                {
                    ElectiveCourse* course = new ElectiveCourse;
                    pch = strtok(NULL,"|");
                    course->setname(pch);
                    pch = strtok(NULL,"|");
                    course->setcredithour(atoi(pch));
                    pch = strtok(NULL,"|");
                    course->setgrade(*pch);
                    CourseList[CourseNum]=course;
                }
            }
        }
        fclose(coursefile);
        return 0;
    }
}

ostream& operator<<(ostream& output,const Student& student)
{
    output<<string("姓名：")<<setw(15)<<left<<student.Name<<string("出生日期：")<<*student.BirthDate<<string("    积点成绩:")<<student.calcreadit()<<string("     选课信息如下\n");
    for(int i=0;i<=student.CourseNum;i++)
    {
        output<<*student.CourseList[i];
        /*if(dynamic_cast<ObligatoryCourse*>(student.CourseList[i])!=NULL)
        {
            ObligatoryCourse* course = dynamic_cast<ObligatoryCourse*>(student.CourseList[i]);
            output<<"性质：必修课     成绩：";
            if(course->getmark()==-1)output<<"未设置\n";
            else output<<course->getmark()<<"\n";
        }
        else
        {
            ElectiveCourse* course = dynamic_cast<ElectiveCourse*>(student.CourseList[i]);
            output<<"性质：选修课     成绩：";
            if(course->getgrade()=='N')output<<"未设置\n";
            else output<<course->getscore()<<"\n";
        }*/
    }
    return output;
}

Student::~Student()
{
    FILE *coursefile;
    char path[300] = STU_FOLDER;
    strcat(path, Name.c_str());
    strcat(path, ".txt");
    coursefile = fopen(path, "w");
    fprintf(coursefile, "// This file supports to use \"//\" to comment\n");
    fprintf(coursefile, "// The format is [1,0]|[name]|[credithour]|[grade or mark][\\n]\n");
    fprintf(coursefile, "// 1 means obligatory course and 0 means elective course.\n");
    fprintf(coursefile, "// Not supported for any Chinese if encoding by GBK.\n");
    char t[150]="// This file is courses of student:";
    strcat(t, Name.c_str());
    strcat(t, " Birthdate:");
    char temp[15];
    sprintf(temp,"%d",BirthDate->GetYear());
    strcat(t, temp);strcat(t, "-");
    sprintf(temp,"%d",BirthDate->GetMonth());
    strcat(t, temp);strcat(t, "-");
    sprintf(temp,"%d",BirthDate->GetDay());
    strcat(t, temp);
    strcat(t, " Grade:");
    sprintf(temp,"%f",calcreadit());
    strcat(t, temp);
    fprintf(coursefile, "%s\n", t);
    for(int i=0;i<=CourseNum;i++)
    {
        if(dynamic_cast<ObligatoryCourse*>(CourseList[i])!=NULL)
        {
            ObligatoryCourse* course = dynamic_cast<ObligatoryCourse*>(CourseList[i]);
            fprintf(coursefile,"1|%s|%d|%d\n",course->getname().c_str(),course->getcredithour(),course->getscore());
        }
        else
        {
            ElectiveCourse* course = dynamic_cast<ElectiveCourse*>(CourseList[i]);
            fprintf(coursefile,"0|%s|%d|%c\n",course->getname().c_str(),course->getcredithour(),course->getgrade());
        }
    }
    fclose(coursefile);
    Count--;
    delete BirthDate;
    //printf("Student clear.\n");
}
