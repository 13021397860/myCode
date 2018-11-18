//
//  Console.cpp
//  Student
//
//  Created by Pirate Hero on 17/5/9.
//  Copyright © 2017年 mac. All rights reserved.
//

#include "Console.hpp"
void Console::run()
{
    Myexception  MMM;
    Student s[101];
    
    char*n;
    
    char N[10];
    long int l;
    int i=0;
    int r=0;
    char u;
    // course *J=new ObligatoryCourse;
    ifstream myfile ("/Users/mac/Desktop/Xcode程序文件/Student/Student/stu.txt");
    
   
    if(!myfile){
        cout << "Unable to open myfile";
        exit(1); // terminate with error
        
    }
    /*
    out<<"姓名： ";
    for(int i=0;i<=A.length-1;i++)
        out<<*(A.name+i);
    cout<<endl;
    out <<"出生日期: "<<A.birthdate<<endl<<" 选课信息如下： "<<endl;
    out<<"必修课："<<endl;
    out<<"必修课共 "<<A.courseNumber2<<" 门 "<<endl;
    
    for(int i=1;i<=A.courseNumber2;i++)
    {
        out<<*(A.OCName[i]);
        out<<"成绩为: ";
        out<<(A.o[i-1])->mark<<endl;
    }
    
    out<<"选修课："<<endl;
    out<<"选修课共 "<<A.courseNumber<<" 门"<<endl;
    
    for(int i=1;i<=A.courseNumber;i++)
    {
        out<<*(A.ECName[i]);
        out<<"成绩为: ";
        out<<(A.e[i-1])->mark<<endl;
    }

    out<<"积点: "<<A.GPA<<endl;
    return out;
*/
    else
    {
        
        char c;
    while ((c=myfile.get())!=EOF)
    {
        //printf("Hi\n");
        r++;
        string duoyude;
        myfile>>duoyude;//姓名
        //printf("1\n");
        char d[20];
        myfile>>d;
        //  printf("2\n");
        long int l=strlen(d);
       /*s[r].name=(char*) malloc(l+1);
        
        for(int p=0;p<=l-1;p++)
            *(s[r].name+p)=d[p];
        */
        s[r].set(l,d);
        //输入完名字
         myfile>>duoyude;//出生日期
       //   printf("3\n");
        int YYEAR,MMONTH,DDAY;
        myfile>>YYEAR>>MMONTH>>DDAY;
         // printf("4\n");
        s[r].birthdate.year=YYEAR;
        s[r].birthdate.month=MMONTH;
        s[r].birthdate.day=DDAY;
        myfile>>duoyude;//选课信息如下
         // printf("5\n");
        myfile>>duoyude;//必修课
        myfile>>duoyude;//必修课共
        int NUMBER;
        myfile>>NUMBER;
        s[r].courseNumber2=NUMBER;
        myfile>>duoyude;//门
        for(int f=1;f<=NUMBER;f++)
        {
           // printf("Hi\n");
            myfile>>duoyude;
            // printf("1\n");
            string a;
            int b;
            // printf("2\n");
            myfile>>a;
             myfile>>duoyude;
           // printf("3\n");
            myfile>>b;
            s[r].OCName[f]=new ObligatoryCourse;
            s[r].OCName[f]->set(a,b);
          
           
             myfile>>duoyude;
           // printf("4\n");
            //"成绩为: "
            myfile>>b;
            s[r].o[f-1]=new ObligatoryCourse;
            (s[r].o[f-1])->mark=b;
        }
        
        myfile>>duoyude;//"选修课："<<endl;
        myfile>>duoyude;//"选修课共 "<<
        myfile>>NUMBER;
        s[r].courseNumber=NUMBER;
        myfile>>duoyude;//" 门"<<endl;
        
        for(int f=1;f<=NUMBER;f++)
        {
            /*
             out <<"课程名:"<<A.name<<" 学分:"<<A.creditHour<<endl;
             */
            myfile>>duoyude;
            string a;
            int b;
            myfile>>a;
            myfile>>duoyude;
            myfile>>b;
            s[r].ECName[f]=new ElectiveCourse;
            s[r].ECName[f]->set(a,b);
            
            
            myfile>>duoyude;
            //"成绩为: "
            myfile>>b;
            s[r].e[f-1]=new ElectiveCourse;
            (s[r].e[f-1])->mark=b;

//             printf("fuck\n");
        }
      //  printf("Hello\n");
        myfile>>duoyude;
        double GGPA;
        myfile>>GGPA;
        s[r].GPA=GGPA;

        
    //    cout<<s[r]<<endl;
        
        
    }
    }
    myfile.close();
    i=r;
    for(;;)
    {
        cout<<"若想录入学生信息请输入1，,若想查询学生信息请输入2，若想退出请输入0"<<endl;
        
        cin>>u;
        if(u=='0') break;
        else if(u=='2')
        {
            cout<<"请输入学生的名字"<<endl;
            char NM[20];
            scanf("%s",NM);
            for(int g=0;g<=i;g++)
            {
                if(!strcmp(NM,s[g].name))
                {    cout<<s[g]<<endl;
                    break;
                }
            }
            
            
        }

        else if(u=='1')
        {
        cout<<"请输入学生的姓名"<<endl;
        cin>>N;
        cout<<"请输入学生的出生日期"<<endl;
        
        l=strlen(N);
        n=N;
        
        
        
        s[i].set(l,n);
        s[i].get();
            int YYYEAR,MMMONTH,DDDAY;
            for(;;)
            {
            cin>>YYYEAR>>MMMONTH>>DDDAY;
                
            s[i].birthdate.year=YYYEAR;
            s[i].birthdate.month=MMMONTH;
            s[i].birthdate.day=DDDAY;
           if( !s[i].birthdate.Judge())
           {cout<<"输入日期错误,请重新输入:"<<endl;
            
               
               MMM.Date[MMM.Datenum][0]=YYYEAR;
               MMM.Date[MMM.Datenum][1]=MMMONTH;
               MMM.Date[MMM.Datenum][2]=DDDAY;
               MMM.Datenum++;
               continue;}
                else
                    break;
            }
        //cout<<"请输入学生的选课信息"<<endl;
            int symbol[8]={0};
        for(;;)
        {
            cout<<"如果想选课请输入1，如果想查询请输入2,如果退出请输入0"<<endl;
            
            
            cin>>u;
            if(u=='1')
            {
                ifstream SC("/Users/mac/Desktop/Xcode程序文件/Student/Student/courseinformation.txt");
                
                
                if(!SC){
                    cout << "Unable to open the file";
                    exit(1); // terminate with error
                    
                }
                else
                {
                    
                    const int LINE_LENGTH = 100;
                    char str[LINE_LENGTH];
                    int y=0;
                    while( SC.getline(str,LINE_LENGTH) )
                    {
                        cout << str;
                        if(symbol[y]==1) cout<<"   已选";
                        cout<<endl;
                        y++;
                    }
                    SC.close();
                }
                cout<<"请输入课程编号"<<endl;
                
               
                
                for(;;)
                {
                    cin>>u;
                if(u>'7'||u<'1')
                {cout<<"输入错误,请重新输入"<<endl;
                    MMM.course+=(char)(u+48);
                }
                else
                {
                    symbol[(int)u-48]=1;
                    break;
                }
                }
               
                int RENWEI=1;
                switch(u)
                {
                    case '1':
                        s[i].addCourse2("eat",10);
                        s[i].o[s[i].O]=new ObligatoryCourse;
                        cout<<"请为这门课程设定成绩（输入一个整数）"<<endl;
                        
                     s[i].o[s[i].O]->set();
                        s[i].O++;
                        break;
                    case '2':
                        s[i].addCourse2("fight",10);
                        s[i].o[s[i].O]=new ObligatoryCourse;
                        cout<<"请为这门课程设定成绩（输入一个整数）"<<endl;
                        s[i].o[s[i].O]->set();
                        s[i].O++;
                        break;
                    case '3':
                        s[i].addCourse2("sing",10);
                        s[i].o[s[i].O]=new ObligatoryCourse;
                        cout<<"请为这门课程设定成绩（输入一个整数）"<<endl;
                        s[i].o[s[i].O]->set();
                        s[i].O++;
                        break;
                    case '4':
                        s[i].addCourse2("love",10);
                        s[i].o[s[i].O]=new ObligatoryCourse;
                        cout<<"请为这门课程设定成绩（输入一个整数）"<<endl;
                        s[i].o[s[i].O]->set();
                        s[i].O++;
                        break;
                    case '5':
                        s[i].addCourse("forget",10);
                        s[i].e[s[i].E]=new ElectiveCourse;
                        cout<<"请为这门课程设定成绩(输入A（95分）B（85分）C（75分）D（65分）E（55分）)"<<endl;
                        s[i].e[s[i].E]->set();
                        s[i].E++;
                        break;
                    case '6':
                        s[i].addCourse("run",10);
                        s[i].e[s[i].E]=new ElectiveCourse;
                        cout<<"请为这门课程设定成绩(输入A（95分）B（85分）C（75分）D（65分）E（55分）)"<<endl;
                        s[i].e[s[i].E]->set();
                        s[i].E++;
                        break;
                    case '7':
                        s[i].addCourse("reflect",10);
                        s[i].e[s[i].E]=new ElectiveCourse;
                        cout<<"请为这门课程设定成绩(输入A（95分）B（85分）C（75分）D（65分）E（55分）)"<<endl;
                        s[i].e[s[i].E]->set();
                        s[i].E++;
                        break;
                    default:
                        break;
                        
                    
                
                }
                
                    
                    
                

                /*
                cout<<"如果想选必修课请输入1，如果想选选修课请输入0"<<endl;
                cin>>u;
                if(u==0)
                {
                //
                
                
                string COURSE;
                int CREDIT;
                cout<<"请输入课程名"<<endl;
                cin>>COURSE;
                cout<<"请输入这门课的学分"<<endl;
                cin>>CREDIT;
                s[i].addCourse(COURSE,CREDIT);
                s[i].e[s[i].E]=new ElectiveCourse;
                cout<<"请为这门课程设定成绩(输入A（95分）B（85分）C（75分）D（65分）E（55分）)"<<endl;
                s[i].e[s[i].E]->set();
                s[i].E++;
                
                
            }
            
           else if(u==1)
            {
                string COURSE;
                int CREDIT;
                cout<<"请输入课程名"<<endl;
                cin>>COURSE;
                cout<<"请输入学分"<<endl;
                cin>>CREDIT;
                s[i].addCourse2(COURSE,CREDIT);
                s[i].o[s[i].O]=new ObligatoryCourse;
                cout<<"请为这门课程设定成绩（输入一个整数）"<<endl;
                s[i].o[s[i].O]->set();
                s[i].O++;
                
            }
            
                /*
                cout<<"如果想继续选课请输入1，如果想退出请输入0"<<endl;
                cin>>u;
                if(u==0) break;
                 */
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
            }
            
           else if(u=='2')
            {
                for(;;)
            {
                cout<<"若想查询此学生的出生日期，请输入1"<<endl;
                cout<<"若想查询此学生的成绩请输入2"<<endl;
                
                for(;;)
                {
                cin>>u;
                if(u==1)
                {
                    cout<<s[i].birthdate;
                    break;
                }
                else if(u==2)
                {
                    cout<<"查询必修课请输入1.查询选修课请输入2"<<endl;
                    cin>>u;
                    cout<<"请输入课程的名称"<<endl;
                    string h;
                    cin>>h;
                    if(u==1)
                        for(int w=1;w<=s[i].courseNumber2;w++)
                        {
                            if(s[i].OCName[w]->name==h)
                            {
                                cout<<"学分为："<<s[i].OCName[w]->creditHour<<endl;
                                cout<<"成绩为:"<<endl;
                                s[i].o[w-1]->getscore();
                                
                            }
                        }
                   else if(u==2)
                        for(int w=1;w<=s[i].courseNumber;w++)
                        {
                            if(s[i].ECName[w]->name==h)
                            {
                                cout<<"学分为："<<s[i].ECName[w]->creditHour<<endl;
                                cout<<"成绩为:"<<endl;
                                s[i].e[w-1]->getscore();
                                
                            }
                        }
                    else
                    {
                        cout<<"输入错误"<<endl;
                    }

                    
                    break;
                }
                else
                {
                    cout<<"输入错误，请重新输入"<<endl;
                    continue;
                }
                }
                cout<<"若想继续查询请输入1，若想退出请输入0"<<endl;
                for(;;)
                {
                cin>>u;
                if(u==0) break;
                else if(u==1) continue;
                else
                {
                    cout<<"输入错误，请重新输入"<<endl;
                    continue;
                }
                }
            }
               
                
                
            }
        else if(u=='0')
        {
            break;
        }
        else
        {
            cout<<"输入错误"<<endl;
            
        }
            
            
            
            
           
        }
            
        s[i].calcCredit();
            if(s[i].GPA!=0)
            {  cout<<"这位同学的信息如下："<<endl;
            
        cout<<s[i];
        
        cout<<endl;
            }
            i++;
        }
        
        
        else
        {
            cout<<"输入错误,请重新输入"<<endl;
            
        }

        
        
    }
    
  
    {

        ofstream outfile("/Users/mac/Desktop/Xcode程序文件/Student/Student/stu.txt");
        if(!outfile){
            cout << "Unable to open otfile";
            exit(1); // terminate with error
        }
            else  for(int g=0;g<=i;g++ )
            {
                outfile<<s[g];
            }
            
        outfile.close();
    }

    
  
    
}
