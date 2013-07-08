#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

/* Much cleaner standard solution */
int main()
{
	stack<int> origin, sorted;
	
	for(int i = 0; i < 10; i++){
		origin.push(rand()%50);
		cout << origin.top() << " pushed." << endl;
	}
	
	
	while(!origin.empty())
	{
		int top = origin.top();
		origin.pop();
		while (!sorted.empty() && top < sorted.top())
		{
			int tmp = sorted.top();
			origin.push(tmp);
			sorted.pop();
		}
		sorted.push(top);
		
	}
	
	while(!sorted.empty())
	{
		cout << sorted.top() << endl;
		sorted.pop();
	}
	
	return 0;
}
