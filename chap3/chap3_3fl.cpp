#include <iostream>
#include <vector>
#include <stack>

//#include "Stack.h"

using namespace std;

class SetofStack
{
  public:
	SetofStack();
	SetofStack(int);
	bool isEmpty();
	void push(int);
	int pop();
	int popAt(int);
  private:
	int capacity;
	vector<stack<int> > *Set; // Stack need to be initialized. Space between "int> (space) >" cannot miss.
	stack<int> *last;
	int top;
};

SetofStack::SetofStack()
{
	capacity = 10;
	Set = NULL;
	top = -1;
	cout << "Stack capacity: " << capacity << endl;
}

SetofStack::SetofStack(int c)
{
	capacity = c;
	Set = NULL;
	top = -1;
	cout << "Stack capacity: " << capacity << endl;
}

bool SetofStack::isEmpty()
{
	return Set == NULL;
}

void SetofStack::push(int v)
{
	if(Set == NULL)
	{
		Set = new vector<stack<int> >;
		stack<int> newstack; 
		newstack.push(v);
		Set->push_back(newstack);
		top++;
		cout << v << " pushed to stack " << top  << "." << endl;
		return;
	}
	stack<int> &last = Set->at(top); // pass by reference required
	if( last.size()!=0 && last.size() < capacity)
	{
		last.push(v);
	}
	else
	{
		stack<int> newstack; 
		newstack.push(v);
		Set->push_back(newstack);
		top++;
	}
	cout << v << " pushed into stack " << top  << "." << endl;
}

int SetofStack::pop()
{
	if(Set == NULL)
	{
		cout << "Set of Stacks is Empty." << endl;
		return -1;
	}
	stack<int> &last = Set->at(top); // pass by reference required
	int val;
	if (last.size() > 1)
	{
		val = last.top();
		last.pop();
		cout << "Poped from stack " << top << "." << endl;
	}
	else if (last.size() == 1)
	{
		val = last.top();
		last.pop();
		Set->pop_back();
		cout << "Poped from stack " << top << "." << endl;
		top--;
	}
	else if (last.size() == 0)
	{
		cout << "Stack " << top << " is empty.";
		top--;
		val = pop();
	}
	return val;
}

int SetofStack::popAt(int n)
{
	if( n > top || n < 0) 
	{
		cout << "Invalid stack number." << endl;
		return -1;
	}
	if ( n == top)
	{
		return pop();
	}
	stack<int> &curr = Set->at(n);// pass by reference required
	int val = curr.top();
	if(curr.size() > 1)
	{
		val = curr.top();
		curr.pop();
		cout << "Poped from stack " << n << "." << " Extra space in stack " << n << endl;;
	}
	else if(curr.size() == 1)
	{
		val = curr.top();
		curr.pop();
		cout << "Poped from stack " << n << "." << " Stack " << n << " is empty." << endl;;
	}
	return val;
}

int main()
{
	SetofStack SS(3);
	SS.push(1);
	SS.push(2);
	SS.push(3);
	
	SS.push(4);
	SS.push(5);
	SS.push(6);
	
	SS.push(7);
	SS.push(8);
	SS.push(9);
	
	SS.pop();
	SS.popAt(1);
	SS.popAt(1);
	SS.popAt(1);
	
	SS.pop();
	SS.pop();
	
	SS.pop();
	
	return 0;
}
