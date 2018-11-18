#include "Consolo.h"
Consolo::Consolo(){} 
Consolo::Consolo(int a)
{
	hide(); 
	char name[50];
	Date birthDate;
	cout<<"������ѧ������: "<<endl;
	cin>>name;
	cout<<"������ѧ������: "<<endl;
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
            cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
            cout<<"����������ѧ������"<<endl;
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
		cerr<<"���ļ�����!"<<endl;
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
	printf("------��ӭʹ�ñ���ѧ��ѡ��ϵͳ------\n");
	printf("-----��ʹ�ü����ϵġ������в���------\n");
	printf("  �鿴ѧ����Ϣ\n"); 
	printf("  ѡ��\n");
	printf("  �˿�\n");
	printf("  �����ļ�\n"); 
	printf("����Ա����:�޸ķ���(��t)\n");
	gotoxy(x,y);
	printf("->");
}
void Consolo::StudentInformationFace()
{
	mode=2;
	system("CLS");
	printf("----------��ӭʹ�ñ���ѧ��ѡ��ϵͳ---------\n");
	printf("-----��ʹ�ü����ϵġ����ͻس����в���------\n");
//	gotoxy
	cout<<*this->student;
	cout<<"�ܼ���:"<<this->student->calcCredit()<<endl;
	printf("\n(��ESC����)\n");
} 
void Consolo::ChooseCourseFace()
{
	system("CLS");
	x=2,y=0;
	top=2;
	bottom=ChooseCourseNumber+1;
	mode=3;
	printf("------��ӭʹ�ñ���ѧ��ѡ��ϵͳ------\n");
	printf("-----��ʹ�ü����ϵġ������в���------\n");
	
	for(int i=1;i<=ChooseCourseNumber;i++)
	{printf("  "); this->ChooseCourseList[i]->printCourse(); } 
	printf("\n(��ESC����)\n");
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
	printf("------��ӭʹ�ñ���ѧ��ѡ��ϵͳ------\n");
	printf("-----��ʹ�ü����ϵġ������в���------\n");

	for(int i=1;i<=DeleteCourseNumber;i++)
	{printf("  "); this->DeleteCourseList[i]->printCourse(); } 
	
	printf("\n(��ESC����)\n");
	
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
	printf("------��ӭʹ�ñ���ѧ��ѡ��ϵͳ------\n");
	printf("-------------����Ա����-------------\n");
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
	printf("----------��ӭʹ�ñ���ѧ��ѡ��ϵͳ---------\n");
	printf("-----��ʹ�ü����ϵġ����ͻس����в���------\n");
//	gotoxy
	cout<<"������Ҫ������ļ���"<<endl;
	cin>>fileName;
	outfile=new ofstream(fileName);
		if(!outfile)
			cerr<<"�޷������ļ���\n";
		else
		{
			(*outfile)<<*student;
			for(int i=1;i<=DeleteCourseNumber;i++)
			{
				(*outfile)<<*DeleteCourseList[i]; 
			}
			(*outfile)<<"����:"<<this->student->calcCredit()<<endl;
			outfile->close();
			delete outfile;
		}
	ChooseModeFace();
}
void Consolo::move(char _op)
{
	if(_op==72)//�� 
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
	if(_op==80)//�� 
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
	if(_op==13)//�س� 
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
							printf("------��ӭʹ�ñ���ѧ��ѡ��ϵͳ------\n");
							printf("-------------����Ա����-------------\n");
									if( typeid(*DeleteCourseList[x-1])==typeid (ElectiveCourse ) )
									{
													printf("�޸�grade:"); 
													gotoxy(2,10);
										while(1) 
										{
											try
												{ 
													char _grade;cin>>_grade;
													
													while (cin.fail())
													{
														 cout<<"ϵͳ�쳣:"<<"The score's format is invalid!"<<"\n";
										           		 cout<<"����������ѧ���ɼ�"<<endl;
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
										            cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
										            cout<<"����������ѧ���ɼ�"<<endl;
										        }
									    }
									}
									
									else 
									if( typeid(*DeleteCourseList[x-1])==typeid (OblitaryCourse)  )
									{
													printf("�޸�mark:");
													gotoxy(2,10);
										while(1)
										{ 
											try
												{ 
													int _mark;cin>>_mark;
													while (cin.fail())
													{
														 cout<<"ϵͳ�쳣:"<<"The score's format is invalid!"<<"\n";
										           		 cout<<"����������ѧ���ɼ�"<<endl;
												        cin.clear();
												        cin.ignore();
												        cin>>_mark;
												    } 
													((OblitaryCourse*)DeleteCourseList[x-1])->setMark(_mark);
													setScoreFace();
												} 
											catch(MyException ex)
										        {
										            cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
										            cout<<"����������ѧ���ɼ�"<<endl;
										        }
										} 
									}
			} 
	}
	}
}
void Consolo::gotoxy(int _y,int _x)//�ƶ����ķ���
{
    CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;                            
    HANDLE    hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.X = _x;                                    
    csbiInfo.dwCursorPosition.Y = _y;                                    
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);   
}

void Consolo::hide()//���ع��
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

