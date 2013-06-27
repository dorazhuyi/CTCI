/*************2013.6.25*********
Author: Yi Zhu
*******************************/
#include <iostream>
#include <cstdlib>
#include "../List/SingleList.h"

using namespace std;

int main()
{
  SingleList SL;
  int i;
  for(i=0;i<10;i++)
   SL.AppendtoHead(rand() % 100);
  SL.display();

  int vx = 50;
  Node* curr = SL.ListHead();

  SingleList small;
  SingleList big;
  for(i=0;i<10;i++)
  {
   if(curr->data < vx) {small.AppendtoHead(curr->data);curr = curr->next;}
   else {big.AppendtoHead(curr->data);curr = curr->next;}
  }
  small.display();
  big.display();
  small.ListRear() -> next = big.ListHead();
  small.display();
  return 0;
}

