#include <iostream>
#include "../List/SingleList.h"

using namespace std;

Node* kthtolast(Node* cur, int k, int &i)
{
  if(cur == NULL) return NULL;
  Node* nd = kthtolast(cur -> Node_next(), k, i);
  i = i+1;
  if(i == k) return cur;
  return nd;
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
 int cnt=0;
 Node *kthnode = kthtolast(SL -> Listhead(), k, cnt);
 cout << k << "th to the end: " << kthnode->Node_value() << endl;
 return 0;
}
