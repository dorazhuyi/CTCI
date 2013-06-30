#include <iostream>
#include <cmath>
#include "List.h"

using namespace std;

/* Try this smart thing later
struct imsum
{
 node* lower;
 int carry;
};
*/

int main()
{
  SList* SL1 = new SList; //Don't forget to new...
  SList* SL2 = new SList;
  node* ListAddfl(node*, node*, int&);

 /* Create List 1 */
 SL1->AppendtoTail(9);
 SL1->AppendtoTail(6);
 SL1->AppendtoTail(6);
 SL1->AppendtoTail(3);
 SL1->display();

 /* Create List 2 */
// SL2->AppendtoTail(1);
 SL2->AppendtoTail(5);
 SL2->AppendtoTail(9);
 SL2->AppendtoTail(2);
 SL2->display();

 if(SL1->ListLength() != SL2->ListLength())
 {
   SList* p = SL1->ListLength() < SL2->ListLength() ? SL1:SL2; 
   int npad = abs(SL1->ListLength() - SL2->ListLength());
   for(int i=0;i<npad;i++)
   {p->AppendtoHead(0);}
 }
 SL1->display();
 SL2->display();

 int c = 0;
 node * sum = ListAddfl(SL1->ListHead(),SL2->ListHead(),c);


 SList* sumlist;
 if(c==0) sumlist = new SList(sum);
 else 
 {node* h = new node(1,sum);
  sumlist = new SList(h);}
 sumlist->display();

 return 0;
}

/*Try my own thought first*/
node* ListAddfl(node* a, node* b, int& carry)
{
 if(a==NULL && b==NULL && carry ==0) return NULL;
 node* s = ListAddfl(a->nextnode(),b->nextnode(),carry); 
 node *l = new node;
 l->setNext(s);
 int val = a->value() + b->value() + carry;
 l->setValue(val%10);
 carry = val>=10?1:0;
 cout << carry << endl;
 return l;
}
