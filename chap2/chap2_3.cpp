#include <iostream>
#include "../List/SingleList.h"

using namespace std;

int main()
{
  SingleList SL;

  SL.AppendtoRear(1);
  SL.AppendtoRear(2);
  SL.AppendtoRear(3);
  SL.AppendtoRear(5);
  SL.AppendtoRear(9);
  SL.display();

  Node* p = SL.Search(3);
  p->data = p->next->data;
  p->next = p->next->next;
  

  SL.display();
  
}
