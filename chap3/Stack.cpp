#include <iostream>
#include "Stack.h"

using namespace std;

void LStack::push(int a)
{
 node* t = new node(a,NULL);
 if(top==NULL) top = t;
 else {t->setNext(top); top=t;}
}

int LStack::pop()
{
 if(top==NULL){cout<<"Empty Stack."<<endl; return 0;}
 int tmp = top->value();
 top = top->nextnode();
 return tmp;
}

AStack::AStack()
{
 array = new int[2];
 top = 0;
 length = 2;
}

AStack::AStack(const int n)
{
 array = new int[n];
 top = 0;
 length = n;
}

void AStack::push(int n)
{
 array[top++]=n;
 if(top==length) 
 {
  length *= 2;
  array = resize(length);
 }
 //cout << top << endl; //Debug
}

int AStack::pop()
{
 if(top==0) {cout<<"Empty Stack."<<endl; return 0;}
 int tmp = array[--top];
 array[++top]=0;
 if(--top <= length/4-1) 
 {
  length = length/2;
  array = resize(length);
 }

 return tmp;
}

int* AStack::resize(int n)
{
 int* tmp = new int[n];
 for(int i=0;i<length;i++)
 {
   tmp[i] = array[i];
 }
 return tmp; 
}
