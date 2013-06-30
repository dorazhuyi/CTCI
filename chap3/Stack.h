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

class LStack
{
 public:
  LStack(){top = NULL;}
  LStack(node* t){top = t;}
  bool isEmpty(){return top==NULL;}
  void push(int);
  int pop();
 private:
  node* top;
};

class AStack
{
 public:
  AStack();
  AStack(const int);
  bool isEmpty(){return top==0;}
  void push(int);
  int pop();
 private:
  int top;
  int* array;
  int length;
  int* resize(int);
};

