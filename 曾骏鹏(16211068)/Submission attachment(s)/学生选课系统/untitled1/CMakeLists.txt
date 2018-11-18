cmake_minimum_required(VERSION 3.7)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp date.cpp date.h student.cpp student.h course.cpp course.h ObligatoryCourse.cpp ObligatoryCourse.h ElectiveCourse.cpp ElectiveCourse.h console.cpp console.h myException.cpp myException.h)
add_executable(untitled1 ${SOURCE_FILES})