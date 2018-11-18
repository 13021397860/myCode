#include "Student.h"

int Student::studentCount=0;

Student::Student(const char *const ch,const int y,const int m,const int d)
{
    ++studentCount;
    Student::SetBirthDate(y,m,d);
    Student::SetName(ch);
    courseNumber=0;
    //ctor
}

Student::Student(const Student &x)
{
    ++studentCount;
    name=x.name;
    birthDate=x.birthDate;
    courseNumber=x.courseNumber;
    for(int i=0;i<MAX_SIZE;i++)
        courseList[i]=x.courseList[i];
}
Student::~Student()
{
    --studentCount;
    delete []name;
    int i;
    while(courseNumber)
    {
        i=courseNumber-1;
        removeCourse(i);
    }
    //dtor
}

void Student::SetBirthDate(const int y,const int m,const int d)
{
    birthDate.SetTime(y,m,d);
}

void Student::SetName(const char *const ch)
{
    if(name) delete []name;
    name=new char[strlen(ch)+1];
    strcpy(name,ch);
}

void Student::ShowBasicInformation()
{
    printf("******* name: %s birthday: %d-%d-%d *******\n",name,birthDate.getYear(),birthDate.getMonth(),birthDate.getDay());
}

void Student::ShowSelectedCourse()
{
    printf("******* the selected course: *******\n");
    if(!courseNumber)
    {
        printf("******* None *******\n");
    }
    for(int i=0;i<courseNumber;i++)
    {
        //cout<<"  course name: "<<setw(25)<<left<<courseList[i]->GetName();
        //cout<<" credit hour: "<<courseList[i]->GetCreditHour()<<" ";
        cout<<*courseList[i];
        cout<<" grade: "<<courseList[i]->getScore()<<endl;
    }
}

const char* const Student::GetName() const
{
    return name;
}

int Student::GetCount()
{
    return studentCount;
}
const int Student::Get_courseNumber()
{
    return courseNumber;
}
Student& Student::addCourse(Course* Acourse)
{
    if(courseNumber==MAX_SIZE)
    {
        cout<<"the full course";
        return *this;
    }
    courseList[courseNumber]=Acourse;
    courseNumber++;
    return *this;
}

/*Student& Student::addCourse(Course& Acourse)
{
    if(courseNumber==MAX_SIZE)
    {
        cout<<"the full course";
        return *this;
    }
    courseList[courseNumber]=new Course;
    courseList[courseNumber]->SetName(Acourse.GetName());
    courseList[courseNumber]->SetCreditHour(Acourse.GetCreditHour());
    courseNumber++;
    return *this;
}
*/
/*Student& Student::addCourse(ObligatoryCourse* Acourse)
{
    if(courseNumber==MAX_SIZE)
    {
        cout<<"the full course";
        return *this;
    }
    if(courseList[courseNumber]=dynamic_cast<ObligatoryCourse*>)
        courseList[courseNumber]=tmp;
    else
    {
        cout<<"failed to add course";
        return *this;
    }
    ObligatoryCourse* tmp=new ObligatoryCourse;
    tmp->creditHour=Acourse->creditHour;
    tmp->name=Acourse->name;
    tmp->mark=Acourse->mark;
    courseNumber++;
    return *this;
}
Student& Student::addCourse(ElectiveCourse* Acourse)
{
    if(courseNumber==MAX_SIZE)
    {
        cout<<"the full course";
        return *this;
    }
    if(courseList[courseNumber]=dynamic_cast<ElectiveCourse*>)
        courseList[courseNumber]=tmp;
    else
    {
        cout<<"failed to add course";
        return *this;
    }
    ElectiveCourse* tmp=new ElectiveCourse;
    tmp->creditHour=Acourse->creditHour;
    tmp->name=Acourse->name;
    tmp->mark=tmp->mark;
    courseNumber++;
    return *this;
}*/
/*Student& Student::addCourse(const string courseName,int creditHour)
{
    if(courseNumber==MAX_SIZE)
    {
        cout<<"the full course";
        return *this;
    }
    Course* added=new Course(courseName,creditHour);
    courseList[courseNumber++]=added;
    return *this;
}*/

Course* Student::getCourse(int i)
{
    return courseList[i];
}

bool Student::removeCourse(int i)//shortage
{
    // i from 0 to courseNumber-1
    if(i>=0&&i<courseNumber)
    {
    delete courseList[i];
    for(int ii=i;ii<courseNumber;ii++)
        courseList[ii]=courseList[ii+1];
    courseList[courseNumber-1]=NULL;
    courseNumber--;
    return 1;
    }
    else
    return 0;
}

ostream & operator << (ostream &output,Student &x)
{
    output<<"******* name: "<<x.name<<" birthday: ";
    output<<x.birthDate.getYear()<<'-'<<x.birthDate.getMonth()<<'-'<<x.birthDate.getDay()<<" *******\n";
    output<<"******* the selected course: *******\n";
    if(!x.courseNumber)
    {
        output<<"******* None *******\n";
    }
    for(int i=0;i<x.courseNumber;i++)
    {
        output<<*x.courseList[i];
        output<<" grade: "<<x.courseList[i]->getScore()<<endl;
    }
    output<<"CreditGrade: "<<x.calcCredit();
    return output;
}

float Student::calcCredit()
{
    int ElectiveCourse_num=0;
    int ObligatoryCourse_credit=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
            ElectiveCourse_num++;
        }
        else if(typeid(*courseList[i])==typeid(ObligatoryCourse))
        {
            ObligatoryCourse_credit+=courseList[i]->GetCreditHour();
        }
    }
    if (!ElectiveCourse_num)
        ElectiveCourse_num=1;
    if (!ObligatoryCourse_credit)
        ObligatoryCourse_credit=1;
    float tmpCredit=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
            dynamic_cast<ElectiveCourse*>(courseList[i]);
            tmpCredit+=(weight_ElectiveCourse*((float)courseList[i]->getScore()))/ElectiveCourse_num;
        }
        else if(typeid(*courseList[i])==typeid(ObligatoryCourse))
        {
            dynamic_cast<ObligatoryCourse*>(courseList[i]);
            tmpCredit+=(weight_ObligatoryCourse*(((float)courseList[i]->getScore())*((float)courseList[i]->GetCreditHour())))/ObligatoryCourse_credit;
        }
    }
    return tmpCredit;
}

void Student::showCalcCredit()
{
    cout<<"grade : "<<calcCredit();
}
