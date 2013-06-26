#include <iostream>
#include <cstring>

using namespace std;

void reverse(char* str)
{
	char* end = str;
	char tmp;
	cout << &str << endl;
	if(str){	
	  while(*end){
	  ++end;
	  }
	  --end;
		cout << &end << endl;
		cout << (&end-&str) << endl;
	  while(str<end){
	    tmp=*str;
	    *str++ = *end;
	    *end-- = tmp;
		cout << *str << "< - >" << *end << endl;
		cout << tmp << endl;
	  }
	}
	
}

int main()
{
	char string1[] = "This is a string.";
	cout << string1 << endl;
	reverse(string1);
	cout << "Reversed: " << string1 << endl;
	return 0;
}
