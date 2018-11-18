#include "Operation.h"
#include <typeinfo>

using namespace std;

Operation::Operation()
{
    //ctor
    /*c[0][0] = new ObligatoryCourse( "C++" , 4 , -1 );
    c[0][1] = new ObligatoryCourse( "Math" , 3 , -1 );
    c[0][2] = new ObligatoryCourse( "English" , 2 , -1 );
    c[1][0] = new ElectiveCourse( "Art" , 2 , 'B' );
    c[1][1] = new ElectiveCourse( "PE" , 1 , 'B' );
    c[1][2] = new ElectiveCourse( "Music" , 1 , 'B' );*/
}

Operation::~Operation()
{
    //dtor
    for( int i = 0; i < 2; i ++ )
    {
        for( int j=0; j < 3; j ++ )
        {
            delete c[i][j];
        }
    }
}

void Operation::run()
{
    char n[ 10 ];
    int d , m , y;
    cout << "Please input student's name" << endl;
    cin >> n;
    while( cin.fail() )
    {
        cin.clear();
        cout << "Please input student's name again" << endl;
        cin >> n;
    }
    //
    Date birth;
    bool input = 1;
    cout << "Please input student's birth day, month-day-year" << endl;
    //
    while(input)
    {
        cin >> m >> d >> y;
        try
        {
            if(cin.fail())
            {
                throw IllegalDate();
            }
            else
            {
                birth.setDate(m,d,y);
            }
            input = 0;
        }
        catch( IllegalDate ex )
        {
            cout << "错误类型：" << ex.what() << endl;
            cout << "Please input student's birth day, month-day-year" << endl;
            cin.clear();
            cin.ignore();
        }
    }
    //
    Student stu( n, birth );
    cout << "Input successfully!" << endl;
    //
    int com;
    int s;
    char ma;
    //
    ofstream out_file;
    //
    while(1)
    {
        cout << "Input 1 to select obligatory course" << endl;
        cout << "Input 2 to select elective course" << endl;
        cout << "Input 3 to set course score" << endl;
        cout << "Input 4 to print student information" << endl;
        cout << "Input 5 to withdraw" << endl;
        cout << "Input 6 to calculate credit" << endl;
        cout << "Input 7 to load into a file" << endl;
        cout << "Input 0 to quit" << endl;
        //
        cin >> com;
        //
        while(cin.fail())
        {
            cin.clear();
            cout << "Illegal input!" << endl;
            cin >> com;
        }
        //
        if( com == 0 )
        {
            cout << "Finished!" << endl;
            return;
        }
        else if( com == 1 )
        {
            for( int i = 0; i < 3; i++ )
            {
                cout << i+1 << ".Name:" << c[ 0 ][ i ] -> getName() << " Credit hour:" << c[ 0 ][ i ] -> getCreditHour() << endl;
            }
            //
            cin >> com;
            //
            while( cin.fail() || com < 1 || com > 3 )
            {
                cin.clear();
                cout << "Illegal input!" << endl;
                cin >> com;
            }
            //
            try
            {
                stu.addCourse( c[ 0 ][ com - 1 ] );
                cout << "Select successfully!" << endl;
            }
            catch(OutArray ex)
            {
                cout << "错误类型：" << ex.what() << endl;
            }
        }
        else if( com == 2 )
        {
            for( int i = 0; i < 3; i++ )
            {
                cout << i+1 << ".Name:" << c[ 1 ][ i ] -> getName() << " Credit hour:" << c[ 1 ][ i ] -> getCreditHour() << endl;
            }
            //
            cin >> com;
            //
            while( cin.fail() || com < 1 || com > 3 )
            {
                cin.clear();
                cout << "Illegal input!" << endl;
                cin >> com;
            }
            //
            try
            {
                stu.addCourse( c[ 1 ][ com - 1 ] );
                cout << "Select successfully!" << endl;
            }
            catch(OutArray ex)
            {
               cout << "错误类型：" << ex.what() << endl;
            }
        }
        else if( com == 3 )
        {
            for( int i = 1; i <= stu.getCourseNumber(); i ++ )
            {
                Course *p = stu.getCourse( i );
                cout << "Name:" << p -> getName() << " Credit hour:" << p -> getCreditHour() << endl;
                if( typeid( *p ) == typeid( ObligatoryCourse ) )
                {
                    cout << "Input 0~100" << endl;
                    //
                    input = 1;
                    while(input)
                    {
                        cin >> s;
                        try
                        {
                            if(cin.fail())
                            {
                                throw IllegalGrade();
                            }
                            else
                            {
                                 p -> setMark( s );
                            }
                            input = 0;
                        }
                        catch( IllegalGrade ex )
                        {
                            cin.clear();
                            cin.ignore();
                            cout << "错误类型：" << ex.what() << endl;
                        }
                    }
                    //
                }
                else
                {
                    cout << "Input A~E" << endl;
                    //
                    input = 1;
                    while(input)
                    {
                        cin >> ma;
                        try
                        {
                            if(cin.fail())
                            {
                                throw IllegalGrade();
                            }
                            else
                            {
                                 p -> setGrade( ma );
                            }
                            input = 0;
                        }
                        catch( IllegalGrade ex )
                        {
                            cin.clear();
                            cin.ignore();
                            cout << "错误类型：" << ex.what() << endl;
                        }
                    }
                }
                cout << "Input successfully!" << endl;
            }
        }
        else if( com == 4 )
        {
            cout << stu;
        }
        else if( com == 5 )
        {
            for( int i = 1; i <= stu.getCourseNumber(); i ++ )
            {
                cout << i << *stu.getCourse( i ) << endl;
            }
            cout << "Input course number:" << endl;
            cin >> com;
            try
            {
                 stu.removeCourse( com );
                cout << "Remove successfully" << endl;
            }
            catch(OutArray ex)
            {
                cout << "错误类型：" << ex.what() << endl;
            }
        }
        else if( com == 6 )
        {
            cout << "Credit " << stu.calcCredit() << endl;
        }
        else if( com == 7 )
        {
            out_file.open( ".\\sum.txt" );
            if(!out_file)
            {
                cerr << "输出文件异常" << endl;
            }
            out_file << stu;
            out_file.close();
        }
        else
        {
            cout << "Illegal input!" << endl;
        }
    }
    //
}

void Operation::read()
{
    ifstream in_file( ".\\courseinfo.txt" );
    if( ! in_file )
    {
        cerr << "数据库异常!" << endl;
        return;
    }
    char c_name[12];
    int c_hour;
    bool is_elective;
    int i=0,j=0;
    while( in_file >> c_name >> c_hour >> is_elective )
    {
        if(is_elective)
        {
            c[1][i] = new ElectiveCourse( c_name , c_hour , 'C' );
            i++;
        }
        else
        {
            c[0][j] = new ObligatoryCourse( c_name , c_hour , 60 );
            j++;
        }
    }
    in_file.close();
}

/*void Operation::test_date()
{
    Date a(1,30,2000);
    cout << a ++ << endl;
    cout << ++ a << endl;
    cout << a << endl;
    return;
}*/
