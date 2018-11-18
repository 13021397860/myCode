#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream outcourse("CourseData.txt",ios::out);
	if (!outcourse)
	{
		cerr<<"File could not open file"<<endl;
		exit(1);
	}
	string name;
	int credit;
	
	int count;
	cout<<"请输入课程总数：";
	cin>>count;
	
	for (int i=0;i<count;i++)
	{
		cin>>name>>credit;
	outcourse<<name<<"      "<<credit<<endl;
	}
	
 } 
