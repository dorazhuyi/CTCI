#include <iostream>

using namespace std;

struct node
{
 int data;
 node* next;
};

node* CreateList(int length)
{
  int i;
  int a;
  node* p = new node;
  cout << "Input integer: ";
  cin >> a;
  p->data = a;
  p->next = NULL;

  node* q = p;//runner

  for(i=1;i<length;i++)
  {
   cout << "Input integer: ";
   cin >> a;
   p = new node;
   p->data = a;
   p->next = q;
   q = p;
  }
  return p;
}

node* ListAdd(node* a, node* b)
{
 if(a==NULL || b==NULL) 
 {cout << "Invalid Input."<<endl;return NULL;}

 int cnt = 0;

 node* p = new node;
 p->data = a->data + b->data + cnt;
 if(p->data > 10)
 {
   p->data = p->data - 10;
   cnt=1;
 }
 else cnt=0;
 node* sum=p;
 node* q = p; //runner
 
 while(a->next!=NULL && b->next!=NULL)
 {
   a = a->next;
   b = b->next;
   p = new node;
   p->data = a->data + b->data + cnt;
   if(p->data >= 10)
   {
     p->data = p->data - 10;
     cnt=1;
   }
   else cnt=0;
   q -> next = p;
   q = p;
 }
 return sum;
}

void display(node* p)
{
  if(p==NULL){cout <<"Empty List." <<endl;return;}
  cout<<"1's digit ";
  while(p!=NULL)
  {cout << " -> " << p->data;
   p = p->next;}
  cout << endl;
}

int main()
{
  cout << "Create List a: " << endl;
  node* a = CreateList(3);
  cout << "Create List b: " << endl;
  node* b = CreateList(3);
  
  display(a);
  display(b);

  node*sum = ListAdd(a,b);
  display(sum);

  return 0;
}

