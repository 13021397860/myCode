#include "cishi.h"
cishi::cishi()
{
}

cishi::~cishi()
{
}
void cishi::yunxing() 
		{
			
			
			
			cout<<"#���޿��б�:"<<endl;
			Odisplay();
			cout<<"#ѡ�޿��б�:"<<endl;
			Edisplay();
			while(1)
			{
				cout<<endl;
				cout<<"#����0�½�ѧ��"<<" "<<endl;
				cout<<"#����1����ѡ��ϵͳ"<<endl; 
				cout<<"#����2��ӡѧ��������ͬʱ��ѯ�ɼ�"<<" "<<endl;
				cout<<"#����3�½����޿�"<<" "<<endl;
				cout<<"#����4�½�ѡ�޿�"<<" "<<endl;
				cout<<"#����5�����˿�ϵͳ"<<" "<<endl;
				cout<<"#����6������ϵͳ"<<" "<<endl;
				cout<<"#����7����Ĭ�Ͽγ��б�"<<" "<<endl;
				cout<<"#����8�����Զ���γ��б�"<<" "<<endl;
				cout<<"#����9���γ��б������Զ����б�"<<" "<<endl;
				cout<<"#����10����ѧ����Ϣ"<<" "<<endl; 
				cout<<"#����-1�˳�"<<endl;
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
						cout<<"#������ѧ�������������ꡢ�¡���:";
						scanf("%s %d %d %d",s,&y,&m,&d);
						M=new Stu(s);
						
						int is=M->setBirth(y,m,d);
						if(is==0)
						{
							throw myexception("the date is invaild!!!");
						} 
						
						stu.push_back(M);
						cout<<"#�����ɹ�"<<endl;
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
					cout<<"#�γ���:";
					string na;
					cin>>na;
					cout<<"#ѧ��:";
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
					cout<<"#�γ���:";
					string na;
					cin>>na;
					cout<<"#ѧ��:";
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
					cout<<"#���޿�:"<<endl;
					Odisplay();
					cout<<"#ѡ�޿�:"<<endl;
					Edisplay();
				}
				else if(x==8)
				{
					courseload();
					cout<<"#���޿�:"<<endl;
					Odisplay();
					cout<<"#ѡ�޿�:"<<endl;
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
			for(int i=0;i<Ocourse.size();i++)//�ͷ��ڴ� �ͷ��ڴ� 
			{
				//cout<<"hahaha"<<endl;
				delete Ocourse[i];
			}
			for(int i=0;i<Ecourse.size();i++)//�ͷ��ڴ� �ͷ��ڴ� 
			{
				//cout<<"lalala"<<endl;
				delete Ecourse[i];
			}
			for(int i=0;i<stu.size();i++)//�ͷ��ڴ� �ͷ��ڴ� 
			{
				//cout<<"xixixi"<<endl;
				delete stu[i];
			}
		}
		void cishi::xuanke() 
		{
			try{
			cout<<"#��ѡ��ѧ�����:";
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
				cout<<"#���޿�:"<<endl;
				Odisplay();
				cout<<endl<<"#ѡ�޿�:"<<endl;
				Edisplay();
				while(1)
				{
					int t,u;
					cout<<"#����1ѡ����޿Σ�����2ѡ��ѡ�޿�,����-1����ѡ��:";
					cin>>t;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>t;
				}
					if(t==1)
					{
						cout<<"#��ѡ��:"<<endl;
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
							cout<<"#ѡ�γɹ�"<<endl;
						}
					}
					else if(t==2)
					{
						cout<<"#��ѡ��:"<<endl;
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
							cout<<"#ѡ�γɹ�"<<endl;
						}
					}
					else if(t==-1)
					{
						break;
					}
					else
					{
						cout<<"#����������"<<endl;
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
			cout<<"#��ѡ��ѧ�����:";
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
					cout<<"#��ѡ��γ����,����-1�˳�";
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
			cout<<"#��ѡ��ѧ�����:";
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
					cout<<"#��ѡ���˿����,����-1�˳�";
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
				cout<<"#���޿γ�"<<endl;return ;
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
				cout<<"#���޿γ�"<<endl;return ;
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
