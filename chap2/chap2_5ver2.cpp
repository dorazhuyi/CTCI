#include <iostream>
#include "List.h"

using namespace std;

int main()
{
  SList* SL1 = new SList;//Don't forget to new...
  SList* SL2 = new SList;
  node* ListAdd(node*, node*, int);

 /* Create List 1 */
 SL1->AppendtoTail(7);
 SL1->AppendtoTail(1);
 SL1->AppendtoTail(6);
 SL1->display();

 /* Create List 2 */
 SL2->AppendtoTail(5);
 SL2->AppendtoTail(9);
 SL2->AppendtoTail(2);
 SL2->display();

 node* sum = ListAdd(SL1->ListHead(), SL2->ListHead(), 0);
 SList Listsum(sum);
 Listsum.display();

 return 0;
}

/* The solution */
node* ListAdd(node*a, node* b, int carry)
{
  if(a==NULL && b==NULL && carry==0){return NULL;}

  node* result = new node(carry, NULL);
  
  int currvalue = carry;
  
  if(a!=NULL) {currvalue += a->value();}
  if(b!=NULL) {currvalue += b->value();}

  result->setValue(currvalue%10);//This is smart

  // Here is the Recursion...TAT
  if(a!=NULL || b!=NULL)
  {
    node* more = ListAdd(a==NULL?NULL:a->nextnode(), b==NULL?NULL:b->nextnode(), currvalue>=10?1:0); // Hey this is smart...
    result->setNext(more);
  }
  return result;
}

