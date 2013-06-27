#include <iostream>
#include "../List/SingleList.h"

using namespace std;

Node* kthtolasti(Node* head, int k)
{
 if(head == NULL) return NULL;
 Node* p, *q;
 p=head;
 q=head;
 for(int i=0;i<k;i++)
 {
   if(q-> Node_next() == NULL) 
   { cout<< "List is shorter than " << k << endl;
     return NULL;
   }
   q = q -> Node_next();
 }
 while(q != NULL)
 {
   p = p -> Node_next();
   q = q -> Node_next();
 }
 return p;
}

int main()
{
 SingleList* SL = new SingleList;
 SL -> appendtorear(1);
 SL -> appendtorear(3);
 SL -> appendtorear(5);
 SL -> appendtorear(7);
 SL -> appendtorear(9);
 SL -> display();
 int k=3;
 Node *kthnode = kthtolasti(SL -> Listhead(), k);
 cout << k << "th to the end: " << kthnode->Node_value() << endl;
 return 0;
}
