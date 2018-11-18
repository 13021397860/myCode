#ifndef CISHI_H
#define CISHI_H
#include <iostream>
#include<vector>
#include"course.h"
#include"date.h"
#include"stu.h"
#include"myexception.h"
#include<fstream>
#define Max 1000
#include<string>
using namespace std;
class cishi
{
	public:
		cishi();
		~cishi();
		vector<Course*>Ocourse;
		vector<Course*>Ecourse;
		vector<Stu*>stu;
		void yunxing();
		void xuanke(); 
		void Odisplay();
		void Edisplay();
		void tuike();
		void dafen();
		Course * course;
		Stu * M;
		void coursesave();
		void courseload();
		void defualtcourseload();
		void stusave();
		ofstream ofile;
		ifstream ifile;
		int yunxing(int argc, char** argv);
	protected:
};

/*
3
ascsave
4

4
asccccccc
5

1
liyuan 1998 7 27
1
4
1
2
2
1
-1

1
xu 1999 9 9
1
3
1
2
2
4
-1


1
xiao 1996 6 6
1
0
1
2
2
0
-1

2



*/

#endif
