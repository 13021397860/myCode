#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <string>
#include <iostream>
#include "console.h"
using namespace std;

int main()
{
    Date testDate(1998,1,1);
    cout<<"testDate: "<<testDate;
    cout<<"++testDate: "<<++testDate;
    cout<<"testDate++: "<<testDate++;

    Console console;
    console.run();


    return 0;
}
