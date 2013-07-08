#include <iostream>

using namespace std;

class stack3
{
 public:
  stack3();
  stack3(int);
  bool isEmpty(int);
  bool isFull(int);
  void push(int, int);
  int pop(int);
  //int* stackarray(){return array;}
 private:
  int* array;
  int top[3];
  int limit[4];
};

stack3::stack3()
{
 array = new int[99];
 top[0]=0;top[1]=33;top[2]=66;
 limit[0]=0;limit[1]=33;limit[2]=66;limit[3]=99;
}

stack3::stack3(int length)
{
 array = new int[length*3];
 top[0]=0;top[1]=length;top[2]=length*2;
 limit[0]=0;limit[1]=length;limit[2]=length*2;limit[3]=length*3;
}

bool stack3::isEmpty(int nstack)
{
 return top[nstack]==limit[nstack];
}

bool stack3::isFull(int nstack)
{
 return top[nstack]==limit[nstack+1];
}

void stack3::push(int nstack, int n)
{
 if(top[nstack]>=limit[nstack+1])
 {
  /*cout << "Stack " << nstack << " exceeds." << endl;
  return;*/
 }
 array[top[nstack]++]=n;
}

int stack3::pop(int nstack)
{
 if(top[nstack]<=limit[nstack])
 {
  cout << "Stack " << nstack << " is empty." << endl;
  return 0;
 }
 int tmp = array[--top[nstack]];
 return tmp;
}

int main()
{
 stack3 * st3 = new stack3;
 int i;
 for(i=0;i<40;i++) st3->push(0,i);
 for(i=33;i<43;i++) st3->push(1,i);
 for(i=66;i<76;i++) st3->push(2,i);
 
 /*
 int* a = st3->stackarray();
 cout << a[33] << endl;*/


 while(!st3->isEmpty(0)) cout << st3->pop(0) << endl;
 while(!st3->isEmpty(1)) cout << st3->pop(1) << endl;
 while(!st3->isEmpty(2)) cout << st3->pop(2) << endl;
  
}


