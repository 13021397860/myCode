#include"Console.h"

Console::Console() {
	initCourse();
}

void Console::initCourse() {
	courseList.clear();
	fstream courseData;
	courseData.open(".\\CourseData.dat",ios::in);
	if(!courseData) {
		cerr<<"Cannot open CourseData.dat!\n";
		return;
	}
	string courseName;
	string temp;
	int creditHour;
	bool IsObligatory;
	while(courseData>>temp>>courseName>>temp>>creditHour>>temp>>IsObligatory) {
		Course* newCourse;
		if(IsObligatory) {
			newCourse=new ObligatoryCourse(courseName,creditHour);
		}
		else {
			newCourse=new ElectiveCourse(courseName,creditHour);
		}
		courseList.push_back(newCourse);
	}
	courseData.close();
}

void Console::run() {
	StudentCreate();
	mainMenu();
}

void Console::commandCheck(int num,int a,int b) {
	if(num<a||num>b) {
		throw MyException(1);
	}
}

void Console::mainMenu() {
	system("cls");
	cout<<*student<<endl;
	cout<<"Enter 1    --  Select your course\n"
	    <<"Enter 2    --  Quit a course\n"
	    <<"Enter 3    --  Set your grade\n"
	    <<"Enter 4    --  Exit\n";
	int command=0;
	cin>>command;
	while(cin.fail()) {
		cin.clear();
		cin.ignore();
		cout<<"Invalid Choice!\n";
		cin>>command;
	}
	try {
		commandCheck(command,1,4);
	}
	catch(MyException exc) {
		cout<<exc.showMsg()<<endl;
		system("pause");
		system("cls");
		mainMenu();
		return ;
	}
	if(command==1) {
		Choose();
	}
	else if(command==2) {
		Remove();
	}
	else if(command==3) {
		SetGrade();
	}
	else if(command==4) {
		system("cls");
		return ;
	}
}

void Console::Choose() {
	system("cls");
	cout<<*student<<endl;
	for(int i=0; i<(int)courseList.size(); i++) {
		cout<<"No."<<i+1<<":"<<*courseList[i]<<endl;
	}
	cout<<endl<<"Enter Number to Select a course \n"<<"Enter 0 to Return\n\n";
	int x;
	cin>>x;
	while(1) {
		while(cin.fail()) {
			cin.clear();
			cin.ignore();
			cout<<"Invalid Input!\nEnter Number to Select a course \n"<<"Enter 0 to Return\n\n";
			cin>>x;
		}
		try {
			commandCheck(x,0,(int)courseList.size());
		}
		catch(MyException exc) {
			cout<<exc.showMsg()<<endl;
			system("pause");
			system("cls");
			mainMenu();
			return ;
		}
		//else {
		break;
		//}
	}
	if(x) {
		student->addCourse(courseList[x-1]);
		vector<Course*>::iterator it=courseList.begin();
		for(int i=0; i<x-1; i++) it++;
		courseList.erase(it);
	}
	mainMenu();
}

void Console::Remove() {
	system("cls");
	cout<<*student<<endl;
	int i;
	cout<<"Which Course will you quit? :";
	cin>>i;
	while(1) {
		while(cin.fail()) {
			cin.clear();
			cin.ignore();
			cout<<"Invalid Input!\nWhich Course will you quit? :";
			cin>>i;
		}
		try {
			commandCheck(i,0,student->getCourseNumber());
		}
		catch(MyException exc) {
			cout<<exc.showMsg()<<endl;
			system("pause");
			system("cls");
			mainMenu();
			return ;
		}
		//else {
		break;
		//}
	}
	student->removeCourse(i-1);
	mainMenu();
}

void Console::SetGrade() {
	system("cls");
	cout<<*student<<endl;
	int i;
	cout<<"Which Course will you set the grade? :";
	cin>>i;
	while(1) {
		while(cin.fail()) {
			cin.clear();
			cin.ignore();
			cout<<"Which Course will you set the grade? :";
			cin>>i;
		}
		try {
			commandCheck(i,0,student->getCourseNumber());
		}
		catch(MyException exc) {
			cout<<exc.showMsg()<<endl;
			system("pause");
			system("cls");
			mainMenu();
			return ;
		}
		//else {
		break;
		//}
	}
	student->setGrade(i-1);
	mainMenu();
}

void Console::StudentCreate() {
	cout<<"Set the Student name:";
	string name;
	cin>>name;
	cout<<"Set the Student's Birthdate:";
	Date date;
	try {
		cin>>date;
	}
	catch(MyException exc) {
		cout<<exc.showMsg()<<endl;
		system("pause");
		system("cls");
		StudentCreate();
		return ;
	}
	student=new Student(name.c_str(),date);
}

void Console::SaveFile() {
	fstream studentData;
	studentData.open(".\\StudentData.dat",ios::out);
	if(!studentData) {
		cerr<<"Cannot open StudentData.dat!\n";
		return;
	}
	studentData<<*student<<endl;
	studentData.close();
}

Console::~Console() {
	SaveFile();
	delete student;
}
