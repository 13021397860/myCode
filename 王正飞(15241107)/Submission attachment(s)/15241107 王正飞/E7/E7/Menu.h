#pragma once

#include "Student.h"

class Menu
{
public:
	static const void MainMenu();
private:
	static const void InputStudentInformation();
	static const void Operation();
	static const void ChooseCourse();
	static const void ViewState();
	static const void RemoveCourse();
	static const void MotifyScore();
	static const void Exit();
	static const void ChooseObligatoryCourse();
	static const void ChooseElectiveCourse();
	static const void CutOffRule();
	static const void LoadCourse();
	static const void Load();
	static const void Save();
	static const void PrepareStudent();
	static const bool InputOption(int &input_option);
};