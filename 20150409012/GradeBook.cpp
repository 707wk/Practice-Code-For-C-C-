/**************************************
 *FILE    :GradeBook.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/9/2015
***************************************/
#include <iostream>

using namespace std;

#include "GradeBook.h"

GradeBook::GradeBook( string name ,string teachname )
{
   setCourseName( name );
   setteachername(teachname); 
} 

void GradeBook::setCourseName( string name )
{
   courseName = name; 
} 

string GradeBook::getCourseName()
{
   return courseName; 
} 

void GradeBook::setteachername( string name )
{
	teachername=name;
}

string GradeBook::getteachername()
{
	return teachername;
}

void GradeBook::displayMessage()
{
   cout << "Welcome to the grade book for\n" << getCourseName()<< "!" << endl;
   cout << "this course is presented by :"<<getteachername()<<"!"<<endl;
}
