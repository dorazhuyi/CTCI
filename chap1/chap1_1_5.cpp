#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;


string replace(string& str)
{
	int cnt[256];
	int i, j;
	int no_char=0;
	string restr;

	for (i=0;i<256;i++){
	  cnt[i]=0;
	}

	cout << str.length() << endl;//input string length
	for(j=0;j<str.length();j++){
	  //cout << (int)str[j] << endl;//current string char
	  ++cnt[(int)str[j]];
	}

	for (i=0;i<256;i++){
	  if(cnt[i]) ++no_char;
	}
	cout << no_char << endl;//char no.
	if(no_char*2 < str.length())
	{ j=0;
	  for (i=0;i<256;i++){
	    if(cnt[i]){
		cout << (char)i << " " << cnt[i] << endl; // repeated char
		restr+=(char)i;
		restr+=(char)(cnt[i]+(int)'0');//concatenate
	    }
	  }
	  return restr;
	} else {
	  return str;
	}

}


int main()
{
	// To get input string
	string instr, string2;
	cout<< "Please input string: ";
	getline(cin,instr);
	//char* string1 = new char[instr.length()+1];
	//string1[instr.length()]=0;
	//memcpy(string1, instr.c_str(), instr.length());

	string2 = replace(instr);
	cout << "Original: " << instr << endl;
	cout << "Replaced: " << string2 << endl;

	return 0;
	
}
