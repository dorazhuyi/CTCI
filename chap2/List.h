class node
{
 public:
  node(){data = 0; next = NULL;}
  node(int a, node* n){data = a;next = n;}
  void setValue(int a){data = a;}
  void setNext(node* n){next = n;}
  int value(){return data;}
  node* nextnode(){return next;}
 private:
  int data;
  node* next;
};

class SList
{
 public:
  SList();
  SList(node*);
  bool isEmpty();
  int ListLength();
  void AppendtoHead(int);
  void AppendtoTail(int);
//  int Delete(int);
//  int DeleteHead();
//  int DeleteTail();
  void display();
  node* ListHead();
 private:
  node* head;
};

