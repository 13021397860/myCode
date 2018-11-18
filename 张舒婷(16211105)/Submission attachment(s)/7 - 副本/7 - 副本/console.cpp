#include "console.h"
#include "Student.h"
#include "MyException.h"
#include "Date.h"
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
                cout<<i+1<<"课程名称："<<  (*student1)[i].getname()<<endl;
            }
            cout<<"0. 退出查询"<<endl;
            cout<<"请输入要查询的课程编号："<<endl;
            int c;
            while(cin>>c)
            {
                if(c==0)
                    break;
                else if(c>0 && c<student1->getcourseNumber()+1)
                    cout<<"课程名称："<<  (*student1)[c-1].getname()<<"   成绩："<<   (*student1)[c-1].getScore()<<endl;
                else cout<<"错误：输入编号越界/n请重新输入要查询的课程编号：";
            }


        }
        else if(num==6)
            cout<<"学生："<<student1->getName()<<"  的绩点为: "<<student1->calcCredit()<<"\n";
        else if(num==7)
        {
            string coursename;
            cout<<"输入要退的课程名称： ";
            cin>>coursename;
            student1->removeCourse(coursename);
        }
        else if(num==8)
        {
            cout<<"请输入需要保存的文件名：";
            cin>>fileName;
            file=new ofstream(fileName);
            if(!file)
            {
                cerr<<"无法创建文件\n";
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
	cout<<"请选择课程："<<endl;
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
            cout<<"您要选的课程是：";
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
            cout<<"您要选的课程是：";
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
	int y,m,d;
	Date birthDate;
    cout<<"请输入姓名:";
	cin>>name;
	cout<<"请输入生日:";
	while(1)
    {
        try
        {
            cin>>y>>m>>d;
            Date birthDate(y,m,d);
            break;
        }
        catch(MyException ex)
        {
            cout<<"错误："<<ex.err()<<endl;
            cout<<"请重新输入学生生日：";
        }

    }

	student1=new Student(name, birthDate);
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
            cout<<"必修课程“"<<(*student1)[i].getname()<<"”的成绩(0-100)：";
            //dynamic_cast<ObligatoryCourse&>((*student1)[i]).setMark(mark);
            while(cin>>mark){
                try
                {
                    dynamic_cast<ObligatoryCourse&>((*student1)[i]).setMark(mark);
                    break;
                }
                catch(MyException ex)
                {
                    cout<<"错误："<<ex.err()<<endl;
                    cout<<"请重新设置，必修课程“"<<(*student1)[i].getname()<<"”的成绩(0-100)：";
                }
			}
        }
        else if (typeid(ElectiveCourse)==typeid((*student1)[i]))
        {
            cout<<"选修课程“"<<(*student1)[i].getname()<<"”的成绩(A-E)：";
            //dynamic_cast<ElectiveCourse&>((*student1)[i]).setgrade(grade);
            while(cin>>grade){
                try
                {
                    dynamic_cast<ElectiveCourse&>((*student1)[i]).setgrade(grade);
                    break;
                }
                catch(MyException ex)
                {
                    cout<<"错误："<<ex.err()<<endl;
                    cout<<"请重新设置，选修课程“"<<(*student1)[i].getname()<<"”的成绩(A-E)：";
                }
			}
        }
    }
}


int console::menu()
{
    int num;
	cout<<"~~~~学生选课系统主菜单~~~~~"<<"\n";
	cout<<"1.必修课程"<<"\n";
	cout<<"2.选修课程"<<"\n";
	cout<<"3.选课情况"<<"\n";
	cout<<"4.设置成绩"<<"\n";
	cout<<"5.查询成绩"<<"\n";
	cout<<"6.绩点成绩"<<"\n";
	cout<<"7.退课"<<"\n";
	cout<<"8.保存"<<"\n";
	cout<<"0.退出程序"<<"\n";
	cout<<"请选择所需操作"<<"\n";
	cin>>num;
	while(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"输入格式错误，请重新输入"<<"\n";
        cin>>num;
    }
    while(num<0||num>8)
    {
        cout<<"请选择0~8之间的数，重新选择："<<"\n";
        cin>>num;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout<<"输入格式错误，请重新输入"<<"\n";
            cin>>num;
        }
    }
	return num;
}
