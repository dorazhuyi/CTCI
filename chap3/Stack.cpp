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
