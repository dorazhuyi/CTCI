#include <iostream>
#include "List.h"

using namespace std;

class 

int main()
{
  SList* SL1 = new SList;//Don't forget to new...
  SList* SL2 = new SList;
  node* ListAddfl(node*, node*, int);

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

 return 0;
}

node* ListAddfl(node*, node*, int);
