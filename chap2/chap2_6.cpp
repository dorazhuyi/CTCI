#include <iostream>
#include "List.h"

using namespace std;

int main()
{
  node* CreateCircular(int, int);
  node* LoopStart(node*);
  
  int start = 5;
  int length = 7;

  node* cir = CreateCircular(start, length);

  node* loops = LoopStart(cir);
  cout << loops->value() << endl;

  return 0;
}

  /* Create a circular list */
node* CreateCircular(int start, int length)
{
  SList* SL = new SList;
  for(int i=0;i<start;i++) SL->AppendtoTail(i);
  node* tail = SL->ListHead();
  while(tail->nextnode()!=NULL) tail=tail->nextnode();
  SL->display();

  SList* SLoop = new SList;
  for(int j=0;j<length-1;j++) SLoop->AppendtoTail(j+1+start);
  node* tail2 =SLoop->ListHead();
  while(tail2->nextnode()!=NULL) tail2=tail2->nextnode(); 
  SLoop->display();

  tail->setNext(SLoop->ListHead());
  tail2->setNext(tail);

  return SL->ListHead();
}

/* Find out the Loop start */
node* LoopStart(node* cir)
{
  
  node* slow = cir;
  node* fast = slow;

  /* Find first Collide */
  do
  {
   slow = slow->nextnode();
   fast = fast->nextnode()->nextnode();
  } while (slow !=fast);

  /* Find loop start */
  fast = cir;
  while (fast!=slow)
  {
   slow = slow->nextnode();
   fast = fast->nextnode();
  }
  
  return slow;
}

