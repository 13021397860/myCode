#include "console.h"
#include <fstream>
void Console::run()
{
	//д���ļ� 
	fstream M("math.txt",ios::out);
	M<<5<<' '<<"��ѧ";
	M.close();
	fstream E("English.txt",ios::out);
	E<<4<<' '<<"Ӣ��";
	E.close();
	fstream C("Chinese.txt",ios::out);
	C<<3<<' '<<"����";
	C.close();
	fstream P("PE.txt",ios::out);
	P<<2<<' '<<"����";
	P.close();
	//main
    char name[50];
    string courseName;
    cout << "������ѧ������: ";
    cin  >> name;
    int year, month, day, choice, len = 0, creditHour;
    
    cout << "�������������: ";
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
        cin.clear();	//���������
		cin.ignore();   //�Ƴ������ַ�
    }
    Course * courseList[10];
    while (choice != 8)
    {
        if (choice == 1)
        {
        	cout << "�����ּ�ѡ��:\n"; 
            cout << "1)--���޿�--\n"
					"2)--ѡ�޿�--\n"
					"��ѡ��";
            cin  >> choice;
            if (cin.fail())
			{
        		cin.clear();	//���������
				cin.ignore();	//�Ƴ������ַ�
    		};
            if (choice == 1)
            {
                cout << "�γ���: ";
                cin  >> courseName;
                cout << "ѧ����: ";
                cin  >> creditHour;
                ObligatoryCourse * p = new ObligatoryCourse(courseName, 0,creditHour);
                courseList[len] = p;
                x.addCourse(p);
                ++len;
                cout << "\nѡ�γɹ���\n\n";
            } 
            else if (choice ==2 )
            {
                cout << "�γ���: ";
                cin  >> courseName;
                cout << "ѧ����: ";
                cin  >> creditHour;
                ElectiveCourse * p = new ElectiveCourse(courseName,0, creditHour);
                courseList[len] = p;
                x.addCourse(p);
                ++len;
                cout << "\nѡ�γɹ���\n\n";
            }
            else
            {
            	cout << "\n�������ѡ��ʧ�ܣ�\n\n";
            	show();
            	cin >> choice;
            	if (cin.fail())
				{
        			cin.clear();	//���������
					cin.ignore();	//�Ƴ������ַ�
    			};
            	continue; 
			}
        }
        else if (choice == 2)
        {
            cout <<"��������ѡ�γ����: ";
            cin >> choice;
            if (cin.fail())
			{
        		cin.clear();	//���������
				cin.ignore();	//�Ƴ������ַ�
    		}
            if(choice <= 0 ||choice > len)
            {
            	cout << "\n��������˿�ʧ�ܣ�\n\n";
            	show();
            	cin >> choice;
            	if (cin.fail())
				{
        			cin.clear();	//���������
					cin.ignore();	//�Ƴ������ַ�
    			};
            	continue; 
			}
            for (int j = choice; j < len; ++j)
                courseList[j - 1] = courseList[j];
            --len;
            x.removeCourse(choice);
            cout << "\n�˿γɹ���\n\n";
        }
        else if (choice == 3)
        {
        	cout <<"\n"<<x<<"\n";
		}           
        else if (choice == 4)
        {
            cout << "�γ����: ";
            cin >> choice;
            if (cin.fail())
			{
        		cin.clear();	//���������
				cin.ignore();	//�Ƴ������ַ�
    		}
            if(choice <= 0 ||choice > len)
            {
            	cout << "\n�����������ʧ�ܣ�\n\n";
            	show();
            	cin >> choice;
            	if (cin.fail())
				{
        			cin.clear();	//���������
					cin.ignore();	//�Ƴ������ַ�
    			};
            	continue; 
			}
			ObligatoryCourse o; ElectiveCourse e;
            SetException tcc;
            if (typeid(*courseList[choice - 1]) == typeid(o))
            {
                int score;
                cout << "�ɼ�(0~100): ";
                //cin >> score;
                while(1)
				{
					cin>>score;
					if(cin.fail())//������벻ƥ�䣬fail()�᷵����
					{
						cin.clear();//���fail״̬ 
						cin.sync();//���������
						cout<<"�������֣����������룺\n";
						continue;
					}
					if(tcc.SetExceptionChecki(score))
                	break;
        		}
                ObligatoryCourse * p = dynamic_cast<ObligatoryCourse*>(courseList[choice - 1]);
                p->setMark(score);
                cout << "\n���óɹ���\n\n";
            }
            else if (typeid(*courseList[choice - 1]) == typeid(e))
            {
                char grade;
                cout << "�ɼ�(A~E): ";
                while(1)
				{
					cin>>grade;
					if(cin.fail())//������벻ƥ�䣬fail()�᷵����
					{
						cin.clear();//���fail״̬ 
						cin.sync();//���������
						cout<<"������ĸ�����������룺\n";
						continue;
					}
					if(tcc.SetExceptionCheckc(grade))
                	break;
        		}
                ElectiveCourse * p = dynamic_cast<ElectiveCourse*>(courseList[choice- 1]);
                p->setGrade(grade);
                cout << "\n���óɹ���\n\n";
            }
        }
        else if (choice == 5)
        {
            cout << "������γ����: ";
            ArrException tccc;
            while(1)
			{
				cin>>choice;
				if(cin.fail())//������벻ƥ�䣬fail()�᷵����
				{
					cin.clear();//���fail״̬ 
					cin.sync();//���������
					cout<<"�������֣����������룺\n";
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
        			cin.clear();	//���������
					cin.ignore();
	//�Ƴ������ַ�
    			}
                if(tc.DateExceptionCheck4(choice,len))
                break;
			}
			*/
            /*
            if (cin.fail())
			{
        		cin.clear();	//���������
				cin.ignore();	//�Ƴ������ַ�
    		}
    		
            if(choice <= 0 ||choice > len)
            {
            	cout << "������󣬲�ѯʧ�ܣ�\n\n";
            	show();
            	cin >> choice;
            	if (cin.fail())
				{
        			cin.clear();	//���������
					cin.ignore();	//�Ƴ������ַ�
    			};
            	continue; 
			}
			*/
			ObligatoryCourse o;ElectiveCourse e;
            Course * p = courseList[choice - 1];
            cout<<"\n�ÿγ̵ĳɼ�Ϊ��"<<p->getScore()<<"\n\n";
        }
        else if (choice == 6)
        {
            cout<<x.calcCredit()<<endl;
        }
        else if (choice == 7)
        {
            //����һ���ļ�������ѧ���ɼ���Ϣд���ļ�
			ofstream outfile("student.txt", ios::out);
			//��ѧ����Ϣ������ļ�����д���ļ�
			outfile<<x;
			cout<<"\n�ѽ�ѧ����Ϣ���浽ָ���ļ���\n"<<endl; 
        }
        else if (choice == 9)
        {
        	int i;
			char s[20];
        	cout << "�����ּ�ѡ��\n"
					"1)���ļ���ȡ��ѧ�γ�(����)\n" 
					"2)���ļ���ȡӢ��γ�(����)\n"
					"3)���ļ���ȡ���Ŀγ�(����)\n"
					"4)���ļ���ȡ�����γ�(ѡ��)\n";
			cin  >> choice;
			if (cin.fail())
			{
        		cin.clear();	//���������
				cin.ignore();	//�Ƴ������ַ�
    		}
			if (choice == 1)
			{
				M.open("math.txt",ios::in);
  				M>>i;               //��ȡ����
 				M.getline(s,20);
            	ObligatoryCourse * p = new ObligatoryCourse(s ,0 ,i );
            	courseList[len] = p;
            	x.addCourse(p);
            	++len;
  				M.close();
  				cout<<"\n��ȡ�ɹ�\n\n";
			}
			else if (choice == 2)
			{
				E.open("English.txt",ios::in);
  				E>>i;               //��ȡ����
 				E.getline(s,20);
            	ObligatoryCourse * p = new ObligatoryCourse(s ,0 ,i );
            	courseList[len] = p;
            	x.addCourse(p);
            	++len;
  				E.close();
  				cout<<"\n��ȡ�ɹ�\n\n";
			}
			else if (choice == 3)
			{
				C.open("Chinese.txt",ios::in);
  				C>>i;               //��ȡ����
 				C.getline(s,20);
            	ObligatoryCourse * p = new ObligatoryCourse(s ,0 ,i );
            	courseList[len] = p;
            	x.addCourse(p);
            	++len;
  				C.close();
  				cout<<"\n��ȡ�ɹ�\n\n";
			}
			else if (choice == 4)
			{
				P.open("PE.txt",ios::in);
  				P>>i;               //��ȡ����
 				P.getline(s,20);
            	ElectiveCourse * p = new ElectiveCourse(s ,0 ,i);
            	courseList[len] = p;
            	x.addCourse(p);
            	++len;
  				P.close();
  				cout<<"\n��ȡ�ɹ�\n\n";
			}
			else
			{
            	cout << "\n������󣬶�ȡʧ�ܣ�\n\n";
            	show();
            	cin >> choice;
            	if (cin.fail())
				{
        			cin.clear();	//���������
					cin.ignore();	//�Ƴ������ַ�
    			};
            	continue; 
			}
        }
        else
		{
			cout<<"\n�����������������\n\n";
		}
		show();
        cin >> choice;
        if (cin.fail())
		{
        	cin.clear();	//���������
			cin.ignore();	//�Ƴ������ַ�
    	};
    } 
    return;
}

void Console::show()
{
    cout << "�����ּ�ѡ��:\n"
            "1)--ѡ��γ�--  	2)--��ѡ�γ�--\n3)--��ӡ��Ϣ--  	4)--���óɼ�--\n"
			"5)--��ѯ�ɼ�--  	6)--��ѯ����--\n7)--�洢�ļ�--  	8)--�뿪����--\n"
			"9)--���ļ�����γ�--\n"; 
	cout << "��ѡ��"; 
}
