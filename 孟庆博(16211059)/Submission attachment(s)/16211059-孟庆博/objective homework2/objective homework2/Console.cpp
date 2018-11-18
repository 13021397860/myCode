#include "stdafx.h"
#include "Console.h"


Console::Console()
{
}

int Console::run()
{
	buildStudent();
	buildCourse();
	selectCourse();	
	return 0;
}


Console::~Console()
{
}

int Console::displayMenu() const
{
	printf("Ҫѡ���޻�����ѡѡ�ޣ�\n1.��������1\n2.ѡ������2\n3.�鿴��ѡ�γ�3\n4.���óɼ�\n5.�Ƴ��γ�\n6.������������\n��������ţ��ûس�����������\n");
	return 0;
}


Course * Console::selectCourse()
{
	while (1)
	{
		displayMenu();
		int opnion;
		while (!(cin >> opnion))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "������һ��21�����ڵ�����\n";
		}
		if (opnion == 1)
		{
			printf("���޿γ��У�\n");
			for (int i = 1; i <= 4; i++)
			{
				cout << i << "." << oc[i]->getName() << endl;
			}
			printf("���������\n");
			cin >> opnion;
			a->addCourse(oc[opnion]);
		}
		else if (opnion == 2)
		{
			printf("ѡ�޿γ��У�\n");
			for (int i = 1; i <= 4; i++)
			{
				cout << i << "." << ec[i]->getName() << endl;
			}
			printf("���������\n");
			cin >> opnion;
			a->addCourse(ec[opnion]);
		}
		else if (opnion == 3)
		{
			cout << *a << endl;
		}
		else if (opnion == 4)
		{
			printf("������γ����\n");
			int num;
			while (1)
			{
				try
				{
					cin >> num;
					a->setGrade(num, 'a');
					break;
				}
				catch (MyException& a)
				{
					a.out();
				}
			}
			printf("��������Ҫ���õĳɼ�\n");
			if (a->nowCourse(num))
			{
				int gra;	
				while (1)
				{
					try
					{
						cin >> gra; 
						GradeException gg;
						if (gra > 100 || gra < 0)
							throw gg;
						break;
					}
					catch (MyException &u)
					{
						u.out();
					}
				}				
				setCourseScore(num, gra);
			}
			else
			{
				char gra;
				cin >> gra;
				setCourseScore(num, gra);
			}			
		}
		else if (opnion == 5)
		{
			printf("������γ����\n");
			int o;
			cin >> o;
			a->removeCourse(o);
		}
		else
		{
			ofstream out("save.txt");
			out << *a;
			out.close();
			break;
		}
	}	
	return nullptr;
}

bool Console::setCourseScore(int n, int g)
{
	a->setGrade(n, g);
	return false;
}

Console & Console::buildStudent()
{
	a = new Student;
	char *namae;
	namae = new char[10];
	printf("������ѧ���������ͳ������ڣ��ÿո����\n");
	cin >> namae;
	int year, month, day;
	while (1)
	{
		try
		{
			cin >> year >> month >> day;
			a->setBirth(year, month, day);
			break;
		}
		catch (MyException& u)
		{
			u.out();
		}
	}
	a->setName(namae);
	return *this;
}

Console & Console::buildCourse()
{
	string ecn[5];
	string ocn[5];
	int occ[5];
	int ecc[5];
	ifstream f2("1.txt");
	if (!f2.is_open()) // ����ļ��Ƿ�ɹ���  
		cout << "cannot open file." << endl;
	for (int i = 1; i <= 4; i++)
	{
		string a;
		f2 >> a;
		ecn[i] = a;
		int b;
		f2 >> b;
		ecc[i] = b;
	}
	for (int i = 1; i <= 4; i++)
	{
		string a;
		f2 >> a;
		ocn[i] = a;
		int b;
		f2 >> b;
		occ[i] = b;
	}
	for (int i = 1; i <= 4; i++)
	{
		oc[i] = new ObligataryCourse;
		oc[i]->setName(ocn[i]);
		oc[i]->setCredit(occ[i]);
		ec[i] = new ElectiveCourse;
		ec[i]->setName(ecn[i]);
		ec[i]->setCredit(ecc[i]);
	}
	f2.close();
	return *this;
}
