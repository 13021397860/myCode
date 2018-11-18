#include "Student.h"
#include <cstring>
#include <typeinfo>
#include <cstdlib>
using namespace std;

int Student::count=0;

Student::Student(const char *const n,int by,int bm,int bd)
{
    name=NULL;
    setName(n);
    count++;
    d.setDate(by,bm,bd);
    countNumber=0;
    //ctor
}

Student::Student(Student &st2)
{
    name=NULL;
    setName(st2.name);
    count++;
    d.setDate(st2.d);
    countNumber=0;
}

Student::~Student()
{
    /*int i=countNumber;
    while(i>0)
    {
        if(removeCourse(i))
            i--;
    }*/
    delete[] name;
    count--;
    //dtor
}

Student& Student::setName(const char *const n)
{
    if(name) delete[] name;
    name = new char[strlen(n)+1];
    strcpy(name, n);
    return *this;
}

int Student::getCountNumber()const
{
    return countNumber;
}

int Student::getCount()const
{
    return count;
}

char * Student::getName()const
{
    return name;
}
/*
void Student::printinf()const
{
    cout<<getName()<<"'s birthday is "<<getBirthYear()
        <<"-"<<getBirthMonth()<<"-"<<getBirthDay()
        <<" ."<<endl;
    if(d.isLeapYear())
        cout<<"It is leap year."<<endl;
    else
        cout<<"It is not leap year."<<endl;
    cout<<"The number is : "<<count<<endl;
}*/

Student& Student::addCourse(Course *course)
{
    if ((course!=NULL)&&!existCourse(course)){
		if(countNumber<MAX_SIZE){
			courseList[countNumber++]=course;	//ֱ��ָ�븳ֵ
		}
	}
	return (*this);
}
/*
Student& Student::addCourse(const string &courseName, int credithour)
{
    if(countNumber<MAX_SIZE)
    {
        Course *co=new Course(courseName,credithour);
        courseList[countNumber++]=co;
    }
    return *this;
}

void Student::printCourseInf()const
{
    cout<<getName()<<"��ѡ "<<getCountNumber()<<" �ſγ�"<<endl;
    int t=getCountNumber();
    cout<<"��ѡ�γ��������£�������ѧ�֣���"<<endl;
    for(int i=0;i<t;i++)
    {
        cout<<i+1<<". "<<courseList[i]->getCourseName()<<"   "<<courseList[i]->getCreditHour()<<endl;
    }
}*/

bool Student::removeCourse(int i)
{
    if(i<countNumber)
    {
		//delete courseList[i];	//�˴������ͷſγ̶�����ڴ�ռ䣬��������û������ͷ�
		for(int j=i;j<countNumber-1;j++)
		{
			courseList[j]=courseList[j+1];	//���������Ŀγ�ǰ�ƣ����Ǳ�ɾ���Ŀγ���Ϣ
		}
		countNumber--;
		return true;
	}
	else
		throw Exception(RANGE_ERROR);
}
/*
bool Student::removeCourse(const string& courseName)
{
    int i;
	for(i=0;i<countNumber;i++){
		if (courseName==courseList[i]->getName()) break;
	}
	if (i<countNumber){
		return removeCourse(i);
	}else{
		return false;
	}
}
*/
bool Student::existCourse(Course *course)
{
	for(int i=0;i<countNumber;i++)
    {
		if(courseList[i]==course) return true;
	}
	return false;
}

int Student::calcObligatoryCredit() const
{
	int totalCredit=0;
	for(int i=0;i<countNumber;i++){
		/*ʹ��RTTI
		if( typeid(ObligatoryCourse)==typeid(courseList[i]))
        {
			totalCredit+=(int)(courseList[i]->getCreditHour());
		}*/
		//ʹ�ö�̬������޿���ѧ��
		totalCredit += this->courseList[i]->getObligatoryCredit();
	}
	return totalCredit;
}

int Student::calcElectiveNumber() const
{
	int number=0;
	for(int i=0;i<countNumber;i++){
		/*ʹ��RTTI�����ʹ��RTTI��Ҫ����ElectiveCourse.hͷ�ļ�
		if(typeid(ElectiveCourse)==typeid(courseList[i])){
			number++;
		}*/
		//ʹ�ö�̬����ѡ�޿�����
		number += this->courseList[i]->getElectiveNumber();
	}
	return number;
}

double Student::calcAchievement() const
{
	int obligatoryCredit=calcObligatoryCredit();	//���޿���ѧ��
	int electiveNumber=calcElectiveNumber();	//ѡ�޿����Ŵ�
	/*����ʹ�ö�̬, ����ʹ��RTTI����ʱ��Ҫ���������������ͷ�ļ�
	int obligatoryAchievement=0;	//���޿γ̻���
	int electiveAchievement=0;		//ѡ�޿γ̻���
	for(int i=0; i<countNumber;i++)
    {
		if( typeid(ObligatoryCourse)==typeid(courseList[i]))
		{
			obligatoryAchievement+=(courseList[i]->getScore())*(courseList[i]->getCreditHour());
		}
		if(typeid(ElectiveCourse)==typeid(courseList[i]))
		{
			electiveAchievement+=(courseList[i]->getScore());
		}
	}
	double result=0;
	if(obligatoryCredit>0) result+=0.6*obligatoryAchievement/obligatoryCredit;
	if(electiveNumber>0) result+=0.4*electiveAchievement/electiveNumber;
    */

    //ʹ�ö�̬
    double result=0;
    for(int i=0;i<countNumber;i++){
		if(obligatoryCredit>0)
			result+=(this->courseList[i]->getWeight())* (this->courseList[i]->getScore()) * (this->courseList[i]->getObligatoryCredit()) / obligatoryCredit;
		if(electiveNumber>0)
			result+=(this->courseList[i]->getWeight()) * (this->courseList[i]->getScore()) * (this->courseList[i]->getElectiveNumber()) / electiveNumber;
	}
	return result;
}

ostream& operator<<(ostream& output, const Student& s)
{
	output<<"������"<<s.name<<"\n�������ڣ�"<<s.d
		<<"\n����ɼ���"<<s.calcAchievement()
		<<"\nѡ����Ϣ���£�\n";
	for(int i=0;i<s.getCountNumber();i++)
    {
		output<<*s.courseList[i];
	}
	return output;
}
