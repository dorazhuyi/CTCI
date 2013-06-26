#include <iostream>

using namespace std;

void replace(char* str, int str_length){
	int end = str_length-1;
	int now = end;
	int spacecnt=0;
	cout << now << " " << end <<  endl;
	cout << ">" << str[10] << "<" << endl;

	while(str[now]==' '){
	  cout << now << " >"<< str[now]<<"< "<< endl;
	  --now;
	  ++spacecnt;
	}
	cout << "first char: " << str[now] << " Space number: " << spacecnt << endl;
	while(spacecnt>0){
	  if(str[now]!=' ') str[end--]=str[now--];
	  else {
	    spacecnt-=2;
	    str[end]='0';
	    str[--end]='2';
	    str[--end]='%';
	    --end;
	    --now;
	  }
	}

}

int main()
{
	char string1[] = "Mr John Smith    ";
	cout << string1 << endl;
	replace(string1, 17);
	cout << "Replaced: " << string1 << endl;
	return 0;
}
