/**************************************
 *FILE    :GradeBook.h
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/9/2015
***************************************/
#include <string>

using std::string;

class GradeBook
{
public:
   GradeBook( string , string ); 
   void setCourseName( string );
   string getCourseName(); 
   void setteachername( string );
   string getteachername(); 
   void displayMessage(); 
private:
   string courseName;
   string teachername;
}; 
