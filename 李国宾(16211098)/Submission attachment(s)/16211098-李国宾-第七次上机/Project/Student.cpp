//Student.cpp
#include"Student.h"
#include<iostream>
#include<cstring>
#include<windows.h>
#include<typeinfo>
using namespace std;

int Student::count=0;

void Student::gradeCheck(int num,int a,int b) {
	if(num<a||num>b) {
		throw MyException(2);
	}
}
void Student::gradeCheck(char num,char a,char b) {
	if(num<a||num>b) {
		throw MyException(2);
	}
}

Student::Student():birthDate(1,1,1)	{
	name=new char[10];
	strcpy(name,"Undefined");
	courseNumber=0;
	count++;
}

Student::Student(const char* a,const Date _Date):birthDate(_Date) {
	name=new char[strlen(a)+1];
	strcpy(name,a);
	courseNumber=0;
	count++;
}

Student::Student(const char* a,const int y,const int m,const int d):birthDate(y,m,d) {
	name=new char[strlen(a)+1];
	strcpy(name,a);
	courseNumber=0;
	count++;
}

Student::Student(const Student& a):birthDate(a.birthDate) {
	name=new char[strlen(a.name)+1];
	strcpy(name,a.name);
	courseNumber=a.courseNumber;
	count++;
}

void Student::setName(const char* a) {
	delete []name;
	name=new char[strlen(a)+1];
	strcpy(name,a);
}

void Student::setGrade(int num) {
	if(num>=0&&num<courseNumber) {
		cout<<"Set the grade to:";
		if(typeid(*courseList[num])==typeid(ObligatoryCourse)) {
			int grade;
			cin>>grade;
			while(1) {
				while(cin.fail()) {
					cin.clear();
					cin.ignore();
					cout<<"\nInvalid Input! Try Again!\nSet the grade to:";
					cin>>grade;
				}
				try {
					gradeCheck(grade,0,100);
				}
				catch(MyException exc) {
					cout<<exc.showMsg()<<endl;
					system("pause");
					system("cls");
					return ;
				}
				//else {
				break;
				//}
			}
			dynamic_cast<ObligatoryCourse*>(courseList[num])->setGrade(grade);
		}
		else {
			string grade="F";
			cin>>grade;
			while(1) {
				while(cin.fail()) {
					cin.clear();
					cin.ignore();
					cout<<"\nInvalid Input! Try Again!\nSet the grade to:";
					cin>>grade;
				}
				try {
					gradeCheck(grade[0],'A','E');
				}
				catch(MyException exc) {
					cout<<exc.showMsg()<<endl;
					system("pause");
					system("cls");
					return ;
				}
				//else {
				break;
				//}
			}
			dynamic_cast<ElectiveCourse*>(courseList[num])->setGrade(grade[0]);
		}
	}
}

void Student::getName(char*& a) {
	delete []a;
	a=new char[strlen(name)+1];
	strcpy(a,name);
}

char* Student::getName() const {
	return name;
}

void Student::getBirthDate(Date* &a) {
	a->setDate(birthDate);
}

Date Student::getBirthDate() const {
	return birthDate;
}

int Student::getCount() {
	return count;
}

Student& Student::addCourse(Course *course) {
	courseList[courseNumber]=course;
	courseNumber++;
	return *this;
}

//Student& Student::addCourse(const string &courseName, int creditHour) {
//	courseList[courseNumber]=new Course(courseName,creditHour);
//	courseNumber++;
//	return *this;
//}

bool Student::removeCourse(int num) {
	if(num>=0&&num<courseNumber) {
		//delete courseList[num];
		courseNumber--;
		for(int i=num; i<courseNumber; i++) {
			courseList[i]=courseList[i+1];
		}
		return 1;
	}
	return 0;
}

//void Student::print(){
//    cout<<endl<<"Student:"<<name<<"        Birthdate:"<<birthDate<<endl;
//
//    for(int i=0;i<courseNumber;i++){
//		cout<<"CourseName:"<<courseList[i]->getName()<<"      "
//			<<"CreditHour:"<<courseList[i]->getCreditHour()<<endl
//            <<"Score:"<<courseList[i]->getScore()<<endl<<endl;
//    }
//    cout<<endl;
//}

ostream& operator<<(ostream& output, const Student& _Student) {
	output<<"StudentName: "<<_Student.getName()<<"  Birthdate: "<<_Student.getBirthDate()<<"  GPA: "<<fixed<<setprecision(2)<<_Student.calcCredit(0.6)<<"  ClassInfo:"<<endl;
	for(int i=0; i<_Student.courseNumber; i++) {
		output<<*(_Student.courseList[i])<<endl;
	}
	return output;
}

double Student::calcCredit(double ObliWeight) const {
	double Grade=0;
	int sumObliHour=0;
	int sumEleNum=0;
	double ObliGrade=0,EleGrade=0;
	for(int i=0; i<courseNumber; i++) {
		if(typeid(*courseList[i])==typeid(ObligatoryCourse)) {
			sumObliHour+=courseList[i]->getCreditHour();
			ObliGrade+=courseList[i]->getCreditHour()*courseList[i]->getScore();
		}
		else {
			sumEleNum++;
			EleGrade+=courseList[i]->getScore();
		}
	}
	if(sumObliHour)
		ObliGrade/=sumObliHour;
	if(sumEleNum)
		EleGrade/=sumEleNum;
	Grade=ObliWeight*ObliGrade+(1-ObliWeight)*EleGrade;
	return Grade;
}

int Student::getCourseNumber() const {
	return courseNumber;
}

Student::~Student() {
	for(int i=0; i<courseNumber; i++)
		delete courseList[i];
	delete []name;
	count--;
}
