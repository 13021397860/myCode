#include "Console.h"
#include <fstream>
 
Console::Console()
{
	
}

Console::~Console()
{
	delete stu;
	for(int i=0;i<5;i++){
		delete _oc[i];
	}
	for(int i=0;i<3;i++){
		delete _ec[i];
	}
	cout<<"Byebye~"<<endl;
}

bool Console::buildCourse()
{
	string oc,ec;
	int oc_ch,ec_ch;
	int num_o,num_e;
	ifstream infoFile( "CourseInfo.txt", ios::in );
	if ( !infoFile )  
		return false;
	infoFile>>num_o>>num_e;
	for(int i=0;i<num_o;i++)
	{
		infoFile>>oc>>oc_ch;
		_oc[i]=new ObligatoryCourse(oc,oc_ch);
	}
	for(int i=0;i<num_e;i++)
	{
		infoFile>>ec>>ec_ch;
		_ec[i]=new ElectiveCourse(ec,ec_ch);
	}
	return true;
}

bool Console::SaveStu()
{
	ofstream outfile("StuInfo.txt", ios::out);
	if ( !outfile )  
		return false;
	outfile<<*stu;
	outfile.close();
	return true;
}

void Console::buildStudent()
{
	char _name[10];
	cout<<"Please input the name£º ";
	scanf("%s",_name);
	int y,m,d;
	cout<<"Please input the date of birth£º ";
	Date _birth;
	while(1)
	{
		scanf("%d%d%d",&y,&m,&d); 
		try{
			_birth.setDate(y,m,d);
			break;	
		}catch(MyException ex){
			cout<<"Exception: "<<ex.what()<<endl; 
			cout<<"Please input again£º ";
		}	
	} 
	stu=new Student(_name,_birth);
}

int Console::choose(int max) const
{
	int a;
	cin>>a;
	while (cin.fail() || a < 0 || a > max)  
	{
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout<<"\nPlease input a [number]:";		
		}
		else{
			cout<<"\nOut of range, try again:";
		}
		cin >> a;
	}
//	cout<<"ok"<<endl;
	return a;
}

int Console::menu() const
{
	cout<<"¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª Menu ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª"<<endl; 
	cout<<"    1. Select obligatory course"<<endl; 
	cout<<"    2. Select elective course"<<endl;
	cout<<"    3. Get info"<<endl;
	cout<<"    4. Remove course"<<endl;
	cout<<"    5. Set the course grade"<<endl;
	cout<<"    6. Save info in file"<<endl;
	cout<<"    0. Quit"<<endl;
	cout<<"¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª"<<endl; 
	cout<<"Please choose an operation(0~6): ";  
	return choose(6);
}

Course* Console::selectCourse(int op)
{
	int n;
	if(op==1)
	{
		for(int i=0;i<5;i++){
			cout<<"    "<<i+1<<".";
			cout<<*_oc[i];
		}
		cout<<"    0.BACK"<<endl;
		cout<<"Please select a course: ";
		n=choose(5);
		if(n){
			n--;
			return _oc[n];
		}
		else{
			return NULL;
		}
	}
	else if(op==2)
	{
		for(int i=0;i<3;i++){
			cout<<"    "<<i+1<<".";
			cout<<*_ec[i];
		}
		cout<<"    0.BACK"<<endl;
		cout<<"Please select a course: ";
		n=choose(3);
		if(n){
			n--;
			return _ec[n];
		}
		else{
			return NULL;
		}
	}
}

void Console::dropCourse()
{
	int n;
	stu->printCourse();
	cout<<"    0.BACK"<<endl;
	cout<<"Please select a course you want to remove: ";
	n=choose(stu->getCourseNumber());
	if(n){
		stu->removeCourse(n);
	}
}

void Console::setCourseScore()
{
	int n;
	stu->printCourse();
	cout<<"    0.BACK"<<endl;
	cout<<"Please select a course you want to set: ";
	scanf("%d",&n);
	while(1)
	{
		if(n)
		{
			try{
				stu->setGrade(n-1);
				break;	
			}catch(MyException ex){
				cout<<"Exception: "<<ex.what()<<endl;
				if(ex.GetType()==OUT_OF_RANGE)
				{
					cout<<"Please select a course you want to set: ";
					scanf("%d",&n);
				}
			}
		}
		else{
			break;
		}
	}
}
	
void Console::run()
{
	buildCourse();  
    buildStudent();
    int choice=menu();
    while (choice!=0)    
	{
        switch (choice)        
		{
            case 1: 
            case 2: 
                stu->addCourse(selectCourse(choice));  
	      		break;
            case 3:
                cout<<*stu;  
				break;
            case 4:
            	dropCourse();
            	break;
            case 5:
                setCourseScore();  
				break;
			case 6:
                if(SaveStu()){
                	cout<<"Successfully Saved!"<<endl;
				} 
				else {
					cout<<"Failed!"<<endl;
				}
				break;
        }
        system("pause"); 
        choice=menu();
    }
}
