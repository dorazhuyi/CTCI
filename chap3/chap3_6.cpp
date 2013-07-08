#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

/* Find the right place in the sorted stack for the current top of the original stack */
void insert(int t, stack<int> &origin, stack<int> &sorted, int &c)
{
	if (sorted.empty())
		return;
	else
	{
		int stop = sorted.top(); // Need to ensure "sorted" is not empty.
		//cout << "Compare: " << t << " " << stop << endl;
		if(t < stop)
		{
			origin.push(stop);
			sorted.pop();
			c++;
			insert(t, origin, sorted, c);
		}
	}
}

int main()
{
	stack<int> origin, sorted;
	
	for(int i = 0; i < 5; i++){
		origin.push(rand()%50);
		cout << origin.top() << " pushed." << endl;
	}
	
	
	while(!origin.empty())
	{
		int cnt = 0;
		int top = origin.top();
		origin.pop();
		insert(top, origin, sorted, cnt);
		sorted.push(top);
		while(cnt > 0)
		{
			int tmp = origin.top();
			sorted.push(tmp);
			origin.pop();
			cnt--;
		}
		
	}
	
	while(!sorted.empty())
	{
		cout << sorted.top() << endl;
		sorted.pop();
	}
	
	return 0;
}
