#pragma once
#include "Student.h"
#include <string>
#include "Base.h"
class Console:virtual public Base
{
public:
	virtual int run();
	virtual ~Console();
	static Console* creatConsole();
	virtual int classID() const;
private:
	virtual inline bool check();
	virtual int displayMenu()const;
	virtual bool buildStudent();
	virtual const Console& buildCourse();
	virtual const void selectCourse(int op);
	virtual bool setCourseScore();
	Student* student = nullptr;
	static Console* myConsole;
	Course *oc[MAX_SIZE];
	Course *ec[MAX_SIZE];
	int ocNum;
	int ecNum;
	std::string OClassFile;
	std::string EClassFile;
	explicit Console();
	Console(const Console &T);
	static const int ClassID = 031514;
};

