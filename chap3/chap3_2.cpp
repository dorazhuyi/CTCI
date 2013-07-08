//chap3_2.cpp try c++ container
#include <iostream>
#include <stack>

using namespace std;

class stackwithmin
{
 public:
  stackwithmin();
  bool isEmpty();
  void newpush(int);
  int newpop();
  int min();
  int newtop();
 private:
  stack<int>* stack1;
  stack<int>* smin;
};

/* Allocate memory for stacks. stack variable didn't work*/
stackwithmin::stackwithmin()
{
 stack1 = new stack<int>;
 smin = new stack<int>;
}

bool stackwithmin::isEmpty()
{
 return stack1->empty();
}

void stackwithmin::newpush(int a)
{
 stack1->push(a);
 if(smin->empty()) smin->push(a);
 else if(a < smin->top()) smin->push(a);
}

int stackwithmin::newpop()
{
 if(stack1->empty()) {cout << "Empty stack." << endl; return 0;}
 int val = stack1->top();
 stack1->pop();
 if(val = smin->top()) smin->pop();
 return val;
}

int stackwithmin::min()
{
 if(stack1->empty()) {cout << "Empty stack." << endl; return 0;}
 return smin->top();
}

int stackwithmin::newtop()
{
 return stack1->top();
}

int main()
{
 stackwithmin stm;
 stm.newpush(5);
 stm.newpush(6);
 stm.newpush(3);
 stm.newpush(7);
 stm.newpush(4);
 stm.newpush(1);

 if(stm.isEmpty()) { cout<<"Stack Empty."<<endl; return 0; }
 cout << stm.min() << endl;
 
 stm.newpop();
 cout << stm.min() << endl;

}
