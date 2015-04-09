/**************************************
 *FILE    :004.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/8/2015
***************************************/
#include <iostream>

using namespace std;

char datestr[12][10]={"first","second","third","fourth","fifth","sixth","seventh","eighth","ninth","tenth","eleventh","twelfth"};

char lrcstr[12][300]={"my true love sent to me: A partridge in a pear tree.",
"my true love sent to me: Two turtle doves, And a partridge in a pear tree.",
"my true love sent to me: Three French hens, Two turtle doves, And a partridge in a pear tree.",
"my true love sent to me: Four calling birds, Three French hens, Two turtle doves, And a partridge in a pear tree.",
"my true love sent to me: Five golden rings; Four calling birds, Three French hens, Two turtle doves, And a partridge in a pear tree.",
"my true love sent to me: Six geese a-laying, Five golden rings; Four calling birds, Three French hens, Two turtle doves, And a partridge in a pear tree.",
"my true love sent to me: Seven swans a-swimming, Six geese a-laying, Five golden rings; Four calling birds, Three French hens, Two turtle doves, And a partridge in a pear tree.",
"my true love sent to me: Eight maids a-milking, Seven swans a-swimming, Six geese a-laying, Five golden rings; Four calling birds, Three French hens, Two turtle doves, And a partridge in a pear tree.",
"my true love sent to me: Nine ladies dancing, Eight maids a-milking, Seven swans a-swimming, Six geese a-laying, Five golden rings; Four calling birds, Three French hens, Two turtle doves, And a partridge in a pear tree.",
"my true love sent to me: Ten lords a-leaping, Nine ladies dancing, Eight maids a-milking, Seven swans a-swimming, Six geese a-laying, Five golden rings; Four calling birds, Three French hens, Two turtle doves, And a partridge in a pear tree.",
"my true love sent to me: Eleven pipers piping, Ten lords a-leaping, Nine ladies dancing, Eight maids a-milking, Seven swans a-swimming, Six geese a-laying, Five golden rings; Four calling birds, Three French hens, Two turtle doves,And a partridge in a pear tree.",
"my true love sent to me: Twelve drummers drumming, Eleven pipers piping, Ten lords a-leaping, Nine ladies dancing, Eight maids a-milking, Seven swans a-swimming, Six geese a-laying, Five golden rings, Four calling birds, Three French hens, Two turtle doves, And a partridge in a pear tree!"};


int main()
{
	int i;
	cout<<"The Twelve days of Christmas. \n";
	for(i=0;i<12;i++)
	{
		cout<<datestr[i]<<"\t"<<lrcstr[i]<<endl;
	}
	return 0;
}
