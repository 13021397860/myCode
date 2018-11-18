#include"Student.h"

int Student::count = 0;

Student::Student()
	:birthDate(),courseNumber(0)
{
	name = NULL;
	setName("Sky");
	for (int i = 0; i < MAX_SIZE; i++)
		courseList[i] = NULL;
	count++;
}

Student::Student(const char* const c)
	:birthDate(),courseNumber(0)
{
	name = NULL;
	setName(c);
	for (int i = 0; i < MAX_SIZE; i++)
		courseList[i] = NULL;
	count++;
}

Student::Student(const char* const c, const Date &d)
	:birthDate(d),courseNumber(0)
{
	name = NULL;
	setName(c);
	for (int i = 0; i < MAX_SIZE; i++)
		courseList[i] = NULL;
	count++;
}

Student::Student(const Student &s) 
	:birthDate(s.birthDate),courseNumber(0)
{
	name = NULL;
	setName(s.name);
	for (int i = 0; i < MAX_SIZE; i++)
		courseList[i] = NULL;
	count++;
}

Student::~Student()
{
	delete[] name;
	count--;
	while (courseNumber)
		removeCourse(courseNumber);
}

Student & Student::setName(const char* const c)
{
	if (name)
		delete[]name;
	name = new char[strlen(c) + 1];
	strcpy_s(name,strlen(c)+1, c);
	return *this;
}

Student & Student::setDate(const Date const date)
{
	birthDate.setYear(date.getYear());
	birthDate.setMonth(date.getMonth());
	birthDate.setDay(date.getDay());
	return *this;
}

Student & Student::setCourseNumber(const int const e)
{
	courseNumber = e;
	return *this;
}

double Student::calcCredit(double weightObligatory, double weightElective) const
{
	int creditObligatory = 0, numberElective = 0;
	for (int i = 1; i <= courseNumber; i++)
	{
		if (typeid(*courseList[i]) == typeid(ObligatoryCourse))
			creditObligatory += dynamic_cast<ObligatoryCourse*>(courseList[i])->getCreditHour();
		else if (typeid(*courseList[i]) == typeid(ElectiveCourse))
			numberElective++;
	}
	double ObligatoryCredit = 0, ElectiveCredit = 0;
	for (int i = 1; i <= courseNumber; i++)
	{
		if (typeid(*courseList[i]) == typeid(ObligatoryCourse))
			ObligatoryCredit += (double)(dynamic_cast<ObligatoryCourse*>(courseList[i])->getCreditHour())
			*(double)(dynamic_cast<ObligatoryCourse*>(courseList[i])->getScore()) / (double)(creditObligatory);
		else if (typeid(*courseList[i]) == typeid(ElectiveCourse))
			ElectiveCredit += (double)(dynamic_cast<ElectiveCourse*>(courseList[i])->getScore()) / (double)(numberElective);
	}
	ObligatoryCredit *= weightObligatory; ElectiveCredit *= weightElective;
	return ObligatoryCredit + ElectiveCredit;
}

Student& Student::addCourse(Course *c)
{
	for (int i = 1; i <= courseNumber; i++)
		if (courseList[i]->getName() == c->getName())
		{
			cout << "重复选课:";
			cout << courseList[i]->getName() << endl;
			return *this;
		}
	if (courseNumber < MAX_SIZE-1)
		courseList[++courseNumber] = c;
	return *this;
}

bool Student::removeCourse(int x)
{
	if (x < MAX_SIZE&&x>0)
	{
		if (courseList[x] != NULL)
		{
			Course *temp = courseList[x];
			delete temp;
			for (int i = x; i < courseNumber; i++)
				courseList[i] = courseList[i + 1];
			courseList[courseNumber] = NULL;
			courseNumber--;
			return true;
		}
	}
	return false;
}

ostream& operator<<(ostream &os, const Student &s)
{
	os << "姓名: " << s.name << " 出生日期: " << s.birthDate << "积点成绩: " << fixed << setprecision(2) << s.calcCredit(0.6, 0.4) << endl;
	os << "选课信息如下:" << endl;
	if (s.courseNumber == 0)
		os << "暂无课程" << endl;
	else
		for (int i = 1; i <= s.courseNumber; i++)
			os << *s.courseList[i];
	return os;
}

Course& Student::operator [](int x)
{
	if (x<0 || x>courseNumber)
		throw MyException(Range_Error);
	return (*courseList[x]);
}