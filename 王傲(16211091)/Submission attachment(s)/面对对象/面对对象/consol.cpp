#include "console.h"
#include <fstream>
void Console::run()
{
	//写入文件 
	fstream M("math.txt",ios::out);
	M<<5<<' '<<"数学";
	M.close();
	fstream E("English.txt",ios::out);
	E<<4<<' '<<"英语";
	E.close();
	fstream C("Chinese.txt",ios::out);
	C<<3<<' '<<"语文";
	C.close();
	fstream P("PE.txt",ios::out);
	P<<2<<' '<<"体育";
	P.close();
	//main
    char name[50];
    string courseName;
    cout << "请输入学生姓名: ";
    cin  >> name;
    int year, month, day, choice, len = 0, creditHour;
    
    cout << "请输入出生日期: ";
    //cin  >> year >> month >> day;
    DateException tc;
    while(cin  >> year >> month >> day)
    {
    	if(tc.DateExceptionCheck(year,month,day))
    	break;
	}
    Student x(name, year, month, day);
    show();
	cin >> choice;
	if (cin.fail())
	{
        cin.clear();	//清除错误标记
		cin.ignore();   //移除错误字符
    }
    Course * courseList[10];
    while (choice != 8)
    {
        if (choice == 1)
        {
        	cout << "按数字键选择:\n"; 
            cout << "1)--必修课--\n"
					"2)--选修课--\n"
					"请选择：";
            cin  >> choice;
            if (cin.fail())
			{
        		cin.clear();	//清除错误标记
				cin.ignore();	//移除错误字符
    		};
            if (choice == 1)
            {
                cout << "课程名: ";
                cin  >> courseName;
                cout << "学分数: ";
                cin  >> creditHour;
                ObligatoryCourse * p = new ObligatoryCourse(courseName, 0,creditHour);
                courseList[len] = p;
                x.addCourse(p);
                ++len;
                cout << "\n选课成功！\n\n";
            } 
            else if (choice ==2 )
            {
                cout << "课程名: ";
                cin  >> courseName;
                cout << "学分数: ";
                cin  >> creditHour;
                ElectiveCourse * p = new ElectiveCourse(courseName,0, creditHour);
                courseList[len] = p;
                x.addCourse(p);
                ++len;
                cout << "\n选课成功！\n\n";
            }
            else
            {
            	cout << "\n输入错误，选课失败！\n\n";
            	show();
            	cin >> choice;
            	if (cin.fail())
				{
        			cin.clear();	//清除错误标记
					cin.ignore();	//移除错误字符
    			};
            	continue; 
			}
        }
        else if (choice == 2)
        {
            cout <<"请输入退选课程序号: ";
            cin >> choice;
            if (cin.fail())
			{
        		cin.clear();	//清除错误标记
				cin.ignore();	//移除错误字符
    		}
            if(choice <= 0 ||choice > len)
            {
            	cout << "\n输入错误，退课失败！\n\n";
            	show();
            	cin >> choice;
            	if (cin.fail())
				{
        			cin.clear();	//清除错误标记
					cin.ignore();	//移除错误字符
    			};
            	continue; 
			}
            for (int j = choice; j < len; ++j)
                courseList[j - 1] = courseList[j];
            --len;
            x.removeCourse(choice);
            cout << "\n退课成功！\n\n";
        }
        else if (choice == 3)
        {
        	cout <<"\n"<<x<<"\n";
		}           
        else if (choice == 4)
        {
            cout << "课程序号: ";
            cin >> choice;
            if (cin.fail())
			{
        		cin.clear();	//清除错误标记
				cin.ignore();	//移除错误字符
    		}
            if(choice <= 0 ||choice > len)
            {
            	cout << "\n输入错误，设置失败！\n\n";
            	show();
            	cin >> choice;
            	if (cin.fail())
				{
        			cin.clear();	//清除错误标记
					cin.ignore();	//移除错误字符
    			};
            	continue; 
			}
			ObligatoryCourse o; ElectiveCourse e;
            SetException tcc;
            if (typeid(*courseList[choice - 1]) == typeid(o))
            {
                int score;
                cout << "成绩(0~100): ";
                //cin >> score;
                while(1)
				{
					cin>>score;
					if(cin.fail())//如果输入不匹配，fail()会返回真
					{
						cin.clear();//清除fail状态 
						cin.sync();//清除缓冲区
						cout<<"不是数字，请重新输入：\n";
						continue;
					}
					if(tcc.SetExceptionChecki(score))
                	break;
        		}
                ObligatoryCourse * p = dynamic_cast<ObligatoryCourse*>(courseList[choice - 1]);
                p->setMark(score);
                cout << "\n设置成功！\n\n";
            }
            else if (typeid(*courseList[choice - 1]) == typeid(e))
            {
                char grade;
                cout << "成绩(A~E): ";
                while(1)
				{
					cin>>grade;
					if(cin.fail())//如果输入不匹配，fail()会返回真
					{
						cin.clear();//清除fail状态 
						cin.sync();//清除缓冲区
						cout<<"不是字母，请重新输入：\n";
						continue;
					}
					if(tcc.SetExceptionCheckc(grade))
                	break;
        		}
                ElectiveCourse * p = dynamic_cast<ElectiveCourse*>(courseList[choice- 1]);
                p->setGrade(grade);
                cout << "\n设置成功！\n\n";
            }
        }
        else if (choice == 5)
        {
            cout << "请输入课程序号: ";
            ArrException tccc;
            while(1)
			{
				cin>>choice;
				if(cin.fail())//如果输入不匹配，fail()会返回真
				{
					cin.clear();//清除fail状态 
					cin.sync();//清除缓冲区
					cout<<"不是数字，请重新输入：\n";
					continue;
				}
				if(tccc.ArrExceptionCheck(choice,len))
                break;
        	}
            /*
            while(cin >> choice)
            {
            	if (cin.fail())
				{
        			cin.clear();	//清除错误标记
					cin.ignore();
	//移除错误字符
    			}
                if(tc.DateExceptionCheck4(choice,len))
                break;
			}
			*/
            /*
            if (cin.fail())
			{
        		cin.clear();	//清除错误标记
				cin.ignore();	//移除错误字符
    		}
    		
            if(choice <= 0 ||choice > len)
            {
            	cout << "输入错误，查询失败！\n\n";
            	show();
            	cin >> choice;
            	if (cin.fail())
				{
        			cin.clear();	//清除错误标记
					cin.ignore();	//移除错误字符
    			};
            	continue; 
			}
			*/
			ObligatoryCourse o;ElectiveCourse e;
            Course * p = courseList[choice - 1];
            cout<<"\n该课程的成绩为："<<p->getScore()<<"\n\n";
        }
        else if (choice == 6)
        {
            cout<<x.calcCredit()<<endl;
        }
        else if (choice == 7)
        {
            //定义一个文件流，将学生成绩信息写入文件
			ofstream outfile("student.txt", ios::out);
			//将学生信息输出到文件，即写入文件
			outfile<<x;
			cout<<"\n已将学生信息储存到指定文件中\n"<<endl; 
        }
        else if (choice == 9)
        {
        	int i;
			char s[20];
        	cout << "按数字键选择：\n"
					"1)按文件读取数学课程(必修)\n" 
					"2)按文件读取英语课程(必修)\n"
					"3)按文件读取语文课程(必修)\n"
					"4)按文件读取体育课程(选修)\n";
			cin  >> choice;
			if (cin.fail())
			{
        		cin.clear();	//清除错误标记
				cin.ignore();	//移除错误字符
    		}
			if (choice == 1)
			{
				M.open("math.txt",ios::in);
  				M>>i;               //读取数据
 				M.getline(s,20);
            	ObligatoryCourse * p = new ObligatoryCourse(s ,0 ,i );
            	courseList[len] = p;
            	x.addCourse(p);
            	++len;
  				M.close();
  				cout<<"\n读取成功\n\n";
			}
			else if (choice == 2)
			{
				E.open("English.txt",ios::in);
  				E>>i;               //读取数据
 				E.getline(s,20);
            	ObligatoryCourse * p = new ObligatoryCourse(s ,0 ,i );
            	courseList[len] = p;
            	x.addCourse(p);
            	++len;
  				E.close();
  				cout<<"\n读取成功\n\n";
			}
			else if (choice == 3)
			{
				C.open("Chinese.txt",ios::in);
  				C>>i;               //读取数据
 				C.getline(s,20);
            	ObligatoryCourse * p = new ObligatoryCourse(s ,0 ,i );
            	courseList[len] = p;
            	x.addCourse(p);
            	++len;
  				C.close();
  				cout<<"\n读取成功\n\n";
			}
			else if (choice == 4)
			{
				P.open("PE.txt",ios::in);
  				P>>i;               //读取数据
 				P.getline(s,20);
            	ElectiveCourse * p = new ElectiveCourse(s ,0 ,i);
            	courseList[len] = p;
            	x.addCourse(p);
            	++len;
  				P.close();
  				cout<<"\n读取成功\n\n";
			}
			else
			{
            	cout << "\n输入错误，读取失败！\n\n";
            	show();
            	cin >> choice;
            	if (cin.fail())
				{
        			cin.clear();	//清除错误标记
					cin.ignore();	//移除错误字符
    			};
            	continue; 
			}
        }
        else
		{
			cout<<"\n输入错误，请重新输入\n\n";
		}
		show();
        cin >> choice;
        if (cin.fail())
		{
        	cin.clear();	//清除错误标记
			cin.ignore();	//移除错误字符
    	};
    } 
    return;
}

void Console::show()
{
    cout << "按数字键选择:\n"
            "1)--选择课程--  	2)--退选课程--\n3)--打印信息--  	4)--设置成绩--\n"
			"5)--查询成绩--  	6)--查询绩点--\n7)--存储文件--  	8)--离开界面--\n"
			"9)--按文件读入课程--\n"; 
	cout << "请选择："; 
}
