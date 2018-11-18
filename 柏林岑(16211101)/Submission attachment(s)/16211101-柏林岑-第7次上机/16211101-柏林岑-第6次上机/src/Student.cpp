#include "Student.h"
#include "Date.h"
#include "MyException.h"
#include<iostream>
#include<string>
#include<cstring>
#include<typeinfo>
#include<fstream>
using namespace std;
int Student::count=0;
Student::Student():birthDate(1,1,1) {
    name= new char[10];
    strcpy(name,"nobody");
    courseNumber=0;
    count++;
}

Student::~Student() {
    delete []name;
    for(int i=0;i<courseNumber;i++)
	delete CourseList[i];
    count--;
}
Student::Student(const Student&stu):birthDate(stu.birthDate) {
    name=new char[strlen(stu.name)+1];
    strcpy(name,stu.name);
    courseNumber=0;
    count++;
}

Student::Student(char*na,const Date&dd):birthDate(dd) {
    setname(na);
    courseNumber=0;
    count++;
}

void Student::setname(const char*na) {
    delete []name;
    name =new char[strlen(na)+1];
    strcpy(name,na);
}
void Student::getbirthDate(Date &a)const {
  a.Datecpy(a,birthDate);
}
char* Student::getname()const {
    return name;
}
int Student::getcount() {
    return count;

}
Student& Student::addCourse(Course *course){
    if(courseNumber<MAX_SIZE){
		CourseList[courseNumber++]=course;
    }
    return (*this);
}
ostream &operator<<(ostream &output,const Student &a){
     output<<"������"<<a.name<<" ";
     output<<"�������ڣ�"<<a.birthDate<<" ѡ����Ϣ���£�\n";
     for(int i=0;i<a.courseNumber;i++){
	 output<<*(a.CourseList[i]);
     }
     return output;
}
bool Student::removeCourse(int i){
    if(i<courseNumber){
        delete CourseList[i];                 //�ͷŸ��ſγ̵���Ϣ
        for(int j=i;j<courseNumber-1;j++){
            CourseList[j]=CourseList[j+1];	  //���������Ŀγ�ǰ�ƣ����Ǳ�ɾ���Ŀγ���Ϣ
        }
        courseNumber--;	                      //��ѡ������-1
        return true;
    }
    else{ return false;}
}
void Student::setGrade(const int x){
	if(x>courseNumber)return ;
	if(typeid(*CourseList[x-1])==typeid(ElectiveCourse)){
	 char g;
	 cout<<"����ɼ�Ϊ(A-E):\n";
	 cin>>g;
	 while(1){
		while(cin.fail())
			{
			cin.clear();      //��cin.fail()��0
			cin.ignore();     //���Ե�ǰ�����ַ�
			cout<<"Error!Please enter A-E to set grade:\n";
			cin>>g;
	}
	try{
	if(g<'A'||g>'E'){
		throw MyException(2);}
	else break;}
	catch (MyException ex){
		cout<<ex.message()<<"\n";
		cout<<"Error!Enter A-E to select\n";
		cin>>g;
	}
    }
	 dynamic_cast<ElectiveCourse*>(CourseList[x-1])->setgrade(g);
	}
	if(typeid(*CourseList[x-1])==typeid(ObligatoryCourse))
		{
	int m;
	cout<<"����ɼ�Ϊ(0-100):\n";
	cin>>m;
	 while(1){
		while(cin.fail())
			{
			cin.clear();      //��cin.fail()��0
			cin.ignore();     //���Ե�ǰ�����ַ�

			cin>>m;
	}
	try{
	if(m<0||m>100){
			throw MyException(2);}
	else break;}
	catch (MyException ex){
		cout<<ex.message()<<"\n";

		cin>>m;
	}

    }
	dynamic_cast<ObligatoryCourse*>(CourseList[x-1])->setScore(m);
}
}
double Student::calcCredit()const{
	double sum=0;
	int ObligatoryCredit=calcObligatoryCredit();
	int ElectiveNumber=calcElectiveNumber();
    for(int i=0;i<courseNumber;i++){
		if(typeid(*CourseList[i])==typeid(ObligatoryCourse)){
			sum+=0.6*(CourseList[i]->getScore()*CourseList[i]->getcreditHour())/ObligatoryCredit;
		}
		else if(typeid(*CourseList[i])==typeid(ElectiveCourse)){
			sum+=0.4*(CourseList[i]->getScore())/ElectiveNumber;
		}
    }
    return sum;
}
int Student::calcObligatoryCredit() const{
	 int Credit=0;
     for(int i=0;i<courseNumber;i++){
	 if(typeid(*CourseList[i])==typeid(ObligatoryCourse))
		Credit+=CourseList[i]->getcreditHour();   //���Ҫ��.�Ļ���Ҫ(*CourseList[i].getcreditHour)
     }
      return Credit;
}
int Student::calcElectiveNumber()const{
     int count=0;
     for(int i=0;i<courseNumber;i++){
		if(typeid(*CourseList[i])==typeid(ElectiveCourse)){
			count++;
		}
     }
     return count;
}
int Student::getcoursenumber()const{
     return courseNumber;
 }
