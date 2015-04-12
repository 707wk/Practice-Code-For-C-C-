/**************************************
 *FILE    :main.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/9/2015
***************************************/
#include <iostream>

using namespace std;

#include "GradeBook.h" 

int main()
{
   GradeBook gradeBook1( "CS101 Introduction to C++ Programming" ,"001");
   GradeBook gradeBook2( "CS102 Data Structures in C++" ,"002");

   cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
      << "\ngradeBook2 created for course: " << gradeBook2.getCourseName() 
      << endl;
   return 0; 
} 
