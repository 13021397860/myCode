cmake_minimum_required(VERSION 3.7)
project(Student)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Student/Date.cpp Student/Date.h Student/Student.cpp Student/Student.h Course/Course.cpp Course/Course.h Course/ElectiveCourse.cpp Course/ElectiveCourse.h Course/ObligatoryCourse.cpp Course/ObligatoryCourse.h UI/Console.cpp UI/Console.h Exception/MyException.cpp Exception/MyException.h)
add_executable(Student ${SOURCE_FILES})