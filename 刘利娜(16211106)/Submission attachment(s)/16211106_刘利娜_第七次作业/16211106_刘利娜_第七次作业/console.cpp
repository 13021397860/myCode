#include "console.h"
#include"Student.h"
#include <fstream>
console::console()
{
    ocNum=0;
    ecNum=0;
}

console::~console()
{
    //dtor
    for(int i=0;i<ocNum;i++)
        delete OC[i];
	for(int i=0;i<ecNum;i++)
        delete EC[i];
}

int console::run()
{
    char fileName[256];
    ofstream *file;
    student();
    course();
	int num=menu();
	while(num)
    {
        if(num==1||num==2)
            student1->addCourse(selectCourse(num));
        else if(num==3)
            cout<<*student1;
        else if(num==4)
            setCourseScore();
        else if(num==5)
        {
            for(int i=0;i<student1->getcourseNumber();i++)
            {
                cout<<"�γ����ƣ�"<<  (*student1)[i].getname()<<"   �ɼ���"<<   (*student1)[i].getScore()<<"\n";
            }
        }
        else if(num==6)
            cout<<"ѧ����"<<student1->getName()<<"  �ļ���Ϊ: "<<student1->calcCredit()<<"\n";
        else if(num==7)
        {
            string coursename;
            cout<<"����Ҫ�˵Ŀγ����ƣ� ";
            cin>>coursename;
            student1->removeCourse(coursename);
        }
        else if(num==8)
        {
            cout<<"��������Ҫ������ļ�����";
            cin>>fileName;
            file=new ofstream(fileName);
            if(!file)
            {
                cerr<<"�޷������ļ�\n";
                break;
            }
            (*file)<<*student1;
            file->close();
            delete file;
        }
        num=menu();
    }
    return 0;
}

Course* console::selectCourse(int num)
{
	int i,choice=-1;
	cout<<"Please select a course:\n";
    if(num==1)
    {
        while((choice>ocNum)||(choice<0))
        {
            for(i=0;i<ocNum;i++)
            {
                string s=OC[i]->getname();
                int t=OC[i]->getcreditHour();
                cout<<i+1<<"."<<s<<"  "<<t<<"\n";
            }
            cout<<"��Ҫѡ�Ŀγ��ǣ�";
            cin>>choice;
        }
        if(choice)
            return OC[choice-1];
    }
    else if(num==2)
    {
        while((choice>ecNum)||(choice<0))
        {
            for(i=0;i<ecNum;i++)
            {
                string s=EC[i]->getname();
                int t=EC[i]->getcreditHour();
                cout<<i+1<<"."<<s<<"  "<<t<<"\n";
            }
            cout<<"��Ҫѡ�Ŀγ��ǣ�";
            cin>>choice;
        }
        if(choice)
            return EC[choice-1];
    }
	return NULL;
}
console& console::student()
{
	char name[20];
	Date birthDate;
    cout<<"Please input a name: ";
	cin>>name;
	cout<<"please input the birthday of the student: ";
    while(true)
    {
        try{
            cin>>birthDate;
            break;
        }
        catch(MyException ex)
        {
            cout<<"Error��"<<ex.what()<<"\n";
            cout<<"Please input the birthday of the student again:";
        }
    }
	student1=new Student(name,birthDate);
	return *this;
}

console& console::course()
{
    char fileName[]=".\\Courselist\\CourseList.txt";
	ifstream file(fileName);
	int flag,credit;
	string name;
	ocNum=0;
	ecNum=0;
	while(file>>flag>>name>>credit)
    {
		switch (flag)
		{
		case 1:
			OC[ocNum++]=new ObligatoryCourse(name,credit);
			break;
		case 2:
			EC[ecNum++]=new ElectiveCourse(name,credit);
			break;
		}
	}
	file.close();

	return *this;
}
void console::setCourseScore()
{
    int mark;
    char grade;
    for(int i=0;i<student1->getcourseNumber();i++)
    {
        if(typeid(ObligatoryCourse)==typeid((*student1)[i]))
        {
            cout<<"���޿γ̡�"<<(*student1)[i].getname()<<"���ĳɼ�(0-100)��";
            cin>>mark;
            //dynamic_cast<ObligatoryCourse&>((*student1)[i]).setMark(mark);
            while(true)
            {
                try
                {
                    dynamic_cast<ObligatoryCourse&>((*student1)[i]).setMark(mark);
                    break;
                }
                catch(MyException eT)
                {
                    cout<<"��ʽ���󣬱��޿γ̡�"<<(*student1)[i].getname()<<"���ĳɼ�(0-100)��";
                    cin>>mark;
                }
			}
        }
        else if (typeid(ElectiveCourse)==typeid((*student1)[i]))
        {
            cout<<"ѡ�޿γ̡�"<<(*student1)[i].getname()<<"���ĳɼ�(A-E)��";
            cin>>grade;
            //dynamic_cast<ElectiveCourse&>((*student1)[i]).setgrade(grade);
            while(true)
            {
                try
                {
                    dynamic_cast<ElectiveCourse&>((*student1)[i]).setgrade(grade);
                    break;
                }
                catch(MyException eT)
                {
                    cout<<"��ʽ����ѡ�޿γ̡�"<<(*student1)[i].getname()<<"���ĳɼ�(A-E)��";
                    cin>>grade;
                }
			}
        }
    }
}


int console::menu()
{
    int num;
	cout<<"|~~~~ѧ��ѡ��ϵͳ���˵�~~~~~|"<<"\n";
	cout<<"|     1.Obligatory Course   |"<<"\n";
	cout<<"|     2.Elective Course     |"<<"\n";
	cout<<"|     3.ѡ�����            |"<<"\n";
	cout<<"|     4.���óɼ�            |"<<"\n";
	cout<<"|     5.��ѯ�ɼ�            |"<<"\n";
	cout<<"|     6.����ɼ�            |"<<"\n";
	cout<<"|     7.�˿�                |"<<"\n";
	cout<<"|     8.����                |"<<"\n";
	cout<<"|     0.�˳�����            |"<<"\n";
	cout<<"|     ��ѡ���������        |"<<"\n";
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<"\n";
	cin>>num;
	while(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"�����ʽ��������������"<<"\n";
        cin>>num;
    }
    while(num<0||num>8)
    {
        cout<<"��ѡ��0~8֮�����������ѡ��"<<"\n";
        cin>>num;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout<<"�����ʽ��������������"<<"\n";
            cin>>num;
        }
    }
	return num;
}
