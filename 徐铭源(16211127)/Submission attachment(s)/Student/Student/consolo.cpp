#include "Consolo.h"
Consolo::Consolo(){} 
Consolo::Consolo(int a)
{
	hide(); 
	char name[50];
	Date birthDate;
	cout<<"请输入学生姓名: "<<endl;
	cin>>name;
	cout<<"请输入学生生日: "<<endl;
	while(1)
    {
        try{
            int year,month,day;
			cin>>year>>month>>day;    
			birthDate.setBirthday(year,month,day);
            break;
        }
		catch(MyException ex)
        {
            cout<<"系统异常："<<ex.what()<<"\n";
            cout<<"请重新输入学生生日"<<endl;
        }
    }
	student=new Student(name, birthDate);
	ChooseModeFace();
	DeleteCourseNumber=0;
	run();
}
void Consolo::run()
{
	ifstream infile(".\\data\\course.txt");
	if(!infile)
	{
		cerr<<"打开文件出错!"<<endl;
	}
	int type;
	string name;
	int credit;
	int mark;char grade;
	int i=1;
	infile>>ChooseCourseNumber; 
	while( infile>>type>>name>>credit )
	{
		switch(type)
		{
			case 1:	
					infile>>grade;
					while (cin.fail())
					{
				        cin.clear();
				        cin.ignore();
				        cin>>grade;
					}ChooseCourseList[i++]=new ElectiveCourse(name,credit,grade);break;
			case 2: 	
					infile>>mark;				
					while (cin.fail())
					{
				        cin.clear();
				        cin.ignore();
				        break;
					}ChooseCourseList[i++]=new OblitaryCourse(name,credit,mark);break;
		} 
	}
	infile.close(); 
	for(;;)
	{
		if(kbhit())
		{
			this->move(getch());
		}
	}
}
void Consolo::ChooseModeFace()
{
	system("CLS");
	x=2,y=0;
	top=2;
	bottom=5;
	mode=1; 
	printf("------欢迎使用北航学生选课系统------\n");
	printf("-----请使用键盘上的↑↓进行操作------\n");
	printf("  查看学生信息\n"); 
	printf("  选课\n");
	printf("  退课\n");
	printf("  保存文件\n"); 
	printf("管理员操作:修改分数(按t)\n");
	gotoxy(x,y);
	printf("->");
}
void Consolo::StudentInformationFace()
{
	mode=2;
	system("CLS");
	printf("----------欢迎使用北航学生选课系统---------\n");
	printf("-----请使用键盘上的↑↓和回车进行操作------\n");
//	gotoxy
	cout<<*this->student;
	cout<<"总绩点:"<<this->student->calcCredit()<<endl;
	printf("\n(按ESC返回)\n");
} 
void Consolo::ChooseCourseFace()
{
	system("CLS");
	x=2,y=0;
	top=2;
	bottom=ChooseCourseNumber+1;
	mode=3;
	printf("------欢迎使用北航学生选课系统------\n");
	printf("-----请使用键盘上的↑↓进行操作------\n");
	
	for(int i=1;i<=ChooseCourseNumber;i++)
	{printf("  "); this->ChooseCourseList[i]->printCourse(); } 
	printf("\n(按ESC返回)\n");
	gotoxy(x,y);
	printf("->");
}
void Consolo::DeleteCourseFace()
{
	system("CLS");
	x=2,y=0;
	top=2;
	bottom=DeleteCourseNumber+1;
	mode=4;
	printf("------欢迎使用北航学生选课系统------\n");
	printf("-----请使用键盘上的↑↓进行操作------\n");

	for(int i=1;i<=DeleteCourseNumber;i++)
	{printf("  "); this->DeleteCourseList[i]->printCourse(); } 
	
	printf("\n(按ESC返回)\n");
	
	gotoxy(x,y);
	printf("->");
}
void Consolo::setScoreFace()
{
	system("CLS");
	x=2,y=0;
	top=2;
	bottom=DeleteCourseNumber+1;
	mode=5; 
	printf("------欢迎使用北航学生选课系统------\n");
	printf("-------------管理员界面-------------\n");
	for(int i=1;i<=DeleteCourseNumber;i++)
	{printf("  "); this->DeleteCourseList[i]->printCourse(); } 
	gotoxy(x,y);
	printf("->");
} 
void Consolo::SavaFileFace()
{
	char fileName[256];
    ofstream *outfile;
	mode=6;
	system("CLS");
	printf("----------欢迎使用北航学生选课系统---------\n");
	printf("-----请使用键盘上的↑↓和回车进行操作------\n");
//	gotoxy
	cout<<"请输入要保存的文件名"<<endl;
	cin>>fileName;
	outfile=new ofstream(fileName);
		if(!outfile)
			cerr<<"无法创建文件！\n";
		else
		{
			(*outfile)<<*student;
			for(int i=1;i<=DeleteCourseNumber;i++)
			{
				(*outfile)<<*DeleteCourseList[i]; 
			}
			(*outfile)<<"绩点:"<<this->student->calcCredit()<<endl;
			outfile->close();
			delete outfile;
		}
	ChooseModeFace();
}
void Consolo::move(char _op)
{
	if(_op==72)//上 
	{
		if(mode==1||mode==3||mode==4||mode==5)
		{ 
			if(x>top)
			{
				gotoxy(x,y);
				printf("  "); 
				x-=1;
				gotoxy(x,y);
				cout<<"->";
			}
		} 
	} 
	if(_op==80)//下 
	{
		if(mode==1||mode==3||mode==4||mode==5)
		{ 
			if(x<bottom)
			{
				gotoxy(x,y);
				printf("  "); 
				x+=1;
				gotoxy(x,y);
				cout<<"->";
			}
		}  
	}
	if(_op=='t') 
	{
		if(mode==1)
		setScoreFace(); 
	}
	if(_op==27)//ESC
	{
		if(mode!=5)
		{
			ChooseModeFace();
		} 
	}
	if(_op==13)//回车 
	{
		switch(mode)
		{
			case 1:
			{
				switch(x)
				{
						case 2:StudentInformationFace();break;
						case 3:ChooseCourseFace();break;
						case 4:DeleteCourseFace();break;
						case 5:SavaFileFace();break;
				} 
				break;
			} 
			case 3:
			{
				if(2<=x&&x<=ChooseCourseNumber+1&&ChooseCourseNumber>0)
				{
					if( typeid(*ChooseCourseList[x-1])==typeid (ElectiveCourse ) )
					{
						Course *a=new ElectiveCourse( *((ElectiveCourse*) ChooseCourseList[x-1]) );
						this->student->addCourse(a);
						DeleteCourseList[++DeleteCourseNumber]=ChooseCourseList[x-1]; 
						for(int i=x-1;i<=ChooseCourseNumber-1;i++) 
						ChooseCourseList[i]=ChooseCourseList[i+1];
						ChooseCourseNumber-=1;
						ChooseCourseFace();
					} 
					
					else if( typeid(*ChooseCourseList[x-1])==typeid (OblitaryCourse)  )
					{
						Course *a=new OblitaryCourse( *((OblitaryCourse*) ChooseCourseList[x-1]) );
						this->student->addCourse(a);
						DeleteCourseList[++DeleteCourseNumber]=ChooseCourseList[x-1]; 
						for(int i=x-1;i<=ChooseCourseNumber-1;i++) 
						ChooseCourseList[i]=ChooseCourseList[i+1];
						ChooseCourseNumber-=1;
						ChooseCourseFace();
					}
				} 
				break;
			} 
			case 4:
			{
				if(2<=x&&x<=DeleteCourseNumber+1&&DeleteCourseNumber>0)
					{
						this->student->removeCourse(x-1); 
						ChooseCourseList[++ChooseCourseNumber]=DeleteCourseList[x-1]; 
						for(int i=x-1;i<=DeleteCourseNumber-1;i++) 
						DeleteCourseList[i]=DeleteCourseList[i+1];
						DeleteCourseNumber-=1;
						DeleteCourseFace();
					} 
					break;
			} 
			case 5:
			{
					mode=6;
							system("CLS");
							printf("------欢迎使用北航学生选课系统------\n");
							printf("-------------管理员界面-------------\n");
									if( typeid(*DeleteCourseList[x-1])==typeid (ElectiveCourse ) )
									{
													printf("修改grade:"); 
													gotoxy(2,10);
										while(1) 
										{
											try
												{ 
													char _grade;cin>>_grade;
													
													while (cin.fail())
													{
														 cout<<"系统异常:"<<"The score's format is invalid!"<<"\n";
										           		 cout<<"请重新输入学生成绩"<<endl;
												        cin.clear();
												        cin.ignore();
												        cin>>_grade;
												    } 
												    
													((ElectiveCourse*)DeleteCourseList[x-1])->setGrade(_grade);
													setScoreFace();
													break;
												} 
											catch(MyException ex)
										        {
										            cout<<"系统异常："<<ex.what()<<"\n";
										            cout<<"请重新输入学生成绩"<<endl;
										        }
									    }
									}
									
									else 
									if( typeid(*DeleteCourseList[x-1])==typeid (OblitaryCourse)  )
									{
													printf("修改mark:");
													gotoxy(2,10);
										while(1)
										{ 
											try
												{ 
													int _mark;cin>>_mark;
													while (cin.fail())
													{
														 cout<<"系统异常:"<<"The score's format is invalid!"<<"\n";
										           		 cout<<"请重新输入学生成绩"<<endl;
												        cin.clear();
												        cin.ignore();
												        cin>>_mark;
												    } 
													((OblitaryCourse*)DeleteCourseList[x-1])->setMark(_mark);
													setScoreFace();
												} 
											catch(MyException ex)
										        {
										            cout<<"系统异常："<<ex.what()<<"\n";
										            cout<<"请重新输入学生成绩"<<endl;
										        }
										} 
									}
			} 
	}
	}
}
void Consolo::gotoxy(int _y,int _x)//移动光标的方法
{
    CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;                            
    HANDLE    hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.X = _x;                                    
    csbiInfo.dwCursorPosition.Y = _y;                                    
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);   
}

void Consolo::hide()//隐藏光标
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=false;
	SetConsoleCursorInfo(hOut,&cci);
}
Consolo::~Consolo()
{
}

