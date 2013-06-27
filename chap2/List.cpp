#include <iostream>
#include "List.h"

using namespace std;

SList::SList()
{
 head = NULL;
}
/* Try this */
SList::SList(node* p)
{
 head = p;
}

bool SList::isEmpty()
{
 return head==NULL;
}

int SList::ListLength()
{
 node* p = head;
 int cnt =0;
 while(p!=NULL)
 {
  cnt++;
  p=p->nextnode();
 }
 return cnt;
}

void SList::AppendtoTail(int a)
{
 node* p = new node(a,NULL);
 if(head==NULL) {head=p;return;}
 node* q = head;
 while(q->nextnode()!=NULL) q = q->nextnode();
 q->setNext(p);
}

void SList::display()
{
 if(head==NULL){cout << "Empty List."<<endl; return;}
 cout << "head";
 node* p = head;
 while(p!=NULL)
 {
  cout<<" -> " << p->value();
  p=p->nextnode();
 }
 cout<<endl;
}

node* SList::ListHead()
{return head;}


