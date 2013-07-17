#include <iostream>
#include <string>

using namespace std;

bool isUnique(string s)
{
	bool flag[256];
	for(int i=0;i<256;i++)
	{
		flag[i] = false;
	}
	int i = 0;
	while(i<s.length())
	{
		//cout << s.at(i) << " ";
		int iflag = (int)s.at(i++);
		//cout << iflag << endl;
		if(flag[iflag]) return false;
		flag[iflag] = true;
	}
	return true;
}

int main()
{
	string str ("AtestString");
	if(isUnique(str))
		cout << "Unique" << endl;
	else
		cout << "Not Unique" << endl;
	
	return 0;
}
