#include "Console.h"
ObligatoryCourse* Console::OC[500];
ElectiveCourse* Console::EC[500];

Console::Console()
{
	ifstream file("Course.txt");
	string name;
	OCnum = ECnum = 0;
	int hour, num;
	if (!file.is_open()) {cout << "�ļ���ȡʧ�ܣ�" << endl;}
	else
	{
		while (file.good()) 
		{
			file >> name >> hour >> num;
			if (num == 1)
				OC[OCnum++] = new ObligatoryCourse(name, hour);
			else if (num == 2)
				EC[ECnum++] = new ElectiveCourse(name, hour);
		}
	}
	file.close();
}

Console::~Console()
{
	for (int i = 0; i < OCnum; i++)
		delete OC[i];
	for (int i = 0; i < ECnum; i++)
		delete EC[i];
}

bool Console::student()
{
	Date D;
	char name[100];
	char *cs;
	string ns;
	Student s;
	int year, month, day;
	int point, hour, type;
	cout << "ѡ���ȡ����ѧ������1��ѡ���½�ѧ������2" << endl;
	cin >> type;
	if (type == 1)
	{
		ifstream file("Stu.txt");
		if (!file.is_open()) { cout << "�ļ���ȡʧ�ܣ�" << endl; }
		else
		{

			file >> name >> year >> month >> day;
			cs = name;
			try
			{
				D.setYear(year);
				D.setMonth(month);
				D.setDay(day);
			}
			catch (MyException ex)
			{
				cout << ex.Identify() << endl;
			}
			s.setName(cs);
			s.setDate(D);
			file >> ns >> hour >> point >> type;
			while (file.good())
			{
				if (type == 1)
				{
					ObligatoryCourse* OC = new ObligatoryCourse(ns, hour);
					OC->setGrade(point);
					s.addCourse(OC);
				}
				else if (type == 2)
				{
					ElectiveCourse* EC = new ElectiveCourse(ns, hour);
					EC->setGrade(74 - point / 10);
					s.addCourse(EC);
				}
				file >> ns >> hour >> point >> type;
			}
		}
		file.close();
	}
	else if (type == 2)
	{
		cout << "Please input the student's name." << endl;
		cin >> name;
		cs = name;
		while (1)
		{
			try
			{
				cin >> D;
				break;
			}
			catch (MyException ex)
			{
				cout << ex.Identify() << endl;
			}
		}
		s.setName(cs);
		s.setDate(D);
	}
	int c = printGUI();
	while (c)
	{
		switch (c)
		{
		case 1:
			selectCourse(s);
			break;
		case 2:
			removeCourse(s);
			break;
		case 3:
			cout << s << endl;
			break;
		case 4:
			setCourseGrade(s);
			break;
		default:
			cout << "Please input right command." << endl;
			break;
		}
		cout << endl;
		c = printGUI();
	}
	ofstream files("Stu.txt");
	if (!files.is_open()) { cout << "�ļ��洢ʧ�ܣ�" << endl; }
	else
	{
		files << s.getName() << endl;
		files << s.getDate();
		for (int i = 1; i <= s.getCourseNumber(); i++)
		{
			files << s[i].getName() << " " << s[i].getCreditHour() << " " << s[i].getScore() << " ";
			if (typeid(ObligatoryCourse) == typeid(s[i]))
				files << 1 << endl;
			else if (typeid(ElectiveCourse) == typeid(s[i]))
				files << 2 << endl;
		}
	}
	files.close();
	return true;
}

int Console::printGUI()
{
	cout << "*****ѡ��ϵͳ*****" << endl;
	cout << "1. ѡ��" << endl;
	cout << "2. �˿�" << endl;
	cout << "3. �鿴ѡ�����" << endl;
	cout << "4. ���ÿγ̳ɼ�" << endl;
	cout << "0. �˳�ѡ��ϵͳ" << endl;
	cout << "��ѡ�����:";
	int x;
	while (!(cin >> x)||x<0||x>4)
	{
		cin.clear(); 
		while (cin.get() != '\n')
			continue;
		cout << "�����������������:";
	}
	cout << endl;
	return x;
}

bool Console::selectCourse(Student &s)
{
	cout << "�γ��б�����:" << endl;
	cout << "���޿�:" << endl;
	for (int i = 0; i < 5; i++)
		cout << i + 1 << ". " << "�γ�����: " << OC[i]->getName() << " ѧ��: " << OC[i]->getCreditHour() << endl;
	cout << "ѡ�޿�:" << endl;
	for (int i = 0; i < 5; i++)
		cout << i + 1 << ". " << "�γ�����: " << EC[i]->getName() << " ѧ��: " << EC[i]->getCreditHour() << endl;
	cout << "ѡ����޿�������1��ѡ�޿�������2:";
	int x, a, b;
	while (!(cin >> x) || x<0 || x>2)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "�����������������:";
	}
	if (x == 1)
	{
		cout << "������γ̱��:";
		cin >> a;
		if (a <= 0 || a > 5)
		{
			cout << "ѡ��ʧ��" << endl;
			return false;
		}
		ObligatoryCourse *cc;
		cc = new ObligatoryCourse;
		cc->setName(OC[a - 1]->getName());
		cc->setCreditHour(OC[a - 1]->getCreditHour());
		s.addCourse(cc);
		return true;
	}
	else if (x == 2)
	{
		cout << "������γ̱��:";
		cin >> b;
		if (b <= 0 || b > 5)
		{
			cout << "ѡ��ʧ��" << endl;
			return false;
		}
		ElectiveCourse *cc;
		cc = new ElectiveCourse;
		cc->setName(EC[b - 1]->getName());
		cc->setCreditHour(EC[b - 1]->getCreditHour());
		s.addCourse(cc);
		return true;
	}
}

bool Console::removeCourse(Student &s)
{
	cout << "��ѡ�γ�:" << endl;
	for (int i = 1; i <= s.getCourseNumber(); i++)
		cout << i <<". "<< s[i];
	cout << "��������ѡ�Ŀγ�:";
	int x;
	while (!(cin >> x))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "�����������������:";
	}
	if (x<1 || x>s.getCourseNumber())
	{
		cout << "��ѡʧ��" << endl;
		return false;
	}
	else
	{
		s.removeCourse(x);
		return true;
	}
}

bool Console::setCourseGrade(Student &s)
{
	cout << "��ѡ�γ�:" << endl;
	for (int i = 1; i <= s.getCourseNumber(); i++)
	{
		cout << i;
		if (typeid(ObligatoryCourse) == typeid(s[i]))
		{
			cout << ". ���޿� " << s[i];
			cout << "������γ̳ɼ���0~100��:";
			int x;
			while (!(cin >> x))
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "�����������������:";
			}
			try 
			{
				dynamic_cast<ObligatoryCourse &>(s[i]).setGrade(x);
			}
			catch (MyException ex)
			{
				cout << ex.Identify() << endl;
				return false;
			}
			cout << s[i];
		}
		else if (typeid(ElectiveCourse) == typeid(s[i]))
		{
			cout << ". ѡ�޿� " << s[i];
			cout << "������γ̳ɼ���A~E��:";
			char x;
			while (!(cin >> x))
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "�����������������:";
			}
			try 
			{
				dynamic_cast<ElectiveCourse &>(s[i]).setGrade(x); 
			}
			catch (MyException ex)
			{
				cout << ex.Identify() << endl;
				return false;
			}
			cin.clear();
			while (cin.get() != '\n')
				continue;
			dynamic_cast<ElectiveCourse &>(s[i]).setGrade(x);
			cout << s[i];
		}
	}
	return true;
}
