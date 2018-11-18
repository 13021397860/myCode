#include <iostream>
#include <iomanip>
#include <typeinfo>

#include "Student.h"
#include "Exception.h"

#define obligatory_course_weight 0.6
#define elective_course_weight 0.4

using namespace std;

int Student::count = 0;

Student::Student() : name("Unknown"), birthday(1, 1, 1), course_number(0) {}

Student::Student(const string input_name, const int input_year, const int input_month, const int input_date) : name(input_name), birthday(input_year, input_month, input_date), course_number(0)
{
	count++;
}

Student::Student(const Student &copy_student) : name(copy_student.name), birthday(copy_student.birthday), course_number(0)
{
	count++;
}

Student::~Student()
{
	while (course_number) delete courst_list[--course_number];
	count--;
}

Student& Student::SetName(const string input_name)
{
	name = input_name;
	return *this;
}

Student& Student::SetBirthday(Time t)
{
	birthday.SetTime(Year, t.GetTime(Year));
	birthday.SetTime(Month, t.GetTime(Month));
	birthday.SetTime(Date, t.GetTime(Date));
	return *this;
}

Student& Student::SetBirthday(const int input_year, const int input_month, const int input_date)
{
	birthday.SetTime(Year, input_year);
	birthday.SetTime(Month, input_month);
	birthday.SetTime(Date, input_date);
	return *this;
}

const string Student::GetName() const
{
	return name;
}

const Time Student::GetBirthday() const
{
	return birthday;
}

const int Student::GetCourseNumber() const
{
	return course_number;
}

const int Student::GetCount()
{
	return count;
}

Student& Student::AddCourse(Course *input_course)
{
	if (course_number >= MaxCourse) throw Exception("This student cannot have more courses\n");
	else
	{
		for (int i = 0;i < course_number;i++) if (courst_list[i]->GetName() == input_course->GetName()) throw Exception("This student has already chosen this course\n");
		cout << "Course chosen successfully\n";
		courst_list[course_number++] = input_course;
	}
	return *this;
}

ostream& operator<<(ostream &output, Student &s)
{
	output << "Name: " << s.name << ", Birthday: " << s.birthday << ", Course Chosen:" << s.course_number << ", Credit Point: " << setprecision(2) << fixed << s.CalCredit() << endl;
	s.ShowCurrentCourse(output);
	return output;
}

const bool Student::RemoveCourse(const int input_course_num)
{
	if (input_course_num >= course_number) return false;
	delete courst_list[input_course_num];
	for (int i = input_course_num;i < course_number - 1;i++) courst_list[i] = courst_list[i + 1];
	course_number--;
	return true;
}

const bool Student::SetCourseScore(const int input_course_num)
{
	cout << "\n----------------------------------------\n";
	int mark; char grade;
	if (typeid(ObligatoryCourse) == typeid(*courst_list[input_course_num]))
	{
		cout << "Input the mark of this obligatory course:\n";
		cin >> mark;
		if (cin.fail() || mark < 0 || mark > 100) { cin.clear(); cin.ignore(INT_MAX, '\n'); throw Exception("GRADE"); }
		dynamic_cast<ObligatoryCourse&>(*courst_list[input_course_num]).SetMark(mark);
		return true;
	}
	else if (typeid(ElectiveCourse) == typeid(*courst_list[input_course_num]))
	{
		cout << "Input the grade of this elective course:\n";
		cin >> grade;
		if (grade < 'A' || grade > 'E') { cin.clear(); cin.ignore(INT_MAX, '\n'); throw Exception("GRADE"); }
		dynamic_cast<ElectiveCourse&>(*courst_list[input_course_num]).SetGrade(grade);
		return true;
	}
	else return false;
}

const void Student::ShowCurrentCourse()
{
	for (int i = 0;i < course_number;i++) cout << i << "." << *courst_list[i] << endl;
}

const void Student::ShowCurrentCourse(ostream &output)
{
	for (int i = 0;i < course_number;i++) output << i << "." << *courst_list[i] << endl;
}

const double Student::CalCredit()
{
	double s = 0, obligatory_total = 0, elective_total = 0;
	for (int i = 0;i < course_number;i++)
	{
		if (typeid(ObligatoryCourse) == typeid(*courst_list[i])) obligatory_total += (double)courst_list[i]->GetCreditHour();
		else if (typeid(ElectiveCourse) == typeid(*courst_list[i])) elective_total++;
		else continue;
	}
	for (int i = 0;i < course_number;i++)
	{
		if (typeid(ObligatoryCourse) == typeid(*courst_list[i])) s += obligatory_course_weight*((double)courst_list[i]->GetScore()*(double)courst_list[i]->GetCreditHour() / obligatory_total);
		else if (typeid(ElectiveCourse) == typeid(*courst_list[i])) s += elective_course_weight*((double)courst_list[i]->GetScore()*(double)courst_list[i]->GetCreditHour() / elective_total);
		else continue;
	}
	return s;
}

const bool Student::isCorrectBirthday() const
{
	return birthday.isLegalTime();
}