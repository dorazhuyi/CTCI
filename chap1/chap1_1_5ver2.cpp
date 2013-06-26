#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int intlen(int a){
	int len;
	while(a>0){
	  a=a/10;
	  len++;
	}
	return len;
}

int countcompression(string& str)
{
	if(str.empty()) return 0;
	int compsize = 0;
	int cnt=1;
	char last = str.at(0);
	for(int j=1;j<str.length();j++){
	  if(str.at(j)==last) {
	    cnt++;
	  } else{
	    compsize+=1+intlen(cnt);
	    cnt=1;
	    last = str.at(j);
	  }
	  //cout << cnt <<" "<< intlen(cnt) << " " << compsize << endl;//resize length
	}
	compsize+=1+intlen(cnt);
	return compsize;
}

string replace(string& str)
{
	cout << str.length() << " " << countcompression(str) << endl;//string length
	if(countcompression(str)>str.length()) return str;

	int cnt=1;
	string restr;

	char last = str.at(0);
	for(int j=1;j<str.length();j++){
	  //cout << last << cnt << endl;//current char
	  if(str.at(j)==last) cnt++;
	  else {
	    stringstream tmp;
	    tmp << cnt;
	    restr+=last;
	    restr+=tmp.str();
	    //cout << restr << endl;//current re-string
	    cnt=1;
	    last=str.at(j);
	  }
	}
	stringstream tmp;
	tmp << cnt;
	restr+=last;
	restr+=tmp.str();
	
	return restr;
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
