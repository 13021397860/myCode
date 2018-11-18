#include "cishi.h"
cishi::cishi()
{
}

cishi::~cishi()
{
}
void cishi::yunxing() 
		{
			
			
			
			cout<<"#必修课列表:"<<endl;
			Odisplay();
			cout<<"#选修课列表:"<<endl;
			Edisplay();
			while(1)
			{
				cout<<endl;
				cout<<"#输入0新建学生"<<" "<<endl;
				cout<<"#输入1进入选课系统"<<endl; 
				cout<<"#输入2打印学生名单，同时查询成绩"<<" "<<endl;
				cout<<"#输入3新建必修课"<<" "<<endl;
				cout<<"#输入4新建选修课"<<" "<<endl;
				cout<<"#输入5进入退课系统"<<" "<<endl;
				cout<<"#输入6进入打分系统"<<" "<<endl;
				cout<<"#输入7载入默认课程列表"<<" "<<endl;
				cout<<"#输入8载入自定义课程列表"<<" "<<endl;
				cout<<"#输入9将课程列表保存至自定义列表"<<" "<<endl;
				cout<<"#输入10保存学生信息"<<" "<<endl; 
				cout<<"#输入-1退出"<<endl;
				int x;
				cin>>x;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>x;
				}
				if(x==-1)break;
				else if(x==0)
				{
					try
					{
						char s[1000];int y,m,d,t,u;
						cout<<"#请输入学生姓名、出生年、月、日:";
						scanf("%s %d %d %d",s,&y,&m,&d);
						M=new Stu(s);
						
						int is=M->setBirth(y,m,d);
						if(is==0)
						{
							throw myexception("the date is invaild!!!");
						} 
						
						stu.push_back(M);
						cout<<"#创建成功"<<endl;
					}catch(myexception ex)
					{
						cerr<<ex.getmessage()<<endl;
					}
					
				}
				else if(x==1)
				{
					for(int i=0;i<stu.size();i++)
					{
						cout<<endl;
						cout<<i<<":";
						cout<<*stu[i];
					}
					xuanke();
					
				}
				else if(x==2)
				{
					for(int i=0;i<stu.size();i++)
					{
						cout<<endl;
						cout<<*stu[i];
					}
				}
				else if(x==3)
				{
					Course *X=new ObligatoryCourse;
					cout<<"#课程名:";
					string na;
					cin>>na;
					cout<<"#学分:";
					int xx;
					cin>>xx;
					while(cin.fail())
					{
						cin.clear();
						cin.ignore();
						cin>>xx;
					}
					X->setName(na);X->setCredit(xx);X->setScore(0);
					Ocourse.push_back(X);
				}
				else if(x==4)
				{
					Course * Y=new ObligatoryCourse;
					cout<<"#课程名:";
					string na;
					cin>>na;
					cout<<"#学分:";
					int xx;
					cin>>xx;
					while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>xx;
				}
					Y->setName(na);Y->setCredit(xx);Y->setScore(0);
					Ecourse.push_back(Y);
				}
				else if(x==5)
				{
					for(int i=0;i<stu.size();i++)
					{
						cout<<endl;
						cout<<i<<":";
						cout<<*stu[i];
					}
					tuike();
				}
				else if(x==6)
				{
					for(int i=0;i<stu.size();i++)
					{
						cout<<endl;
						cout<<i<<":";
						cout<<*stu[i];
					}
					dafen();
				}
				else if(x==7)
				{
					defualtcourseload();
					cout<<"#必修课:"<<endl;
					Odisplay();
					cout<<"#选修课:"<<endl;
					Edisplay();
				}
				else if(x==8)
				{
					courseload();
					cout<<"#必修课:"<<endl;
					Odisplay();
					cout<<"#选修课:"<<endl;
					Edisplay();
				}
				else if(x==9)
				{
					coursesave();
				}
				else if(x==10)
				{
					stusave();
				}
			}
			for(int i=0;i<Ocourse.size();i++)//释放内存 释放内存 
			{
				//cout<<"hahaha"<<endl;
				delete Ocourse[i];
			}
			for(int i=0;i<Ecourse.size();i++)//释放内存 释放内存 
			{
				//cout<<"lalala"<<endl;
				delete Ecourse[i];
			}
			for(int i=0;i<stu.size();i++)//释放内存 释放内存 
			{
				//cout<<"xixixi"<<endl;
				delete stu[i];
			}
		}
		void cishi::xuanke() 
		{
			try{
			cout<<"#请选择学生编号:";
			int x;
			cin>>x;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cin>>x;
			}
			if(x>=stu.size())
			{
				throw myexception("the subscript is invaild!!!");
			}
			else
			{
				cout<<"#必修课:"<<endl;
				Odisplay();
				cout<<endl<<"#选修课:"<<endl;
				Edisplay();
				while(1)
				{
					int t,u;
					cout<<"#输入1选择必修课，输入2选择选修课,输入-1结束选课:";
					cin>>t;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>t;
				}
					if(t==1)
					{
						cout<<"#请选择:"<<endl;
						Odisplay();
						cin>>u;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>u;
				}
						if(u>=0&&u<Ocourse.size())
						{
							course=new ObligatoryCourse(Ocourse[u]->getName(),Ocourse[u]->getCredit(),0);
							stu[x]->addCourse(course);
							cout<<"#选课成功"<<endl;
						}
					}
					else if(t==2)
					{
						cout<<"#请选择:"<<endl;
						Edisplay();
						cin>>u;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>u;
				}
						if(u>=0&&u<Ecourse.size())
						{
							course=new ElectiveCourse(Ecourse[u]->getName(),Ecourse[u]->getCredit(),0);
							stu[x]->addCourse(course);
							cout<<"#选课成功"<<endl;
						}
					}
					else if(t==-1)
					{
						break;
					}
					else
					{
						cout<<"#请重新输入"<<endl;
						continue;
					}
				}
				
			}
		}catch(myexception ex)
		{
			cout<<ex.getmessage()<<endl;
		}
		}
		void cishi::dafen()
		{
			try
			{
			cout<<"#请选择学生编号:";
			int x;
			cin>>x;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>x;
				}
			if(x>=stu.size())
			{
				throw myexception("the subscript is invaild!!!");
			}
			else
			{
				while(1)
				{
					cout<<"#请选择课程序号,输入-1退出";
					int y;
					cin>>y;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>y;
				}
					if(y==-1)break;
					stu[x]->vaCourse(y);
				}
				
			}
		}catch(myexception ex)
		{
			cerr<<ex.getmessage()<<endl;
		}
		}
		void cishi::tuike()
		{
			try{
			cout<<"#请选择学生编号:";
			int x;
			cin>>x;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>x;
				}
			if(x>=stu.size())
			{
				throw myexception("the subscript is invaild!!!");
			}
			else 
			{
				while(1)
				{
					cout<<"#请选择退课序号,输入-1退出";
					int y;
					cin>>y;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>y;
				}
					if(y==-1)break;
					stu[x]->removeCoourse(y);
				}
				
			}
		}catch(myexception ex)
		{
			cout<<ex.getmessage()<<endl;
		}
		}
		void cishi::Odisplay()
		{
			if(Ocourse.size()==0)
			{
				cout<<"#暂无课程"<<endl;return ;
			}
			for(int i=0;i<Ocourse.size();i++)
			{
				cout<<i<<":"<<*Ocourse[i];
			}
		}
		void cishi::Edisplay()
		{
			if(Ecourse.size()==0)
			{
				cout<<"#暂无课程"<<endl;return ;
			}
			for(int i=0;i<Ecourse.size();i++)
			{
				cout<<i<<":"<<*Ecourse[i];
			}
		}
		void cishi::coursesave()
		{
			ofile.open("courselist.txt",ios::trunc);
			ofile.close();
			ofile.open("courselist.txt",ios::out);
			for(int i=0;i<Ocourse.size();i++)
			{
				ofile<<*Ocourse[i];
			}	
			ofile<<"xx "<<"Obligatoryisover"<<' '<<"xx "<<-1<<' '<<"xx"<<endl;
			for(int i=0;i<Ecourse.size();i++)
			{
				ofile<<*Ecourse[i];
			}
			ofile<<"xx "<<"Electiveisover"<<' '<<"xx "<<-1<<' '<<"xx"<<endl;
			ofile.close();
		}
		void cishi::defualtcourseload()
		{
			while(Ocourse.size())
			{
				delete Ocourse[Ocourse.size()-1];
				Ocourse.pop_back();
			}
			while(Ecourse.size())
			{
				delete Ecourse[Ecourse.size()-1];
				Ecourse.pop_back();
			}
			ifile.open("defualtcourselist.txt",ios::in);
			ObligatoryCourse* X;
			ElectiveCourse* Y;
			string temp;
			string name;
			int credit;
			while(1)
			{
				ifile>>temp>>name;
				ifile>>temp;
				ifile>>credit;
				ifile>>temp;
				if(credit!=-1)
				{
					X=new ObligatoryCourse(name,credit,0);
					Ocourse.push_back(X);
				}
				else break;
			}
			while(1)
			{
				ifile>>temp>>name;
				ifile>>temp;
				ifile>>credit;
				ifile>>temp;
				if(credit!=-1)
				{
					Y=new ElectiveCourse(name,credit,'F');
					Ecourse.push_back(Y);
				}
				else break;
			}
			ifile.close();
		}
		void cishi::courseload()
		{
			while(Ocourse.size())
			{
				delete Ocourse[Ocourse.size()-1];
				Ocourse.pop_back();
			}
			while(Ecourse.size())
			{
				delete Ecourse[Ecourse.size()-1];
				Ecourse.pop_back();
			}
			ifile.open("courselist.txt",ios::in);
			ObligatoryCourse* X;
			ElectiveCourse* Y;
			string temp;
			string name;
			int credit;
			while(1)
			{
				ifile>>temp>>name;
				ifile>>temp;
				ifile>>credit;
				ifile>>temp;
				if(credit!=-1)
				{
					X=new ObligatoryCourse(name,credit,0);
					Ocourse.push_back(X);
				}
				else break;
			}
			while(1)
			{
				ifile>>temp>>name;
				ifile>>temp;
				ifile>>credit;
				ifile>>temp;
				if(credit!=-1)
				{
					Y=new ElectiveCourse(name,credit,'F');
					Ecourse.push_back(Y);
				}
				else break;
			}
			ifile.close();
		}
		void cishi::stusave()
		{
			ofile.open("stulist.txt",ios::out);
			for(int i=0;i<stu.size();i++)
			{
				ofile<<*stu[i];
			}
			ofile.close();
		}
