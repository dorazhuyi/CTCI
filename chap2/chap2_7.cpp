#include <iostream>
#include "List.h"

using namespace std;

int main()
{
 bool isPalindrome(node*, int);
 bool isPalindrome(node*);
 /* Create Palindrome List*/
 SList *SLodd = new SList;
 for(int i=0;i<5;i++) SLodd->AppendtoTail(i);
 for(int i=1;i<5;i++) SLodd->AppendtoHead(i);
 SLodd->display();

 SList *SLeven = new SList;
 for(int i=0;i<4;i++) SLeven->AppendtoTail(i);
 for(int i=0;i<4;i++) SLeven->AppendtoHead(i);
 SLeven->display();

 //if(isPalindrome(SLodd->ListHead(),SLodd->ListLength())) cout << "Palindrome." << endl;
 //if(isPalindrome(SLeven->ListHead(),SLeven->ListLength())) cout << "Palindrome." << endl;
 if(isPalindrome(SLodd->ListHead())) cout << "Palindrome." << endl;
 if(isPalindrome(SLeven->ListHead())) cout << "Palindrome." << endl;

 

 return 0;
}

/* List length is known*/
bool isPalindrome(node* head, int length)
{
  SList* tmp = new SList;
  for(int i=0;i<length/2;i++)
  {
    tmp->AppendtoHead(head->value());
    head = head->nextnode();
  }
  tmp->display();
  if(length%2 == 1) head = head->nextnode();

//  cout << head->value() << endl;

  node* p = tmp->ListHead();
  while(p!=NULL)
  {
    if(p->value()!=head->value()) return false;
    else
    {
      p = p->nextnode();
      head = head->nextnode();
    }
  }
  return true;
}

/* List length is unknown*/
bool isPalindrome(node* head)
{
  SList* tmp = new SList;
  node* runner = head;
  while(runner!=NULL && runner->nextnode()!=NULL)
  {
    tmp->AppendtoHead(head->value());
    head = head->nextnode();
    runner = runner->nextnode()->nextnode();
  }
  tmp->display();

  if(runner!=NULL) head = head->nextnode();

//  cout << head->value() << endl;

  node* p = tmp->ListHead();
  while(p!=NULL)
  {
    if(p->value()!=head->value()) return false;
    else
    {
      p = p->nextnode();
      head = head->nextnode();
    }
  }
  return true;
}
