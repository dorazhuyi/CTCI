#include <iostream>
#include <stack>

using namespace std;

class myQueue
{
  public:
	myQueue();
	void enqueue(int);
	int dequeue();
	bool isEmpty();
  private:
	stack<int> *stackNew;
	stack<int> *stackOld;
};

myQueue::myQueue()
{
	stackNew = new stack<int>;
	stackOld = new stack<int>;
}

void myQueue::enqueue(int v)
{
	stackNew->push(v);
}

int myQueue::dequeue()
{
	if(stackOld->empty())
	{
		if(stackNew->empty())
		{
			cout << "Error: Empty queue." << endl;
			return -1;
		}
		while(!stackNew->empty())
		{
			int val = stackNew->top();
			stackNew->pop();
			stackOld->push(val);
		}
	}
	int v = stackOld->top();
	stackOld->pop();
	return v;
}

bool myQueue::isEmpty()
{
	return (stackOld->empty() && stackNew->empty());
}

int main()
{
	myQueue MQ;
	MQ.enqueue(1);
	MQ.enqueue(3);
	MQ.enqueue(5);
	MQ.enqueue(7);
	MQ.enqueue(9);
	
	while(!MQ.isEmpty()) 
		cout << MQ.dequeue() << endl;
		
	return 0;
}
