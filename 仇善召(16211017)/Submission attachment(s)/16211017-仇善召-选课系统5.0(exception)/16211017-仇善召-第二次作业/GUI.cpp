#include "GUI.h"
#include <fstream>
GUI::GUI()
{
    //ctor
}
int GUI::run()
{
    int i;
    cout<<"*******************测试文件读入操作***************"<<endl;
    ifstream ifile("data.txt");
     int isObli;
     string name;
     int hour;
    while (ifile>>isObli>>name>>hour)
    {
         Course *p;
    if ( 1==isObli)
     {
         p=new ObligatoryCourse;
         p->setname(name);
         p->setHour(hour);
     }
    if (2==isObli )
     {
          p=new ElectiveCourse;
         p->setname(name);
         p->setHour(hour);
     }
     cout<<*p;
    }
    cout<<"*******************测试文件读入操作***************"<<endl;


    Student a;
    cout<<" 请输入学生姓名：";
    char s[20];
    cin>> s;
    a.setName(s);

    cout<<" 请输入学生生日: ";
    int y,m,d;
    while (1){
     cin>>y>>m>>d;
     try
      {
        Date date(y,m,d);
        a.setDate( date );
        break;
      }catch (My_Exception ex)
      {
        cout<<ex.what()<<endl;
      }
    }


   cout<<" 学生对象构建完毕。接下来您想：\n输入1查看学生信息\n输入2添加课程\n输入3添加课程成绩\n输入4退选课程\n输入5退出程序\n输入6保存学生信息\n";


    while ( 1 )

    {
        int i;
        cin>>i;
       while ( cin.fail() || i>=7 || i<=0 )
       {
           cout<<"指令错误。请重新输入：\n";
           cin.clear();
           cin.ignore();
           cin>>i;
       }
        if ( i==5 )
        return 0;
       else if ( i==1 )
      {

        cout<<a;
        cout<<" 查看信息完毕。接下来您想：\n输入2添加课程\n输入3添加课程成绩\n输入4退选课程\n输入5退出程序\n输入6保存学生信息\n";

      }
      else if ( i==6 )
      {
        ofstream ofile("student.txt");
        ofile<<a;
        ofile.flush();
        ofile.close();
        cout<<"保存信息完毕。接下来您想：\n输入1查看学生信息\n输入2添加课程\n输入3添加课程成绩\n输入4退选课程\n输入5退出程序\n";
      }
   else  if ( i==2 )
    {

        cout<<"\n添加必修课请输入1\n添加选修课请输入2\n";
        int m;
        cin>>m;
        cout<<" 请输入课程名字： "<<endl;
        string z;
        cin>>z;
        cout<<" 请输入课程学分： "<<endl;
        int hour;
        cin>>hour;
        /*cout<<" 请输入课程成绩： "<<endl;
        int mark;
        cin>>mark;*/
        if ( m==1 )
        {
            Course *c=new ObligatoryCourse();
            c->setname(z);
            c->setHour(hour);
           // c->setScore(mark);
            a.addCourse(c);
        }
        else if ( m==2 )
        {

            Course *c=new ElectiveCourse();
            c->setname(z);
            c->setHour(hour);
           // c->setScore(mark);
            a.addCourse(c);
        }
    cout<<" 课程添加完毕。接下来您想：\n输入1查看学生信息\n输入2继续添加课程\n输入3添加课程成绩\n输入4退选课程\n输入5退出程序\n输入6保存学生信息\n";


    }
    else if ( i==3 )
    {
        int x,chengji;
        cout<<"请输入要添加课的序号"<<endl;
       while(1){
          try{
               cin>>x;
               if ( x<=0 || x>a.courseNumber)
                throw My_Exception(2);
               break;
          }catch ( My_Exception ex)
          {
              cout<<ex.what()<<endl;
          }

       }
        cout<<"请输入该课的成绩"<<endl;
        while(1){
          try{
               cin>>chengji;
               if ( chengji<0 || chengji>100)
                throw My_Exception(3);
               break;
          }catch ( My_Exception ex)
          {
              cout<<ex.what()<<endl;
          }

       }
        a.courseList[x-1]->setScore(chengji);
        cout<<" 成绩添加完毕。接下来您想：\n输入1查看学生信息\n输入2继续添加课程\n输入3添加课程成绩\n输入4退选课程\n输入5退出程序\n输入6保存学生信息\n";
    }
    else if ( i==4 )
    {
        int x;
        cout<<"请输入退选课的序号"<<endl;
         while(1){
          try{
               cin>>x;
               if ( x<=0 || x>a.courseNumber)
                throw My_Exception(2);
               break;
          }catch ( My_Exception ex)
          {
              cout<<ex.what()<<endl;
          }

       }
        a.removeCourse(x);
         cout<<" 课程退选完毕。接下来您想：\n输入1查看学生信息\n输入2继续添加课程\n输入3添加课程成绩\n输入4退选课程\n输入5退出程序\n输入6保存学生信息\n";
    }
    }
    return 0;
}
GUI::~GUI()
{
    //dtor
}
