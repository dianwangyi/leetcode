#include <iostream>
#include <string>
using namespace std;
 
int main()
{ 
   
	{ 
   
		char szTest[] = "\0abc";
		string s;
		s += szTest;
		printf("size is %u\n", s.size());
	} 
 
	{ 
   
		char szTest[] = "\0abc";
		string s;
		s.append(szTest, sizeof(szTest) - 1);
		printf("size is %u\n", s.size());
	} 
 
	return 0;
}